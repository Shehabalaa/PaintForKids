#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point p3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	corner1 = P1;
	corner2 = P2;
	corner3 = p3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(corner1, corner2,corner3, FigGfxInfo, Selected);
}
bool CTriangle::check(int, int)
{
	return true;
}
figures  CTriangle::FigType() 
{
	return tri;
}

void CTriangle::Save(ofstream &fOut) const
{
	fOut << left << setw(5) << "RECTANGLE" << setw(10) << ID << setw(12) << corner1.x << setw(14) << corner1.y;
	fOut << setw(16) << corner2.x << setw(18) << corner2.y << setw(23) << setw(25) << corner3.x << setw(30) << corner3.y;
	fOut << FigGfxInfo.DrawClr.getColorName() << setw(35) << FigGfxInfo.FillClr.getColorName() << endl;

}

