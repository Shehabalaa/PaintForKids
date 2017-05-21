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
	pOut->PrintMessage("Choose Max||Min Area");

	do {
		pOut->CreateAreaTypeBar();
		Choice = pIn->GetAreaType();
	} while (Choice == -1);
	pOut->PrintMessage("You didn't choose");
	pManager->UpdateInterface(PickList, size);


	return Successful;
}
void PickByArea::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	
	while (size>= 0)
	{
		if (WrongCount == 0)
		{

			pOut->PrintMessage("YOU LOSE");
			string s;
			s = "images\\MenuItems\\LOSE.jpg";

			for (int j = 1; j < 500; j++)
			{
				pOut->GetWindow()->DrawImage(s, UI.width - j, 150, 500, 350);
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

		//checks

		pIn->GetPointClicked(click.x, click.y);
		
		
		
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
				}
				else
				{
					WrongCount--;
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
				}
				else
				{
					WrongCount--;
				}


			}

		}
	}
}
PickByArea::~PickByArea()
{
}
