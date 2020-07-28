#include "LetterI.h"

LetterI::LetterI(): AlphaNumeric(NUMOFTOPCUBES, NUMOFBOTCUBES, true) {
	numberOfTopCubes = NUMOFTOPCUBES;
	numberOfBotCubes = NUMOFBOTCUBES;
	setup();
}

void LetterI::setup() { // create letter I
	// hardcoded relative positions
	bottomComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(6.0f, 2.0f, 2.0f)));
	bottomComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, -0.05f, 0.0f)));// bottom

	bottomComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.5f, 2.0f)));
	bottomComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, -0.025f, 0.0f))); // bottom middle
	
	topComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.5f, 2.0f)));
	topComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.025f, 0.0f)));// top middle

	topComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(6.0f, 2.0f, 2.0f)));
	topComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.055f, 0.0f)));// top

	// setup hierarchy
	bottomComponents[0].updateChild(&bottomComponents[1]); // base
	bottomComponents[1].updateChild(&topComponents[0]);
	topComponents[0].updateChild(&topComponents[1]); //base top
			
	updateBase(&bottomComponents[0]);
	updateBaseTop(&topComponents[0]);

	// set letter slightly above grid
	traverse(glm::translate(mat4(1.0f), vec3(0.0f, 0.07f, 0.0f)), 0);
}

LetterI::~LetterI() {
	delete[] topComponents;
	delete[] bottomComponents;
}