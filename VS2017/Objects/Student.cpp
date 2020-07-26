#include "Student.h"

void Student::updateModelMatrix() {
	for (AlphaNumeric* component : components) {
		component->updateModelMatrix();
	}
	sphere->updateModelMatrix();
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
	sphere->translateModel(t);
}

void Student::scale(mat4 s) {

	//Place back to origin
	vec3 translationComponent = vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);
	mat4 tempworldMatrix = glm::translate(mat4(1.0), translationComponent * -1.0f); //place back to origin
	for (AlphaNumeric* component : components) {
		component->translateModel(tempworldMatrix);
	}
	sphere->translateModel(tempworldMatrix);
	
	//modelMatrix = s * modelMatrix;
	for (AlphaNumeric* component : components) {
		component->translateModel(s);
	}
	sphere->translateModel(s);

	//Place back to original spot
	tempworldMatrix = glm::translate(mat4(1.0), translationComponent);
	for (AlphaNumeric* component : components) {
		component->translateModel(tempworldMatrix);
	}
	
	sphere->translateModel(tempworldMatrix);
}

// NOTE TO SELF (Melina): remove all worldMatrixLocations params after finished testing :|
void Student::rotate(mat4 r, GLuint worldMatrixLocation) {
	
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

	sphere->translateModel(tempworldMatrix);

	for (AlphaNumeric* component : components) {
		component->translateModel(r);
	}

	sphere->translateModel(r);

	modelMatrix = r * modelMatrix;

	//Place back to original spot
	tempworldMatrix = glm::translate(mat4(1.0), translationComponent);
	for (AlphaNumeric* component : components) {
		component->translateModel(tempworldMatrix);
	}

	sphere->translateModel(tempworldMatrix);
}

void Student::draw(GLuint modelMatrixLocation, int sphereVertices) {
	// draw all components of model
	components[0]->draw(modelMatrixLocation);
	components[1]->draw(modelMatrixLocation);
	sphere->draw(modelMatrixLocation, sphereVertices);
}