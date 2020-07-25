#include "Keven.h"

Keven::Keven() {
	components[0] = new LetterV();
	components[1] = new Number0();
	setup();
}

void Keven::setup() {
	// set positions of number and letter relative to the center of the model
	components[0]->translateModel(glm::translate(mat4(1.0f), vec3(-0.1f, 0.0f, 0.0f)));
	components[1]->translateModel(glm::translate(mat4(1.0f), vec3(0.1f, 0.0f, 0.0f)));

	mat4 initialDisplacement = glm::translate(mat4(1.0f), vec3(0.0f, 0.01f, -0.05f));
	modelMatrix = initialDisplacement * modelMatrix;
	// place model in predetermined position on grid
	components[0]->translateModel(initialDisplacement); // Translate to top left corner
	components[1]->translateModel(initialDisplacement);
}

void Keven::draw(GLuint modelMatrixLocation) {
	// draw all components of model
	components[0]->draw(modelMatrixLocation);
	components[1]->draw(modelMatrixLocation);
}

Keven::~Keven() {

}