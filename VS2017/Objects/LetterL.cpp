#include "LetterL.h"

LetterL::LetterL() {
	modelMatrix = mat4(1.0f);
	setup();
}

void LetterL::setup() { //create letter O
	// hardcoded relative positions
	components[0].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));
	components[1].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.05f, -0.05f, 0.0f)) * glm::scale(mat4(1.0f), vec3(4.0f, 2.0f, 2.0f)));

	// set letter slightly above grid
	concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
}

mat4 LetterL::getModelMatrix() {
	return modelMatrix;
}

void LetterL::concatModelMatrix(mat4 mat) {
	modelMatrix = mat * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatModelMatrix(mat);
	}
}

void LetterL::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

LetterL::~LetterL() {

}