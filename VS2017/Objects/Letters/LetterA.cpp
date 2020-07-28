#include "LetterA.h"

LetterA::LetterA() : AlphaNumeric(NUMOFTOPCUBES, NUMOFBOTCUBES, true) {
	numberOfTopCubes = NUMOFTOPCUBES;
	numberOfBotCubes = NUMOFBOTCUBES;
	setup();
}

void LetterA::setup() { //create letter A
	// hardcoded relative positions
	topComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.75f, 2.0f)));
	topComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.05f, 0.0045f, 0.0f)));// right edge top

	topComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.75f, 2.0f)));
	topComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0045f, 0.0f)));// left edge top

	topComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(7.0f, 1.5f, 2.0f)));
	topComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.045f, 0.0f)));// top edge

	topComponents[3].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 1.5f, 2.0f))); // middle edge
	topComponents[3].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, -0.01f, 0.0f)));

	bottomComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.75f, 2.0f)));
	bottomComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.05f, -0.045f, 0.0f)));// right edge bottom

	bottomComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.75f, 2.0f)));
	bottomComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, -0.045f, 0.0f)));// left edge bottom

	bottomComponents[1].updateChild(&bottomComponents[0]); //base
	bottomComponents[0].updateChild(&topComponents[0]);
	topComponents[0].updateChild(&topComponents[1]); //base top
	topComponents[1].updateChild(&topComponents[2]);
	topComponents[2].updateChild(&topComponents[3]);

	updateBase(&bottomComponents[1]);
	//updateBaseTop(&topComponents[0]);

	// set letter slightly above grid
	traverse(glm::translate(mat4(1.0f), vec3(0.0f, 0.065f, 0.0f)), 0);
	
	//bottomComponents[0].updateChild(NULL);
	
	//for (int i = 0; i < NUMOFCUBES; i++) {
	//	components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.065f, 0.0f)));
	//}
}

LetterA::~LetterA() {
	delete[] topComponents;
	delete[] bottomComponents;
}