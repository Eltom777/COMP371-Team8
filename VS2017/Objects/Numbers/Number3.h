#pragma once
#include "AlphaNumeric.h"

class Number3 : public AlphaNumeric
{
	static const int NUMOFCUBES = 6;
	static const int NUMOFTOPCUBES = 3;
	static const int NUMOFBOTCUBES = 3;

public:
	Number3();
	~Number3();
	void setup();
};

