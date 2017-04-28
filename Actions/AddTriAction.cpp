#include "..\Actions\AddTriAction.h"
#include "../Figures/CTriangle.h"


AddTriAction::AddTriAction(ApplicationManager * pApp) : Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("New Triangle: Click at first corner");
	pIn->GetPointClicked(c1.x, c1.y);
	pOut->PrintMessage("New Triangle: Click at second corner");
	pIn->GetPointClicked(c2.x, c2.y);
	pOut->PrintMessage("New Triangle: Click at third corner");
	pIn->GetPointClicked(c3.x, c3.y);
	TriGfxInfo.isFilled = false;
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.BorderWidth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

void AddTriAction::Execute()
{
	ReadActionParameters();

	int figs_count = pManager->GetFigCount();
	CTriangle *t = new CTriangle(c1, c2, c3, TriGfxInfo,figs_count);

	if (t->InDrawingArea())
		pManager->AddFigure(t);
	else pManager->GetOutput()->PrintMessage("out of the Drawing area ");
}

AddTriAction::~AddTriAction()
{
}
