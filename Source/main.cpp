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

#include <Objects/Grid.h> //rendered objects
#include <Camera.h>

const char* getVertexShaderSource()
{
    // Insert Shaders here ...
   // For now, you use a string for your shader code, in the assignment, shaders will be stored in .glsl files

    return
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;"
        "layout (location = 1) in vec3 aColor;"
        ""
        "uniform mat4 worldMatrix = mat4(1.0);"
        "uniform mat4 viewMatrix = mat4(1.0);" // default value for view matrix (identity)
        "uniform mat4 projectionMatrix = mat4(1.0);"
        ""
        "out vec3 vertexColor;"
        "void main()"
        "{"
        "   vertexColor = aColor;"
        "mat4 modelViewProjection = projectionMatrix * viewMatrix * worldMatrix;"
        "gl_Position = modelViewProjection * vec4(aPos.x, aPos.y, aPos.z, 1.0);"
        "}";
}


const char* getFragmentShaderSource()
{
    return
        "#version 330 core\n"
        "in vec3 vertexColor;"
        "out vec4 FragColor;"
        "void main()"
        "{"
        "   FragColor = vec4(vertexColor.r, vertexColor.g, vertexColor.b, 1.0f);"
        "}";
}


int compileAndLinkShaders()
{
    // compile and link shader program
     // return shader program id
     // ------------------------------------


     // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = getVertexShaderSource();
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = getFragmentShaderSource();
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;

}

int createvao()
{
    /* can be deleted
    float AXISLENGTH = static_cast<float>(5) / static_cast <float>(100);
    // A vertex is a point on a polygon, it contains positions and other data (eg: colors)
   
    glm::vec3 grid[36];
    glm:: vec3 axis[] = {
        // position					        // color 
         //x-axis
         glm::vec3(0.0f,  0.0f, 0.0f),       glm::vec3(1.0f,  0.0f, 0.0f),
         glm::vec3(AXISLENGTH, 0.0f, 0.0f),  glm::vec3(1.0f,  0.0f, 0.0f),

         //y-axis
         glm::vec3(0.0f,  0.0f, 0.0f),       glm::vec3(0.0f,  1.0f, 0.0f),
         glm::vec3(0.0f, AXISLENGTH, 0.0f),  glm::vec3(0.0f,  1.0f, 0.0f),

         //z-axis
         glm::vec3(0.0f,  0.0f, 0.0f),       glm::vec3(0.0f,  0.0f, 1.0f),
         glm::vec3(0.0f, 0.0f, AXISLENGTH),  glm::vec3(0.0f,  0.0f, 1.0f),
    };
    
    
    //generategrid
    //generate columns
    int numOfColumns = (3 + 2) * 4;
    float offset = static_cast<float>(1) / static_cast <float>(4);
    float counter = 0;
    for (int i = 0; i < numOfColumns; i = i + 4) {
        grid[i] = glm::vec3(-0.5f + counter, 0.5f, 0.0f);
        grid[i+1] = glm::vec3(1.0f, 1.0f, 1.0f);
        grid[i+2] = glm::vec3(-0.5 + counter, -0.5f, 0.0f);
        grid[i+3] = glm::vec3(1.0f, 1.0f, 1.0f);
        counter += offset;
    }

    offset = 0.333f;
    counter = 0;
    for (int i = 20; i < 36; i = i + 4) {
        grid[i] = glm::vec3(-0.5f, 0.5f - counter, 0.0f);
        grid[i + 1] = glm::vec3(1.0f, 1.0f, 1.0f);
        grid[i + 2] = glm::vec3(0.5, 0.5f - counter, 0.0f);
        grid[i + 3] = glm::vec3(1.0f, 1.0f, 1.0f);
        counter += offset;
    }
    
    // Create a vertex array
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    

    // Upload Vertex Buffer to the GPU, keep a reference to it (vbo)
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(grid), grid, GL_STATIC_DRAW);
   

    glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
        3,                   // size
        GL_FLOAT,            // type
        GL_FALSE,            // normalized?
        2 * sizeof(glm::vec3), // stride - each vertex contain 2 vec3 (position, color)
        (void*)0             // array buffer offset
    );
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
        3,
        GL_FLOAT,
        GL_FALSE,
        2 * sizeof(glm::vec3),
        (void*)sizeof(glm::vec3)      // color is offseted a vec3 (comes after position)
    );
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // VAO already stored the state we just defined, safe to unbind buffer
    glBindVertexArray(0); // Unbind to not modify the VAO

    return vao;
    */
    return 0;
}


int main(int argc, char*argv[])
{
    // Initialize GLFW and OpenGL version
    glfwInit();
    //Grid objGrid;

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

    // Create Window and rendering context using GLFW, resolution is 800x600
    GLFWwindow* window = glfwCreateWindow(800, 600, "Comp371 - Assignment 1 - Team 8", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    

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
    int shaderProgram = compileAndLinkShaders();

	// Create Camera Object
	Camera camera(window);

    
    // Define and upload geometry to the GPU here ...
    Grid objGrid;
    int gridVAO = objGrid.createGridVAO();
    int axisVAO = objGrid.createAxisVAO();
    
    // Entering Main Loop
    while(!glfwWindowShouldClose(window))
    {
		// Enable z-buffer
		glEnable(GL_DEPTH_TEST);

        // Each frame, reset color of each pixel to glClearColor
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set up Perspective View
        glm::mat4 Projection = glm::perspective(glm::radians(45.0f),  // field of view in degrees
            800.0f / 600.0f,     // aspect ratio
            0.01f, 100.0f);      // near and far (near > 0)
    	
        
		GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
		glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &Projection[0][0]);
    	
        //glPolygonMode(GL_FRONT, GL_LINE);
        glUseProgram(shaderProgram);
        glBindVertexArray(gridVAO);
        glDrawArrays(GL_LINES, 0, objGrid.gridToPrint); // 3 vertices, starting at index 0
        glBindVertexArray(axisVAO);
        glDrawArrays(GL_LINES, 0, objGrid.axisToPrint);
        glBindVertexArray(0);

    	// Camera frame timing
		camera.handleFrameData();

		// Set up Camera
		glm::mat4 viewMatrix = glm::lookAt(camera.cameraPos, // position
			camera.cameraPos + camera.cameraFront, // front
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
