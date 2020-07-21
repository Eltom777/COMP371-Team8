#pragma once
#include "AlphaNumeric.h"

class LetterL : public AlphaNumeric
{
	static const int NUMOFCUBES = 2;

public:
	LetterL();
	~LetterL();
	void setup();
	void updateModelMatrix();
	void draw(GLuint worldMatrixLocation);
	//int getVAO();

private:
	Cube components[NUMOFCUBES];
};

