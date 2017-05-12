#include "ScrambleAndFind.h"
#include"../Figures/CTriangle.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CCircle.h"
#include"../Figures/Cline.h"

void ScrampleAndFindAction::GenerateNormalAndRandomLLists()
{
	// random list size between 5 and 20
	ListSize = rand() % (10 - 5 + 1) + 4;
	int tri_num=0, rec_num=0, circle_num=0, line_num=0;
	circle_num = rand() % (ListSize + 1);
	if(circle_num!=ListSize)
		tri_num = rand() % (ListSize - circle_num + 1) ;
	if (circle_num+tri_num != ListSize)
		rec_num = rand() % (ListSize - circle_num-tri_num + 1);
	if (circle_num + tri_num+rec_num != ListSize)
		line_num = rand() % (ListSize - circle_num - tri_num - rec_num + 1);

	ListSize = tri_num + rec_num + line_num+circle_num;
	NormalList = new CFigure*[ListSize];
	RandomizdList = new CFigure*[ListSize];
	for (int i = 0; i < circle_num; i++)
	{
		//NormalList[i] = new CCircle;
		RandomizdList[i] = new CCircle;
		RandomizdList[i]->SetRandomParameter(0, UI.width - 15, UI.ToolBarHeight + 1, UI.height - UI.StatusBarHeight - 1);
	}
	for (int i = circle_num ; i < circle_num+tri_num; i++)
	{
		//NormalList[i] = new CTriangle;
		RandomizdList[i] = new CTriangle;
		RandomizdList[i]->SetRandomParameter(0, UI.width - 15, UI.ToolBarHeight + 1, UI.height - UI.StatusBarHeight - 1);
	}
	for (int i = circle_num + tri_num; i < circle_num + tri_num +rec_num; i++)
	{
		//NormalList[i] = new CRectangle;
		RandomizdList[i] = new CRectangle;
		RandomizdList[i]->SetRandomParameter(0, UI.width - 15, UI.ToolBarHeight + 1, UI.height - UI.StatusBarHeight - 1);
	}
	for (int i = circle_num + tri_num + rec_num; i < circle_num + tri_num + rec_num+line_num; i++)
	{
		//NormalList[i] = new Cline;
		RandomizdList[i] = new Cline;
		RandomizdList[i]->SetRandomParameter(0, UI.width - 15, UI.ToolBarHeight + 1, UI.height - UI.StatusBarHeight - 1);
	}

}

ScrampleAndFindAction::ScrampleAndFindAction(ApplicationManager * pApp) :Action(pApp)
{
	CFigure ** NormalList = NULL;
	CFigure ** RandomizdList = NULL;
	ListSize = 0;
}

ActionState ScrampleAndFindAction::ReadActionParameters()
{
	NormalList = pManager->GetDeepCopyFromFigList(ListSize);
	RandomizdList = pManager->GetDeepCopyFromFigList(ListSize);
	if (ListSize)
	{
		for (int i = 0; i < ListSize; i++)
		{
			RandomizdList[i]->MovetoRandomCoord(UI.width/2+1, UI.width - 15, UI.ToolBarHeight + 1, UI.height - UI.StatusBarHeight - 1);
		}
		return Successful;
	}
	else
	{
		pOut->PrintMessage("No Figures to Play with!!Do you want to generate Figures?(Y/n)");
		string temp = pIn->GetSrting(pOut);
		if (temp == "n" || temp == "N")
			return Just_Canceled;
		else
		{
			GenerateNormalAndRandomLLists();
			pOut->PrintMessage("FiguresList generated successfully");
		}
		
	}


	return Successful;
}

void ScrampleAndFindAction::Execute()
{
	while (1)
	{
		if (ReadActionParameters() == Just_Canceled)
			return;
		/*

		  Some Logic
		*/

		// pManager->UpdateInterface(NormlList);
		pManager->UpdateInterface(RandomizdList,ListSize);

		Sleep(1000);


	}

}

ScrampleAndFindAction::~ScrampleAndFindAction()
{
	if (NormalList)
	{
		for (int i = 0; i < ListSize; i++)
		{
			delete NormalList[i];
			delete RandomizdList[i];
		}
	}
}
