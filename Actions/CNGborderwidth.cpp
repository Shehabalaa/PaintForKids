#include"CNGborderwidth.h"
#include<iostream>
CNGborderwidth :: CNGborderwidth (ApplicationManager *pApp) : Action (pApp)
{
}
ActionState CNGborderwidth :: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage(" choose Pen Width");
	pOut->CreateBorderBar();
	Pen = pIn->GetBorder();
	return Successful;
}


void CNGborderwidth :: Execute ()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (Pen > 0)
	{
		if (pManager->countselected() > 0)
		{
			pManager->change_PenWidth_Action(Pen);
			pManager->GraphSaved = false;
		}
		else
		{

			UI.PenWidth = Pen;

		}
	}
	else { pOut->PrintMessage("you didn't choose a width "); }
}
CNGborderwidth :: ~ CNGborderwidth()
{
}