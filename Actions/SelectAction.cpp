#include"..\Actions\SelectAction.h"
#include "../Figures/Cline.h"

ActionSelect::ActionSelect(ApplicationManager *pApp) :Action(pApp)
{
	pManager = pApp;
	m.x = 0;
	m.y = 0;
}


int ActionSelect::countselect()
{
	return pManager->countselected();


}
ActionState ActionSelect::ReadActionParameters()
{
	window* pWind = pOut->GetWindow();
	pWind->FlushKeyQueue(); // clear any bad Esc Left 
	pOut->PrintMessage("Select: Click on a figure");

	pIn->GetPointClickedv2(m.x,m.y);
	if (m.y < UI.ToolBarHeight)
	{
		return Canceled_And_Switched_To_Another_One;
	}

	pWind->FlushMouseQueue(); // to delete last mouse click as it won't be used again
	return Successful;
}

void ActionSelect::Execute()
{
	while (true)
	{
		switch (ReadActionParameters())
		{
		case Canceled_And_Switched_To_Another_One:
			return;
		case Successful: // do nothing and continue action excution
			break;
		}


		CFigure * fig = NULL;
		fig = pManager->GetFigure(m.x, m.y);
		int count = countselect();

		if (fig != NULL)
		{
			if (fig->IsSelected())
				fig->SetSelected(false);
			else
			{
				fig->SetSelected(true);
			}
		}
		count = countselect();
		if (count == 1)
		{
			CFigure * SelectedFigure = pManager->GetSelectedFigure();
			SelectedFigure->PrintInfo(pManager->GetOutput());

		}
		else if (count > 1)
		{
			string temp = " NO.of selected figures : ";
			temp += count;
			pManager->GetOutput()->PrintMessage(temp);
		}
		pManager->UpdateInterface();
	}
}



ActionSelect::~ActionSelect()
{



}