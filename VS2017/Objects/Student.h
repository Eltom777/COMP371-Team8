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
	//void rotate(mat4 r, GLuint modelMatrixLocation);
	void rotate(mat4 r);
	void draw(GLuint modelMatrixLocation, int sphereVertices, int cubeVAO, int sphereVAO);

protected:
	AlphaNumeric* components[2] = { letter, number };
	AlphaNumeric* letter;
	AlphaNumeric* number;
	Sphere* sphere = new Sphere();
	mat4 modelMatrix = mat4(1.0f);
};