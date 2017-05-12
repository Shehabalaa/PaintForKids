#include"PickByTypeAction.h"




PickByTypeAction::PickByTypeAction(ApplicationManager *pApp, figures Type) :Action(pApp)
{
	pManager = pApp;
	click.x = 0;
	click.y = 0;
	RightCount = 0;
	WrongCount = 5;
	
	type = Type;
	PickedFigureNumber = pManager->CountFigure(type);

}

ActionState PickByTypeAction::ReadActionParameters()
{


	pOut->PrintMessage("Pick A Figure");
	pIn->GetPointClicked(click.x, click.y);



	//pIn->GetPointClicked(click.x, click.y);
	return Successful;
}

void PickByTypeAction::Execute()
{

	while (pManager->GetFigCount()>0)
	{
		if (WrongCount == 0)
		{
			pOut->PrintMessage("YOU LOSE");
			string s;
			s= "images\\MenuItems\\LOSE.jpg";
			
			for (int j = 1; j <500; j++)
			{
				pOut->GetWindow()->DrawImage(s,UI.width- j, 150, 500, 350);
			}
			
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->PrintMessage("Click to Continue");
			break;
		}
		if (RightCount == PickedFigureNumber)
		{

			pOut->PrintMessage("YOU WIN");
			string s;
			s = "images\\MenuItems\\WIN.jpg";
			pOut->GetWindow()->DrawImage(s, 340, 150, 500, 350);
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->PrintMessage("Click to Continue");
			break;
		}

		ReadActionParameters();
		CFigure *PickedFigure= pManager->GetFigure(click.x, click.y);
		if (PickedFigure != NULL)
		{
			if (PickedFigure->FigType() == type)
			{
				RightCount++;

				pManager->DeletePickedFigure(PickedFigure);
				pManager->UpdateInterface();
			}

			else
			{
				WrongCount--;
			}
		}
	}


}

PickByTypeAction ::~ PickByTypeAction ()
{



}