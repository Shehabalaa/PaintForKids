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
			pOut->PrintMessage("File successfully opened and Data Saved Press Enter to Exit");
			string temp = pIn->GetSrting(pOut); // this temp just read user replay
		}
	}
}

void ExitAction::ReadActionParameters()
{
	if(!pManager->GetIfListSaved())
	{
		pOut->PrintMessage("Do you want to save graph befor exit?(Y,n)");
		string temp = pIn->GetSrting(pOut); // this temp just read user replay
		if (temp[0] == 'n' || temp[0] == 'N')
			Answer = false;
		else
			Answer = true;
	}
	
}
