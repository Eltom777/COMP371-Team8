#include "AlphaNumeric.h"
#include <iostream>

mat4 AlphaNumeric::getModelMatrix() {
	return modelMatrix;
}

AlphaNumeric::AlphaNumeric(int numOfCubes, bool isLetter) {
	numberOfCubes = numOfCubes;
	components = new Cube[numberOfCubes];
	this->isLetter = isLetter;
	if (isLetter) {
		filename = "../Assets/Textures/Wood.jpg";
	}
	else {
		filename = "../Assets/Textures/Metal.jpg";
	}
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


void AlphaNumeric::create() {
	cubeVAO = components[0].createCubeVAO();
	textureId = loadTexture(filename);
}

void AlphaNumeric::draw(Shader* shaderProgram, const bool isTexture) {
	
	shaderProgram->use();
	
	if (isTexture) {
		if (isLetter) {
			glActiveTexture(GL_TEXTURE1);
		}
		else {
			glActiveTexture(GL_TEXTURE2);
		}
		//bind texture
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureId);
		//glUniform1i(shaderProgram->getLocation("textureSampler"), 0);
	}

	//bind vao
	glBindVertexArray(cubeVAO);

	for (int i = 0; i < numberOfCubes; i++) {
		shaderProgram->setMat4("worldMatrix", components[i].getModelMatrix());
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

void AlphaNumeric::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (int i = 0; i < numberOfCubes; i++) {
		//components[i].setModelMatrix(modelMatrix);
	}
}


AlphaNumeric::~AlphaNumeric() {
	delete[] components;
}
