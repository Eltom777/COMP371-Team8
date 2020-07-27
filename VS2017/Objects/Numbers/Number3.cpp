#include "Number3.h"

Number3::Number3() : AlphaNumeric(NUMOFCUBES, false){
	setup();
}
Number3::Number3() : AlphaNumeric(NUMOFTOPCUBES, NUMOFBOTCUBES){
	numberOfTopCubes = NUMOFTOPCUBES;
	numberOfBotCubes = NUMOFBOTCUBES;
	setup();
}
void Number3::setup() { //create number3
	// hardcoded relative positions
	bottomComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 3.5f, 2.0f))); // right (bot)
	bottomComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, -0.035f, 0.0f)));
	
	bottomComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f))); // make base
	bottomComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, -0.05f, 0.0f))); // bottom

	bottomComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 1.0f, 2.0f)));
	bottomComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, -0.0075f, 0.0f))); // middle (bottom)

	topComponents[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 3.5f, 2.0f))); // right (top)
	topComponents[0].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.035f, 0.0f)));

	topComponents[1].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	topComponents[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.05f, 0.0f))); // top

	topComponents[2].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 1.0f, 2.0f)));
	topComponents[2].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0075f, 0.0f))); // middle (top)


	// setup hierarchy
	bottomComponents[1].updateChild(&bottomComponents[0]); // base
	bottomComponents[0].updateChild(&bottomComponents[2]);
	bottomComponents[2].updateChild(&topComponents[2]);
	updateBase(&bottomComponents[1]);
	topComponents[2].updateChild(&topComponents[0]); // base of the top
	topComponents[0].updateChild(&topComponents[1]);

	// set letter slightly above grid
	traverse(glm::translate(mat4(1.0f), vec3(0.0f, 0.07f, 0.0f)), 0);


	/*for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.07f, 0.0f)));
	}*/
}

Number3::~Number3() {
	// delete[] components;
	delete[] topComponents;
	delete[] bottomComponents;
}
