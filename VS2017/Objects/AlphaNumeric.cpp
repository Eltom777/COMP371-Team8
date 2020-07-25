#include "AlphaNumeric.h"
#include <iostream>

mat4 AlphaNumeric::getModelMatrix() {
	return modelMatrix;
}

AlphaNumeric::AlphaNumeric(int numOfCubes) {
	numberOfCubes = numOfCubes;
	components = new Cube[numberOfCubes];
}

void AlphaNumeric::translateModel(mat4 t)
{
	modelMatrix = t * modelMatrix;
	for (int i = 0; i < numberOfCubes; i++) {
		components[i].updateTranslation(t);
	}
}

void AlphaNumeric::scaleModel(mat4 s)
{
	//Place back to origin
	vec3 translationComponent = vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);
	mat4 tempworldMatrix = translate(mat4(1.0), translationComponent * -1.0f); //place back to origin
	translateModel(tempworldMatrix);

	modelMatrix = s * modelMatrix;
	translateModel(s);

	//Place back to original spot
	tempworldMatrix = translate(mat4(1.0), translationComponent);
	translateModel(tempworldMatrix);
}

void AlphaNumeric::rotateModel(mat4 r, GLuint worldMatrixLocation)
{
	////Place back to origin
	vec3 translationComponent = vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);
	mat4 tempworldMatrix = translate(mat4(1.0), translationComponent * -1.0f); //place back to origin
	translateModel(tempworldMatrix);

	modelMatrix = r * modelMatrix;
	translateModel(r);

	//TESTING
	traverse(r);

	//Place back to original spot
	tempworldMatrix = translate(mat4(1.0), translationComponent);
	translateModel(tempworldMatrix);
}

void AlphaNumeric::traverse(mat4 mat)
{
	traverse(mat, &components[0]); //always make 0 your first parent
}

void AlphaNumeric::traverse(mat4 mat, Cube* current)
{
	if (current == NULL)
	{
		std::cout << "returning";
		return;
	}

	// do whatever you wanna do here before moving on to next child

	if (current->getChild())
	{
		traverse(mat, current->getChild());
	}
}

AlphaNumeric::~AlphaNumeric() {
	delete[] components;
}
