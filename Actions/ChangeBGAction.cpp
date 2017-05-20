#include"..\Actions\ChangeBGAction.h"


ChangeBGAction::ChangeBGAction(ApplicationManager *pApp) :Action(pApp)
{
	pManager = pApp;

}


ActionState ChangeBGAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->CreateColorsBar();

	pOut->PrintMessage("Choose color");
	co = pIn->GetColor();


	return Successful;

}

void ChangeBGAction::Execute()
{
	Output* pOut = pManager->GetOutput();
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
	case SELECT_LIGHT_COLOR:
		pOut->SetBGColor(LIGHTGOLDENRODYELLOW);
		break;
	case SELECT_LIME_COLOR:
		pOut->SetBGColor(LIMEGREEN);
		break;
	case SELECT_WHITE_COLOR:
		pOut->SetBGColor(WHITE);
		break;


	}
	pOut->PrintMessage("BackGround Color Changed");
}

ChangeBGAction::~ChangeBGAction()
{
}