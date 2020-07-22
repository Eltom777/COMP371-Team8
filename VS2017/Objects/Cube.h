#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "Grid.h"

class Cube
{
public:
	Cube();
	~Cube();
	mat4 getModelMatrix();
	void setModelMatrix(mat4 matrix);
	void concatModelMatrix(mat4 tmatrix);
	int createCubeVAO();

private:
	static const glm::vec3 vertices[];
	mat4 modelMatrix;
	mat4 worldMatrix;
	mat4 rotationMatrix;
	mat4 translationMatrix;
	mat4 scalingMatrix;
	Grid scaleFactor;
};

