#pragma once
#include "AlphaNumeric.h"

class Student
{
public:
	void updateModelMatrix();
	mat4 getModelMatrix();
	void translate(mat4 mat);
	void scale(mat4 mat);
	void rotate(mat4 mat);

protected:
	AlphaNumeric* components[2] = { Letter, Number };
	AlphaNumeric* Letter;
	AlphaNumeric* Number;
	mat4 modelMatrix = mat4(1.0f);
};