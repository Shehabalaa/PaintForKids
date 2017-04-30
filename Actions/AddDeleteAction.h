#pragma once
#include "Action.h"


class AddDeleteAction :public Action
{
public:
	AddDeleteAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddDeleteAction();

};
