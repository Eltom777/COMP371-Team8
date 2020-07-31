#pragma once
#include "Light.h"
#include "Student.h"
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
	void setupLight(Shader* shaderProgram, Shader* shadowShader, Student* model);
	~Shadow();
	bool getIsSet(){ return isSet;}

	const unsigned int DEPTH_MAP_TEXTURE_SIZE = 1024;
};

