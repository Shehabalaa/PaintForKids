#pragma once
#include "Action.h"
#include "..\Actions\PickByTypeAction.h"
#include"PickByFillingColorAction.h"
#include"Pick_By_Area.h"
#include "..\Actions\PickByTypeAction.h"
#include"PickByFillingColorAction.h"
#include"PickBy_Type_and_FillingColor.h"
#include"ToPlayAction.h"
class PickandHideAction : public Action
{
	Point click;
	ActionType PICKING_TYPE;
	Colors ByColor;
	figures fig;
	color  Color;
	Action * mode;
	bool Filled;
	CFigure ** PickList;
	int size;
	
public:
	PickandHideAction(ApplicationManager *pApp);
	virtual ActionState ReadActionParameters();
	~PickandHideAction();

	void InitData();
	int Getsize();

	
	//Execute action (code depends on action type)
	virtual void Execute();
};
