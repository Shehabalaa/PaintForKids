#pragma once

#include "Action.h"
class CopyAction : public Action
{
public:
	CopyAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CopyAction();

};