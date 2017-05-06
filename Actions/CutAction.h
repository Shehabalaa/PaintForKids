#pragma once
#include "Action.h"
class CutAction : public Action
{
public:
	CutAction(ApplicationManager *);
	virtual ActionState ReadActionParameters();
	virtual void Execute();
	~CutAction();

};
