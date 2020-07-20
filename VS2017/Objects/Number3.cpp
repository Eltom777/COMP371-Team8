#include "Number3.h"

Number3::Number3() {
	modelMatrix = mat4(1.0f);
	setup();
}

void Number3::setup() { //create number3
	// hardcoded relative positions
	components[0].concatModelMatrix(glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f))); //glm::translate(mat4(1.0f), vec3(0.05f, 0.0f, 0.0f))  *
	components[1].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.05f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[2].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[3].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, -0.05f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));

	// set letter slightly above grid
	concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
}

mat4 Number3::getModelMatrix() {
	return modelMatrix;
}

void Number3::concatModelMatrix(mat4 mat) {
	modelMatrix = mat * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatModelMatrix(mat);
	}
}

void Number3::draw(GLuint modelMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);

	}
}

Number3::~Number3() {

}
