#pragma once
#include "Action.h"

class addlineaction : public Action
{
private:
	Point s, e; 
	GfxInfo LineGfxInfo;
public:
	addlineaction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	~addlineaction();

};

