#include "AlphaNumeric.h"

mat4 AlphaNumeric::getModelMatrix() {
	return modelMatrix;
}

void AlphaNumeric::translate(mat4 t) {
	translationMatrix = t * translationMatrix;
	updateModelMatrix();
}

void AlphaNumeric::scale(mat4 t) {
	scalingMatrix = t * scalingMatrix;
	updateModelMatrix();
}

void AlphaNumeric::rotate(mat4 t) {
	rotationMatrix = t * rotationMatrix;
	updateModelMatrix();
}