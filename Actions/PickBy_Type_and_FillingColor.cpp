#include"..\Actions\PickBy_Type_and_FillingColor.h"
PickByTypeandFillingColorAction::PickByTypeandFillingColorAction(ApplicationManager *pApp, CFigure ** PickList, int &size, figures Type,color c, bool Filled) :Action(pApp)
{
	pManager = pApp;
	click.x = 0;
	click.y = 0;
	RightCount = 0;
	WrongCount = 5;
	this->size = size;
	this->PickList = PickList;
	type = Type;
	
	/////////
	this->Color = c;
	
	fill = Filled;
	
	PickedFigureNumber = pManager->CountFigure(PickList, size,Type, c, fill);


}

ActionState PickByTypeandFillingColorAction::ReadActionParameters()
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
	//pIn->GetPointClicked(click.x, click.y);
	return Successful;
}

void PickByTypeandFillingColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (size > 0)
	{
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

			if (ReadActionParameters() == Successful) {
				CFigure *F = pManager->GetFigure(click.x, click.y, PickList, size);
				if (F != NULL)
				{
					if (fill)
					{
						if (F->GetFillClr() == Color&&F->FigType() == type)
						{

							RightCount++;
							pManager->DeletePickedFigure(PickList, size, F);
							pManager->UpdateInterface(PickList, size);
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
						if (!F->IsFilled() && F->FigType() == type)

						{

							pManager->DeletePickedFigure(PickList, size, F);
							pManager->UpdateInterface(PickList, size);
							RightCount++;
							string messege = "Correct ";
							pOut->PrintMessage(messege);
						}
						else { 
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
	else
		pOut->PrintMessage("No Figuers to play with");
}

PickByTypeandFillingColorAction ::~PickByTypeandFillingColorAction()
{



}