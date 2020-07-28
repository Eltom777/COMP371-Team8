#include "AlphaNumeric.h"
#include <iostream>

mat4 AlphaNumeric::getModelMatrix() {
	return modelMatrix;
}

AlphaNumeric::AlphaNumeric(int numOfCubes) {
	numberOfCubes = numOfCubes;
	components = new Cube[numberOfCubes];
}

AlphaNumeric::AlphaNumeric(int numOfTopCubes, int numOfBotCubes) {
	numberOfTopCubes = numOfTopCubes;
	numberOfBotCubes = numOfBotCubes;
	topComponents = new Cube[numberOfTopCubes];
	bottomComponents = new Cube[numberOfBotCubes];
	base = NULL;
}

void AlphaNumeric::updateBase(Cube* b)
{
	this->base = b;
}

Cube* AlphaNumeric::getBase()
{
	return this->base;
}

void AlphaNumeric::updateBaseTop(Cube * b)
{
	this->baseTop = b;
}

Cube * AlphaNumeric::getBaseTop()
{
	return this->baseTop;
}

void AlphaNumeric::traverse(mat4 mat, int transformation)
{
	traverse(mat, getBase(), transformation);
}

void AlphaNumeric::traverse(mat4 mat, Cube* current, int transformation)
{
	if (current == NULL)
	{
		std::cout << "returning";
		return;
	}

	// do whatever you wanna do here before moving on to next child
	if (transformation == 0)
	{
		current->updateTranslation(mat);
	}
	if (transformation == 1)
	{
		current->updateRotation(mat);
	}
	if (transformation == 2)
	{
		current->updateScale(mat);
	}

	// move to next child
	if (current->getChild())
	{
		traverse(mat, current->getChild(), transformation);
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

	//modelMatrix = r * modelMatrix;
	//translateModel(r);

	//Place back to original spot
	tempworldMatrix = translate(mat4(1.0), translationComponent);
	translateModel(tempworldMatrix);
}

void AlphaNumeric::translateModel(mat4 t)
{
	modelMatrix = t * modelMatrix;
	
	for (int i = 0; i < numberOfTopCubes; i++) {
		topComponents[i].updateTranslation(t);
	}
	for (int i = 0; i < numberOfBotCubes; i++) {
		bottomComponents[i].updateTranslation(t);
	}
}

void AlphaNumeric::translateModelTop(mat4 t)
{
	modelMatrix = t * modelMatrix;

	for (int i = 0; i < numberOfTopCubes; i++) {
		topComponents[i].updateTranslation(t);
	}
}

void AlphaNumeric::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
}

//void AlphaNumeric::draw(GLuint modelMatrixLocation) {
//	for (int i = 0; i < numberOfCubes; i++) {
//		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting modelmatrix of each cube
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//	}
//}

void AlphaNumeric::drawTop(GLuint modelMatrixLocation) {
	for (int i = 0; i < numberOfTopCubes; i++) {
		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &topComponents[i].getModelMatrix()[0][0]); //setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

void AlphaNumeric::drawBottom(GLuint modelMatrixLocation) {
	for (int i = 0; i < numberOfBotCubes; i++) {
		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &bottomComponents[i].getModelMatrix()[0][0]); //setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

void AlphaNumeric::randomLocation(float x, float z)
{
	mat4 t = glm::translate(mat4(1.0), glm::vec3(x, 0.0f, z));
	modelMatrix = t * modelMatrix;

	for (int i = 0; i < numberOfCubes; i++) {
		components[i].updateTranslation(t);
	}

}

AlphaNumeric::~AlphaNumeric() {
	//delete[] components;
	delete[] topComponents;
	delete[] bottomComponents;
}
