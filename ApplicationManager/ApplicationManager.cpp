#include "ApplicationManager.h"
#include "..\Actions\AddRectAction.h"
#include"..\Actions\AddlineAction.h"
#include"..\Actions\AddCircleAction.h"
#include"..\Actions\AddTriAction.h"
#include "..\Actions\SaveAction.h"
#include "..\Actions\Select.h"
#include<iomanip>


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigListSaved = true;
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		pAct = new  AddlineAction(this);
		break;
	case DRAW_CIRC:
		pAct = new AddCircleAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;
	case DRAWING_AREA:
		pOut->PrintMessage("a click on the drawing area");
		break;
	case SELECT:
		pAct = new ActionSelect(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);
		break;
	case EXIT1:
		//pAct = new Exit1Action(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		pAct = NULL;
		delete pAct;
	
	}
}
int ApplicationManager::countselected()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			if (FigList[i]->IsSelected())
				count++;
		}
	}
	return count;
}
void ApplicationManager::PrintSelected()
{


}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
		FigListSaved = false;
	}
	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	bool check;

	for (int i = 0; i < FigCount; i++)
	{
		check = FigList[i]->check(x,y);

		if (check == true)
		{
			return FigList[i];
		}
	}


	return NULL;
}

void ApplicationManager::SaveAll(ofstream& fOut)
{
	//firstly writing all colors names and total number of figures then calling all Virtual Save functions of all figures in FigList
	FigListSaved = true;
	fOut<<left<<setw(10)<< UI.DrawColor.getColorName() << setw(10) << UI.FillColor.getColorName();
	fOut << setw(10) << UI.BkGrndColor.getColorName()<<endl;
	fOut << FigCount << endl;
	//for (int i = 0; i<FigCount; i++)
		//FigList[i]->Save(fOut);
	
}

bool ApplicationManager::GetIfListSaved() const
{
	return FigListSaved;
}
int ApplicationManager::GetFigCount()
{
	return FigCount;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
