#pragma once
#include "AlphaNumeric.h"

class LetterV : public AlphaNumeric
{
	static const int NUMOFCUBES = 5;

public:
	LetterV();
	~LetterV();
	void setup();
	void concatModelMatrix(mat4 mat);
	mat4 getModelMatrix();
	void draw(GLuint modelMatrixLocation);

private:
	Cube components[NUMOFCUBES];
	mat4 modelMatrix;
};