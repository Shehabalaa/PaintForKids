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


	pOut->PrintMessage("Pick A Figure");
	pIn->GetPointClicked(click.x, click.y);



	//pIn->GetPointClicked(click.x, click.y);
	return Successful;
}

void PickByTypeandFillingColorAction::Execute()
{

	while (pManager->GetFigCount() > 0)
	{
		if (WrongCount == 0)
		{
			pOut->PrintMessage("YOU LOSE");
			string s;
			s = "images\\MenuItems\\LOSE.jpg";

			for (int j = 1; j < 500; j++)
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

		ReadActionParameters();
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
				}

			}
			else
			{
				if (!F->IsFilled() && F->FigType() == type)

				{

					pManager->DeletePickedFigure(PickList, size, F);
					pManager->UpdateInterface(PickList, size);
					RightCount++;
				}
				else WrongCount--;
			}

		}
	}
}

PickByTypeandFillingColorAction ::~PickByTypeandFillingColorAction()
{



}