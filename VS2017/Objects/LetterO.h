#pragma once
#include "AlphaNumeric.h"

static const int NUMOFCUBES = 4;

class LetterO : public AlphaNumeric
{
	public:
		LetterO();
		~LetterO();
		void setup();
		void concatWorldMatrix(mat4 mat);
		mat4 getWorldMatrix();
		void draw(GLuint worldMatrixLocation);
	private:
		Cube components[NUMOFCUBES];
		mat4 worldMatrix;
};

