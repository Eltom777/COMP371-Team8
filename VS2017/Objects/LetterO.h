#pragma once
#include "Cube.h"

static const int NUMOFCUBES = 1;

class LetterO
{
	public:
		LetterO();
		~LetterO();
		void setup();
		void concatWorldMatrix(mat4 mat);
		mat4 getWorldMatrix();
		void drawLetter(GLuint worldMatrixLocation);
	private:
		Cube components[NUMOFCUBES];
		mat4 worldMatrix;
};

