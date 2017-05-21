#include"PickByTypeAction.h"




PickByTypeAction::PickByTypeAction(ApplicationManager *pApp,CFigure ** PickList,int &size, figures Type) :Action(pApp)
{
	pManager = pApp;
	click.x = 0;
	click.y = 0;
	RightCount = 0;
	WrongCount = 5;
	this->size = size;
	this->PickList = PickList;
	type = Type;
	PickedFigureNumber = pManager->CountFigure(PickList,size,type);

}

ActionState PickByTypeAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Pick A Figure");
	pIn->GetPointClickedv2(click.x, click.y);
	
	if (click.y < UI.ToolBarHeight)
	{
		return Canceled_And_Switched_To_Another_One;
	}
	pOut->GetWindow()->FlushMouseQueue(); // to delete last mouse click as it won't be used again


	//pIn->GetPointClicked(click.x, click.y);
	return Successful;
}

void PickByTypeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
		while (1)
		{

			if (WrongCount == 0)
			{
				pOut->PrintMessage("YOU LOSE");
				string s;
				s = "images\\MenuItems\\LOSE.jpg";
				pOut->GetWindow()->DrawImage(s, 340, 150, 500, 350);
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

			if (ReadActionParameters() == Successful)
			{
				CFigure *PickedFigure = pManager->GetFigure(click.x, click.y, PickList, size);
				if (PickedFigure != NULL)
				{
					if (PickedFigure->FigType() == type)
					{
						RightCount++;

						pManager->DeletePickedFigure(PickList, size, PickedFigure);
						pManager->UpdateInterface(PickList, size);
					}

					else
					{
						WrongCount--;
					}
				}
			}
			else {
				return;
			}
		}
	
	
}




PickByTypeAction ::~ PickByTypeAction ()
{



}