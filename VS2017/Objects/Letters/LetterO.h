#pragma once
#include "AlphaNumeric.h"

class LetterO : public AlphaNumeric
{
	static const int NUMOFCUBES = 6;
	static const int NUMOFTOPCUBES = 3;
	static const int NUMOFBOTCUBES = 3;

public:
	LetterO();
	~LetterO();
	void setup();
};