#pragma once
#include <GL\glew.h>
#include <glm\gtc\matrix_transform.hpp>
#include "Light.h"
#include "Shader.h"
class Shadow
{
	const unsigned int DEPTH_MAP_TEXTURE_SIZE = 1024;
private:
	bool isSet = false;
public:
	Light light;
	Shadow();
	void setupBuffer();
	void setupLight(Shader* shaderProgram);
	~Shadow();
};

