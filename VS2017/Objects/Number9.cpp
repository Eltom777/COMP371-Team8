#include "Number9.h"
#include <iostream>

Number9::Number9() : AlphaNumeric(NUMOFCUBES) {
	numberOfCubes = NUMOFCUBES;
	setup();
}

void Number9::setup() { //create number 9
	// hardcoded relative positions
	components[0].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 3.0f, 2.0f)));
	components[0].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.08f, 0.03f, 0.0f)));// left edge

	components[1].updateScale(glm::scale(mat4(1.0f), vec3(4.0f, 2.0f, 2.0f)));
	components[1].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f)));// bottom edge

	components[2].updateScale(glm::scale(mat4(1.0f), vec3(5.0f, 2.0f, 2.0f)));
	components[2].updateTranslation(glm::translate(mat4(1.0f), vec3(-0.04f, 0.06f, 0.0f))); // top edge

	components[3].updateScale(glm::scale(mat4(1.0f), vec3(2.0f, 7.0f, 2.0f)));
	components[3].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f))); // right edge

	components[0].updateChild(&components[2]);
	//components[2].sibling = &components[1];
	components[2].updateChild(&components[3]);
	components[3].updateChild(&components[1]);

	std::cout << "base " << &components[0] << " and child " << components[0].getChild() << "\n";
	std::cout << "base " << &components[2] << " and child " << components[2].getChild() << "\n";
	std::cout << "base " << &components[3] << " and child " << components[3].getChild() << "\n";
	std::cout << "base " << &components[1] << " and child " << components[1].getChild() << "\n";
	std::cout << "\n";

	// set letter slightly above grid
	for (int i = 0; i < NUMOFCUBES; i++) {
		components[i].updateTranslation(glm::translate(mat4(1.0f), vec3(0.0f, 0.06f, 0.0f)));
	}
}

Number9::~Number9() {
	delete[] components;
}