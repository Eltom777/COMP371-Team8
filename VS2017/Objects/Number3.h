#pragma once
#include "AlphaNumeric.h"

class Number3
{
	static const int NUMOFCUBES = 4;

	public:
		Number3();
		~Number3();
		void setup();
		void concatWorldMatrix(mat4 mat);
		mat4 getWorldMatrix();
		void draw(GLuint worldMatrixLocation);
	private:
		Cube components[NUMOFCUBES];
		mat4 worldMatrix;
};

