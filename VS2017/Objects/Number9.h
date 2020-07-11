#pragma once
#include "AlphaNumeric.h"

class Number9 : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

public:
	Number9();
	~Number9();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);

private:
	Cube components[NUMOFCUBES];
	mat4 worldMatrix;
};

