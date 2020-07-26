#include "LetterI.h"

LetterI::LetterI(): AlphaNumeric(NUMOFCUBES, true) {
	setup();
}

void LetterI::setup() { // create letter I
	// hardcoded relative positions
	components[0].updateScale(glm::scale(mat4(1.0f), vec3(6.0f, 2.0f, 2.0f)));
	components[0].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, -0.05f, 0.0f)));// bottom

	components[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));
	components[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)));// middle

	components[2].updateScale(glm::scale(mat4(1.0f), vec3(6.0f, 2.0f, 2.0f)));
	components[2].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.05f, 0.0f)));// top


	// set letter slightly above grid
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.065f, 0.0f)));
	}
}

LetterI::~LetterI() {
	delete[] components;
}