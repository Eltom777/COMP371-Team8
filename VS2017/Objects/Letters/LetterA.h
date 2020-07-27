#pragma once
#include "AlphaNumeric.h"

class LetterA : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

public:
	LetterA();
	~LetterA();
	void setup();
};

