
#include "ApplicationManager.h"
#include "..\Actions\LoadAction.h"
#include "..\Actions\AddRectAction.h"
#include "..\Actions\AddTriAction.h"
#include "..\Actions\AddlineAction.h"
#include "..\Actions\AddCircleAction.h"
#include "..\Actions\SaveAction.h"
#include "..\Actions\ExitAction.h"
#include "..\Actions\SelectAction.h"
#include "..\Actions\ChangeBGAction.h"
#include "..\Actions\PickandHideAction.h"
#include "..\Actions\ToDrawAction.h"
#include "..\Actions\ToPlayAction.h"
#include "..\Actions\MoveAction.h"
#include "..\Actions\CutAction.h"
#include "..\Actions\CopyAction.h"
#include "..\Actions\PasteAction.h"
#include "..\Actions\DeleteAction.h"
#include "..\Figures\Cline.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CTriangle.h"

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
		pOut->PrintMessage("A click on drawing area");
		break;
	case PLAYING_AREA:
		pOut->PrintMessage("A click on Playing area");
		break;
	case SELECT:
		pAct = new ActionSelect(this);
		break;
	case SAVE:
		pAct = new SaveAction(this);
		break;
	case MOVE :
		pAct = new MoveAction(this);
		break;
	case LOAD:
		pAct = new LoadAction(this);
		break;
	case CHNG_BK_CLR:
		pAct = new ChangeBGAction(this);
			break;
	case TO_DRAW:
		pAct = new ToDrawAction(this);
		break;
	case TO_PLAY:
		pAct = new ToPlayAction(this);
		break;
	case PICK:
		pAct = new PickandHideAction(this);
		break;
	case COPY:
		pAct = new CopyAction(this);
		break;
	case CUT:
		pAct = new CutAction(this);
		break;
	case PASTE:
		pAct = new PasteAction(this);
		break;
	case DEL:
		pAct = new DeleteAction(this);
		break;
	case EXIT:
		pAct = new ExitAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;
		pAct = NULL;
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

	for (int i = (FigCount-1); i >= 0; i--)
	{
		check = FigList[i]->check(x,y);

		if (check == true)
		{
			return FigList[i];
		}
	}


	return NULL;
}
CFigure *ApplicationManager::GetSelectedFigure() const
{

	for (int i = 0; i < FigCount; i++)
	{

		if (FigList[i]->IsSelected())
			return FigList[i];
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
	for (int i = 0; i<FigCount; i++)
		FigList[i]->Save(fOut);
	
}




void ApplicationManager::LoadAll( ifstream & InFile)
{
	//firstly load UI information (crnt draw color,bg color,etc..)
	string temp; // this string will be used several time to read strings from file
	InFile>>temp; UI.DrawColor = color::getColorObject(temp);
	InFile >> temp; UI.FillColor = color::getColorObject(temp);
	InFile >> temp; UI.BkGrndColor = color::getColorObject(temp);
	InFile >> temp; 
	FigCount = stoi(temp);
	for (int i = 0; i < FigCount && !InFile.eof(); i++)
	{
		InFile >> temp;
		if (temp == "RECTANGLE")
			FigList[i] = new CRectangle;
		else if (temp == "CIRCLE")
			FigList[i] = new CCircle;
		else if (temp == "TRIANGLE")
			FigList[i] = new CTriangle;
		else if (temp == "LINE")
			FigList[i] = new Cline;

		FigList[i]->Load(InFile);
	}
	FigListSaved = true;



}
///////////////////////////////////////////////////////////////
bool ApplicationManager::MoveFigures(int x,int y)
{
	BlockingDirection tmp = No_Block;
	bool CASE = true;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			tmp = FigList[i]->Move(x, y);
			switch (tmp) // if any figure while moving gets out of drawing area ,unmove already moved figures and return false;
			{
			case No_Block:
				break;
			case Block_in_X_Direction:
				for (int j = 0; j < i + 1; j++)
				{
					if (FigList[j]->IsSelected())
					{
						FigList[j]->Move(-x, 0);
					}
				}
				CASE = false;
				x = 0;
				break;
			case Block_in_Y_Direction:
				for (int j = 0; j < i + 1; j++)
				{
					if (FigList[j]->IsSelected())
					{
						FigList[j]->Move(0, -y);
					}
				}
				CASE = false;
				y = 0;
				break;

			case Block_in_XY_Direction:
				for (int j = 0; j < i + 1; j++)
				{
					if (FigList[j]->IsSelected())
					{
						FigList[j]->Move(-x, -y);
					}
				}
				CASE = false;
				return CASE;
				break;

			}
		}
	}
	UpdateInterface();
	return CASE;
}

///////////////////////////////////////////////////////////////////////////////

void ApplicationManager::DeleteAll()
{

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigList[i] = NULL;
			swap(FigList[i], FigList[FigCount - 1]);
			FigCount--;
			i--;
		}
	}

	if (FigCount == 0)
		FigListSaved = true;

}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::CutAll()
{
	CopyAll();
	DeleteAll();
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::CopyAll()
{
	ClipBoard.clear();

	for (int i = 0; i <FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			ClipBoard.push_back(FigList[i]->CreateCopy());
		}
	}

}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::PasteAll()
{
	Point p,centroid; int x = 0, y = 0;
	pIn->GetPointClicked(p.x, p.y);
	if (p.y >= UI.ToolBarHeight && p.y < UI.height - UI.StatusBarHeight  && p.x < UI.width - UI.ColorsBarWidth)
	{
		if (!ClipBoard.empty())
		{
			for (int i = 0; i < ClipBoard.size(); i++)
			{
				x += ClipBoard[i]->CentroidOfFigure().x;
				y += ClipBoard[i]->CentroidOfFigure().y;

			}
			centroid.x = x / ClipBoard.size();
			centroid.y = y / ClipBoard.size();


			for (int i = 0; i < ClipBoard.size(); i++)
			{
				CFigure* tmp_ptr = ClipBoard[i]->CreateCopy();
				tmp_ptr->Move(p.x - centroid.x, p.y - centroid.y);
					AddFigure(tmp_ptr);
			}
		}
		
	}

}
////////////////////////////////////////////////////////////////////////////////////





bool ApplicationManager::GetIfListSaved() const
{
	return FigListSaved;
}
void ApplicationManager::CleanFiglist()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];

	FigCount = 0;
	FigListSaved = true;
}

void ApplicationManager::CleanClipboard()
{
	ClipBoard.clear();
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
	pOut->GetWindow()->SetBrush(UI.BkGrndColor);
	pOut->GetWindow()->SetPen(UI.BkGrndColor, 1);
	pOut->GetWindow()->DrawRectangle(0, UI.ToolBarHeight, UI.width-UI.ColorsBarWidth, UI.height- UI.StatusBarHeight);

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
{//asdasdasdsaa
	CleanFiglist();
	delete pIn;
	delete pOut;
	
}

