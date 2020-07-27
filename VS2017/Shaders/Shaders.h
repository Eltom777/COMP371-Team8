#pragma once
#include <iostream>

#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler
#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp>

class Shaders {
public:
	Shaders() {};
	~Shaders() {};
	const char* getVertexShaderSource();
	const char* getFragmentShaderSource();
	int compileAndLinkShaders();
};