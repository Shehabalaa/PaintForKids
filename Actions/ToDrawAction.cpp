#include "ToDrawAction.h"

ToDrawAction::ToDrawAction(ApplicationManager *pApp):Action(pApp)
{
}


void ToDrawAction::Execute()
{
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