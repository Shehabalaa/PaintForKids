#include "Cline.h"
Cline::Cline(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
	slope = (P1.y - P2.y) / (P1.x - P2.x);
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
	if (y == slope*x || y == -1 * slope*x)
	{
		if ((((x > start.x) && (x < end.x))&&((y < start.y) && (y > end.y))) || ((( x<start.x && x>end.x)   && (y>start.y && y<end.y))))
		{
			return true;

		}
		else return true;
	}


}