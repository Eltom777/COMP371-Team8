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
#include <string>

#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler
#include <GLFW/glfw3.h> // GLFW provides a cross-platform interface for creating a graphical context,
						// initializing OpenGL and binding inputs

#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp>

#include <Grid.h> //rendered objects
#include <Camera.h>
#include <Thomas.h>
#include <Melina.h>
#include <Sharon.h>
#include <Anissa.h>
#include <Keven.h>
#include <Sphere.h>

using namespace std;

// Which model we are currently looking at (0, 1, 2, 3, 4), if -1, then we are not looking at any models
static int currentModel = -1;

// Textures not enabled yet
bool isTexture = false;
bool isLighting = true;

// Forward declaration of camera and shader program
Camera* camera_ptr;
int width, height;
Shader* shaderProgram;
Shader* shadowShader;

// Lighting
//glm::vec3 lightSourcePosition(0.0f, 1.5f, -3.0f); //   IF we want to get fancy with it, uncomment this
glm::vec3 lightSourcePosition(0.0f, 3.0f, -1.0f);
glm::vec3 lightFocus(0.0f, 0.0f, 0.0f);

glm::vec3 ambient(0.3f);
glm::vec3 diffuse(1.0f);
glm::vec3 specular(1.0f);


// Random location range
const float MIN_RAND = -0.5f, MAX_RAND = 0.5f;
const float range = MAX_RAND - MIN_RAND;

//Function interfaces for camera response to mouse input
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

void setUpProjection(Shader* shaderProgram, Camera* camera) {
	// Set up Perspective View
	glm::mat4 Projection = glm::perspective(glm::radians(camera->fov),  // field of view in degrees
		1024.0f / 768.0f,     // aspect ratio
		0.01f, 100.0f);      // near and far (near > 0)

	shaderProgram->setMat4("projectionMatrix", Projection);
}

void renderGridAxis(Shader* shaderProgram, Grid objGrid) {
	// Draw grid and axis
	objGrid.drawAxis(shaderProgram);
	objGrid.drawGrid(shaderProgram, isTexture, isLighting); // 3 vertices, starting at index 0
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
			//Model2->translateTop(glm::translate(mat4(1.0f), vec3(-0.005f, 0.0f, 0.0f)));
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
void rotateLeft(GLFWwindow* window) {
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

void rotateRight(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
	{
		switch (currentModel)
		{
		case 1:
			Model1->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
			break;
		case 2:
			Model2->rotate(glm::rotate(mat4(1.0f), glm::radians(0.5f), vec3(0.0f, 0.005f, 0.0f)));
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
void cameraFocus(GLFWwindow* window, Shader* shaderProgram, Camera* camera) {

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

void setUpCamera(Camera* camera, Shader* shaderProgram) {
	glm::mat4 viewMatrix = glm::lookAt(camera->cameraPos, // position
		camera->cameraDirection, // front -- camera.cameraPos + camera.cameraFront
		camera->cameraUp);  // up

	shaderProgram->setMat4("viewMatrix", viewMatrix);
}

/*
Main method.
*/
int main(int argc, char* argv[])
{
	// Initialize GLFW and OpenGL version
	initialize();

	// Create Window and rendering context using GLFW, resolution is 1024x768
	GLFWwindow* window = glfwCreateWindow(1024, 768, "COMP371 - Assignment 2 - Team 8", NULL, NULL);
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
	shaderProgram = new Shader("../Assets/Shaders/texturedVertexShader.vertexshader", "../Assets/Shaders/texturedFragmentShader.Fragmentshader");
	shadowShader = new Shader("../Assets/Shaders/shadow_vertex.glsl", "../Assets/Shaders/shadow_fragment.glsl");

	// Setup texture and framebuffer for creating shadow map

	  // Dimensions of the shadow texture, which should cover the viewport window
	  // size and shouldn't be oversized and waste resources
	  const unsigned int DEPTH_MAP_TEXTURE_SIZE = 1024;

	// Variable storing index to texture used for shadow mapping
	GLuint depth_map_texture;
	// Get the texture
	glGenTextures(1, &depth_map_texture);
	// Bind the texture so the next glTex calls affect it
	glBindTexture(GL_TEXTURE_2D, depth_map_texture);
	// Create the texture and specify it's attributes, including widthn height,
	// components (only depth is stored, no color information)
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, DEPTH_MAP_TEXTURE_SIZE,
				DEPTH_MAP_TEXTURE_SIZE, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	// Set texture sampler parameters.
	// The two calls below tell the texture sampler inside the shader how to
	// upsample and downsample the texture. Here we choose the nearest filtering
	// option, which means we just use the value of the closest pixel to the
	// chosen image coordinate.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// The two calls below tell the texture sampler inside the shader how it
	// should deal with texture coordinates outside of the [0, 1] range. Here we
	// decide to just tile the image.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// todo UNCOMMENT WHEN READY TO RENDER SHADOWS
	//// Variable storing index to framebuffer used for shadow mapping
	//GLuint depth_map_fbo;  // fbo: framebuffer object
	//// Get the framebuffer
	//glGenFramebuffers(1, &depth_map_fbo);
	//// Bind the framebuffer so the next glFramebuffer calls affect it
	//glBindFramebuffer(GL_FRAMEBUFFER, depth_map_fbo);
	//// Attach the depth map texture to the depth map framebuffer
	//// glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
	//// depth_map_texture, 0);
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D,
	//						depth_map_texture, 0);
	//glDrawBuffer(GL_NONE);  // disable rendering colors, only write depth values

	// Create Camera Object
	camera_ptr = new Camera(window);

	// Set View and Projection matrices on both shaders
	setUpProjection(shaderProgram, camera_ptr);

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

	//Setup lighting
	shaderProgram->setVec3("lightPos", lightSourcePosition);

	// Other OpenGL states to set once
  	// Enable Backface culling
  	//glEnable(GL_DEPTH_TEST);
  	//glEnable(GL_CULL_FACE);
	  
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
		//setUpProjection(shaderPrograms[1], camera_ptr);

		// Light parameters for shadow rendering
		vec3 lightDirection = normalize(lightFocus - lightSourcePosition);

		// Render grid and axis
		renderGridAxis(shaderProgram, objGrid);

		float lightNearPlane = 0.01f;
		float lightFarPlane = 100.0f;

		mat4 lightProjMatrix = //frustum(-1.0f, 1.0f, -1.0f, 1.0f, lightNearPlane, lightFarPlane);
			perspective(50.0f, (float)DEPTH_MAP_TEXTURE_SIZE / (float)DEPTH_MAP_TEXTURE_SIZE, lightNearPlane, lightFarPlane);
		mat4 lightViewMatrix = lookAt(lightSourcePosition, lightFocus, vec3(0, 1, 0));
		mat4 lightSpaceMatrix = lightProjMatrix * lightViewMatrix;

		// 
		SetUniformMat4(shaderScene, "light_proj_view_matrix", lightProjMatrix * lightViewMatrix);
		SetUniform1Value(shaderScene, "light_near_plane", lightNearPlane);
		SetUniform1Value(shaderScene, "light_far_plane", lightFarPlane);
		SetUniformVec3(shaderScene, "light_position", lightSourcePosition);
		SetUniformVec3(shaderScene, "light_direction", lightDirection);



		// Draw AlphaNumeric models
		Model1->draw(shaderProgram, isTexture);
		Model2->draw(shaderProgram, isTexture);
		Model3->draw(shaderProgram, isTexture);
		Model4->draw(shaderProgram, isTexture);
		Model5->draw(shaderProgram, isTexture);

		// Important: setting worldmatrix back to normal so other stuff doesn't get scaled down
		shaderProgram->setMat4("worldMatrix", mat4(1.0f));
		shaderProgram->setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
		shaderProgram->setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
		shaderProgram->setVec3("lightPos", lightSourcePosition);
		shaderProgram->setVec3("viewPos", camera_ptr->cameraPos);

		// Model Render Mode
		renderMode(window);

		// Camera frame timing
		camera_ptr->handleFrameData();

		//refresh specular
		shaderProgram->setVec3("viewPos", camera_ptr->cameraPos);

		// Set up Camera
		if (currentModel == -1) {
			setUpCamera(camera_ptr, shaderProgram);
			//setUpCamera(camera_ptr, shaderPrograms[1]);
		}

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
		rotateLeft(window);

		// Rotating Right
		rotateRight(window);
		
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
	glViewport(-4, -4, width + 4, height + 4); // changed values: supposed to fix pitfall but doesnt seem to work
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_X && action == GLFW_PRESS)
	{
		if (isTexture) {
			isTexture = false;
		}
		else {
			isTexture = true;
		}
	}

	if (key == GLFW_KEY_B && action == GLFW_PRESS)
	{
		if (isLighting) {
			isLighting = false;
		}
		else {
			isLighting = true;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		// randomizer code from https://stackoverflow.com/questions/5289613/generate-random-float-between-two-floats/5289624
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
