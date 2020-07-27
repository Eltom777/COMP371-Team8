#pragma once
#include "AlphaNumeric.h"

class Number0 : public AlphaNumeric
{
	static const int NUMOFCUBES = 7;
	static const int NUMOFTOPCUBES = 4;
	static const int NUMOFBOTCUBES = 3;

public:
	Number0();
	~Number0();
	void setup();
};

