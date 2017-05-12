#pragma once
#include "Action.h"

//Picks Figure By Filling color
class ByFillingColor : public Action
{
private:
	color Color;
	Colors co;
	int RightCount;
	int WrongCount;
	int PickedFigureNumber;
	bool fill;
	Point click;
public:
	ByFillingColor(ApplicationManager *pApp,color,bool);

	
	virtual ActionState ReadActionParameters();

	
	virtual void Execute();
	~ByFillingColor();
};

