#pragma once
#include "Action.h"
#include "..\Actions\PickByTypeAction.h"
#include"PickByFillingColorAction.h"
class PickandHideAction : public Action
{
	Point click;
	ActionType PICKING_TYPE;
	Colors ByColor;
	figures fig;
	color  Color;
	Action * mode;
	bool Filled;
	CFigure ** PickList;
	int size;
	
public:
	PickandHideAction(ApplicationManager *pApp);
	virtual ActionState ReadActionParameters();
	~PickandHideAction();
	int CountFigure(figures);
	int CountFigure(color, bool);
	void InitData();
	int Getsize();
	void DeletePickedFigure(CFigure *);
	CFigure *GetFigure(int x, int y) const;
	void UpdateInterface() const;
	//Execute action (code depends on action type)
	virtual void Execute();
};
