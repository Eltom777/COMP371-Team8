#include "LightCube.h"

LightCube::LightCube() : AlphaNumeric(NUMOFCUBES) {
	setup();
}

void LightCube::setup() { //create letter O
	// hardcoded relative positions
	components[0].updateScale(glm::scale(mat4(1.0f), vec3(1.0f, 1.0f, 1.0f)));
	components[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)));

	// set letter slightly above grid
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
	}
}

void LightCube::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		//component.setModelMatrix(modelMatrix);
	}
}

void LightCube::draw(GLuint worldMatrixLocation) {
	for (int i = 0; i < NUMOFCUBES; i++) {
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &components[i].getModelMatrix()[0][0]); //setting worldmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

LightCube::~LightCube() {

}