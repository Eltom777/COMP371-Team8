#include "Number4.h"


Number4::Number4() : AlphaNumeric(NUMOFCUBES, false) {
	setup();
}
Number4::Number4() : AlphaNumeric(NUMOFTOPCUBES, NUMOFBOTCUBES) {
	numberOfTopCubes = NUMOFTOPCUBES;
	numberOfBotCubes = NUMOFBOTCUBES;
	setup();
}
void Number4::setup() { // create number 4
	// hardcoded relative positions
	topComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.5f, 2.0f)));
	topComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.08f, 0.025f, 0.0f)));// left edge

	topComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(4.0f, 2.0f, 2.0f)));
	topComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)));// bottom edge

	topComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 3.5f, 2.0f)));
	topComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.035f, 0.0f))); // right edge top

	bottomComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 3.5f, 2.0f)));
	bottomComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, -0.03f, 0.0f))); // right edge bottom

	bottomComponents[0].updateChild(&topComponents[0]); // base
	updateBase(&bottomComponents[0]);

	topComponents[0].updateChild(&topComponents[1]);
	topComponents[1].updateChild(&topComponents[2]);

	// set letter slightly above grid
	traverse(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)), 0);
	
	// bottomComponents[0].updateChild(NULL);

	//for (int i = 0; i < NUMOFCUBES; i++) {
	//	components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
	//}
	
}

Number4::~Number4() {
	//delete[] components;
	delete[] topComponents;
	delete[] bottomComponents;
}