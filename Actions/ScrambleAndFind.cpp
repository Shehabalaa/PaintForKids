#include "ScrambleAndFind.h"

void ScrampleAndFindAction::GenerateNormalAndRandomLLists()
{
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
			RandomizdList[i]->SetRandomCoord(0, UI.width - 1, UI.ToolBarHeight + 1, UI.height - UI.StatusBarHeight - 1);
		}
		return Successful;
	}
	else
	{
		pOut->PrintMessage("No Figures to Play with!!Do you want to generate Figures?(Y/n)");
		if (pIn->GetSrting(pOut) == "n" || pIn->GetSrting(pOut) == "n")
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
		pManager->UpdateInterface(RandomizdList);

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
