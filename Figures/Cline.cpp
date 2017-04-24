#include "Cline.h"
Cline::Cline(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
	if ((P1.x - P2.x) != 0)
	slope = float((P1.y - P2.y)) / float(P1.x - P2.x);
	else slope = 0;
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

	float slope2 = float(y - start.y) / float(x - start.x);
	if (abs(slope - slope2) <5)
	{
		if (1)
		{
			return true;

		}
		else return true;
	}


}

void Cline::Save(ofstream & fOut) const
{
	fOut << left << setw(5) << "LINE" << setw(10) << ID << setw(12) << start.x << setw(14) << start.y;
	fOut << setw(16) << end.x << setw(18) << end.y << setw(23) << FigGfxInfo.DrawClr.getColorName() << setw(28) << FigGfxInfo.FillClr.getColorName() << endl;

}
