#include "CTriangle.h"
#include<cmath>

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

bool CTriangle::check(int x, int y)
{
	double area, area1, area2, area3, sum ;
	
	area = abs((corner1.x*corner2.y + corner2.x*corner3.y + corner3.x*corner1.y - corner1.y*corner2.x - corner2.y*corner3.x - corner3.y*corner1.x) / 2);
	area1 = abs((x*corner2.y + corner2.x*corner3.y + corner3.x*y - y*corner2.x - corner2.y*corner3.x - corner3.y*x) / 2);
	area2 = abs((corner1.x*y + x*corner3.y + corner3.x*corner1.y - corner1.y*x - y*corner3.x - corner3.y*corner1.x) / 2);
	area3 = abs((corner1.x*corner2.y + corner2.x*y + x*corner1.y - corner1.y*corner2.x - corner2.y*x - y*corner1.x) / 2);

	sum = area1 + area2 + area3;
	if (abs(sum -area)<5)
		return true;
	else return false;
}