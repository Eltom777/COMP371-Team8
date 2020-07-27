#pragma once
#include "AlphaNumeric.h"

class LetterV : public AlphaNumeric
{
	static const int NUMOFCUBES = 7;
	static const int NUMOFTOPCUBES = 4;
	static const int NUMOFBOTCUBES = 3;

public:
	LetterV();
	~LetterV();
	void setup();
};