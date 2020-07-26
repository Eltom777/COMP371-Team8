#include "LetterL.h"

LetterL::LetterL() : AlphaNumeric(NUMOFCUBES, true){
	setup();
}

void LetterL::setup() { //create letter O
	// hardcoded relative positions
	components[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));
	components[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)));

	components[1].updateScale(glm::scale(mat4(1.0f), vec3(4.0f, 2.0f, 2.0f)));
	components[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.05f, -0.05f, 0.0f)));

	components[0].updateChild(&components[1]);

	// set letter slightly above grid
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
	}
}

void LetterL::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
	for (int i = 0; i < NUMOFCUBES; i++) {
		//component.setModelMatrix(modelMatrix);
	}
}


LetterL::~LetterL() {

}