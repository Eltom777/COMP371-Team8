#include "LetterA.h"

LetterA::LetterA() {
	worldMatrix = mat4(1.0f);
	setup();
}

void LetterA::setup() { //create letter A
	components[0].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 7.5f, 2.0f))); // right edge
	components[1].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 7.5f, 2.0f))); // left edge
	components[2].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 1.5f, 2.0f))); // top edge
	components[3].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.005f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 1.0f, 2.0f))); // bottom edge

	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.065f, 0.0f))); // Shift above grid
}

mat4 LetterA::getWorldMatrix() {
	return worldMatrix;
}

void LetterA::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatWorldMatrix(mat);
	}
}

void LetterA::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getWorldMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

LetterA::~LetterA() {

}