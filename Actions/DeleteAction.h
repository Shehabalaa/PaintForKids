#pragma once
#include "Action.h"


class DeleteAction :public Action
{
public:
	DeleteAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~DeleteAction();

};
