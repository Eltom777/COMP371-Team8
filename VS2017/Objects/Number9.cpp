#include "Number9.h"

Number9::Number9() {
	worldMatrix = mat4(1.0f);
	setup();
}

void Number9::setup() { //create number 9
	//hardcoded values
	components[0].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.08f, 0.03f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 3.0f, 2.0f)));
	components[1].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(4.0f, 2.0f, 2.0f)));
	components[2].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.04f, 0.06f, 0.0f)) * glm::scale(mat4(1.0f), vec3(5.0f, 2.0f, 2.0f)));
	components[3].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));

	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
}

mat4 Number9::getWorldMatrix() {
	return worldMatrix;
}

void Number9::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	for (int i = 0; i < NUMOFCUBES9; i++) {
		components[i].concatWorldMatrix(mat);
	}
}

void Number9::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES9; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getWorldMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

Number9::~Number9() {

}