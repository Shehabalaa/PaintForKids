#pragma once
#include"Action.h"
class ToDrawAction:public Action
{
public:
	ToDrawAction(ApplicationManager *pApp);
	~ToDrawAction();
	virtual void Execute();
	virtual void ReadActionParameters();
};

