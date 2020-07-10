#include "Sharon.h"

Sharon::Sharon() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Sharon::setup() {
	number.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)));
	letter.concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));

	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.75f, 0.01f, 0.75f))); // Translate to bottom left corner
}

mat4 Sharon::getWorldMatrix() {
	return worldMatrix;
}

void Sharon::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	letter.concatWorldMatrix(mat);
	number.concatWorldMatrix(mat);
}

void Sharon::draw(GLuint worldMatrixLocation) {
	letter.draw(worldMatrixLocation);
	number.draw(worldMatrixLocation);
}

Sharon::~Sharon() {

}