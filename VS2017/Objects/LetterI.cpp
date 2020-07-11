#include "LetterI.h"

LetterI::LetterI() {
	worldMatrix = mat4(1.0f);
	setup();
}

void LetterI::setup() { // create letter I
	components[0].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, -0.05f, 0.0f)) 
		* glm::scale(mat4(1.0f), vec3(6.0f, 2.0f, 2.0f))); // bottom
	components[1].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f))
		* glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f))); // middle
	components[2].concatWorldMatrix(glm::translate(mat4(1.0f), vec3(-0.05f, 0.05f, 0.0f))
		* glm::scale(mat4(1.0f), vec3(6.0f, 2.0f, 2.0f))); // top

	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.065f, 0.0f)));
}

mat4 LetterI::getWorldMatrix() {
	return worldMatrix;
}

void LetterI::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatWorldMatrix(mat);
	}
}

void LetterI::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getWorldMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

LetterI::~LetterI() {

}