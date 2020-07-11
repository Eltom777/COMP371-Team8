#include "LetterI.h"
#include "Number3.h"

class Anissa : public AlphaNumeric
{
	public: 
		Anissa();
		~Anissa();
		void setup();
		void concatWorldMatrix(mat4 mat);
		mat4 getWorldMatrix();
		void draw(GLuint worldMatrixLocation);

	private:
		LetterI letter;
		Number3 number;
		mat4 worldMatrix;
};