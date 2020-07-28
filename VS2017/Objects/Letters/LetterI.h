#pragma once
#include "AlphaNumeric.h"

class LetterI : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;
	static const int NUMOFTOPCUBES = 2;
	static const int NUMOFBOTCUBES = 2;

public:
	LetterI();
	~LetterI();
	void setup();
};

