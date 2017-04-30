#pragma once
#include "Action.h"
class PickandHideAction : public Action
{
	Point click;
	ActionType PICKING_TYPE;
	ActionType Figure;
	color ByColor;
	
public:
	PickandHideAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	~PickandHideAction();
	//Execute action (code depends on action type)
	virtual void Execute();
};
