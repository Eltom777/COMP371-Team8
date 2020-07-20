#pragma once
#include "AlphaNumeric.h"

class Number4 : public AlphaNumeric
{
	static const int NUMOFCUBES = 3;

public:
	Number4();
	~Number4();
	void setup();
	void concatModelMatrix(mat4 mat);
	mat4 getModelMatrix();
	void draw(GLuint modelMatrixLocation);

private:
	Cube components[NUMOFCUBES];
	mat4 modelMatrix;
};

