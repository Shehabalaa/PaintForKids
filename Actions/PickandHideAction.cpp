#include"..\Actions\PickandHideAction.h"

PickandHideAction::PickandHideAction(ApplicationManager *pApp) :Action(pApp)
{
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
		if (size == 0)
			break;
		pOut->PrintMessage("Pick The First Figure  ");
		pIn->GetPointClicked(click.x, click.y);

		FirstFigure =pManager->GetFigure(click.x, click.y,PickList,size);
		
	} while (FirstFigure == NULL);
	pOut->ClearStatusBar();
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
		pManager->UserGuide();
		PICKING_TYPE = pIn->GetUserAction();
	} while (PICKING_TYPE != PICK_AREA&&PICKING_TYPE !=PICK_FILL &&PICKING_TYPE !=PICK_TYPEFILL &&PICKING_TYPE !=PICK_TYPE && PICKING_TYPE !=TO_PLAY);
	return Successful;
}

void PickandHideAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	UI.InterfaceMode = MODE_PICKANDHIDE;
	pOut->CreatePickandHideToolBar();
	pOut->PrintMessage("Pick------&-----Hide");
	if (pManager->GetFigCount() > 0)
	{
		if (pManager->GetFigCount() > 0)
		{
			ReadActionParameters();

			if (!(PICKING_TYPE == PICK_AREA) && !(PICKING_TYPE == TO_PLAY))
				InitData();


			if (PICKING_TYPE == PICK_TYPE)
			{
				mode = new PickByTypeAction(pManager, PickList, size, fig);
				mode->Execute();
			}
			else if (PICKING_TYPE == PICK_FILL)
			{
				mode = new ByFillingColor(pManager, PickList, size, Color, Filled);
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
			else if (PICKING_TYPE == TO_PLAY)
			{
				mode = new ToPlayAction(pManager);
				mode->Execute();
			}

		}
		else
		{
			pOut->PrintMessage("No Figures To Play With . click to continue");
			int x, y;
			pIn->GetPointClicked(x, y);
			mode = new ToPlayAction(pManager);
			mode->Execute();


		}
	}
	else {
		pOut->PrintMessage("No Figures To Play With . click to continue");
		int x, y;
		pIn->GetPointClicked(x, y);
		mode = new ToPlayAction(pManager);
		mode->Execute();
	}
	mode = new ToPlayAction(pManager);
	mode->Execute();

}
PickandHideAction::~PickandHideAction()
{
	delete mode;
	for (int i = 0; i < size; i++)
		delete PickList[i];
}