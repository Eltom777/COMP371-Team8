#include "Student.h"

void Student::updateModelMatrix() {
	for (AlphaNumeric* component : components) {
		component->updateModelMatrix();
	}
}

mat4 Student::getModelMatrix()
{
	return modelMatrix;
}

void Student::translate(mat4 t) {
	for (AlphaNumeric* component : components) {
		component->translateModel(t);
	}
}

void Student::scale(mat4 t) {
	for (AlphaNumeric* component : components) {
		component->translateModel(t);
	}
}

void Student::rotate(mat4 t) {
	for (AlphaNumeric* component : components) {
		component->translateModel(t);
	}
}