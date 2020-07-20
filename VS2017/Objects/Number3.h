#pragma once
#include "AlphaNumeric.h"

class Number3
{
	static const int NUMOFCUBES = 4;

	public:
		Number3();
		~Number3();
		void setup();
		void concatModelMatrix(mat4 mat);
		mat4 getModelMatrix();
		void draw(GLuint modelMatrixLocation);
	private:
		Cube components[NUMOFCUBES];
		mat4 modelMatrix;
};

