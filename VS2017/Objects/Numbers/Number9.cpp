#include "Number9.h"
#include <iostream>

Number9::Number9() : AlphaNumeric(NUMOFCUBES, false) {
	setup();
}

Number9::Number9() : AlphaNumeric(NUMOFTOPCUBES, NUMOFBOTCUBES) {
	//numberOfCubes = NUMOFCUBES;
	numberOfTopCubes = NUMOFTOPCUBES;
	numberOfBotCubes = NUMOFBOTCUBES;
	setup();
}

void Number9::setup() { //create number 9
	// hardcoded relative positions

	topComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(1.0f, 2.0f, 1.0f)));
	topComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.025f, 0.06f, 0.0f))); // left edge (top)

	topComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 0.5f, 1.0f)));
	topComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.085f, 0.0f))); // top edge (top)

	topComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(1.0f, 2.0f, 1.0f)));
	topComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.025f, 0.06f, 0.0f))); // top right edge (top)

	bottomComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 0.5f, 1.0f)));
	bottomComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.04f, 0.0f))); // bottom edge

	bottomComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(1.0f, 2.0f, 1.0f)));
	bottomComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.025f, 0.02f, 0.0f))); // bottom right edge

	// Set children
	bottomComponents[1].updateChild(&bottomComponents[0]); //base
	bottomComponents[0].updateChild(&topComponents[0]);
	updateBase(&bottomComponents[1]);
	topComponents[0].updateChild(&topComponents[1]);
	topComponents[1].updateChild(&topComponents[2]);

	// set letter slightly above grid
	traverse(glm::translate(mat4(1.0f), vec3(0.0f, 0.01f, 0.0f)), 0);

	bottomComponents[0].updateChild(NULL);
	topComponents[0].updateChild(NULL);
	topComponents[1].updateChild(NULL);

	/*for (int i = 0; i < numberOfTopCubes; i++) {
		topComponents[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.01f, 0.0f)));
	}*/

	/*for (int i = 0; i < numberOfBotCubes; i++) {
		bottomComponents[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.01f, 0.0f)));
	}*/
}

Number9::~Number9() {
	//delete[] components;
	delete[] topComponents;
	delete[] bottomComponents;
}