#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickByTypeAction : public Action
{
	Point click;
	int RightCount;
	int WrongCount;
	figures type;
	int PickedFigureNumber;
	bool Filled;
public:
	
	PickByTypeAction(ApplicationManager *pApp,figures);
	virtual ActionState ReadActionParameters();
	~PickByTypeAction();
	
	virtual void Execute();
};
