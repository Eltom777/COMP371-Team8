#pragma once
#include "AlphaNumeric.h"

static const int NUMOFCUBESL = 2;

class LetterL : public AlphaNumeric
{
public:
	LetterL();
	~LetterL();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);

private:
	Cube components[NUMOFCUBESL];
	mat4 worldMatrix;
};

