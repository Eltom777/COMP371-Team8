#include "LetterA.h"
#include "Number4.h"

class Sharon : public AlphaNumeric {
public:
	Sharon();
	~Sharon();
	void setup();
	void concatWorldMatrix(mat4 mat);
	mat4 getWorldMatrix();
	void draw(GLuint worldMatrixLocation);
private:
	LetterA letter;
	Number4 number;
	mat4 worldMatrix;
};