#include "Thomas.h"

Thomas::Thomas() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Thomas::setup() { //create letter O
	number.concatWorldMatrix( glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)) );
	letter.concatWorldMatrix( glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)) );

	concatWorldMatrix( glm::translate(mat4(1.0f), vec3(-0.75f, 0.0f, -0.75f)) ); //Translate to top left corner
}

mat4 Thomas::getWorldMatrix() {
	return worldMatrix;
}

void Thomas::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	letter.concatWorldMatrix(mat);
	number.concatWorldMatrix(mat);
}

void Thomas::draw(GLuint worldMatrixLocation) {
	letter.draw(worldMatrixLocation);
	number.draw(worldMatrixLocation);
}

Thomas::~Thomas() {

}