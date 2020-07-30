#pragma once
#include <GL\glew.h>
#include <glm\gtc\matrix_transform.hpp>
#include "Light.h"
#include "Shader.h"
class Shadow
{
	
private:
	bool isSet = false;
public:
	Light light;
	GLuint depth_map_fbo;
	GLuint depth_map_texture;
	Shadow();
	void setupBuffer();
	void setupLight(Shader* shaderProgram, Shader* shadowShader);
	~Shadow();
	bool getIsSet(){ return isSet;}

	const unsigned int DEPTH_MAP_TEXTURE_SIZE = 1024;
};

