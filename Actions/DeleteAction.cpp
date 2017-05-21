#include"DeleteAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) : Action(pApp)
{}

void DeleteAction::Execute()
{
	if (pManager->countselected())
	{
		if (pManager->GetFigCount())
			pManager->DeleteAll();
	}
	else
	{
		pManager->GetOutput()->PrintMessage("No Slected Figures to be Deleted");
		Sleep(1000);
	}
	

}

ActionState  DeleteAction::ReadActionParameters()
{
	return Successful;
}

DeleteAction::~DeleteAction()
{
}