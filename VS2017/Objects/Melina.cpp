#include "Melina.h"

Melina::Melina() {
	components[0] = new LetterL();
	components[1] = new Number9();
	setup();
}

void Melina::setup() {
	// set positions of number and letter relative to the center of the model
	components[0]->translate(glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)));
	components[1]->translate(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));

	// place model in predetermined position on grid
	components[0]->translate(glm::translate(mat4(1.0f), vec3(0.75f, 0.01f, -0.75f))); // Translate to top right corner
	components[1]->translate(glm::translate(mat4(1.0f), vec3(0.75f, 0.01f, -0.75f)));
}

void Melina::draw(GLuint modelMatrixLocation) {
	// draw all components of model
	components[0]->draw(modelMatrixLocation);
	components[1]->draw(modelMatrixLocation);
}

Melina::~Melina() {

}