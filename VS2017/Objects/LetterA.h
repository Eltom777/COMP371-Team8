#pragma once
#include "AlphaNumeric.h"

class LetterA : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

public:
	LetterA();
	~LetterA();
	void setup();
	void updateModelMatrix();
	void draw(GLuint worldMatrixLocation);
	//int getVAO();

private:
	Cube components[NUMOFCUBES];
};

