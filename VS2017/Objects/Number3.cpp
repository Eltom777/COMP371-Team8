#include "Number3.h"

Number3::Number3() : AlphaNumeric(NUMOFCUBES){
	numberOfCubes = NUMOFCUBES;
	setup();
}

void Number3::setup() { //create number3
	// hardcoded relative positions
	components[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));

	components[1].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.05f, 0.0f)));

	components[2].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[2].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)));

	components[3].updateScale(glm::scale(mat4(1.0f), vec3(3.0f, 2.0f, 2.0f)));
	components[3].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, -0.05f, 0.0f)));

	// set letter slightly above grid
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.07f, 0.0f)));
	}
}

Number3::~Number3() {
	delete[] components;
}
