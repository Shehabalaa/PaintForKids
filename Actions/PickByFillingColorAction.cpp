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
	pOut->PrintMessage("Pick A Figure");
	pIn->GetPointClicked(click.x, click.y);

	
	return Successful;

}

void ByFillingColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	while (pManager->GetFigCount() >= 0)
	{
		if (WrongCount == 0)
		{
			
				pOut->PrintMessage("YOU LOSE");
				string s;
				s = "images\\MenuItems\\LOSE.jpg";

				for (int j = 1; j <500; j++)
				{
					pOut->GetWindow()->DrawImage(s, 340, 150, 500, 350);
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

		CFigure* F = pManager->GetFigure(click.x, click.y,PickList,size);
		if (F != NULL)
		{
			if (fill)
			{
				if (F->GetFillClr() == Color  && F->FigType()!=line)
				{

					RightCount++;
					pManager->DeletePickedFigure(PickList,size,F);
					pManager->UpdateInterface(PickList,size);
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
					pManager->DeletePickedFigure(PickList,size,F);
					pManager->UpdateInterface(PickList,size);
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