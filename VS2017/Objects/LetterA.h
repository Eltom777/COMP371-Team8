#pragma once
#include "AlphaNumeric.h"

class LetterA : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

public:
	LetterA();
	~LetterA();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);
private:
	Cube components[NUMOFCUBES];
	mat4 worldMatrix;
};
