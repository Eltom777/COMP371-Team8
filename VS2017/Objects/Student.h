#pragma once
#include "AlphaNumeric.h"
#include "Sphere.h"
#include "Shadow.h"


class Student
{
public:
	void updateModelMatrix();
	mat4 getModelMatrix();
	void translate(mat4 t);
	void translateTop(mat4 t);
	void scale(mat4 s);
	//void rotate(mat4 r, GLuint modelMatrixLocation);
	void rotate(mat4 r);
	//void draw(GLuint modelMatrixLocation, int sphereVertices, int cubeVAO, int sphereVAO);
	void draw(Shader* shaderProgram, Shader* shaderShadow, const bool isTexture, const bool isShadow, Shadow* shadowPtr, GLFWwindow* window);

	void randomLocation(float x, float z);

	void create();

protected:
	AlphaNumeric* components[2] = { letter, number };
	AlphaNumeric* letter;
	AlphaNumeric* number;
	Sphere* sphere = new Sphere();
	mat4 modelMatrix = mat4(1.0f);
};