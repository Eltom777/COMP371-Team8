#include "Melina.h"

Melina::Melina() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Melina::setup() {
	number.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)));
	letter.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));

	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.75f, 0.01f, -0.75f))); // Translate to top right corner
}

mat4 Melina::getWorldMatrix() {
	return worldMatrix;
}

void Melina::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	letter.concatWorldMatrix(mat);
	number.concatWorldMatrix(mat);
}

void Melina::draw(GLuint worldMatrixLocation) {
	letter.draw(worldMatrixLocation);
	number.draw(worldMatrixLocation);
}

Melina::~Melina() {

}