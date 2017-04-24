#include "AddCircleAction.h"
#include "..\ApplicationManager/ApplicationManager.h"
#include"..\Figures\CCircle.h"



AddCircleAction::AddCircleAction(ApplicationManager * pApp) : Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("New Line: Click at the center");
	pIn->GetPointClicked(c.x, c.y);
	pOut->PrintMessage("New Line: Click at the circumference");
	pIn->GetPointClicked(r.x, r.y);
	CircleGfxInfo.isFilled = false;					
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle *cir = new CCircle(c, r, CircleGfxInfo);
	if (cir->InDrawingArea())
		pManager->AddFigure(cir);
	else pManager->GetOutput()->PrintMessage("out of the Drawing area ");
}



AddCircleAction::~AddCircleAction()
{
}

