#pragma once
#include "Action.h"



class ActionSelect : public Action
{
	Point m;
public:
	ActionSelect(ApplicationManager *pApp);
	int countselect();
	ActionState ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	~ActionSelect();

};