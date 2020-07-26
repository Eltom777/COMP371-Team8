#pragma once
#include "AlphaNumeric.h"

class Student
{
public:
	void updateModelMatrix();
	mat4 getModelMatrix();
	void translate(mat4 t);
	void scale(mat4 s);
	void rotate(mat4 r);
	void draw(Shader* shaderProgram, const bool isTexture);
	void create();

protected:
	AlphaNumeric* components[2] = { Letter, Number };
	AlphaNumeric* Letter;
	AlphaNumeric* Number;
	mat4 modelMatrix = mat4(1.0f);
};