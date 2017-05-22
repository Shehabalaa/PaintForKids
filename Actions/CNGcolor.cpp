#include"CNGcolor.h"
CNGcolor :: CNGcolor(ApplicationManager * pApp):Action (pApp)
{
}
ActionState CNGcolor :: ReadActionParameters ()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Colors C;
	pOut->CreateColorsBar();
	pOut->PrintMessage(" Choose the Color to Fill your Figure(s) !");
	C=pIn->GetColor();
	switch (C)
	{
	case SELECT_BLACK_COLOR:
		Colour=BLACK;
		break;
	case SELECT_GREEN_COLOR:
		Colour=GREEN;
		break;
	case SELECT_YELLOW_COLOR:
		Colour=YELLOW;
		break;
	case SELECT_RED_COLOR:
		Colour=RED;
		break;
	case SELECT_BLUE_COLOR:
		Colour=BLUE;
		break;
	case SELECT_BROWN_COLOR:
		Colour=BROWN;
		break;
	case SELECT_ORANGE_COLOR:
		Colour=ORANGE;
		break;
	case SELECT_ROSE_COLOR:
		Colour=ROSYBROWN;
		break;
	case SELECT_LIGHT_COLOR:
		Colour=LIGHTGOLDENRODYELLOW;
		break;
	case SELECT_LIME_COLOR:
		Colour=LIMEGREEN;
		break;
	case SELECT_WHITE_COLOR:
		Colour=WHITE;
		break;
	case SELECT_NON_COLOR:
		Colour = AZURE;
		break;
	}
	return Successful;
}
void CNGcolor::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (C != EMPTY2)
	{
		if (pManager->countselected() > 0 && Colour != AZURE)
		{
			pManager->change_Filled_color_Action(Colour);
			pManager->GraphSaved = false;
			pManager->AdjustList(CHNG_FILL_CLR);

		}
		else
		{
			if (Colour != AZURE)
			{
				UI.FillColor = Colour;
				UI.FilledFigures = true;
				pManager->GraphSaved = false;
				pManager->AdjustList(CHNG_FILL_CLR);
			}
		}
	}
	else { pOut->PrintMessage("you didn't choose a color"); }

}
CNGcolor :: ~CNGcolor()
{
}