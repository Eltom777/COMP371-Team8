#include "Number0.h"

Number0::Number0(): AlphaNumeric(NUMOFCUBES, false) {
	setup();
}

void Number0::setup() {
	// rotation matrix
	glm::vec3 rotationAxis(0.0f, 0.0f, 1.0f);
	
	// hardcoded relative positions
	components[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 6.5f, 2.0f)));
	components[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.035f, 0.0f, 0.0f)));

	components[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 6.5f, 2.0f)));
	components[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.035f, 0.0f, 0.0f)));

	components[2].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));

	components[3].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[3].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, -0.06f, 0.0f)));

	// Cross in the number
	components[4].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 1.0f, 2.0f)));
	components[4].updateRotation(glm::rotate(mat4(1.0f), 45.0f, rotationAxis));

	// set letter slightly above grid
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.07f, 0.0f)));
	}
}

void Number0::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		//component.setModelMatrix(modelMatrix);
	}
}

Number0::~Number0() {

}