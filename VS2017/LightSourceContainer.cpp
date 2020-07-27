#include "LightSourceContainer.h"

LightSourceContainer::LightSourceContainer(glm::vec3* lightSourcePosition) {
	this->lightSourcePosition = *lightSourcePosition;
	components[0] = new LightCube();
	setup();
}

void LightSourceContainer::setup() {
	// set positions of number and letter relative to the center of the model

	mat4 initialDisplacement = glm::translate(mat4(1.0f), this->lightSourcePosition);
	modelMatrix = initialDisplacement * modelMatrix;
	// place model in predetermined position on grid
	components[0]->translateModel(initialDisplacement); // Translate to top left corner
}

void LightSourceContainer::draw(GLuint modelMatrixLocation) {
	// draw all components of model
	components[0]->draw(modelMatrixLocation);
}

LightSourceContainer::~LightSourceContainer() {

}