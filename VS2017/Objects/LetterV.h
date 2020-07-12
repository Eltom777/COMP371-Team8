#pragma once
#include "AlphaNumeric.h"

class LetterV : public AlphaNumeric
{
	static const int NUMOFCUBES = 5;

public:
	LetterV();
	~LetterV();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);

private:
	Cube components[NUMOFCUBES];
	mat4 worldMatrix;
};