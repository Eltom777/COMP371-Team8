#pragma once
#include "AlphaNumeric.h"

class LetterO : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

public:
	LetterO();
	~LetterO();
	void updateModelMatrix();
	void setup();
	void draw(GLuint worldMatrixLocation);
	//int getVAO();

private:
	Cube components[NUMOFCUBES];
};