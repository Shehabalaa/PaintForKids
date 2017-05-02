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
void  ActionSelect::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select: Click on a figure");


	pIn->GetPointClicked(m.x, m.y);
}

void ActionSelect::Execute()
{
	ReadActionParameters();
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
	else if(count >1 )
	{
		string temp =" NO.of selected figures : ";
		temp += count;
		pManager->GetOutput()->PrintMessage(temp);
	}
}

ActionSelect::~ActionSelect()
{



}