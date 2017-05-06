#pragma once

#include "Action.h"





class ChangeBGAction : public Action
{
	Colors co;

public:
	ChangeBGAction(ApplicationManager *pApp);
	
	virtual ActionState ReadActionParameters();
	~ChangeBGAction();
	//Execute action (code depends on action type)
	virtual void Execute();
};
