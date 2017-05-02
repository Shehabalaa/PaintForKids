#include"CutAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

CutAction::CutAction(ApplicationManager * pApp) : Action(pApp)
{}
void CutAction::Execute()
{
	pManager->CutAll();
}

void  CutAction::ReadActionParameters()
{
}
CutAction::~CutAction()
{
}