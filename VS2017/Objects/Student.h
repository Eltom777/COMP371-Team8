#pragma once
#include "AlphaNumeric.h"

class Student
{
public:
	void updateModelMatrix();
	void translate(mat4 mat);
	void scale(mat4 mat);
	void rotate(mat4 mat);

protected:
	AlphaNumeric* components[2] = { Letter, Number };
	AlphaNumeric* Letter;
	AlphaNumeric* Number;
};