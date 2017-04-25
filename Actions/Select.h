#pragma once
#include "Action.h"

class ActionSelect : public Action
{
	Point m;
public:
	ActionSelect(ApplicationManager *pApp);
	int countselect();
	virtual void ReadActionParameters();
	~ActionSelect();
	//Execute action (code depends on action type)
	virtual void Execute();
};