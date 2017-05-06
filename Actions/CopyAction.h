#pragma once

#include "Action.h"
class CopyAction : public Action
{
public:
	CopyAction(ApplicationManager *);
	virtual ActionState ReadActionParameters();
	virtual void Execute();
	~CopyAction();

};