#pragma once
#include "Cube.h"

class AlphaNumeric {
public:
    // pure virtual functions
    // makes sure that all the letters and numbers we create have the same base functions
    virtual void setup() = 0; // set up position and shape of cubes for the model
    virtual void concatModelMatrix(mat4 mat) = 0; // apply transformation to all cubes (trans, rot, scale)
    virtual mat4 getModelMatrix() = 0; // get matrix of model (position & transformations) in world space 
    virtual void draw(GLuint worldMatrixLocation) = 0; // render model cube by cube

    void updateModelMatrix();
    void translate(mat4 mat);
    void scale(mat4 mat);
    void rotate(mat4 mat);

    virtual int getVAO();
private:
    mat4 modelMatrix;
    mat4 translationMatrix = mat4(1.0f);
    mat4 scalingMatrix = mat4(1.0f);
    mat4 rotationMatrix = mat4(1.0f);
};

void AlphaNumeric::updateModelMatrix() {
    modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
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