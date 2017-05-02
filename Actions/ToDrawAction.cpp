#include "ToDrawAction.h"

ToDrawAction::ToDrawAction(ApplicationManager *pApp):Action(pApp)
{
}


void ToDrawAction::Execute()
{
	UI.InterfaceMode = MODE_DRAW;
	pOut->PrintMessage("Welcome to DrawMode");
}

void ToDrawAction::ReadActionParameters()
{
}


ToDrawAction::~ToDrawAction()
{
}