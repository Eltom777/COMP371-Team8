#include "LetterV.h"
#include "Number0.h"

class Keven : public AlphaNumeric {
public:
	Keven();
	~Keven();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);
private:
	LetterV letter;
	Number0 number;
	mat4 worldMatrix;
};