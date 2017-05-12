#ifndef CNGCOLOR
#define CNGCOLOR
#include "..\Actions\Action.h"
class CNGcolor : public Action
{
private :
                           
	color Colour;
public:
	CNGcolor( ApplicationManager *pApp);
	virtual ActionState ReadActionParameters();
	virtual void Execute() ;
	~CNGcolor();
};
#endif