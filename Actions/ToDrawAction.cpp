#include "ToDrawAction.h"

ToDrawAction::ToDrawAction(ApplicationManager *pApp):Action(pApp)
{
}


void ToDrawAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	UI.InterfaceMode = MODE_DRAW;
	pOut->CreateDrawToolBar();
	pOut->PrintMessage("Welcome to DrawMode");

	if (pManager->IsFigListRandomized)
	{
		pManager->CleanFiglist();
		pManager->IsFigListRandomized = false;
	}
}

ActionState ToDrawAction::ReadActionParameters()
{
	return Successful;
}


ToDrawAction::~ToDrawAction()
{
}