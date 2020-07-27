#include "Melina.h"
#include <iostream>

Melina::Melina() {
	components[0] = new LetterL();
	components[1] = new Number9();
	setup();
}

void Melina::setup() {
	// set positions of number and letter relative to the center of the model
	components[0]->translateModel(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)));
	components[1]->translateModel(glm::translate(mat4(1.0f), vec3(0.05f, 0.0f, 0.0f)));

	// place model in predetermined position on grid
	mat4 initialDisplacement = glm::translate(mat4(1.0f), vec3(0.75f, 0.01f, -0.75f));
	modelMatrix = initialDisplacement * modelMatrix;

	components[0]->translateModel(initialDisplacement); // Translate to top right corner
	components[1]->translateModel(initialDisplacement);

	sphere->translateModel(initialDisplacement);
	sphere->translateModel(glm::translate(mat4(1.0f), vec3(0.0f, 0.13f, 0.0f)));

	sphere->updateChild(&components[0]->topComponents[0]);
	(*&components[0]->topComponents[0]).updateChild(&components[1]->topComponents[0]);
	(*&components[0]->topComponents[0]).updateChild(&components[1]->topComponents[1]);
	(*&components[0]->topComponents[0]).updateChild(&components[1]->topComponents[2]);
}

Melina::~Melina() {

}