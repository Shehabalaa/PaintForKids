#include"CutAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

CutAction::CutAction(ApplicationManager * pApp) : Action(pApp)
{}
void CutAction::Execute()
{
	if (pManager->countselected())
	{
		if (pManager->GetFigCount())
			pManager->CutAll();
	}
	else
	{
		pManager->GetOutput()->PrintMessage("No Slected Figures to be Cut");
		Sleep(1000);
	}

}

ActionState CutAction::ReadActionParameters()
{
	return Successful;
}
CutAction::~CutAction()
{
}