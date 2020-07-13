#include "Thomas.h"

Thomas::Thomas() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Thomas::setup() {
	// set positions of number and letter relative to the center of the model
	number.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)));
	letter.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));

	// place model in predetermined position on grid
	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.75f, 0.01f, -0.75f))); // Translate to top left corner
}

mat4 Thomas::getWorldMatrix() {
	// get matrix of model (position & transformations) in world space 
	return worldMatrix;
}

void Thomas::concatWorldMatrix(mat4 mat) {
	// apply tranformation to all components of model
	worldMatrix = mat * worldMatrix;
	letter.concatWorldMatrix(mat);
	number.concatWorldMatrix(mat);
}

void Thomas::draw(GLuint worldMatrixLocation) {
	// draw all components of model
	letter.draw(worldMatrixLocation);
	number.draw(worldMatrixLocation);
}

Thomas::~Thomas() {

}