#include "Number9.h"

Number9::Number9() {
	modelMatrix = mat4(1.0f);
	setup();
}

void Number9::setup() { //create number 9
	// hardcoded relative positions
	components[0].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.08f, 0.03f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 3.0f, 2.0f)));
	components[1].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(4.0f, 2.0f, 2.0f)));
	components[2].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.04f, 0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(5.0f, 2.0f, 2.0f)));
	components[3].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));

	// set letter slightly above grid
	glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f));
}

void Number9::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (Cube component : components) {
		component.setModelMatrix(modelMatrix);
	}
}

void Number9::draw(GLuint modelMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

Number9::~Number9() {

}