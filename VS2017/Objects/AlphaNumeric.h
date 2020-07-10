#pragma once
#include "Cube.h"

class AlphaNumeric {
public:
    // pure virtual functions
    virtual void setup() = 0;
    virtual void concatWorldMatrix(mat4 mat) = 0;
    virtual mat4 getWorldMatrix() = 0;
    virtual void draw(GLuint worldMatrixLocation) = 0;
};