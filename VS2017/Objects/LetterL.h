#pragma once
#include "AlphaNumeric.h"

class LetterL : public AlphaNumeric
{
	static const int NUMOFCUBES = 2;

public:
	LetterL();
	~LetterL();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);

private:
	Cube components[NUMOFCUBES];
	mat4 worldMatrix;
};

