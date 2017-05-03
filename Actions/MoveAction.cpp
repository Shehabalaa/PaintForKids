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
		pWind->GetMouseCoord(present.x, present.y);
	} while (pWind->GetButtonState(LEFT_BUTTON, present.x, present.y) == BUTTON_UP);
	
	pOut->PrintMessage("Drag Figure(s)");

}
#include<iostream>
void  MoveAction::Execute()
{
	ReadActionParameters();
	window * pWind = pOut->GetWindow();

	pWind->FlushMouseQueue();
	pWind->GetMouseCoord(next.x, next.y);
	while (pWind->GetButtonState(LEFT_BUTTON, next.x, next.y) != BUTTON_UP)
		{

		pWind->FlushMouseQueue();
		pWind->GetMouseCoord(next.x, next.y);

		// these two statments to avoid havig bad parameters mouse going places on edges of window that cause to round edges

		int x = (next.x - present.x);
		int y = (next.y - present.y);
		if (next.x > 65000 || next.x < 0)
		{
			next.x = 0;
			x = 0;
		}
		if (next.y > 65000 || next.y < 0)
		{
			next.y = 0;
			y = 0;

		}
		
		pManager->MoveFigures(x,y);

		present.x = next.x;
		present.y = next.y;

		Sleep(20);

		}
	
}

MoveAction ::~MoveAction()
{

}