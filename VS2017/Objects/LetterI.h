#pragma once
#include "AlphaNumeric.h"

class  LetterI : public AlphaNumeric
{
	static const int NUMOFCUBES = 3;

	public:
		LetterI();
		~LetterI();

		void setup();
		void concatModelMatrix(mat4 mat);
		mat4 getModelMatrix();
		void draw(GLuint worldMatrixLocation);

	private:
		Cube components[NUMOFCUBES];
		mat4 modelMatrix;
};