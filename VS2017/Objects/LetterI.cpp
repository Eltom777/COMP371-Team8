#include "LetterI.h"

LetterI::LetterI() {
	setup();
}

void LetterI::setup() { // create letter I
	// hardcoded relative positions
	components[0].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, -0.05f, 0.0f)) 
		* glm::scale(mat4(1.0f), vec3(6.0f, 2.0f, 2.0f))); // bottom
	components[1].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f))
		* glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f))); // middle
	components[2].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.05f, 0.0f))
		* glm::scale(mat4(1.0f), vec3(6.0f, 2.0f, 2.0f))); // top

	// set letter slightly above grid
	glm::translate(mat4(1.0f), vec3(0.0f, 0.065f, 0.0f));
}

void LetterI::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (Cube component : components) {
		component.setModelMatrix(modelMatrix);
	}
}

void LetterI::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

LetterI::~LetterI() {

}