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

void Student::rotate(mat4 r) {

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
	//modelMatrix = r * modelMatrix;

	//Place back to original spot
	tempworldMatrix = glm::translate(mat4(1.0), translationComponent);
	for (AlphaNumeric* component : components) {
		component->translateModel(tempworldMatrix);
	}
}


void Student::draw(Shader* shaderProgram, const bool isTexture) {
	components[0]->draw(shaderProgram, isTexture);
	components[1]->draw(shaderProgram, isTexture);
	sphere->draw(modelMatrixLocation, sphereVertices);
}

void Student::create() {
	components[0]->create();
	components[1]->create();
}

void Student::randomLocation(float x, float z)
{
	mat4 t = glm::translate(mat4(1.0), glm::vec3(x, 0.0f, z));
	modelMatrix = t * modelMatrix;

	for (AlphaNumeric* component : components) {
		component->randomLocation(x, z);
	}
	sphere->translateModel(tempworldMatrix);
}

	// Draw all components of model, disable blending when drawing the alphanumeric models
void Student::draw(GLuint modelMatrixLocation, int sphereVertices, int cubeVAO, int sphereVAO) {
	glDisable(GL_BLEND);
	glBindVertexArray(cubeVAO);
	/*components[0]->draw(modelMatrixLocation);
	components[1]->draw(modelMatrixLocation);*/
	components[0]->drawTop(modelMatrixLocation);
	components[0]->drawBottom(modelMatrixLocation);
	components[1]->drawTop(modelMatrixLocation);
	components[1]->drawBottom(modelMatrixLocation);
	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glBindVertexArray(sphereVAO);
	sphere->draw(modelMatrixLocation, sphereVertices);
}
