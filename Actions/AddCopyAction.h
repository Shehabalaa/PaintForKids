#pragma once

#include "Action.h"
class AddCopyAction : public Action
{
public:
	AddCopyAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddCopyAction();

};