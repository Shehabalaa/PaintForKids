#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
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

	if (((x > Corner1.x  && x < Corner2.x) && (y > Corner1.y &&y < Corner2.y)) || ((y > Corner1.y  && y < Corner2.y) && (x > Corner1.x &&x < Corner2.x)))
	{
		return true;
	}
	else return false;

}

void CRectangle::Save(ofstream & fOut) const
{
	fOut << left << setw(14) << "RECTANGLE" /*<< setw(10) << ID*/ << setw(12) << Corner1.x << setw(14) << Corner1.y;
	fOut << setw(16) << Corner2.x << setw(18) << Corner2.y << setw(23) << FigGfxInfo.DrawClr.getColorName() << setw(28) << FigGfxInfo.FillClr.getColorName() << endl;

}