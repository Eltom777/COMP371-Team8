#include "LetterV.h"
#include "Number0.h"

class Keven : public AlphaNumeric {
public:
	Keven();
	~Keven();
	void setup();
	void concatModelMatrix(mat4 mat);
	mat4 getModelMatrix();
	void draw(GLuint modelMatrixLocation);
private:
	LetterV letter;
	Number0 number;
	mat4 modelMatrix;
};