#pragma once
#include "AlphaNumeric.h"

class LetterA : public AlphaNumeric
{
	static const int NUMOFCUBES = 6;
	static const int NUMOFTOPCUBES = 4;
	static const int NUMOFBOTCUBES = 2;

public:
	LetterA();
	~LetterA();
	void setup();
	void updateModelMatrix();
};

