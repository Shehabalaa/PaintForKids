#pragma once
#include "Action.h"

class AddTriAction : public Action
{
private:
	Point s, e;
	GfxInfo LineGfxInfo;
public:
	AddTriAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	AddTriAction();

};

