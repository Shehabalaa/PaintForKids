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

	pManager->CleanFiglist();
	pManager->CleanClipboard();
}

ActionState ExitAction::ReadActionParameters()
{
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
