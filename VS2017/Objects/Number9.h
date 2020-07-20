#pragma once
#include "AlphaNumeric.h"

class Number9 : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

public:
	Number9();
	~Number9();
	void setup();
	void concatModelMatrix(mat4 mat);
	mat4 getModelMatrix();
	void draw(GLuint modelMatrixLocation);

private:
	Cube components[NUMOFCUBES];
	mat4 modelMatrix;
};

