#include"PasteAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

PasteAction::PasteAction(ApplicationManager * pApp) : Action(pApp)
{}
void PasteAction::Execute()
{

	pManager->PasteAll();
}
void  PasteAction::ReadActionParameters()
{

}
PasteAction::~PasteAction()
{
}