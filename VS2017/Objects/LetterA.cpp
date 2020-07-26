#include "LetterA.h"

LetterA::LetterA() : AlphaNumeric(NUMOFCUBES, true) {
	setup();
}

void LetterA::setup() { //create letter A
	// hardcoded relative positions
	components[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 7.5f, 2.0f)));
	components[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.05f, 0.0f, 0.0f)));// right edge

	components[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 7.5f, 2.0f)));
	components[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)));// left edge

	components[2].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 1.5f, 2.0f)));
	components[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));// top edge

	components[3].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 1.0f, 2.0f)));
	components[3].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.005f, 0.0f)));

	// set letter slightly above grid
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.065f, 0.0f)));
	}
}

void LetterA::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		//component.setModelMatrix(modelMatrix);
	}
}

LetterA::~LetterA() {

}