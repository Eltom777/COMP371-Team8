#include "Number3.h"

Number3::Number3() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Number3::setup() { //create number3
	components[0].concatWorldMatrix(glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f))); //glm::translate(mat4(1.0f), vec3(0.05f, 0.0f, 0.0f))  *
	components[1].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.05f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[2].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[3].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, -0.05f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));

	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f))); // Shift above grid
}

mat4 Number3::getWorldMatrix() {
	return worldMatrix;
}

void Number3::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatWorldMatrix(mat);
	}
}

void Number3::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getWorldMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);

	}
}

Number3::~Number3() {

}
