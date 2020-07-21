#include "Sharon.h"

Sharon::Sharon() {
	components[0] = new LetterA();
	components[1] = new Number4();
	setup();
}

void Sharon::setup() {
	// set positions of number and letter relative to the center of the model
	components[0]->translate(glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)));
	components[1]->translate(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));

	// place model in predetermined position on grid
	components[0]->translate(glm::translate(mat4(1.0f), vec3(-0.75f, 0.01f, 0.75f))); // Translate to bottom left corner
	components[1]->translate(glm::translate(mat4(1.0f), vec3(-0.75f, 0.01f, 0.75f)));
}

void Sharon::draw(GLuint modelMatrixLocation) {
	// draw all components of model
	components[0]->draw(modelMatrixLocation);
	components[1]->draw(modelMatrixLocation);
}

Sharon::~Sharon() {

}