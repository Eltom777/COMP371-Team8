#pragma once
#include "AlphaNumeric.h"

class Number4 : public AlphaNumeric
{
	static const int NUMOFCUBES = 3;

public:
	Number4();
	~Number4();
	void setup();
	void updateModelMatrix();
	void draw(GLuint modelMatrixLocation);
};

