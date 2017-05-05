#include "AddlineAction.h"
#include "../Figures/Cline.h"


AddlineAction::AddlineAction(ApplicationManager * pApp) : Action(pApp)
{}

void AddlineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("New Line: Click at first point");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(s.x, s.y);

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd corner and store in point P2
	pIn ->GetPointClicked(e.x, e.y);

	LineGfxInfo .isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWidth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddlineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	int figs_count = pManager->GetFigCount();
	//Create a rectangle with the parameters read from the user
	Cline *l = new Cline(s, e, LineGfxInfo);

	if (l->InDrawingArea())
		pManager->AddFigure(l);
	else pManager->GetOutput()->PrintMessage("out of the Drawing area ");
}



AddlineAction::~AddlineAction()
{
}
