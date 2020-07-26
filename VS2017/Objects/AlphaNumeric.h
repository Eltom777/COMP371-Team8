#pragma once
#include "Cube.h"
#include "Object.h"

class AlphaNumeric : public Object
{
public:
	AlphaNumeric(int numOfCubes, bool isLetter);
	mat4 getModelMatrix();
	void updateModelMatrix();
	void translateModel(mat4 t);
	void scaleModel(mat4 s);
	void rotateModel(mat4 r, GLuint modelMatrixLocation);
	void traverse(mat4 mat);
	void traverse(mat4 mat, Cube* current);
	void randomLocation(float x, float z);
	Cube* components;
	GLuint textureId;
	void draw(Shader* shaderProgram, const bool isTexture);
	GLuint cubeVAO;
	void create();

	Cube* components;
protected:
	mat4 modelMatrix = mat4(1.0f);
	mat4 translationMatrix = mat4(1.0f);
	mat4 scalingMatrix = mat4(1.0f);
	mat4 rotationMatrix = mat4(1.0f);
	int numberOfCubes;
	char* filename; //Texture location
	bool isLetter;
	Cube* components;
};