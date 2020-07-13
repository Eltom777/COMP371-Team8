#include "Keven.h"

Keven::Keven() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Keven::setup() {
	number.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)));
	letter.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));

	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.01f, -0.75f))); // Translate to top left corner
}

mat4 Keven::getWorldMatrix() {
	return worldMatrix;
}

void Keven::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	letter.concatWorldMatrix(mat);
	number.concatWorldMatrix(mat);
}

void Keven::draw(GLuint worldMatrixLocation) {
	letter.draw(worldMatrixLocation);
	number.draw(worldMatrixLocation);
}

Keven::~Keven() {

}