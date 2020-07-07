//
// COMP 371 Labs Framework
//
// Created by Nicolas Bergeron on 20/06/2019.
//
// Inspired by the following tutorials:
// - https://learnopengl.com/Getting-started/Hello-Window
// - https://learnopengl.com/Getting-started/Hello-Triangle

#include <iostream>


#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler

#include <GLFW/glfw3.h> // GLFW provides a cross-platform interface for creating a graphical context,
                        // initializing OpenGL and binding inputs

#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp> // include this to create transformation matrices

const char* getVertexShaderSource()
{
    // For now, you use a string for your shader code, in the assignment, shaders will be stored in .glsl files

	//gl_Position = modelViewProjection * vec4(aPos.x, aPos.y, aPos.z, 1.0);"
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

int createVertexArrayObject()
{
    // A vertex is a point on a polygon, it contains positions and other data (eg: colors)

	// square
	//glm::vec3 vertices[] = {
	//	glm::vec3(0.5f,  0.5f, 0.03f),  // top right position
	//	glm::vec3(0.0f,  1.0f, 0.0f),  // top center color (red)

	//	glm::vec3(0.5f, -0.5f, 0.03f),  // bottom right
	//	glm::vec3(1.0f,  0.0f, 0.0f),  // top center color (red)

	//	glm::vec3(-0.5f, -0.5f, 0.03f),  // bottom left
	//	glm::vec3(0.0f,  0.0f, 1.0f),  // top center color (blue)

	//	glm::vec3(-0.5f, 0.5f, 0.03f),  // top left
	//	glm::vec3(1.0f,  0.0f, 0.0f),  // top center color (re)
	//};

	// triangle
	/**glm::vec3 vertices[] = {
		glm::vec3(0.0f,  0.5f, 0.03f),  // top right position
		glm::vec3(1.0f,  0.0f, 0.0f),  // top center color (red)

		glm::vec3(0.5f, -0.5f, 0.03f),  // bottom right
		glm::vec3(0.0f,  1.0f, 0.0f),  // top center color (red)

		glm::vec3(-0.5f, -0.5f, 0.03f),  // bottom left
		glm::vec3(0.0f,  0.0f, 1.0f),  // top center color (blue)
	};*/

	// cube
	glm::vec3 vertices[] = {
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f,  0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f,  0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f,  0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),

		glm::vec3(-0.5f, -0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f, -0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),

		glm::vec3(-0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f,  0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),

		glm::vec3( 0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f,  0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f, -0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),

		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f, -0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f, -0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),

		glm::vec3(-0.5f,  0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f,  0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3( 0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f,  0.5f,  0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f),
		glm::vec3(-0.5f,  0.5f, -0.5f),
		glm::vec3(1.0f,  1.0f, 1.0f)
	};

	// unused atm
	GLuint elements[] = {
		0, 1, 3, //first triangle
		1, 2, 3 //second triangle
	};
    
    // Create a vertex array
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    
    // Upload Vertex Buffer to the GPU, keep a reference to it (vertexBufferObject)
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Create element array
	/**
	GLuint elementBufferObject;
	glGenBuffers(1, &elementBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
	*/
	
	
	
    glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
                          3,                   // size
                          GL_FLOAT,            // type
                          GL_FALSE,            // normalized?
                          2*sizeof(glm::vec3), // stride - each vertex contain 2 vec3 (position, color)
                          (void*)0             // array buffer offset
                          );
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          2*sizeof(glm::vec3),
                          (void*)sizeof(glm::vec3)    // color is offseted a vec3 (comes after position)
                          );
    glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return vao;
}


int main(int argc, char*argv[])
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

    // Create Window and rendering context using GLFW, resolution is 800x600

    GLFWwindow* window = glfwCreateWindow(1024, 768, "Comp371 - Lab 02", NULL, NULL);
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
    
    // Define and upload geometry to the GPU here ...
    int vao = createVertexArrayObject();
    
    // Variables to be used later in tutorial
    float angle = 0;
    float rotationSpeed = 180.0f;  // 180 degrees per second
    float lastFrameTime = glfwGetTime();

	// Enable Backface culling
	// This is when we "ignore" polygons that are behind the viewpoint to optimize our program
	//Enable(GL_CULL_FACE);

	// Uncomment this call to draw in wireframe polygons.
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Enable z-buffer (hidden surface removal)
	glEnable(GL_DEPTH_TEST);

	// Camera Attributes
	glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);

	// World space positions of our cubes (FOR TESTING)
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

    // Entering Main Loop
	while (!glfwWindowShouldClose(window))
	{
		// Each frame, reset color of each pixel to glClearColor
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw geometry
		glUseProgram(shaderProgram);
		glBindVertexArray(vao);

		float dt = glfwGetTime() - lastFrameTime;
		lastFrameTime += dt;

		// Set up Perspective View (Camera does not work without perspective view)
		glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f),  // field of view in degrees
			800.0f / 600.0f,     // aspect ratio
			0.01f, 100.0f);      // near and far (near > 0)

		GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
		glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]);


		// Set up Camera
		glm::mat4 viewMatrix = glm::lookAt(	cameraPos, // position
											cameraPos + cameraFront, // front
											cameraUp);  // up
		GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
		glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);


		// Render 10 different boxes (FOR TESTING)
		for (GLuint i = 0; i < 10; i++)
		{
			// calculate the model matrix for each object and pass it to shader before drawing
			glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			GLuint viewWorldMatrix = glGetUniformLocation(shaderProgram, "worldMatrix");
			glUniformMatrix4fv(viewWorldMatrix, 1, GL_FALSE, &model[0][0]);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		//glBindVertexArray(0);

		// End Frame
		glfwSwapBuffers(window); // double buffering
		glfwPollEvents();

		// Handle inputs
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		// Camera inputs
		float cameraSpeed = 2.5f * dt;

		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			cameraPos += cameraSpeed * cameraFront;
		}

		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			cameraPos -= cameraSpeed * cameraFront;
		}

		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		}

		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		}

		// by default, camera is centered at the origin and look towards negative z-axis
		// home button = 1
		if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		{
			cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		}

	}
    
    // Shutdown GLFW
    glfwTerminate();
    
    return 0;
}
