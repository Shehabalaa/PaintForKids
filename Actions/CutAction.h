#pragma once
#include "Action.h"
class CutAction : public Action
{
public:
	CutAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CutAction();

};
