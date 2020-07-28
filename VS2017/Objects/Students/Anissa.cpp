#include "Anissa.h"

Anissa::Anissa() {
	components[0] = new LetterI();
	components[1] = new Number3();
	setup();
}

void Anissa::setup() {
	// set positions of number and letter relative to the center of the model
	components[0]->translateModel(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));
	components[1]->translateModel(glm::translate(mat4(1.0f), vec3(0.01f, 0.0f, 0.0f)));

	mat4 initialDisplacement = glm::translate(mat4(1.0f), vec3(0.75f, 0.01f, 0.75));
	modelMatrix = initialDisplacement * modelMatrix;
	// place model in predetermined position on grid
	components[0]->translateModel(initialDisplacement);
	components[1]->translateModel(initialDisplacement);
	sphere->translateModel(initialDisplacement);
	sphere->translateModel(glm::translate(mat4(1.0f), vec3(0.0f, 0.15f, 0.0f)));
}

Anissa::~Anissa() {

}