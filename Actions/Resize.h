#pragma once
#include "..\Actions\Action.h"


class Resize : public Action 
{
private:
	float ResizeRatio;
public :
	Resize(ApplicationManager * pApp );    //constructor
		// read resize parameters 
	virtual void ReadActionParameters();
	
	//resize (chaange the figures dimentions in figure list in application manager)
	virtual void Execute() ;
	~Resize();
};