#include"CopyAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

CopyAction::CopyAction(ApplicationManager * pApp) : Action(pApp)
{}
void CopyAction::Execute()
{
	pManager->CopyAll();
}

void  CopyAction::ReadActionParameters()
{
}
CopyAction::~CopyAction()
{
}