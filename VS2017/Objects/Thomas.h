#include "LetterO.h"
#include "Number3.h"

class Thomas : public AlphaNumeric {
public :
	Thomas();
	~Thomas();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);
private :
	LetterO letter;
	Number3 number;
	mat4 worldMatrix;
};