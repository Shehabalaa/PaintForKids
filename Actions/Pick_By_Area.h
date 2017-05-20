#pragma once
#include "Action.h"

//Picks Figure By Area
class PickByArea : public Action
{
private:
	
	int RightCount;
	int WrongCount;
	int PickedFigureNumber;
	pair<int, CFigure*> MAX;
	Point click;
	CFigure ** PickList;
	int size;
public:
	PickByArea(ApplicationManager *pApp, CFigure ** PickList, int &size);


	virtual ActionState ReadActionParameters();


	virtual void Execute();
	~PickByArea();
};

