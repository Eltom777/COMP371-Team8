#pragma once
#include "AlphaNumeric.h"

class Number0 : public AlphaNumeric
{
	static const int NUMOFCUBES = 5;

public:
	Number0();
	~Number0();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);
private:
	Cube components[NUMOFCUBES];
	mat4 worldMatrix;
};

