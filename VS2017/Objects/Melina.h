#include "LetterL.h"
#include "Number9.h"

class Melina : public AlphaNumeric {
public:
	Melina();
	~Melina();
	void setup();
	void concatModelMatrix(mat4 mat);
	mat4 getModelMatrix();
	void draw(GLuint modelMatrixLocation);
private:
	LetterL letter;
	Number9 number;
	mat4 modelMatrix;
};