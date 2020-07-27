//
// Uses the COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 20/06/2019.
//
// Inspired by the following tutorials:
// - https://learnopengl.com/Getting-started/Hello-Window
// - https://learnopengl.com/Getting-started/Hello-Triangle
//
// Modified by Team 8 for Assignment 1 due 12/07/2020.
//
//

#include <iostream>
#include <string>

#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler
#include <GLFW/glfw3.h> // GLFW provides a cross-platform interface for creating a graphical context,
						// initializing OpenGL and binding inputs

#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp>
<<<<<<< HEAD
#include <Objects/Shader.h>
=======
#include <Objects/Shaders.h>
#include <LightSourceContainer.h>
>>>>>>> added specular lighting
#include <Objects/Grid.h> //rendered objects
#include <Objects/Camera.h>
#include <Objects/Thomas.h>
#include <Objects/Melina.h>
#include <Objects/Sharon.h>
#include <Objects/Anissa.h>
#include <Objects/Keven.h>

using namespace std;

// which model we are currently looking at (0, 1, 2, 3, 4)
// if -1, then we are not looking at any models
static int currentModel = -1;
static bool isTexture = false;
Camera* camera_ptr;
Shader* shaderProgram;

// random location range
const float MIN_RAND = -0.5f, MAX_RAND = 0.5f;
const float range = MAX_RAND - MIN_RAND;

>
//Function interfaces for camera response to mouse input.
void mouse_callback(GLFWwindow* window, double xpos, double ypos); 
void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// Models
Thomas* Model1 = new Thomas();
Melina* Model2 = new Melina();
Sharon* Model3 = new Sharon();
Anissa* Model4 = new Anissa();
Keven* Model5 = new Keven();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);



// Lighting
// These values seem to center the light for some reason, more investigating to do as why
glm::vec3 lightSourcePosition(3.0f, -3.0f, 12.0f);
//LightSourceContainer* LightSource = new LightSourceContainer(&lightSourcePosition); Does not appear where the light is comming from, reinstate once problem above is fixed


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

void setUpProjection(Shader shaderProgram, Camera* camera) {
	// Set up Perspective View
	glm::mat4 Projection = glm::perspective(glm::radians(camera->fov),  // field of view in degrees
		1024.0f / 768.0f,     // aspect ratio
		0.01f, 100.0f);      // near and far (near > 0)

<<<<<<< HEAD
	shaderProgram.setMat4("projectionMatrix", Projection);
=======

	GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &Projection[0][0]);
>>>>>>> added specular lighting
}

void renderGridAxisCube(Shader* shaderProgram, const Shader shaderArray[], Grid objGrid) {
	// Draw grid and axis
	objGrid.drawAxis(shaderArray[0]);
	objGrid.drawGrid(shaderProgram, isTexture); // 3 vertices, starting at index 0
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
Translations in increments of 0.005f
*/
void translateLeft(GLFWwindow* window, Thomas* Model1, Melina* Model2, Sharon* Model3, Anissa* Model4, Keven* Model5) {
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

void translateRight(GLFWwindow* window, Thomas* Model1, Melina* Model2, Sharon* Model3, Anissa* Model4, Keven* Model5) {
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

void translateUp(GLFWwindow* window, Thomas* Model1, Melina* Model2, Sharon* Model3, Anissa* Model4, Keven* Model5) {
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

void translateDown(GLFWwindow* window, Thomas* Model1, Melina* Model2, Sharon* Model3, Anissa* Model4, Keven* Model5) {
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
void rotateLeft(GLFWwindow* window, Thomas* Model1, Melina* Model2, Sharon* Model3, Anissa* Model4, Keven* Model5) {
	if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			Model1->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 2:
			Model2->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 3:
			Model3->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 4:
			Model4->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 5:
			Model5->rotate(glm::rotate(mat4(1.0f), glm::radians(-0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		default:
			break;
		}
	}
}

void rotateRight(GLFWwindow* window, Thomas* Model1, Melina* Model2, Sharon* Model3, Anissa* Model4, Keven* Model5) {
	if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			Model1->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 2:
			Model2->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 1.0f, 0.0f)));
			break;
		case 3:
			Model3->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 4:
			Model4->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 5:
			Model5->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
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
void scaleUp(GLFWwindow* window, Thomas* Model1, Melina* Model2, Sharon* Model3, Anissa* Model4, Keven* Model5) {
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
void scaleDown(GLFWwindow* window, Thomas* Model1, Melina* Model2, Sharon* Model3, Anissa* Model4, Keven* Model5) {
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
void cameraFocus(GLFWwindow* window, Shader* shaderProgram, Camera* camera, Thomas* Model1, Melina* Model2, Sharon* Model3, Anissa* Model4, Keven* Model5) {

	if (currentModel == 1 && glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		glm::mat4 modelMatrix = Model1->getModelMatrix();

		glm::vec3 translationComponent = glm::vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);

		glm::mat4 viewMatrix = glm::lookAt(glm::vec3(-0.75f, 0.01f, 0.0f), // position
											translationComponent, // front camera.cameraPos + camera.cameraFront
											camera->cameraUp);  // up

		shaderProgram->setMat4("viewMatrix", viewMatrix);

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

		shaderProgram->setMat4("viewMatrix", viewMatrix);

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

		shaderProgram->setMat4("viewMatrix", viewMatrix);

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

		shaderProgram->setMat4("viewMatrix", viewMatrix);

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

		shaderProgram->setMat4("viewMatrix", viewMatrix);

		currentModel = 5;
	}
	else if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
	{
		currentModel = -1;
	}
}

void setUpCamera(Camera* camera, Shader shaderProgram) {
	glm::mat4 viewMatrix = glm::lookAt(camera->cameraPos, // position
		camera->cameraDirection, // front -- camera.cameraPos + camera.cameraFront
		camera->cameraUp);  // up

<<<<<<< HEAD
	shaderProgram.setMat4("viewMatrix", viewMatrix);
=======
	
	GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);
>>>>>>> added specular lighting
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
	glfwSetKeyCallback(window, key_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetKeyCallback(window, key_callback);

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
	// Array of Shader Programs : 0 = color shader , 1 = texture shader
	Shader shaderPrograms[] = { 
								Shader("../Assets/Shaders/colorVertexShader.vertexshader", "../Assets/Shaders/colorFragmentShader.Fragmentshader"),
								Shader("../Assets/Shaders/texturedVertexShader.vertexshader", "../Assets/Shaders/texturedFragmentShader.Fragmentshader") 
							};
	shaderProgram = shaderPrograms;

	// Create Camera Object
	camera_ptr = new Camera(window);

	// Set View and Projection matrices on both shaders
	setUpProjection(shaderPrograms[0], camera_ptr);
	setUpCamera(camera_ptr, shaderPrograms[0]);

	setUpProjection(shaderPrograms[1], camera_ptr);
	setUpCamera(camera_ptr, shaderPrograms[1]);

	// Define and upload geometry to the GPU here ...
	Grid objGrid;
	Cube objCube;
	objCube.setModelMatrix();
	objGrid.setup();
	
	//Load Texture and VAO for Models
	Model1->create();
	Model2->create();
	Model3->create();
	Model4->create();
	Model5->create();

	


	// Entering Main Loop
	while (!glfwWindowShouldClose(window))
	{
		// Enable z-buffer
		glEnable(GL_DEPTH_TEST);

		// Each frame, reset color of each pixel to glClearColor
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		// Set up Perspective View
		setUpProjection(shaderPrograms[0], camera_ptr);
		setUpProjection(shaderPrograms[1], camera_ptr);

		// Render grid and axis and cube
		renderGridAxisCube(shaderProgram, shaderPrograms, objGrid);
		
		// Rotating Right
		//rotateRight(window, worldMatrixLocation);

		//// activating lighting shader
		glUseProgram(shaderProgram);
		glUniform3f(glGetUniformLocation(shaderProgram, "objectColor"), 1.0f, 0.5f, 0.31f);
		glUniform3f(glGetUniformLocation(shaderProgram, "lightColor"), 1.0f, 1.0f, 1.0f);
		glUniform3fv(glGetUniformLocation(shaderProgram, "lightPos"), 1, &lightSourcePosition[0]);
		glUniform3fv(glGetUniformLocation(shaderProgram, "viewPos"), 1, &camera_ptr->cameraPos[0]);


		// randomizer code from https://stackoverflow.com/questions/5289613/generate-random-float-between-two-floats/5289624
	

		// Draw AlphaNumeric models
<<<<<<< HEAD
		Model1->draw(shaderProgram, isTexture);
		Model2->draw(shaderProgram, isTexture);
		Model3->draw(shaderProgram, isTexture);
		Model4->draw(shaderProgram, isTexture);
		Model5->draw(shaderProgram, isTexture);
=======
		Model1->draw(worldMatrixLocation);
		Model2->draw(worldMatrixLocation);
		Model3->draw(worldMatrixLocation);
		Model4->draw(worldMatrixLocation);
		Model5->draw(worldMatrixLocation);
		//LightSource->draw(worldMatrixLocation); // reinstate once issue is figured out

		// Draw the lamp object
>>>>>>> added specular lighting

		// Important: setting worldmatrix back to normal so other stuff doesn't get scaled down
		shaderProgram->setMat4("worldMatrix", mat4(1.0f));

		// Model Render Mode
		renderMode(window);

		// Camera frame timing
		camera_ptr->handleFrameData();
    
		// Set up Camera
		setUpCamera(camera_ptr, shaderPrograms[0]);
		setUpCamera(camera_ptr, shaderPrograms[1]);

		// Transformations of Models

		// Translating left
		translateLeft(window, Model1, Model2, Model3, Model4, Model5);

		// Translating right
		translateRight(window, Model1, Model2, Model3, Model4, Model5);

		// Translating up
		translateUp(window, Model1, Model2, Model3, Model4, Model5);

		// Translating down
		translateDown(window, Model1, Model2, Model3, Model4, Model5);

		// Rotating Left
		rotateLeft(window, Model1, Model2, Model3, Model4, Model5);
		
		// Rotating Right
		rotateRight(window, Model1, Model2, Model3, Model4, Model5);

		// Scale Up
		scaleUp(window, Model1, Model2, Model3, Model4, Model5);

		// Scale Down
		scaleDown(window, Model1, Model2, Model3, Model4, Model5);

		// Change camera view to model view 
		// ** Currently, key needs to be held down because camera is set up in the while loop.
		cameraFocus(window, shaderProgram, camera_ptr, Model1, Model2, Model3, Model4,  Model5);
		cameraFocus(window, shaderProgram, camera_ptr, Model1, Model2, Model3, Model4, Model5);

		// End frame
		glfwSwapBuffers(window);

		// Detect inputs
		glfwPollEvents();

		// Handle inputs
		camera_ptr->handleKeyboardInputs();
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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(-4, -4, width + 4, height + 4); // changed values: supposed to fix pitfall but doesnt seem to work
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	/*if (key == GLFW_KEY_X && action == GLFW_PRESS)
	{
		if (isTexture)
			isTexture = false;
		else
			isTexture = true;
	}*/

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		// Get random x and z values
		float randomX = range * ((((float)rand()) / (float)RAND_MAX)) + MIN_RAND;
		float randomZ = range * ((((float)rand()) / (float)RAND_MAX)) + MIN_RAND;

		// Make sure it doesn't go past the grid
		mat4 m;
		switch (currentModel)
		{
		case 1: 
			m = Model1->getModelMatrix();
			break;
		case 2:
			m = Model2->getModelMatrix();
			break;
		case 3:
			m = Model3->getModelMatrix();
			break;
		case 4:
			m = Model4->getModelMatrix();
			break;
		case 5:
			m = Model5->getModelMatrix();
			break;
		}

		float currentX = m[3][0];
		float currentZ = m[3][2];

		if (currentX + randomX < -1.0f) { randomX = randomX + 0.5f; }
		else if (currentX + randomX > 1.0f) { randomX = randomX - 0.5f; }

		if (currentZ + randomZ < -1.0f) { randomZ = randomZ += 0.5f; }
		else if (currentZ + randomZ > 1.0f) { randomZ = randomZ - 0.5f; }

		// Move to "random" location
		// Currently relative of previous position (fix if time)
		switch (currentModel)
		{
		case 1:
			Model1->randomLocation(randomX, randomZ);
			break;
		case 2:
			Model2->randomLocation(randomX, randomZ);
			break;
		case 3:
			Model3->randomLocation(randomX, randomZ);
			break;
		case 4:
			Model4->randomLocation(randomX, randomZ);
			break;
		case 5:
			Model5->randomLocation(randomX, randomZ);
			break;
		}

		currentModel = -1; // set view back to origin to see new location
	}
}
/*
Toggle Textures on and off
*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_X && action == GLFW_PRESS)
	{
		if (isTexture) {
			isTexture = false;
			shaderProgram--;
		}
		else {
			isTexture = true;
			shaderProgram++;
		}
	}
}
