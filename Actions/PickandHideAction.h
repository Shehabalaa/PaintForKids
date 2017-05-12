#pragma once
#include "Action.h"
#include "..\Actions\PickByTypeAction.h"
#include"PickByFillingColorAction.h"
class PickandHideAction : public Action
{
	Point click;
	ActionType PICKING_TYPE;
	Colors ByColor;
	figures fig;
	color  Color;
	Action * mode;
	bool Filled;
	
public:
	PickandHideAction(ApplicationManager *pApp);
	virtual ActionState ReadActionParameters();
	~PickandHideAction();
	void InitData();
	//Execute action (code depends on action type)
	virtual void Execute();
};
