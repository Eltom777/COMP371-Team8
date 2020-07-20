#include "LetterA.h"
#include "Number4.h"

class Sharon : public AlphaNumeric {
public:
	Sharon();
	~Sharon();
	void setup();
	void concatModelMatrix(mat4 mat);
	mat4 getModelMatrix();
	void draw(GLuint modelMatrixLocation);
private:
	LetterA letter;
	Number4 number;
	mat4 modelMatrix;
};