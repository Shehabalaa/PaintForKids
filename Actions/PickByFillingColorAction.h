#pragma once
#include "Action.h"

//Picks Figure By Filling color
class ByFillingColor : public Action
{
private:
	color Color;
	int RightCount;
	int WrongCount;
	int PickedFigureNumber;
	bool fill;
	Point click;
	CFigure ** PickList;
	int size;
public:
	ByFillingColor(ApplicationManager *pApp, CFigure ** PickList, int &size, color,bool);
	
	virtual ActionState ReadActionParameters();

	virtual void Execute();
	~ByFillingColor();
};

