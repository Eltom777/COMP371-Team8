#pragma once
#include "AlphaNumeric.h"

static const int NUMOFCUBES9 = 4;

class Number9 : public AlphaNumeric
{
public:
	Number9();
	~Number9();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);

private:
	Cube components[NUMOFCUBES9];
	mat4 worldMatrix;
};

