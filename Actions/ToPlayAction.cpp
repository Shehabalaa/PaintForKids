#include "ToPlayAction.h"

ToPlayAction::ToPlayAction(ApplicationManager *pApp) :Action(pApp)
{
}


void ToPlayAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	UI.InterfaceMode = MODE_PLAY;
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("Welcome to PlayMode");
}

ActionState ToPlayAction::ReadActionParameters()
{
	return Successful;
}


ToPlayAction::~ToPlayAction()
{
}