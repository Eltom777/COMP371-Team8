#include "LetterV.h"

LetterV::LetterV() {
	worldMatrix = mat4(1.0f);
	setup();
}

void LetterV::setup() { //create letter V
	// hardcoded relative positions
	// base of V
	components[0].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.05f, -0.05f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	// first row
	components[1].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.020f, -0.010f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	components[2].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.080f, -0.010f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	// second row
	components[3].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.005f, 0.03f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	components[4].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.095f, 0.03f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f)));
	
	// set letter slightly above grid
	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
}

mat4 LetterV::getWorldMatrix() {
	return worldMatrix;
}

void LetterV::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatWorldMatrix(mat);
	}
}

void LetterV::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getWorldMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

LetterV::~LetterV() {

}