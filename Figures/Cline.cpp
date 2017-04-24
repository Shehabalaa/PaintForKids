#include "Cline.h"
Cline::Cline(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
	if ((P1.x - P2.x) != 0)
	slope = float((P1.y - P2.y)) / float(P1.x - P2.x);
	else slope = -1;

	length = sqrt(pow((start.x - end.x), 2) + pow((start.y - end.y), 2));
}


void Cline::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(start, end, FigGfxInfo, Selected);
}

figures Cline::FigType()
{
	return line;
}
bool Cline::check(int x, int y)
{
	if (slope == -1)
	{

	}
	else if (slope == 0)
	{


	}
	else
	{
		float slope2 = float(y - start.y) / float(x - start.x);
		if (abs(slope - slope2) < 3)
		{
			int l1 = sqrt(pow((x - start.x), 2) + pow((y - start.y), 2));
			int l2 = sqrt(pow((x - end.x), 2) + pow((y - end.y), 2));
			if (abs((l1 + l2) - length) <= 1)
				return true;
			else return false;
		}
	}
	return false;

}

void Cline::Save(ofstream & fOut) const
{
	fOut << left << setw(5) << "LINE" << setw(10) << ID << setw(12) << start.x << setw(14) << start.y;
	fOut << setw(16) << end.x << setw(18) << end.y << setw(23) << FigGfxInfo.DrawClr.getColorName() << setw(28) << FigGfxInfo.FillClr.getColorName() << endl;

}

bool  Cline::InDrawingArea()
{
	if (start.y > UI.ToolBarHeight && start.y < UI.height - UI.StatusBarHeight && end.y > UI.ToolBarHeight && end.y < UI.height - UI.StatusBarHeight && start.x < UI.width - 70 && end.x < UI.width - 70)
	{
		return true;
	}
	else return false;



}