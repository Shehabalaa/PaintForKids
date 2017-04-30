#pragma once
#include "Action.h"
class AddPasteAction : public Action
{
public:
	AddPasteAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddPasteAction();

};