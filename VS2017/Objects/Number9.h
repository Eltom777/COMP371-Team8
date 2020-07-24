#pragma once
#include "AlphaNumeric.h"

class Number9 : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

public:
	Number9();
	~Number9();
	void setup();
	void updateModelMatrix();

};

