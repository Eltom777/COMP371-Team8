#include "LetterV.h"

LetterV::LetterV() : AlphaNumeric(NUMOFCUBES){
	setup();
}

void LetterV::setup() { //create letter V
	// hardcoded relative positions
	components[0].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.05f, -0.05f, 0.0f)));

	components[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	components[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.020f, -0.010f, 0.0f)));

	components[2].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	components[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.080f, -0.010f, 0.0f)));

	components[3].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	components[3].updateTranslation(glm::translate(mat4(1.0f), vec3(0.005f, 0.03f, 0.0f)));

	components[4].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	components[4].updateTranslation(glm::translate(mat4(1.0f), vec3(0.095f, 0.03f, 0.0f)));

	// set letter slightly above grid
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
	}
}

void LetterV::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		//component.setModelMatrix(modelMatrix);
	}
}

void LetterV::draw(GLuint modelMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

LetterV::~LetterV() {

}