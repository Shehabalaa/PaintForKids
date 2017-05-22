#include "..\Actions\AddTriAction.h"
#include "../Figures/CTriangle.h"


AddTriAction::AddTriAction(ApplicationManager * pApp) : Action(pApp)
{}

ActionState AddTriAction::ReadActionParameters()
{
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


	return Successful;
}

void AddTriAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() < pManager->GetMaxFigCount())
	{
		ReadActionParameters();

		int figs_count = pManager->GetFigCount();
		CTriangle *t = new CTriangle(c1, c2, c3, TriGfxInfo);

		if (t->InDrawingArea())
		{
			t->SetID();
			pManager->AddFigure(t);
			pManager->AdjustList(DRAW_TRI);
		}
		else pManager->GetOutput()->PrintMessage("out of the Drawing area ");
	}
	else
	{
		pOut->PrintMessage("Can't Add More Figures as figures reached its maximumnumber");
	}
}

AddTriAction::~AddTriAction()
{
}
