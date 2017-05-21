#include"..\Actions\PickandHideAction.h"

PickandHideAction::PickandHideAction(ApplicationManager *pApp) :Action(pApp)
{
	pManager = pApp;
	click.x = 0;
	click.y = 0;
	PickList = pManager->GetDeepCopyFromFigList(size);
	pManager->UpdateInterface(PickList, size);
}

void PickandHideAction::InitData()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure * FirstFigure = NULL;
	do {
		if (pManager->GetFigCount() == 0)
			break;
		pOut->PrintMessage("Pick The First Figure  ");
		pIn->GetPointClicked(click.x, click.y);

		FirstFigure =pManager->GetFigure(click.x, click.y,PickList,size);
		
	} while (FirstFigure == NULL);
		
	if (FirstFigure != NULL)
	{
		fig = FirstFigure->FigType();
		if (FirstFigure->IsFilled())
		{
			Filled = true;
			Color = FirstFigure->GetFillClr();
		}

		else
		{
			Filled = false;
		}

		pManager->DeletePickedFigure(PickList, size, FirstFigure);
		
	}
	pManager->UpdateInterface(PickList, size);

}

int PickandHideAction::Getsize()
{
	return size;
}


ActionState  PickandHideAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	do {
		pOut->PrintMessage("Choose a Playing Mode ");


		PICKING_TYPE = pIn->GetUserAction();
	} while (PICKING_TYPE == EMPTY);
	return Successful;
}

void PickandHideAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	UI.InterfaceMode = MODE_PICKANDHIDE;
	pOut->CreatePickandHideToolBar();
	pOut->PrintMessage("Pick------&-----Hide");
	ReadActionParameters();
	if (!(PICKING_TYPE == PICK_AREA))
		InitData();
	
		
	if (PICKING_TYPE == PICK_TYPE)
	{
		mode = new PickByTypeAction(pManager,PickList,size,fig );
		mode->Execute();
	}
	else if (PICKING_TYPE == PICK_FILL)
	{
		mode = new ByFillingColor(pManager,PickList,size,Color,Filled);
		mode->Execute();
	}
	else if (PICKING_TYPE == PICK_TYPEFILL)
	{
		mode = new PickByTypeandFillingColorAction(pManager, PickList, size, fig, Color, Filled);
		mode->Execute();
	}

	else if (PICKING_TYPE == PICK_AREA)
	{
		mode = new PickByArea(pManager, PickList, size);
		mode->Execute();

	}


}
PickandHideAction::~PickandHideAction()
{

}