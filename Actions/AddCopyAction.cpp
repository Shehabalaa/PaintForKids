#include"AddCopyAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

AddCopyAction::AddCopyAction(ApplicationManager * pApp) : Action(pApp)
{}
void AddCopyAction::Execute()
{
	pManager->ClipBoard.clear();
	pManager->CopyFigure();
}

void  AddCopyAction::ReadActionParameters()
{
}
AddCopyAction::~AddCopyAction()
{
}