#include "Number0.h"

Number0::Number0() {
	modelMatrix = mat4(1.0f);
	setup();
}

void Number0::setup() {
	// rotation matrix
	glm::vec3 rotationAxis(0.0f, 0.0f, 1.0f);
	
	// hardcoded relative positions
	components[0].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.035f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 6.5f, 2.0f)));
	components[1].concatModelMatrix(glm::translate(mat4(1.0f), vec3(-0.035f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 6.5f, 2.0f)));
	components[2].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[3].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, -0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));

	// Cross in the number
	components[4].concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 1.0f, 2.0f)));
	components[4].concatModelMatrix(glm::rotate(mat4(1.0f), 45.0f, rotationAxis));

	// set letter slightly above grid
	concatModelMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.07f, 0.0f)));
}

mat4 Number0::getModelMatrix() {
	return modelMatrix;
}

void Number0::concatModelMatrix(mat4 mat) {
	modelMatrix = mat * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatModelMatrix(mat);
	}
}

void Number0::draw(GLuint modelMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);

	}
}

Number0::~Number0() {

}