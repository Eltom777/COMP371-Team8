#include "Number0.h"

Number0::Number0() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Number0::setup() {
	// rotation matrix
	glm::vec3 rotationAxis(0.0f, 0.0f, 1.0f);
	
	// hardcoded relative positions
	components[0].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.035f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 6.5f, 2.0f)));
	components[1].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.035f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 6.5f, 2.0f)));
	components[2].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[3].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, -0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));

	// Cross in the number
	components[4].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 1.0f, 2.0f)));
	components[4].concatWorldMatrix(glm::rotate(mat4(1.0f), 45.0f, rotationAxis));

	// set letter slightly above grid
	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.07f, 0.0f)));
}

mat4 Number0::getWorldMatrix() {
	return worldMatrix;
}

void Number0::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatWorldMatrix(mat);
	}
}

void Number0::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getWorldMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);

	}
}

Number0::~Number0() {

}