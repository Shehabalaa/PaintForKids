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
}

ActionState ToDrawAction::ReadActionParameters()
{
	return Successful;
}


ToDrawAction::~ToDrawAction()
{
}