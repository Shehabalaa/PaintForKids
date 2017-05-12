#include"CNGcolor.h"
CNGcolor :: CNGcolor(ApplicationManager * pApp):Action (pApp)
{
}
ActionState CNGcolor :: ReadActionParameters ()
{
	Colors C;
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
	case SELECT_GREY_COLOR:
		Colour=GREY;
		break;
	case SELECT_LIME_COLOR:
		Colour=LIMEGREEN;
		break;
	case SELECT_WHITE_COLOR:
		Colour=WHITE;
		break;
	}
	return Successful;
}
void CNGcolor :: Execute ()
{
			ReadActionParameters();
	if(pManager->countselected()>0)
	{
	pManager->change_Filled_color_Action(Colour);
	
	}
	else
	{
		UI.FillColor=Colour;
	}
}
CNGcolor :: ~CNGcolor()
{
}