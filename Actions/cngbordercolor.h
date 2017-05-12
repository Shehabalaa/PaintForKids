#ifndef CNGBORDERCOLOR
#define CNGBORDERCOLOR
#include "..\Actions\Action.h"
class CNGborderColor : public Action
{
private :
                           //What is difference between enum Colors and class Color
	color Colour;
public:
	CNGborderColor( ApplicationManager *pApp);
	virtual ActionState ReadActionParameters();
	virtual void Execute() ;
	~CNGborderColor();
};
#endif