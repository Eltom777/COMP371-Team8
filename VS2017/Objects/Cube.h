#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "Grid.h"

class Cube
{
public:
	Cube();
	~Cube();
	mat4 getModelMatrix();
	void setModelMatrix();
	int createCubeVAO();
	void updateScale(mat4 s);
	void updateRotation(mat4 r);
	void updateTranslation(mat4 t);

private:
	static const glm::vec3 vertices[];
	mat4 modelMatrix;
	mat4 worldMatrix;
	mat4 rotationMatrix;
	mat4 translationMatrix;
	mat4 scalingMatrix;
	Grid gridPointer;
	float scalingFactor = 1.0f / static_cast <float>(gridPointer.getNumberOfColumns());;
};

