#include"..\Actions\PickandHideAction.h"

PickandHideAction::PickandHideAction(ApplicationManager *pApp) :Action(pApp)
{
	pManager = pApp;
	click.x = 0;
	click.y = 0;
}

void PickandHideAction::InitData()
{
	
	CFigure * FirstFigure = NULL;
	do {
		if (pManager->GetFigCount() == 0)
			break;
		pOut->PrintMessage("Pick The First Figure  ");
		pIn->GetPointClicked(click.x, click.y);
		FirstFigure =pManager->GetFigure(click.x, click.y);
		
	} while (FirstFigure == NULL);
		
		fig=FirstFigure->FigType();
		if (FirstFigure->IsFilled())
		{
			Filled = true;
			Color = FirstFigure->GetFillClr();
		}

		else
		{
			Filled = false;
		}

		pManager->DeletePickedFigure(FirstFigure);
		pManager->UpdateInterface();

}

ActionState  PickandHideAction::ReadActionParameters()
{
	
	pOut->PrintMessage("Choose a Playing Mode ");
	PICKING_TYPE = pIn->GetUserAction();


	return Successful;
}

void PickandHideAction::Execute()
{
	UI.InterfaceMode = MODE_PICKANDHIDE;
	pOut->CreatePickandHideToolBar();
	pOut->PrintMessage("Pick------&-----Hide");
	ReadActionParameters();
	InitData();
	
		
	if (PICKING_TYPE == PICK_TYPE)
	{

		mode = new PickByTypeAction(pManager,fig );
		mode->Execute();

	}
	else if (PICKING_TYPE == PICK_FILL)
	{

		

		mode = new ByFillingColor(pManager,Color,Filled);
		mode->Execute();
	}
	else if (PICKING_TYPE == PICK_TYPEFILL)
	{
		//
	}

	else if (PICKING_TYPE == PICK_AREA)
	{

		//
	}


}
PickandHideAction::~PickandHideAction()
{

}