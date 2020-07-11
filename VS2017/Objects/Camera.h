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

	float lastX;
	float lastY;

	float angle;
	float lastFrameTime;

	float cameraSpeed;
	const float cameraPanSpeed = 1.0f;

	void handleFrameData();
	void handleKeyboardInputs();
private:
	GLFWwindow* window;
};