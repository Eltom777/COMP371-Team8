#include "Number0.h"

Number0::Number0(): AlphaNumeric(NUMOFCUBES, false) {
	setup();
}

Number0::Number0(): AlphaNumeric(NUMOFTOPCUBES, NUMOFBOTCUBES) {
	numberOfTopCubes = NUMOFTOPCUBES;
	numberOfBotCubes = NUMOFBOTCUBES;
	setup();
}

void Number0::setup() {
	// rotation matrix
	glm::vec3 rotationAxis(0.0f, 0.0f, 1.0f);
	
	// hardcoded relative positions
	bottomComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.0f, 2.0f)));
	bottomComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.035f, -0.04f, 0.0f))); // left (bottom)

	bottomComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	bottomComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, -0.06f, 0.0f))); // bottom
	
	bottomComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 2.0f, 2.0f)));
	bottomComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(0.035f, -0.04f, 0.0f))); // right (bottom)

	topComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.5f, 2.0f)));
	topComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.035f, 0.015f, 0.0f))); // right (top)

	topComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	topComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f))); // top

	topComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 4.5f, 2.0f)));
	topComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.035f, 0.015f, 0.0f))); // left (top)

	// Cross in the number
	topComponents[3].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 1.0f, 2.0f)));
	topComponents[3].updateRotation(glm::rotate(mat4(1.0f), 45.0f, rotationAxis));

	// setup hierarchy
	bottomComponents[0].updateChild(&bottomComponents[1]);
	bottomComponents[1].updateChild(&bottomComponents[2]);
	bottomComponents[2].updateChild(&topComponents[0]);
	
	topComponents[0].updateChild(&topComponents[1]);
	topComponents[1].updateChild(&topComponents[2]);
	topComponents[2].updateChild(&topComponents[3]);

	updateBase(&bottomComponents[0]);
	updateBaseTop(&topComponents[0]);

	// set letter slightly above grid
	traverse(glm::translate(mat4(1.0f), vec3(0.0f, 0.07f, 0.0f)), 0);
}

Number0::~Number0() {
	//delete[] components;
	delete[] topComponents;
	delete[] bottomComponents;
}