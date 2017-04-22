#pragma once
#include "Action.h"

class AddlineAction : public Action
{
private:
	Point s, e; 
	GfxInfo LineGfxInfo;
public:
	AddlineAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	~AddlineAction();

};

