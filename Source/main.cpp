//
// Uses the COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 20/06/2019.
//
// Inspired by the following tutorials:
// - https://learnopengl.com/Getting-started/Hello-Window
// - https://learnopengl.com/Getting-started/Hello-Triangle
//
// Modified by Team 8 for Assignment 2 due 27/07/2020.
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
#include <Objects/Keven.h>
#include <Sphere.h>

using namespace std;

// Which model we are currently looking at (0, 1, 2, 3, 4)
// If -1, then we are not looking at any models
static int currentModel = -1;
Camera* camera_ptr;
int width, height;

// Sphere paths and vertices variables
string spherePath = "../Assets/Models/sphere.obj";
int sphereVertices;

//Function interfaces for camera response to mouse input.
void mouse_callback(GLFWwindow* window, double xpos, double ypos); 
void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// Models
Thomas* Model1 = new Thomas();
Melina* Model2 = new Melina();
Sharon* Model3 = new Sharon();
Anissa* Model4 = new Anissa();
Keven* Model5 = new Keven();
// Sphere* sphere = new Sphere();

void initialize() {
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
}

/*
Returns an array of VAOs for cubes, grids, and axes. 
*/
int* createCubeGridSphereVAO(Cube objCube, Grid objGrid, Sphere objSphere) {
	// create VAOs
	int cubeVAO = objCube.createCubeVAO();
	int gridVAO = objGrid.createGridVAO();
	int axisVAO = objGrid.createAxisVAO();
	GLuint sphereVAO = objSphere.createSphereVAO(spherePath, sphereVertices);

	int VAO[4] = { cubeVAO, gridVAO, axisVAO, sphereVAO };

	return VAO;
}

void setUpProjection(int shaderProgram, Camera* camera) {
	// Set up Perspective View
	glm::mat4 Projection = glm::perspective(glm::radians(camera->fov),  // field of view in degrees
		(float)width / height,     // aspect ratio
		0.01f, 100.0f);      // near and far (near > 0)

	GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &Projection[0][0]);
}

void renderGridAxisCubeSphere(int shaderProgram, int* VAO, Grid objGrid) {
	// Draw grid and axis
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO[1]); // grid
	glDrawArrays(GL_LINES, 0, objGrid.gridToPrint); // 3 vertices, starting at index 0
	glBindVertexArray(VAO[2]); // axis
	glDrawArrays(GL_LINES, 0, objGrid.axisToPrint);
	glBindVertexArray(VAO[0]); // cube
	glBindVertexArray(VAO[3]); // sphere
}

/*
Method for changing the render mode of all the models.
*/
void renderMode(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // all triangles filled in
	else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // triangle edges only
	else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); // triangle vertices only
}

void selectModel(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		currentModel = 1; // Thomas
	}

	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		currentModel = 2; // Melina
	}

	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
	{
		currentModel = 3; // Sharon
	}

	else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
	{
		currentModel = 4; // Anissa
	}

	else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
	{
		currentModel = 5; // Keven
	}
}

/*
Methods for translating models. Passing all models for the switch statements.
Translations in increments of 0.005f.
*/
void translateLeft(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			Model1->translate(glm::translate(mat4(1.0f), vec3(-0.005f, 0.0f, 0.0f)));
			break;
		case 2:
			Model2->translate(glm::translate(mat4(1.0f), vec3(-0.005f, 0.0f, 0.0f)));
			break;
		case 3:
			Model3->translate(glm::translate(mat4(1.0f), vec3(-0.005f, 0.0f, 0.0f)));
			break;
		case 4:
			Model4->translate(glm::translate(mat4(1.0f), vec3(-0.005f, 0.0f, 0.0f)));
			break;
		case 5:
			Model5->translate(glm::translate(mat4(1.0f), vec3(-0.005f, 0.0f, 0.0f)));
			break;
		default:
			break;
		}
	}
}

void translateRight(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			Model1->translate(glm::translate(mat4(1.0f), vec3(0.005f, 0.0f, 0.0f)));
			break;
		case 2:
			Model2->translate(glm::translate(mat4(1.0f), vec3(0.005f, 0.0f, 0.0f)));
			break;
		case 3:
			Model3->translate(glm::translate(mat4(1.0f), vec3(0.005f, 0.0f, 0.0f)));
			break;
		case 4:
			Model4->translate(glm::translate(mat4(1.0f), vec3(0.005f, 0.0f, 0.0f)));
			break;
		case 5:
			Model5->translate(glm::translate(mat4(1.0f), vec3(0.005f, 0.0f, 0.0f)));
			break;
		default:
			break;
		}
	}
}

void translateUp(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			Model1->translate(glm::translate(mat4(1.0f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 2:
			Model2->translate(glm::translate(mat4(1.0f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 3:
			Model3->translate(glm::translate(mat4(1.0f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 4:
			Model4->translate(glm::translate(mat4(1.0f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 5:
			Model5->translate(glm::translate(mat4(1.0f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		default:
			break;
		}
	}
}

void translateDown(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			Model1->translate(glm::translate(mat4(1.0f), vec3(0.0f, -0.005f, 0.0f)));
			break;
		case 2:
			Model2->translate(glm::translate(mat4(1.0f), vec3(0.0f, -0.005f, 0.0f)));
			break;
		case 3:
			Model3->translate(glm::translate(mat4(1.0f), vec3(0.0f, -0.005f, 0.0f)));
			break;
		case 4:
			Model4->translate(glm::translate(mat4(1.0f), vec3(0.0f, -0.005f, 0.0f)));
			break;
		case 5:
			Model5->translate(glm::translate(mat4(1.0f), vec3(0.0f, -0.005f, 0.0f)));
			break;
		default:
			break;
		}
	}
}

/*
Methods for rotating models. Passing all models for the switch statements.
Rotations in increments of 0.5f radians.
*/
void rotateLeft(GLFWwindow* window, GLuint modelMatrixLocation) {
	if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			//Model1->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 2:
			Model2->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)), modelMatrixLocation);
			break;
		case 3:
			//Model3->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 4:
			//Model4->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 5:
			//Model5->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		default:
			break;
		}
	}
}

void rotateRight(GLFWwindow* window, GLuint modelMatrixLocation) {
	if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			//Model1->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 2:
			Model2->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 1.0f, 0.0f)), modelMatrixLocation);
			break;
		case 3:
			//Model3->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 4:
			//Model4->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 5:
			//Model5->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		default:
			break;
		}
	}
}

/*
Methods for scaling. Passing all models for switch statements.
Scaling in increments of 0.005f.
*/
void scaleUp(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			Model1->scale(glm::scale(mat4(1.0f), vec3(1.005f, 1.005f, 1.005f)));
			break;
		case 2:
			Model2->scale(glm::scale(mat4(1.0f), vec3(1.005f, 1.005f, 1.005f)));
			break;
		case 3:
			Model3->scale(glm::scale(mat4(1.0f), vec3(1.005f, 1.005f, 1.005f)));
			break;
		case 4:
			Model4->scale(glm::scale(mat4(1.0f), vec3(1.005f, 1.005f, 1.005f)));
			break;
		case 5:
			Model5->scale(glm::scale(mat4(1.0f), vec3(1.005f, 1.005f, 1.005f)));
			break;
		default:
			break;
		}
	}
}

void scaleDown(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			Model1->scale(glm::scale(mat4(1.0f), vec3(0.995f, 0.995f, 0.995f)));
			break;
		case 2:
			Model2->scale(glm::scale(mat4(1.0f), vec3(0.995f, 0.995f, 0.995f)));
			break;
		case 3:
			Model3->scale(glm::scale(mat4(1.0f), vec3(0.995f, 0.995f, 0.995f)));
			break;
		case 4:
			Model4->scale(glm::scale(mat4(1.0f), vec3(0.995f, 0.995f, 0.995f)));
			break;
		case 5:
			Model5->scale(glm::scale(mat4(1.0f), vec3(0.995f, 0.995f, 0.995f)));
			break;
		default:
			break;
		}
	}
}

/*
Method for focusing on a single model at a time.
Numbers pressed are associated with corresponding model.
Sets camera's focus to number associated with chosen model.
Sets currentModel to number associated with chosen model.
*/
void cameraFocus(GLFWwindow* window, int shaderProgram, Camera* camera) {

	GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");

	if (currentModel == 1 && glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		glm::mat4 modelMatrix = Model1->getModelMatrix();

		glm::vec3 translationComponent = glm::vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);

		glm::mat4 viewMatrix = glm::lookAt(glm::vec3(-0.75f, 0.01f, 0.0f), // position
											translationComponent, // front camera.cameraPos + camera.cameraFront
											camera->cameraUp);  // up

		GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
		glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

		currentModel = 1;
	}

	// Melina Model
	else if (currentModel == 2 && glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		glm::mat4 modelMatrix = Model2->getModelMatrix();

		glm::vec3 translationComponent = glm::vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);

		glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0.75f, 0.01f, 0.0f), // position
			translationComponent, // front camera.cameraPos + camera.cameraFront
			camera->cameraUp);  // up

		GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
		glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

		currentModel = 2;
	}

	// Sharon Model
	else if (currentModel == 3 && glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
	{
		glm::mat4 modelMatrix = Model3->getModelMatrix();

		glm::vec3 translationComponent = glm::vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);

		glm::mat4 viewMatrix = glm::lookAt(glm::vec3(-0.75f, 0.01f, 1.5f), // position
			translationComponent, // front camera.cameraPos + camera.cameraFront
			camera->cameraUp);  // up

		glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

		currentModel = 3;
	}

	// Anissa Model
	else if (currentModel == 4 && glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
	{
		glm::mat4 modelMatrix = Model4->getModelMatrix();

		glm::vec3 translationComponent = glm::vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);

		glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0.75f, 0.01f, 1.5f), // position
			translationComponent, // front camera.cameraPos + camera.cameraFront
			camera->cameraUp);  // up

		GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
		glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

		currentModel = 4;
	}
  
  // Keven Model
	else if (currentModel == 5 && glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
	{
		glm::mat4 modelMatrix = Model5->getModelMatrix();

		glm::vec3 translationComponent = glm::vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);

		glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.01f, 1.0f), // position
			translationComponent, // front camera.cameraPos + camera.cameraFront
			camera->cameraUp);  // up

		GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
		glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

		currentModel = 5;
	}
	else if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
	{
		currentModel = -1;
	}
}

void setUpCamera(Camera* camera, int shaderProgram) {
	glm::mat4 viewMatrix = glm::lookAt(camera->cameraPos, // position
		camera->cameraDirection, // front -- camera.cameraPos + camera.cameraFront
		camera->cameraUp);  // up
	GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);
}

/*
Main method.
*/
int main(int argc, char* argv[])
{
	// Initialize GLFW and OpenGL version
	initialize();

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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // resizes window correctly

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
	camera_ptr = new Camera(window);

	// Define and upload geometry to the GPU here ...
	Grid objGrid;
	Cube objCube;
	Sphere objSphere;
	int* VAO = createCubeGridSphereVAO(objCube, objGrid, objSphere);

	// Entering Main Loop
	while (!glfwWindowShouldClose(window))
	{
		// Enable z-buffer
		glEnable(GL_DEPTH_TEST);

		// Each frame, reset color of each pixel to glClearColor
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Set up Perspective View
		glfwGetWindowSize(window, &width, &height); // if window is resized, get new size to draw perspective view correctly
		setUpProjection(shaderProgram, camera_ptr);

		// Render grid and axis and cube
		renderGridAxisCubeSphere(shaderProgram, VAO, objGrid);

		GLuint worldMatrixLocation = glGetUniformLocation(shaderProgram, "worldMatrix"); //linking with shader

		// Draw AlphaNumeric models
		Model1->draw(worldMatrixLocation, sphereVertices);
		Model2->draw(worldMatrixLocation, sphereVertices);
		Model3->draw(worldMatrixLocation, sphereVertices);
		Model4->draw(worldMatrixLocation, sphereVertices);
		Model5->draw(worldMatrixLocation, sphereVertices);

		// an attempt to draw a sphere?? idk i think cuz it's connected to the shader it won't work;;
		//sphere->draw(worldMatrixLocation, sphereVertices);

		// Important: setting worldmatrix back to normal so other stuff doesn't get scaled down
		glm::mat4 worldMatrix = mat4(1.0f);
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &worldMatrix[0][0]);

		// Model Render Mode
		renderMode(window);

		// Camera frame timing
		camera_ptr->handleFrameData();
    
		// Set up Camera
		if(currentModel == -1)
			setUpCamera(camera_ptr, shaderProgram);

		// Choose which model to do transformation
		selectModel(window);

		// Transformations of Models

		// Translating left
		translateLeft(window);

		// Translating right
		translateRight(window);

		// Translating up
		translateUp(window);

		// Translating down
		translateDown(window);

		// Rotating Left
		//rotateLeft(window);

		// Rotating Right
		rotateRight(window, worldMatrixLocation);
		
		// Scale Up
		scaleUp(window);

		// Scale Down
		scaleDown(window);

		// Change camera view to model view 
		cameraFocus(window, shaderProgram, camera_ptr);

		// End frame
		glfwSwapBuffers(window);

		// Detect inputs
		glfwPollEvents();

		// Handle inputs
		camera_ptr->handleKeyboardInputs();

		glBindVertexArray(0);
	}
  
	// Shutdown GLFW
	glfwTerminate();

	return 0;
}

/*
Adaptors based on the interfaces at the top.
Handle camera responses to mouse actions.
*/
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	camera_ptr->mouseCallbackHandler(window, xpos, ypos);
}

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
{
	camera_ptr->mouseScrollHandler(window, xOffset, yOffset);
} 	

// Makes sure the window is correctly resized (continues drawing)
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
