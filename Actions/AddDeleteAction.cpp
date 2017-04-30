#include"AddDeleteAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

AddDeleteAction::AddDeleteAction(ApplicationManager * pApp) : Action(pApp)
{}
void AddDeleteAction::Execute()
{
	

	pManager->DeleteFigure();
}
void  AddDeleteAction::ReadActionParameters()
{

}

AddDeleteAction::~AddDeleteAction()
{
}