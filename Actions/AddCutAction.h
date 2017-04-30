#pragma once
#include "Action.h"
class AddCutAction : public Action
{
public:
	AddCutAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddCutAction();

};
