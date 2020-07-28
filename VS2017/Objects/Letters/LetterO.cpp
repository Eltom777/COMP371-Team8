#include "LetterO.h"

LetterO::LetterO() : AlphaNumeric(NUMOFTOPCUBES, NUMOFBOTCUBES) {
	numberOfTopCubes = NUMOFTOPCUBES;
	numberOfBotCubes = NUMOFBOTCUBES;
	setup();
}

void LetterO::setup() { //create letter O
	// hardcoded relative positions
	bottomComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 3.5f, 2.0f)));
	bottomComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, -0.035f, 0.0f))); // left (bottom)

	bottomComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	bottomComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, -0.06f, 0.0f))); // bottom

	bottomComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 3.5f, 2.0f)));
	bottomComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.05f, -0.035f, 0.0f))); // right (bottom)

	topComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 3.5f, 2.0f)));
	topComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.05f, 0.035f, 0.0f))); // right (top)

	topComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	topComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f))); // top

	topComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 3.5f, 2.0f)));
	topComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.035f, 0.0f))); // left (top)

	// setup hierarchy
	bottomComponents[0].updateChild(&bottomComponents[1]); //base
	bottomComponents[1].updateChild(&bottomComponents[2]);
	bottomComponents[2].updateChild(&topComponents[0]);
	topComponents[0].updateChild(&topComponents[1]); //base top
	topComponents[1].updateChild(&topComponents[2]);

	updateBase(&bottomComponents[0]);
	//updateBaseTop(&topComponents[0]);

	// set letter slightly above grid
	traverse(glm::translate(mat4(1.0f), vec3(0.0f, 0.08f, 0.0f)), 0);

	/*for(int i = 0; i < NUMOFCUBES; i++){
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.08f, 0.0f)));
	}*/
}

LetterO::~LetterO() {
	//delete[] components;
	delete[] topComponents;
	delete[] bottomComponents;
}