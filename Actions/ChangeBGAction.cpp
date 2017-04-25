#include"..\Actions\ChangeBGAction.h"
#include "..\ApplicationManager\ApplicationManager.h"


ChangeBGAction::ChangeBGAction(ApplicationManager *pApp) :Action(pApp)
{
	pManager = pApp;

}



void  ChangeBGAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("choose color");
	co = pIn->GetColor();

}

void ChangeBGAction::Execute()
{
	ReadActionParameters();
	switch (co)
	{
	case SELECT_BLACK_COLOR:
		pOut->SetBGColor(BLACK);
		break;
	case SELECT_GREEN_COLOR:
		pOut->SetBGColor(GREEN);
		break;
	case SELECT_YELLOW_COLOR:
		pOut->SetBGColor(YELLOW);
		break;
	case SELECT_RED_COLOR:
		pOut->SetBGColor(RED);
		break;
	case SELECT_BLUE_COLOR:
		pOut->SetBGColor(BLUE);
		break;
	case SELECT_BROWN_COLOR:
		pOut->SetBGColor(BROWN);
		break;
	case SELECT_ORANGE_COLOR:
		pOut->SetBGColor(ORANGE);
		break;
	case SELECT_ROSE_COLOR:
		pOut->SetBGColor(ROSYBROWN);
		break;
	case SELECT_GREY_COLOR:
		pOut->SetBGColor(GREY);
		break;
	case SELECT_LIME_COLOR:
		pOut->SetBGColor(LIMEGREEN);
		break;
	case SELECT_WHITE_COLOR:
		pOut->SetBGColor(WHITE);
		break;


	}

}

ChangeBGAction::~ChangeBGAction()
{
}