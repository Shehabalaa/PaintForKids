#include "ToPlayAction.h"

ToPlayAction::ToPlayAction(ApplicationManager *pApp) :Action(pApp)
{
}


void ToPlayAction::Execute()
{
	UI.InterfaceMode = MODE_PLAY;
	pOut->PrintMessage("Welcome to PlayMode");
}

void ToPlayAction::ReadActionParameters()
{
}


ToPlayAction::~ToPlayAction()
{
}