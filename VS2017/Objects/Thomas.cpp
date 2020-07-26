#include "Thomas.h"

Thomas::Thomas() {
	components[0] = new LetterO();
	components[1] = new Number3();
	setup();
}

void Thomas::setup() {
	// set positions of number and letter relative to the center of the model
	components[0]->translateModel(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));
	components[1]->translateModel(glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)));

	mat4 initialDisplacement = glm::translate(mat4(1.0f), vec3(-0.75f, 0.01f, -0.75f));
	modelMatrix = initialDisplacement * modelMatrix;
	// place model in predetermined position on grid
	components[0]->translateModel(initialDisplacement); // Translate to top left corner
	components[1]->translateModel(initialDisplacement);
	sphere->translateModel(initialDisplacement);
}

Thomas::~Thomas() {

}