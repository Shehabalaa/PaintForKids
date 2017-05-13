#include"DeleteAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) : Action(pApp)
{}

void DeleteAction::Execute()
{
	pManager->DeleteAll();

}

ActionState  DeleteAction::ReadActionParameters()
{
	return Successful;
}

DeleteAction::~DeleteAction()
{
}