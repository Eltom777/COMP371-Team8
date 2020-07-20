#pragma once
#include "AlphaNumeric.h"

class Number0 : public AlphaNumeric
{
	static const int NUMOFCUBES = 5;

public:
	Number0();
	~Number0();
	void setup();
	void concatModelMatrix(mat4 mat);
	mat4 getModelMatrix();
	void draw(GLuint modelMatrixLocation);
private:
	Cube components[NUMOFCUBES];
	mat4 modelMatrix;
};

