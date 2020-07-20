#include "LetterI.h"
#include "Number3.h"

class Anissa : public AlphaNumeric
{
	public: 
		Anissa();
		~Anissa();
		void setup();
		void concatModelMatrix(mat4 mat);
		mat4 getModelMatrix();
		void draw(GLuint modelMatrixLocation);

	private:
		LetterI letter;
		Number3 number;
		mat4 modelMatrix;
};