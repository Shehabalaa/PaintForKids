#include"..\Figures\CTriangle.h"
#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager\ApplicationManager.h"
#include"..\Actions\Action.h"
#include "..\Actions\AddTriAction.h"


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
	TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

void AddTriAction::Execute()
{
	ReadActionParameters();

	int fig = pManager->GetFigCount();
	CTriangle *t = new CTriangle(c1, c2, c3, TriGfxInfo,fig);

	if (t->InDrawingArea())
		pManager->AddFigure(t);
	else pManager->GetOutput()->PrintMessage("out of the Drawing area ");
}

AddTriAction::~AddTriAction()
{
}
