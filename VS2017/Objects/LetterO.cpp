#include "LetterO.h"

LetterO::LetterO() {
	worldMatrix = mat4(1.0f);
	setup();
}

void LetterO::setup() { //create letter O
	components[0].concatWorldMatrix( glm::translate(mat4(1.0f), vec3(0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 6.0f, 2.0f))   );
	components[1].concatWorldMatrix( glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)) * glm::scale(mat4(1.0f), vec3(2.0f, 6.0f, 2.0f))  );
	components[2].concatWorldMatrix( glm::translate(mat4(1.0f), vec3(0.0f, 0.04f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f))    );
	components[3].concatWorldMatrix( glm::translate(mat4(1.0f), vec3(0.0f, -0.04f, 0.0f)) * glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f))   );
	
	concatWorldMatrix(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
}

mat4 LetterO::getWorldMatrix() {
	return worldMatrix;
}

void LetterO::concatWorldMatrix(mat4 mat) {
	worldMatrix = mat * worldMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].concatWorldMatrix(mat);
	}
}

void LetterO::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getWorldMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
	}
}

LetterO::~LetterO() {
	
}