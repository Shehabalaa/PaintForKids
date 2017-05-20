#include"..\Actions\MoveAction.h"
#include "../Figures/Cline.h"

MoveAction::MoveAction(ApplicationManager *pApp) :Action(pApp)
{
	present.x = 0;
	present.y = 0;
	next.x = 0;
	next.y = 0;
}



ActionState MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	window * pWind = pOut->GetWindow();
	do
	{
		pWind->GetMouseCoord(present.x, present.y);
	} while (pWind->GetButtonState(LEFT_BUTTON, present.x, present.y) == BUTTON_UP);
	
	pOut->PrintMessage("Drag Figure(s)");


	return Successful;
}
#include <ctime>
void  MoveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	window * pWind = pOut->GetWindow();
	int count = 0;
	double start = clock();

	while (1)
	{
		// these two statments to avoid havig bad parameters mouse going places on edges of window that cause to round edges
		pWind->GetMouseCoord(present.x, present.y);
		do
		{
			pWind->GetMouseCoord(next.x, next.y);

		} while (abs(next.x - present.x) < 2 && abs(next.y - present.y) < 2);

		if (pWind->GetButtonState(LEFT_BUTTON, next.x, next.y) == BUTTON_UP)
			break;

		int x = (next.x - present.x);
		int y = (next.y - present.y);
		if (next.x > UI.width-15 || next.x < 0 || present.x > UI.width-15 || present.x < 0)
			x = 0;
		if (next.y > UI.height-15 || next.y < 0 || present.y > UI.width-15 || present.y < 0)
			y = 0;

		if (x || y) // no need to move if both x and y =0
			pManager->MoveFigures(x, y);
		

		if (clock() - start >= 34)
		{
			pManager->UpdateInterface();
			start = clock();
		}
	}
	
}

MoveAction ::~MoveAction()
{

}