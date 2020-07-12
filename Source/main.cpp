//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 20/06/2019.
//
// Inspired by the following tutorials:
// - https://learnopengl.com/Getting-started/Hello-Window
// - https://learnopengl.com/Getting-started/Hello-Triangle
//
//
//Modified by:
//
// Liam-Thomas Flynn on 09/07/2020
//
//

#include <iostream>

#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler
#include <GLFW/glfw3.h> // GLFW provides a cross-platform interface for creating a graphical context,
                        // initializing OpenGL and binding inputs

#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp>

#include <Objects/Shaders.h>
#include <Objects/Grid.h> //rendered objects
#include <Objects/Camera.h>
#include <Objects/Thomas.h>
#include <Objects/Melina.h>
#include <Objects/Sharon.h>
#include <Objects/Anissa.h>

Camera* camera_ptr;
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);


int main(int argc, char* argv[])
{
    // Initialize GLFW and OpenGL version
    glfwInit();

#if defined(PLATFORM_OSX)	
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
    // On windows, we set OpenGL version to 2.1, to support more hardware
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
#endif

    // Create Window and rendering context using GLFW, resolution is 1024x768

    GLFWwindow* window = glfwCreateWindow(1024, 768, "Comp371 - Assignment 1 - Team 8", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
	
    glfwMakeContextCurrent(window);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to create GLEW" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  
    // Compile and link shaders here ...
    Shaders shaders;
    int shaderProgram = shaders.compileAndLinkShaders();

	// Create Camera Object
	Camera camera(window);
	camera_ptr = &camera;
	

    // Define and upload geometry to the GPU here ...
    Grid objGrid;
    int gridVAO = objGrid.createGridVAO();
    int axisVAO = objGrid.createAxisVAO();

    Cube objCube;
    int cubeVAO = objCube.createCubeVAO();
    glm::mat4 worldMatrix = mat4(1.0f);

    // Models
    Thomas Model1;
    Melina Model2;
    Sharon Model3;
    Anissa Model4;

    // Entering Main Loop
    while (!glfwWindowShouldClose(window))
    {

        // Enable z-buffer
        glEnable(GL_DEPTH_TEST);

        // Each frame, reset color of each pixel to glClearColor
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set up Perspective View
        glm::mat4 Projection = glm::perspective(glm::radians(camera.fov),  // field of view in degrees
            1024.0f / 768.0f,     // aspect ratio
            0.01f, 100.0f);      // near and far (near > 0)

        GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
        glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &Projection[0][0]);

        //glPolygonMode(GL_FRONT, GL_LINE);
        // Draw grid and axis
        glUseProgram(shaderProgram);
        glBindVertexArray(gridVAO);
        glDrawArrays(GL_LINES, 0, objGrid.gridToPrint); // 3 vertices, starting at index 0
        glBindVertexArray(axisVAO);
        glDrawArrays(GL_LINES, 0, objGrid.axisToPrint);

        // Draw letters
        GLuint worldMatrixLocation = glGetUniformLocation(shaderProgram, "worldMatrix"); //linking with shader
        glBindVertexArray(cubeVAO);
        Model1.draw(worldMatrixLocation);
        Model2.draw(worldMatrixLocation);
        Model3.draw(worldMatrixLocation);
        Model4.draw(worldMatrixLocation);
        glBindVertexArray(0);

        glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &worldMatrix[0][0]); //*Important: setting worldmatrix back to normal so other stuff doesn't get scaled down

        // Camera frame timing
        camera.handleFrameData();
        
		// Set up Camera
		glm::mat4 viewMatrix = glm::lookAt(camera.cameraPos, // position
			camera.cameraDirection, // front -- camera.cameraPos + camera.cameraFront
			camera.cameraUp);  // up
		GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
		glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

        // Set up Camera
        glm::mat4 viewMatrix = glm::lookAt(camera.cameraPos, // position
            vec3(0.0f, 0.0f, 0.0f), // front camera.cameraPos + camera.cameraFront
            camera.cameraUp);  // up
        GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

        // End frame
        glfwSwapBuffers(window);

        // Detect inputs
        glfwPollEvents();

        // Handle inputs
        camera.handleKeyboardInputs();
    }

    // Shutdown GLFW
    glfwTerminate();
    
	return 0;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	camera_ptr->mouseCallbackHandler(window, xpos, ypos);
}

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
{
	camera_ptr->mouseScrollHandler(window, xOffset, yOffset);
}