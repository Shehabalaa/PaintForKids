#pragma once
#include "Action.h"


class DeleteAction :public Action
{
public:
	DeleteAction(ApplicationManager *);
	virtual ActionState ReadActionParameters();
	virtual void Execute();
	~DeleteAction();

};
