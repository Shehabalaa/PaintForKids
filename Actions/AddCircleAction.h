#pragma once
#include "Action.h"
#include "../Figures/CCircle.h"

class AddCircleAction : public Action
{
private:
	Point c, r;
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	~AddCircleAction();



};