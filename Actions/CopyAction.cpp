#include"CopyAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

CopyAction::CopyAction(ApplicationManager * pApp) : Action(pApp)
{}
void CopyAction::Execute()
{
	if(pManager->countselected())
		pManager->CopyAll();
	else
	{
		pManager->GetOutput()->PrintMessage("No Slected Figures to be Copied");
		Sleep(1000);
	}
}

ActionState  CopyAction::ReadActionParameters()
{
	return Successful;
}
CopyAction::~CopyAction()
{
}