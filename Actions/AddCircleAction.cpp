#include "AddCircleAction.h"
#include "../Figures/CCircle.h"


AddCircleAction::AddCircleAction(ApplicationManager * pApp) : Action(pApp)
{}

ActionState AddCircleAction::ReadActionParameters()
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

	return Successful;

}

//Execute the action
void AddCircleAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() < pManager->GetMaxFigCount())
	{
		ReadActionParameters();

		CCircle *cir = new CCircle(c, r, CircleGfxInfo);
		if (cir->InDrawingArea())
		{
			cir->SetID();
			pManager->AddFigure(cir);
			pManager->AdjustList(DRAW_CIRC);
		}
		else 
			pOut->PrintMessage("Out of the Drawing area ");
	}
	else
	{
		pOut->PrintMessage("Can't Add More Figures as figures reached its maximumnumber");
	}
}



AddCircleAction::~AddCircleAction()
{
}

