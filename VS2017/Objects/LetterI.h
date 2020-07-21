#pragma once
#include "AlphaNumeric.h"

class LetterI : public AlphaNumeric
{
	static const int NUMOFCUBES = 3;

public:
	LetterI();
	~LetterI();
	void setup();
	void updateModelMatrix();
	void draw(GLuint worldMatrixLocation);
	//int getVAO();

private:
	Cube components[NUMOFCUBES];
};

