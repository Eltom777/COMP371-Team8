#include "LetterA.h"
#include "Number4.h"
#include "Student.h"

class Sharon : public Student {
public:
	Sharon();
	~Sharon();
	void setup();
	void draw(GLuint modelMatrixLocation);
	//int getVAO();
};