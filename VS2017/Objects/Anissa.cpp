#include "Anissa.h"

Anissa::Anissa() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Anissa::setup() {
	letter.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));
	number.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.01f, 0.001f, 0.0f)));

	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.75f, 0.01f, 0.75)));
}

mat4 Anissa::getWorldMatrix() {
	return worldMatrix;
}

void Anissa::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	letter.concatWorldMatrix(mat);
	number.concatWorldMatrix(mat);
}

void Anissa::draw(GLuint worldMatrixLocation) {
	letter.draw(worldMatrixLocation);
	number.draw(worldMatrixLocation);
}

Anissa::~Anissa() {

}