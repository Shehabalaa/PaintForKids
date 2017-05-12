#ifndef CNGBORDERWIDTH
#define CNGBORDERWIDTH
#include "..\Actions\Action.h"
class CNGborderwidth : public Action
{
private :
                           
	int Pen;
public:
	CNGborderwidth( ApplicationManager *pApp);
	virtual ActionState ReadActionParameters();
	virtual void Execute() ;
	~CNGborderwidth();
};
#endif