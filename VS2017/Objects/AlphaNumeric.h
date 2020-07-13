#pragma once
#include "Cube.h"

class AlphaNumeric {
public:
    // pure virtual functions
    // makes sure that all the letters and numbers we create have the same base functions
    virtual void setup() = 0; // set up position and shape of cubes for the model
    virtual void concatWorldMatrix(mat4 mat) = 0; // apply transformation to all cubes (trans, rot, scale)
    virtual mat4 getWorldMatrix() = 0; // get matrix of model (position & transformations) in world space 
    virtual void draw(GLuint worldMatrixLocation) = 0; // render model cube by cube
};