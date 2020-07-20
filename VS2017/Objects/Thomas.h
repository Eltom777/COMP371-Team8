#include "LetterO.h"
#include "Number3.h"

class Thomas : public AlphaNumeric {
public :
	Thomas();
	~Thomas();
	void setup();
	void concatModelMatrix(mat4 mat);
	mat4 getModelMatrix();
	void draw(GLuint modelMatrixLocation);
private :
	LetterO letter;
	Number3 number;
	mat4 modelMatrix;
};