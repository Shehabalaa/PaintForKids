#include"..\Actions\MoveAction.h"
#include "../Figures/Cline.h"

MoveAction::MoveAction(ApplicationManager *pApp) :Action(pApp)
{
	present.x = 0;
	present.y = 0;
	next.x = 0;
	next.y = 0;
}



void   MoveAction::ReadActionParameters()
{
	window * pWind = pOut->GetWindow();
	do
	{
		pWind->GetMouseCoord(next.x, next.y);
	} while (pWind->GetButtonState(LEFT_BUTTON, present.x, present.y) == BUTTON_UP);
	
	pOut->PrintMessage("Drag Figure(s)");

}

void  MoveAction::Execute()
{
	ReadActionParameters();

	window * pWind = pOut->GetWindow();

	pWind->FlushMouseQueue();

	while ( pWind->GetButtonState(LEFT_BUTTON,next.x,next.y)!= BUTTON_UP)
	{
		pWind->GetMouseCoord(next.x, next.y);
		int x = (next.x - present.x);
		int y = (next.y - present.y);
		pManager->MoveFigures(x,y);
		present.x = next.x; present.y = next.y;
		pWind->FlushMouseQueue();
		Sleep(25);
	}

}

MoveAction ::~MoveAction()
{

}