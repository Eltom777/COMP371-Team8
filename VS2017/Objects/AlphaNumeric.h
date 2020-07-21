#pragma once
#include "Cube.h"

class AlphaNumeric
{
public:
	mat4 getModelMatrix();
	virtual void updateModelMatrix() = 0;
	void translate(mat4 mat);
	void scale(mat4 mat);
	void rotate(mat4 mat);
	virtual void draw(GLuint modelMatrixLocation) = 0;

protected:
	mat4 modelMatrix = mat4(1.0f);
	mat4 translationMatrix = mat4(1.0f);
	mat4 scalingMatrix = mat4(1.0f);
	mat4 rotationMatrix = mat4(1.0f);
};