#pragma once
#include "AlphaNumeric.h"

class LetterO : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

public:
	LetterO();
	~LetterO();
	void setup();
	void updateModelMatrix();
};