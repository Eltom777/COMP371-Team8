#pragma once
#include "AlphaNumeric.h"

class Number9 : public AlphaNumeric
{
	//static const int NUMOFCUBES = 5;
	static const int NUMOFTOPCUBES = 3;
	static const int NUMOFBOTCUBES = 2;

public:
	Number9();
	~Number9();
	void setup();
};

