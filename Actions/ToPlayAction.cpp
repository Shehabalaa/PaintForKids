#include "ToPlayAction.h"

ToPlayAction::ToPlayAction(ApplicationManager *pApp) :Action(pApp)
{
}


void ToPlayAction::Execute()
{
	string Msg = "Welcome to PlayMode!";
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	UI.InterfaceMode = MODE_PLAY;
	pOut->CreatePlayToolBar();
	if (!pManager->GetFigCount())
	{
		Msg += " oops No Figures to play with do you want to generate random figures :) (Y/n)";
		pOut->PrintMessage(Msg);
		string answer = pIn->GetSrting(pOut);
		if (answer == "n" || answer == "N")
		{
			pManager->ExecuteAction(TO_DRAW);
		}
		else
			pManager->GenerateRandomFigList();

		pOut->GetWindow()->FlushMouseQueue(); // delete bad clicks while waiting input form keyboard
	}
	
}

ActionState ToPlayAction::ReadActionParameters()
{
	return Successful;
}


ToPlayAction::~ToPlayAction()
{
}