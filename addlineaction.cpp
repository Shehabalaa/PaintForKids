#include "addlineaction.h"

#include"..\Cline.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"..\Actions\Action.h"



addlineaction::addlineaction(ApplicationManager * pApp) : Action(pApp)
{}

void addlineaction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("New Line: Click at first point");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(s.x, s.y);

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd corner and store in point P2
	pIn ->GetPointClicked(e.x, e.y);

	LineGfxInfo .isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void addlineaction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	Cline *l = new Cline(s, e, LineGfxInfo);

	//Add the line to the list of figures
	pManager->AddFigure(l);
}



addlineaction::~addlineaction()
{
}
