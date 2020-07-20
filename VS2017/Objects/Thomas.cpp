#include "Thomas.h"

Thomas::Thomas() {
	modelMatrix = mat4(1.0f);
	setup();
}

void Thomas::setup() {
	// set positions of number and letter relative to the center of the model
	number.concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)));
	letter.concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));

	// place model in predetermined position on grid
	concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.75f, 0.01f, -0.75f))); // Translate to top left corner
}

mat4 Thomas::getModelMatrix() {
	// get matrix of model (position & transformations) in model space 
	return modelMatrix;
}

void Thomas::concatModelMatrix(mat4 mat) {
	// apply tranformation to all components of model
	modelMatrix = mat * modelMatrix;
	letter.concatModelMatrix(mat);
	number.concatModelMatrix(mat);
}

void Thomas::draw(GLuint modelMatrixLocation) {
	// draw all components of model
	letter.draw(modelMatrixLocation);
	number.draw(modelMatrixLocation);
}

Thomas::~Thomas() {

}