#include"PasteAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

PasteAction::PasteAction(ApplicationManager * pApp) : Action(pApp)
{}
void PasteAction::Execute()
{
	if (pManager->GetClipBoardSize())
	{
		ReadActionParameters();
		pManager->PasteAll(p);
	}
	else
	{
		pManager->GetOutput()->PrintMessage("No Figures In Clipboard to be pasted");
		Sleep(1000);
	}

	
}
ActionState PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Select target Point");
	pIn->GetPointClicked(p.x,p.y);

	return Successful;
}
PasteAction::~PasteAction()
{
}