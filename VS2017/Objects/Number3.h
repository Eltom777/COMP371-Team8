#pragma once
#include "AlphaNumeric.h"

class Number3 : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

	public:
		Number3();
		~Number3();
		void updateModelMatrix();
		void setup();
		void draw(GLuint modelMatrixLocation);
	private:
		Cube components[NUMOFCUBES];
};

