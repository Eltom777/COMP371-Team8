#pragma once
#include "AlphaNumeric.h"

class Number4 : public AlphaNumeric
{
	static const int NUMOFCUBES = 3;

public:
	Number4();
	~Number4();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);

private:
	Cube components[NUMOFCUBES];
	mat4 worldMatrix;
};

