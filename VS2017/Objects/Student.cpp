#include "Student.h"

void Student::updateModelMatrix() {
	for (AlphaNumeric* component : components) {
		component->updateModelMatrix();
	}
}

mat4 Student::getModelMatrix()
{
	return modelMatrix;
}

void Student::translate(mat4 t) {
	modelMatrix = t * modelMatrix;
	for (AlphaNumeric* component : components) {
		component->translateModel(t);
	}
}

void Student::scale(mat4 s) {

	modelMatrix = s * modelMatrix;

	//Place back to origin
	vec3 translationComponent = vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);
	mat4 tempworldMatrix = glm::translate(mat4(1.0), translationComponent * -1.0f); //place back to origin
	for (AlphaNumeric* component : components) {
		component->translateModel(tempworldMatrix);
	}
	
	//modelMatrix = s * modelMatrix;
	for (AlphaNumeric* component : components) {
		component->translateModel(s);
	}

	//Place back to original spot
	tempworldMatrix = glm::translate(mat4(1.0), translationComponent);
	for (AlphaNumeric* component : components) {
		component->translateModel(tempworldMatrix);
	}
}

// NOTE TO SELF (Melina): remove all worldMatrixLocations params after finished testing :|
void Student::rotate(mat4 r) {
	
	//TESTING
	//components[1]->rotateModel(r, worldMatrixLocation);
	////components[1]->rotateModel(r, worldMatrixLocation);

	//modelMatrix = r * modelMatrix;


	//Place back to origin
	vec3 translationComponent = vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);
	mat4 tempworldMatrix = glm::translate(mat4(1.0), translationComponent * -1.0f); //place back to origin
	for (AlphaNumeric* component : components) {
		component->translateModel(tempworldMatrix);
	}

	for (AlphaNumeric* component : components) {
		component->translateModel(r);
	}

	modelMatrix = r * modelMatrix;

	//Place back to original spot
	tempworldMatrix = glm::translate(mat4(1.0), translationComponent);
	for (AlphaNumeric* component : components) {
		component->translateModel(tempworldMatrix);
	}
}


void Student::draw(Shader* shaderProgram, const bool isTexture) {
	components[0]->draw(shaderProgram, isTexture);
	components[1]->draw(shaderProgram, isTexture);
}

void Student::create() {
	components[0]->create();
	components[1]->create();

void Student::randomLocation(float x, float z)
{
	mat4 t = glm::translate(mat4(1.0), glm::vec3(x, 0.0f, z));
	modelMatrix = t * modelMatrix;

	for (AlphaNumeric* component : components) {
		component->randomLocation(x, z);
	}
}