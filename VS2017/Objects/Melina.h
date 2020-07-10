#include "LetterL.h"
#include "Number9.h"

class Melina {
public:
	Melina();
	~Melina();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);
private:
	LetterL letter;
	Number9 number;
	mat4 worldMatrix;
};