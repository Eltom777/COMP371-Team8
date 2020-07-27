#pragma once
#include "AlphaNumeric.h"

class Number4 : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;
	static const int NUMOFTOPCUBES = 3;
	static const int NUMOFBOTCUBES = 1;

public:
	Number4();
	~Number4();
	void setup();
};

