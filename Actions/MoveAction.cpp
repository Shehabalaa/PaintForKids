#include"..\Actions\MoveAction.h"
#include "../Figures/Cline.h"

MoveAction::MoveAction(ApplicationManager *pApp) :Action(pApp)
{
	pManager = pApp;
	present.x = 0;
	present.y = 0;
	next.x = 0;
	next.y = 0;
}



void   MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Drag Figure(s)");


	
}

void  MoveAction::Execute()
{
	ReadActionParameters();
	button bu;
	clicktype b = LEFT_CLICK;
	clicktype a = pOut->GetWindow()->GetMouseClick(next.x, next.y);
	present.x = 0;
	present.y = 0;
	while ( a== b)
	{
		int x = next.x - present.x;
		int y = next.y - present.y;

		pManager->MoveFigures(x,y);
	}

}

MoveAction ::~MoveAction()
{



}