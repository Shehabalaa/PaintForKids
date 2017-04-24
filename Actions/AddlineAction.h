#pragma once
#include "Action.h"

class AddlineAction : public Action
{
private:
	Point s, e; 
	GfxInfo LineGfxInfo;
public:
	AddlineAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddlineAction();

};

