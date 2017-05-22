#include "ExitAction.h"

ExitAction::ExitAction(ApplicationManager * pApp):Action(pApp)
{
	Answer = false;
}

ExitAction::~ExitAction()
{
}

void ExitAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (Answer)
	{
		pManager->ExecuteAction(SAVE);
		if (pManager->GetIfListSaved())
		{
			pOut->PrintMessage("Data Saved successfully Press Enter to Exit");
			string temp = pIn->GetSrting(pOut); // this temp just read user replay
		}
	}

}

ActionState ExitAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(!pManager->GetIfListSaved())
	{
		pOut->PrintMessage("Do you want to save graph before exit?(Y,n)");
		string temp = pIn->GetSrting(pOut); // this temp just read user replay
		if (temp[0] == 'n' || temp[0] == 'N')
			Answer = false;
		else
			Answer = true;
	}

	return Successful;
}
