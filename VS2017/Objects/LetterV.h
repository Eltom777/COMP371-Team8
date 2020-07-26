#pragma once
#include "AlphaNumeric.h"

class LetterV : public AlphaNumeric
{
	static const int NUMOFCUBES = 5;

public:
	LetterV();
	~LetterV();
	void setup();
};