#include"CutAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

CutAction::CutAction(ApplicationManager * pApp) : Action(pApp)
{}
void CutAction::Execute()
{
	pManager->CutAll();
}

ActionState CutAction::ReadActionParameters()
{
	return Successful;
}
CutAction::~CutAction()
{
}