#include"..\Actions\Pick_By_Area.h"
#include"..\Figures\CFigure.h"
#include<iostream>
using namespace std;

PickByArea::PickByArea(ApplicationManager * pApp, CFigure ** PickList, int &size) : Action(pApp)
{
	WrongCount = 5; RightCount = 0;
	this->PickList = PickList;
	this->size = size;
	MAX.first = 0;
	MAX.second = NULL;
	MIN.first = 1000000; 
	MIN.second = NULL;
	PickedFigureNumber = pManager->GetFigCount();
	
}
ActionState PickByArea::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	
	if (!pIn->GetPointClickedv2(click.x, click.y))
	{
		return Canceled_And_Switched_To_Another_One;
	}

	return Successful;
	


}
void PickByArea::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	

		pOut->CreateAreaTypeBar();
		do {
			pOut->PrintMessage("Choose Max||Min Area");
			Choice = pIn->GetAreaType();

		} while (Choice == -1);
		pManager->UpdateInterface(PickList, size);

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

			//checks




			if (ReadActionParameters() == Successful) {
				if (Choice == Max)
				{
					MAX.first = 0; MAX.second = NULL;
					for (int i = 0; i < size; i++)
					{
						if (PickList[i]->GetArea() > MAX.first)
						{
							MAX.first = PickList[i]->GetArea();
							MAX.second = PickList[i];
						}
					}
					CFigure* F = pManager->GetFigure(click.x, click.y, PickList, size);
					if (F != NULL)
					{
						if (F == MAX.second)
						{

							RightCount++;
							pManager->DeletePickedFigure(PickList, size, F);
							pManager->UpdateInterface(PickList, size);
							string messege = "Correct ";
							pOut->PrintMessage(messege);
						}
						else
						{
							WrongCount--;
							string messege = "WRONG.. You Have " + to_string(WrongCount) + " Chances left";
							pOut->PrintMessage(messege);
						}


					}
				}

				else if (Choice == Min)
				{
					{
						MIN.first = 1000000; MIN.second = NULL;
						for (int i = 0; i < size; i++)
						{
							if (PickList[i]->GetArea() < MIN.first)
							{
								MIN.first = PickList[i]->GetArea();
								MIN.second = PickList[i];
							}
						}
					}
					CFigure* F = pManager->GetFigure(click.x, click.y, PickList, size);
					if (F != NULL)
					{
						if (F == MIN.second)
						{

							RightCount++;
							pManager->DeletePickedFigure(PickList, size, F);
							pManager->UpdateInterface(PickList, size);
							string messege = "Correct ";
							pOut->PrintMessage(messege);
						}
						else
						{
							WrongCount--;
							string messege = "WRONG.. You Have " + to_string(WrongCount) + " Chances left";
							pOut->PrintMessage(messege);
						}


					}

				}
			}
			else { return; }
		}

}
PickByArea::~PickByArea()
{
}
