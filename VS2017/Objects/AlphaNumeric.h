#pragma once
#include "Cube.h"
#include "Object.h"

class AlphaNumeric : public Object
{
public:
	AlphaNumeric(int numOfCubes, bool isLetter);
	AlphaNumeric(int numOfTopCubes, int numOfBotCubes);
	~AlphaNumeric();
	mat4 getModelMatrix();
	void updateBase(Cube * b);
	Cube * getBase();
	void updateBaseTop(Cube * b);
	Cube * getBaseTop();
	void traverse(mat4 mat, int transformation);
	void traverse(mat4 mat, Cube* current, int transformation); // 0 - TRANSLATION | 1 - ROTATION | 2 - SCALING
	void updateModelMatrix();
	void translateModel(mat4 t);
	void translateModelTop(mat4 t);

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
	//void drawTop(GLuint modelMatrixLocation);
	//void drawBottom(GLuint modelMatrixLocation);

	
	Cube* components;
	Cube* topComponents;
	Cube* bottomComponents;
	Cube* base;
	Cube* baseTop;
protected:
	mat4 modelMatrix = mat4(1.0f);
	mat4 translationMatrix = mat4(1.0f);
	mat4 scalingMatrix = mat4(1.0f);
	mat4 rotationMatrix = mat4(1.0f);
	int numberOfCubes;
	char* filename; //Texture location
	bool isLetter;
	Cube* components;
	int numberOfTopCubes;
	int numberOfBotCubes;
};