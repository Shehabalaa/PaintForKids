#pragma once
#include "Action.h"


class AddTriAction : public Action
{
private:
	Point c1, c2, c3;
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager *pApp);

	virtual ActionState ReadActionParameters();
	virtual void Execute();

	~AddTriAction();

};

