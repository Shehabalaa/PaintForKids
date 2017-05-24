#include "ScrambleAndFind.h"
#include"../Figures/CTriangle.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CCircle.h"
#include"../Figures/Cline.h"


int ScrampleAndFindAction::GetIndexOfFutureHighLighted()
{
	int id = RandomizdList[ListSize - 1]->GetID();

	for (int i = 0; i < ListSize; i++)
	{
		if (NormalList[i]->GetID() == id)
			return i;
	}
	return -1;
}

int ScrampleAndFindAction::GetFigureIDinRandomList(int x, int y)
{

	for (int i = ListSize-1; i >=0; i--)
	{
		if (RandomizdList[i]->check(x, y))
			return RandomizdList[i]->GetID();
	}

	return -1;
}

void ScrampleAndFindAction::DeleteFigureFromBothLists(int ID)
{
	for (int i = 0; i < ListSize; i++)
	{
		if (NormalList[i]->GetID() == ID)
		{
			delete NormalList[i];
			NormalList[i] = NULL;
			break;
		}
	}
	for (int i = 0; i < ListSize; i++)
	{
		if (RandomizdList[i]->GetID() == ID)
		{
			delete 	RandomizdList[i];
			RandomizdList[i] = NULL;
			break;
		}
	}
	
	ListSize--;

	pManager->AdjustList(DEL,NormalList, ListSize);
	pManager->AdjustList(DEL,RandomizdList, ListSize);

}

ScrampleAndFindAction::ScrampleAndFindAction(ApplicationManager * pApp) :Action(pApp)
{
	CFigure ** NormalList = NULL;
	CFigure ** RandomizdList = NULL;
	ListSize = 0;
}



ActionState ScrampleAndFindAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	NormalList = pManager->GetDeepCopyFromFigList(ListSize);
	int centroid_y_1, centroid_y_2;
	int y = 0;
	for (int i = 0; i <ListSize; i++)
		y += NormalList[i]->CentroidOfFigure().y;

	centroid_y_1 = y / ListSize;


	for (int i = 0; i < ListSize; i++)
	{
		NormalList[i]->SetScrambleParameter();
	}

	y = 0;

	for (int i = 0; i <ListSize; i++)
		y += NormalList[i]->CentroidOfFigure().y;

	centroid_y_2 = y / ListSize;

	for (int i = 0; i < ListSize; i++)
		NormalList[i]->Move(0, centroid_y_1 - centroid_y_2);



	// copy normal to randomized

	RandomizdList = new CFigure*[ListSize];
	int temp = rand() % (ListSize); // in radnom order
	for (int i = 0; i < ListSize; i++)
	{
		RandomizdList[temp] = NormalList[i]->CreateCopy();
		RandomizdList[temp]->MovetoRandomCoord(UI.width / 2 + 1, UI.width - 15, UI.ToolBarHeight + 1, UI.height - UI.StatusBarHeight - 1);
		temp++;
		temp %= ListSize;
	}
	

	return Successful;
}

void ScrampleAndFindAction::Execute()
{
	int x = 0, y = 0, RightCount = 0, WrongCount = 0, CurrentID = 0;
	string MSG;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	int Tries = ListSize;


	pOut->PrintMessage("In This Gaame you should Search about and Select the Opposite to the Highlighted Figure(s) in right graph.");
	while (Tries>0)
	{
		MSG = "";
		int index = GetIndexOfFutureHighLighted();
		NormalList[index]->SetSelected(true);
		CurrentID = NormalList[index]->GetID();
		pManager->UpdateInterface(NormalList, RandomizdList, ListSize);
		// Drawing Line Between Two graphs
		if (UI.BkGrndColor == RED)
			pOut->GetWindow()->SetPen(BLACK, 2);
		else
			pOut->GetWindow()->SetPen(RED, 2);
		pOut->GetWindow()->DrawLine((UI.width - UI.ColorsBarWidth - 15) / 2, UI.ToolBarHeight, (UI.width - UI.ColorsBarWidth - 15) / 2, UI.height - UI.StatusBarHeight);
		
		
		if (pIn->GetPointClickedv2(x, y))
		{
			if (x < (UI.width - 15) / 2 || GetFigureIDinRandomList(x, y) != CurrentID)
			{
				MSG += "HardLuck Try Again";
				WrongCount++;
				NormalList[index]->SetSelected(false);
			}
			else
			{
				DeleteFigureFromBothLists(CurrentID);
				MSG += "Good Job";
				RightCount++;

			}


			pManager->UpdateInterface(NormalList, RandomizdList, ListSize);
			if (UI.BkGrndColor == RED)
				pOut->GetWindow()->SetPen(BLACK, 2);
			else
				pOut->GetWindow()->SetPen(RED, 2);
			pOut->GetWindow()->DrawLine((UI.width - UI.ColorsBarWidth - 15) / 2, UI.ToolBarHeight, (UI.width - UI.ColorsBarWidth - 15) / 2, UI.height - UI.StatusBarHeight);
			MSG += " You did " + to_string(RightCount) + " Right" + " and " + to_string(WrongCount) + " Wrong";
			pOut->PrintMessage(MSG);

		}
		else if (x / UI.MenuItemWidth < 4) // selects any of first three icons
			return;

		Tries--;
	}

	if (RightCount > WrongCount)
		pOut->GetWindow()->DrawImage("images\\MenuItems\\WIN.jpg", 340, 150, 500, 350);
	else 
		pOut->GetWindow()->DrawImage("images\\MenuItems\\LOSE.jpg", 340, 150, 500, 350);

	MSG = "Game is over You did " + to_string(RightCount) + " Right" + " and " + to_string(WrongCount)+ " Wrong" + " Click To Continue";
	pOut->PrintMessage(MSG);
	int k, z;
	pIn->GetPointClicked(k, z);
	//pOut->GetWindow()->FlushMouseQueue();// avoid bad clicking effects if user didnot catch message//bla avoid bla bta3
	pOut->ClearStatusBar();
}

ScrampleAndFindAction::~ScrampleAndFindAction()
{
		for (int i = 0; i < ListSize; i++)
		{
			delete NormalList[i];
			delete RandomizdList[i];
		}
}
