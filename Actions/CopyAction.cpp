#include"CopyAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

CopyAction::CopyAction(ApplicationManager * pApp) : Action(pApp)
{}
void CopyAction::Execute()
{
	pManager->CopyAll();
}

ActionState  CopyAction::ReadActionParameters()
{
	return Successful;
}
CopyAction::~CopyAction()
{
}