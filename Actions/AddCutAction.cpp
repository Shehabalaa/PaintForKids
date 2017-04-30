#include"AddCutAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

AddCutAction::AddCutAction(ApplicationManager * pApp) : Action(pApp)
{}
void AddCutAction::Execute()
{
	pManager->CutFigure();
}

void  AddCutAction::ReadActionParameters()
{
}
AddCutAction::~AddCutAction()
{
}