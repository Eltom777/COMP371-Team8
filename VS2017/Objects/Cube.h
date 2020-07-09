#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Grid.h"
using namespace glm;


class Cube
{
public:
	Cube();
	~Cube();
	mat4 getWorldMatrix();
	void setWorldMatrix(mat4 matrix);
	void concatWorldMatrix(mat4 tmatrix);
	int createCubeVAO();

private:
	static const glm::vec3 vertices[];
	mat4 worldMatrix;
	Grid scaleFactor;
};

