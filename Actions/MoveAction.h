
#pragma once
#include "Action.h"





class MoveAction : public Action
{
	Point present;
	Point next;
	Point diff; // space to be moved 
public:
	MoveAction(ApplicationManager *pApp);
	
	virtual ActionState ReadActionParameters();
	~MoveAction();
	//Execute action (code depends on action type)
	virtual void Execute();
};