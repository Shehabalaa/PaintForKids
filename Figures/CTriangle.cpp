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
figures  CTriangle::FigType() {
	return tri;
}

