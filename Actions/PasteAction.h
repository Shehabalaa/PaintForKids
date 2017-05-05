#pragma once
#include "Action.h"
class PasteAction : public Action
{
	Point p, centroid;
public:
	PasteAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PasteAction();

};