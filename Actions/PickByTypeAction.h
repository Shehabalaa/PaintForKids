#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include"PickandHideAction.h"
class PickByTypeAction : public Action
{
	Point click;
	int RightCount;
	int WrongCount;
	figures type;
	int PickedFigureNumber;
	bool Filled;
	int size;
	CFigure** PickList;
	
public:
	
	PickByTypeAction(ApplicationManager *pApp, CFigure **, int&,figures);
	virtual ActionState ReadActionParameters();
	~PickByTypeAction();
	
	virtual void Execute();
};
