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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	window* pWind = pOut->GetWindow();
	
	pManager->UserGuide();


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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select figure(s)");
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
			temp += to_string(count);
			pOut->PrintMessage(temp);
		}
		pManager->UpdateInterface();
	}

}



ActionSelect::~ActionSelect()
{



}