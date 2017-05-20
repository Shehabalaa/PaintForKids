#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include"PickandHideAction.h"
class PickByTypeandFillingColorAction : public Action
{
	Point click;
	int RightCount;
	int WrongCount;
	figures type;
	int PickedFigureNumber;
	//bool Filled;
	int size;
	CFigure** PickList;
	///////////
	color Color;
	//Colors co;
	bool fill;
	
public:

	PickByTypeandFillingColorAction(ApplicationManager *pApp, CFigure ** PickList, int &size, figures Type, color c, bool Filled);
	virtual ActionState ReadActionParameters();
	~PickByTypeandFillingColorAction();

	virtual void Execute();
};

