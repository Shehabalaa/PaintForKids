#include "AddCircleAction.h"



AddCircleAction::AddCircleAction(ApplicationManager * pApp) : Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("New Circle: Click at the center");
	pIn->GetPointClicked(c.x, c.y);
	pOut->PrintMessage("New Circle: Click at the circumference");
	pIn->GetPointClicked(r.x, r.y);
	CircleGfxInfo.isFilled = false;					
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	CircleGfxInfo.BorderWidth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	ReadActionParameters();
	int figs_count = pManager->GetFigCount();
	
	CCircle *cir = new CCircle(c, r, CircleGfxInfo, figs_count);
	if (cir->InDrawingArea())
		pManager->AddFigure(cir);
	else pManager->GetOutput()->PrintMessage("Out of the Drawing area ");
}



AddCircleAction::~AddCircleAction()
{
}

