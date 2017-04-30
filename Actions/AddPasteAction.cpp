#include"AddPasteAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

AddPasteAction::AddPasteAction(ApplicationManager * pApp) : Action(pApp)
{}
void AddPasteAction::Execute()
{

	pManager->PasteFigure();
}
void  AddPasteAction::ReadActionParameters()
{

}
AddPasteAction::~AddPasteAction()
{
}