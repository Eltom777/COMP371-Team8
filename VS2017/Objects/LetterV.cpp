#include "LetterV.h"

LetterV::LetterV() {
	setup();
}

void LetterV::setup() { //create letter V
	// hardcoded relative positions
	// base of V
	components[0].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.05f, -0.05f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	// first row
	components[1].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.020f, -0.010f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	components[2].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.080f, -0.010f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	// second row
	components[3].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.005f, 0.03f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	components[4].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.095f, 0.03f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	
	// set letter slightly above grid
	glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f));
}

void LetterV::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (Cube component : components) {
		component.setModelMatrix(modelMatrix);
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