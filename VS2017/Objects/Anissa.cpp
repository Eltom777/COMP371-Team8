#include "Anissa.h"

Anissa::Anissa() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Anissa::setup() {
	// set positions of number and letter relative to the center of the model
	letter.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));
	number.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.01f, 0.005f, 0.0f)));

	// place model in predetermined position on grid
	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.75f, 0.01f, 0.75)));
}

mat4 Anissa::getWorldMatrix() {
	// get matrix of model (position & transformations) in world space 
	return worldMatrix;
}

void Anissa::concatWorldMatrix(mat4 mat) {
	// apply tranformation to all components of model
	worldMatrix = mat * worldMatrix;
	letter.concatWorldMatrix(mat);
	number.concatWorldMatrix(mat);
}

void Anissa::draw(GLuint worldMatrixLocation) {
	// draw all components of model
	letter.draw(worldMatrixLocation);
	number.draw(worldMatrixLocation);
}

Anissa::~Anissa() {

}