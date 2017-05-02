#pragma once
#include"Action.h"
class ToPlayAction :public Action
{
public:
	ToPlayAction(ApplicationManager *pApp);
	~ToPlayAction();
	virtual void Execute();
	virtual void ReadActionParameters();

};

