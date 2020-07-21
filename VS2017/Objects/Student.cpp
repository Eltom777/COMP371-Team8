#include "Student.h"

void Student::updateModelMatrix() {
	for (AlphaNumeric* component : components) {
		component->updateModelMatrix();
	}
}

void Student::translate(mat4 t) {
	for (AlphaNumeric* component : components) {
		component->translate(t);
	}
}

void Student::scale(mat4 t) {
	for (AlphaNumeric* component : components) {
		component->scale(t);
	}
}

void Student::rotate(mat4 t) {
	for (AlphaNumeric* component : components) {
		component->rotate(t);
	}
}