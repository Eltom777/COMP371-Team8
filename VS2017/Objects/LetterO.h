#pragma once
#include "AlphaNumeric.h"

class LetterO : public AlphaNumeric
{
	static const int NUMOFCUBES = 4;

	public:
		LetterO();
		~LetterO();
		void setup();
		void concatModelMatrix(mat4 mat);
		mat4 getModelMatrix();
		void draw(GLuint worldMatrixLocation);
	private:
		Cube components[NUMOFCUBES];
		mat4 modelMatrix;
};

