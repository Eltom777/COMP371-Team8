#include "Camera.h"

Camera::Camera(GLFWwindow* window)
{
	this->window = window;
	
	this->cameraPos = glm::vec3(0.0f, 0.5f, 3.0f);
	this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	this->cameraX = glm::vec3(1.0f, 0.0f, 0.0f);
	
	this->pan = -90.0f;
	this->tilt = 0.0f;

	this->lastX = 400.0f;
	this->lastY = 300.0f;
	
	this->angle = 0;
	this->lastFrameTime = glfwGetTime();
}

void Camera::handleFrameData()
{
	this->dt = glfwGetTime() - this->lastFrameTime;
	this->lastFrameTime += this->dt;
	this->cameraSpeed = 2.5f * this->dt;
}

void Camera::handleKeyboardInputs()
{
	// Close the window
	if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(this->window, true);
	
	// Home button
	if (glfwGetKey(this->window, GLFW_KEY_0) == GLFW_PRESS)
	{
		this->cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	}

	// forward, backward, left and right
	if (glfwGetKey(this->window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		this->cameraPos += this->cameraSpeed * this->cameraFront;
	}

	if (glfwGetKey(this->window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		this->cameraPos -= this->cameraSpeed * this->cameraFront;
	}

	if (glfwGetKey(this->window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		this->cameraPos -= glm::normalize(glm::cross(this->cameraFront, this->cameraUp)) * this->cameraSpeed;
	}

	if (glfwGetKey(this->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		this->cameraPos += glm::normalize(glm::cross(this->cameraFront, this->cameraUp)) * this->cameraSpeed;
	}


	// Up and down
	if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS)
	{
		this->cameraPos -= glm::normalize(glm::cross(this->cameraFront, this->cameraX)) * this->cameraSpeed;
	}

	if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS)
	{
		this->cameraPos += glm::normalize(glm::cross(this->cameraFront, this->cameraX)) * this->cameraSpeed;
	}

	// 5 degrees left and right
	if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS)
	{
		this->pan -= this->cameraPanSpeed;
		glm::vec3 front;
		front.x = cos(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		front.y = sin(glm::radians(this->tilt));
		front.z = sin(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		this->cameraFront = glm::normalize(front);
	}

	if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS)
	{
		this->pan += this->cameraPanSpeed;
		glm::vec3 front;
		front.x = cos(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		front.y = sin(glm::radians(this->tilt));
		front.z = sin(glm::radians(this->pan)) * cos(glm::radians(this->tilt));
		this->cameraFront = glm::normalize(front);
	}
}


