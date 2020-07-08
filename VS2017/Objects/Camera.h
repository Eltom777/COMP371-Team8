#pragma once
#include <glm/glm.hpp>
#include <GLFW/glfw3.h> 

class Camera
{
public:
	Camera(GLFWwindow* window);
	
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 cameraX;

	float dt;

	float pan;
	float tilt;
	float fov;

	float lastX;
	float lastY;

	float lastFrameTime;

	float cameraSpeed;
	const float cameraPanSpeed = 1.0f;
	const float mouseSensitivity = 0.1f;

	void handleFrameData();
	void handleKeyboardInputs();
	
	void mouseCallbackHandler(GLFWwindow* window, double xpos, double ypos);
	void mouseScrollHandler(GLFWwindow* window, double xOffset, double yOffset);
private:
	GLFWwindow* window;

	
};