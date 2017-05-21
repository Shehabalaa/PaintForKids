#include"CNGborderColor.h"
CNGborderColor :: CNGborderColor (ApplicationManager * pApp):Action(pApp)
{

}
ActionState CNGborderColor::ReadActionParameters()
{
	Colors C;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreateColorsBar();
	pOut->PrintMessage(" Choose the Color for your Borders !");
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

void CNGborderColor ::Execute()
{
	ReadActionParameters();
	if(pManager->countselected()>0)
	{
		pManager->change_border_color_Action(Colour);
	}
	
	else
	{
		if(Colour != AZURE)
			UI.DrawColor=Colour;
	}

}
CNGborderColor ::~ CNGborderColor ()
{
}