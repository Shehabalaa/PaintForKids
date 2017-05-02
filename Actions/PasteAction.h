#pragma once
#include "Action.h"
class PasteAction : public Action
{
public:
	PasteAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PasteAction();

};