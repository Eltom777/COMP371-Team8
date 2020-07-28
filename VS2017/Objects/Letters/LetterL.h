#pragma once
#include "AlphaNumeric.h"

class LetterL : public AlphaNumeric
{
	//static const int NUMOFCUBES = 3;
	static const int NUMOFTOPCUBES = 1;
	static const int NUMOFBOTCUBES = 2;

public:
	LetterL();
	~LetterL();
	void setup();
};
