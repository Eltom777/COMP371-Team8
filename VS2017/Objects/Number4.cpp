#include "Number4.h"

Number4::Number4() : AlphaNumeric(NUMOFCUBES) {
	setup();
}

void Number4::setup() { //create number 4
	// hardcoded relative positions
	components[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.5f, 2.0f)));
	components[0].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.08f, 0.025f, 0.0f)));// left edge

	components[1].updateScale(glm::scale(mat4(1.0f), vec3(4.0f, 2.0f, 2.0f)));
	components[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)));// bottom edge

	components[2].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));
	components[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f))); // right edge

	// set letter slightly above grid
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
	}
	
}

void Number4::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		//component.setModelMatrix(modelMatrix);
	}
}

void Number4::draw(GLuint modelMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

Number4::~Number4() {

}