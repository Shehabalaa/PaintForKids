#pragma once
#include "Action.h"


class ScrampleAndFindAction : public Action
{
private:
	int ListSize; // size of two list randomized and not randomized
	CFigure ** RandomizdList; // randmized list of figures
	CFigure **NormalList; // NormaLlist of figures
	int GetIndexOfFutureHighLighted();
	int GetFigureIDinRandomList(int x,int y);
	void DeleteFigureFromBothLists(int ID);
public:
	ScrampleAndFindAction(ApplicationManager*);
	virtual ActionState ReadActionParameters();
	virtual void Execute();
	~ScrampleAndFindAction();

};