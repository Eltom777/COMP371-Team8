#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "Grid.h"

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

