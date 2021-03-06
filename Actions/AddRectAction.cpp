#include "AddRectAction.h"
#include "../Figures/CRectangle.h"


AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{
}

ActionState AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	if (UI.FilledFigures)
		RectGfxInfo.isFilled =true;	//default is not filled
	else RectGfxInfo.isFilled=false;
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWidth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
	return Successful;
}

//Execute the action
void AddRectAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() < pManager->GetMaxFigCount())
	{
		//This action needs to read some parameters first
		ReadActionParameters();

		//Create a rectangle with the parameters read from the user
		CRectangle *R = new CRectangle(P1, P2, RectGfxInfo);

		if (R->InDrawingArea())
		{
			R->SetID();
			pManager->AddFigure(R);
			pManager->AdjustList(DRAW_RECT);
		}
		else pManager->GetOutput()->PrintMessage("out of the Drawing area ");

	}
	else
	{
		pOut->PrintMessage("Can't Add More Figures as figures reached its maximumnumber");
	}
	
}
