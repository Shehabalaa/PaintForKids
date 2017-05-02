#include"..\Actions\PickandHideAction.h"

PickandHideAction::PickandHideAction(ApplicationManager *pApp) :Action(pApp)
{
	pManager = pApp;
	click.x = 0;
	click.y = 0;
}

void  PickandHideAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose a Playing Mode ");
	PICKING_TYPE = pIn->GetUserAction();

	
	
	//pIn->GetPointClicked(click.x, click.y);
}

void PickandHideAction::Execute()
{
	pOut->CreatePickandHideToolBar();
	ReadActionParameters();
	if (PICKING_TYPE == PICK_TYPE)
	{
		pOut->CreatePickandHideFiguresToolBar();

		Figure =pIn->GetUserAction();
	}




}
PickandHideAction::~PickandHideAction()
{



}