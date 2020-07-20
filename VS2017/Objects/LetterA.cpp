#include "LetterA.h"

LetterA::LetterA() {
	modelMatrix = mat4(1.0f);
	setup();
}

void LetterA::setup() { //create letter A
	// hardcoded relative positions
	components[0].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 7.5f, 2.0f))); // right edge
	components[1].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 7.5f, 2.0f))); // left edge
	components[2].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 1.5f, 2.0f))); // top edge
	components[3].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.005f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 1.0f, 2.0f))); // bottom edge

	// set letter slightly above grid
	concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.065f, 0.0f))); // Shift above grid
}

mat4 LetterA::getModelMatrix() {
	return modelMatrix;
}

void LetterA::concatModelMatrix(mat4 mat) {
	modelMatrix = mat * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatModelMatrix(mat);
	}
}

void LetterA::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

LetterA::~LetterA() {

}