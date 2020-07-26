#pragma once
#include "AlphaNumeric.h"

class Number0 : public AlphaNumeric
{
	static const int NUMOFCUBES = 5;

public:
	Number0();
	~Number0();
	void setup();
	void updateModelMatrix();
};

