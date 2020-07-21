#include "LetterO.h"

LetterO::LetterO() {
	setup();
}

void LetterO::setup() { //create letter O
	// hardcoded relative positions
	components[0].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));
	components[1].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));
	components[2].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[3].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, -0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	
	// set letter slightly above grid
	components[0].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.09f, 0.0f)));
	components[1].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.09f, 0.0f)));
	components[2].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.09f, 0.0f)));
	components[3].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.09f, 0.0f)));
}

void LetterO::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (Cube component : components) {
		component.concatModelMatrix(modelMatrix);
	}
}

void LetterO::draw(GLuint modelMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
	}
}

LetterO::~LetterO() {
	
}