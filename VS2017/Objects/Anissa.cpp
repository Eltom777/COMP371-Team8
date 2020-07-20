#include "Anissa.h"

Anissa::Anissa() {
	modelMatrix = mat4(1.0f);
	setup();
}

void Anissa::setup() {
	// set positions of number and letter relative to the center of the model
	letter.concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));
	number.concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.01f, 0.005f, 0.0f)));

	// place model in predetermined position on grid
	concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.75f, 0.01f, 0.75)));
}

mat4 Anissa::getModelMatrix() {
	// get matrix of model (position & transformations) in model space 
	return modelMatrix;
}

void Anissa::concatModelMatrix(mat4 mat) {
	// apply tranformation to all components of model
	modelMatrix = mat * modelMatrix;
	letter.concatModelMatrix(mat);
	number.concatModelMatrix(mat);
}

void Anissa::draw(GLuint modelMatrixLocation) {
	// draw all components of model
	letter.draw(modelMatrixLocation);
	number.draw(modelMatrixLocation);
}

Anissa::~Anissa() {

}