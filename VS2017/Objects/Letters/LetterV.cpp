#include "LetterV.h"

LetterV::LetterV() : AlphaNumeric(NUMOFTOPCUBES, NUMOFBOTCUBES) {
	numberOfTopCubes = NUMOFTOPCUBES;
	numberOfBotCubes = NUMOFBOTCUBES;
	setup();
}

void LetterV::setup() { //create letter V
	// hardcoded relative positions
	bottomComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.0f, 2.0f))); // left (bottom)
	bottomComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.020f, -0.03f, 0.0f)));

	bottomComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f))); // bottom
	bottomComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.05f, -0.05f, 0.0f)));

	bottomComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.0f, 2.0f))); // right (bottom)
	bottomComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.080f, -0.03f, 0.0f)));

	topComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f))); // leftmost (top)
	topComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.005f, 0.03f, 0.0f)));

	topComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.0f, 2.0f))); // leftmid (top)
	topComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.020f, 0.010f, 0.0f)));

	topComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.0f, 2.0f))); // rightmid (top)
	topComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.080f, 0.010f, 0.0f)));

	topComponents[3].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.0f, 2.0f))); // rightmost (top)
	topComponents[3].updateTranslation(glm::translate(mat4(1.0f), vec3(0.095f, 0.03f, 0.0f)));

	// setup hierarchy
	bottomComponents[0].updateChild(&bottomComponents[1]);
	bottomComponents[1].updateChild(&bottomComponents[2]);
	bottomComponents[2].updateChild(&topComponents[0]);
	updateBase(&bottomComponents[0]);
	topComponents[0].updateChild(&topComponents[1]);
	topComponents[1].updateChild(&topComponents[2]);
	topComponents[2].updateChild(&topComponents[3]);

	// set letter slightly above grid
	traverse(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)), 0);

	/*for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
	}*/
}

LetterV::~LetterV() {
	delete[] components;
}