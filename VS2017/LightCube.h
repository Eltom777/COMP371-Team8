#pragma once
#include "AlphaNumeric.h"

class LightCube : public AlphaNumeric
{
	static const int NUMOFCUBES = 1;

public:
	LightCube();
	~LightCube();
	void setup();
	void updateModelMatrix();
	void draw(GLuint worldMatrixLocation);
};

