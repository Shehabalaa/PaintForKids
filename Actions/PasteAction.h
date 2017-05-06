#pragma once
#include "Action.h"
class PasteAction : public Action
{
	Point p, centroid;
public:
	PasteAction(ApplicationManager *);
	virtual ActionState ReadActionParameters();
	virtual void Execute();
	~PasteAction();

};