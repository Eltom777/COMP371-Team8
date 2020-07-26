#pragma once
#include "AlphaNumeric.h"
#include "Sphere.h"

class Student
{
public:
	void updateModelMatrix();
	mat4 getModelMatrix();
	void translate(mat4 t);
	void scale(mat4 s);
	void rotate(mat4 r);
	void draw(Shader* shaderProgram, const bool isTexture);
	void create();

	void randomLocation(float x, float z);

protected:
	AlphaNumeric* components[2] = { letter, number };
	AlphaNumeric* letter;
	AlphaNumeric* number;
	Sphere* sphere;
	mat4 modelMatrix = mat4(1.0f);
};