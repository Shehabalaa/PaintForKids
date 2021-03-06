#include"..\Actions\PickByFillingColorAction.h"
#include"..\Figures\CFigure.h"
ByFillingColor::ByFillingColor(ApplicationManager * pApp,CFigure ** PickList,int &size,color c,bool Filled) : Action(pApp)
{
	this->Color = c;
	WrongCount = 5; RightCount = 0;
	fill = Filled;
	this->PickList = PickList;
	this->size = size;
	PickedFigureNumber = pManager->CountFigure(PickList,size,c,fill);


}

ActionState ByFillingColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	
	if (!pIn->GetPointClickedv2(click.x, click.y))
	{
		if (click.y < UI.ToolBarHeight && click.x >212 && click.x < 276)
		{
			return Canceled_And_Switched_To_Another_One;
		}
		else
			pOut->GetWindow()->FlushMouseQueue();
	}

	return Successful;
	

}

void ByFillingColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	while (1)
	{
		if (WrongCount == 0)
		{
			pOut->PrintMessage("YOU LOSE");
			string s;
			s = "images\\MenuItems\\LOSE.jpg";
			pOut->GetWindow()->DrawImage(s, 340, 150, 500, 350);
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->PrintMessage("Click to Continue");
			break;
		}
		if (RightCount == PickedFigureNumber)
		{

			pOut->PrintMessage("YOU WIN");
			string s;
			s = "images\\MenuItems\\WIN.jpg";
			pOut->GetWindow()->DrawImage(s, 340, 150, 500, 350);
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->PrintMessage("Click to Continue");
			break;
		}
		//checks
		if (ReadActionParameters() == Successful)
		{

			CFigure* F = pManager->GetFigure(click.x, click.y, PickList, size);
			if (F != NULL)
			{
				if (fill)
				{
					if (F->GetFillClr() == Color  && F->FigType() != line)
					{

						RightCount++;
						pManager->DeletePickedFigure(PickList, size, F);
						pManager->UpdateInterface(PickList, size);
						string messege = "Correct ";
						pOut->PrintMessage(messege);
					}
					else
					{
						WrongCount--;
						string messege = "WRONG.. You Have " + to_string(WrongCount) + " Chances left";
						pOut->PrintMessage(messege);
					}
				}


				else
				{
					if (!F->IsFilled())

					{
						pManager->DeletePickedFigure(PickList, size, F);
						pManager->UpdateInterface(PickList, size);
						RightCount++;
						string messege = "Correct ";
						pOut->PrintMessage(messege);
					}
					else
					{
						WrongCount--;
						string messege = "WRONG.. You Have " + to_string(WrongCount) + " Chances left";
						pOut->PrintMessage(messege);
					}
				}

			}
		}
		
		else { return; }
	}
	
	
}

ByFillingColor::~ByFillingColor()
{
}