#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo,int fig):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID = fig + 13;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
figures  CRectangle::FigType()
{
	return rec;
}
bool CRectangle::check(int x, int y)
{
	if (Corner1.x < Corner2.x)
	{
		if (x > Corner1.x && x < Corner2.x)
			if ((y > Corner1.y && y < Corner2.y) || (y<Corner1.y && y>Corner2.y))
				return true;
	}
	else if (Corner1.x > Corner2.x)
	{
		if (x < Corner1.x && x > Corner2.x)
			if ((y > Corner2.y && y < Corner1.y) || (y<Corner2.y && y>Corner1.y))
				return true;
	}

	return false;

}


void CRectangle::Save(ofstream & fOut) const
{
	fOut << left << setw(14) << "RECTANGLE" /*<< setw(10) << ID*/ << setw(12) << Corner1.x << setw(14) << Corner1.y;
	fOut << setw(16) << Corner2.x << setw(18) << Corner2.y << setw(23) << FigGfxInfo.DrawClr.getColorName() << setw(28) << FigGfxInfo.FillClr.getColorName() << endl;

}
bool CRectangle::InDrawingArea()
{
	if (Corner1.y > UI.ToolBarHeight && Corner1.y < UI.height - UI.StatusBarHeight && Corner2.y > UI.ToolBarHeight && Corner2.y < UI.height - UI.StatusBarHeight && Corner1.x < UI.width - 70 && Corner2.x < UI.width - 70)
	{
		return true;
	}
	else return false;
}