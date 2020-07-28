#include "LetterL.h"
#include <iostream>

LetterL::LetterL() : AlphaNumeric(NUMOFCUBES, true){
	setup();
}
LetterL::LetterL() : AlphaNumeric(NUMOFTOPCUBES, NUMOFBOTCUBES) {
	numberOfTopCubes = NUMOFTOPCUBES;
	numberOfBotCubes = NUMOFBOTCUBES;
	setup();
}

void LetterL::setup() { //create letter L
	//// hardcoded relative positions
	topComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(1.0f, 2.0f, 1.0f)));
	topComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f))); // top left (top)

	bottomComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(1.0f, 2.0f, 1.0f)));
	bottomComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.02f, 0.0f))); // bottom left

	bottomComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 1.0f, 1.0f)));
	bottomComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.03f, 0.01f, 0.0f))); // right

	bottomComponents[1].updateChild(&bottomComponents[0]); //base
	bottomComponents[0].updateChild(&topComponents[0]); //base top
	updateBase(&bottomComponents[1]);
	//updateBaseTop(&topComponents[0]);

	// set letter slightly above grid
	traverse(glm::translate(mat4(1.0f), vec3(0.0f, 0.01f, 0.0f)), 0);
}

LetterL::~LetterL() {
	//delete[] components;
	delete[] topComponents;
	delete[] bottomComponents;
}