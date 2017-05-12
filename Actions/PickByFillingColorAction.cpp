#include"..\Actions\PickByFillingColorAction.h"
#include"..\Figures\CFigure.h"
ByFillingColor::ByFillingColor(ApplicationManager * pApp,color c,bool Filled) : Action(pApp)
{
	this->Color = c;
	WrongCount = 5; RightCount = 0;
	fill = Filled;
	PickedFigureNumber = pManager->CountFigure(c,fill);


}

ActionState ByFillingColor::ReadActionParameters()
{
	pOut->PrintMessage("Pick A Figure");
	pIn->GetPointClicked(click.x, click.y);

	
	return Successful;
}

void ByFillingColor::Execute()
{

	while (pManager->GetFigCount() >= 0)
	{
		if (WrongCount == 0)
		{
			
				pOut->PrintMessage("YOU LOSE");
				string s;
				s = "images\\MenuItems\\LOSE.jpg";

				for (int j = 1; j <500; j++)
				{
					pOut->GetWindow()->DrawImage(s, UI.width - j, 150, 500, 350);
				}

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
		ReadActionParameters();

		CFigure* F = pManager->GetFigure(click.x, click.y);
		if (F != NULL)
		{
			if (fill)
			{
				if (F->GetFillClr() == Color)
				{

					RightCount++;
					pManager->DeletePickedFigure(F);
					pManager->UpdateInterface();
				}
				else
				{
					WrongCount--;
				}

			}
			else
			{
				if (!F->IsFilled())

				{
					pManager->DeletePickedFigure(F);
					pManager->UpdateInterface();
					RightCount++;
				}
				else WrongCount--;
			}

		}
	}
}
ByFillingColor::~ByFillingColor()
{
}