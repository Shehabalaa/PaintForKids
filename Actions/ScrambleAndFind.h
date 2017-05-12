#pragma once
#include "Action.h"


class ScrampleAndFindAction : public Action
{
private:
	int ListSize; // size of two list randomized and not randomized
	CFigure ** RandomizdList; // randmized list of figures
	CFigure **NormalList; // NormaLlist of figures
	void GenerateNormalAndRandomLLists(); // this utillty func generate normal and random list in random way
public:
	ScrampleAndFindAction(ApplicationManager*);
	virtual ActionState ReadActionParameters();
	virtual void Execute();
	~ScrampleAndFindAction();

};