#include"PasteAction.h"
#include "..\ApplicationManager/ApplicationManager.h"

PasteAction::PasteAction(ApplicationManager * pApp) : Action(pApp)
{}
void PasteAction::Execute()
{
	ReadActionParameters();
	pManager->PasteAll(p);
	
}
void  PasteAction::ReadActionParameters()
{
	pOut->PrintMessage("Please Select target Point");
	pIn->GetPointClicked(p.x,p.y);
}
PasteAction::~PasteAction()
{
	
	pIn->GetPointClicked(p.x, p.y);
}