#include "CCircle.h"
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	rad = P2;
}


void CCircle::Draw(Output* pOut) const
{
	int R;
	R = sqrt(pow((rad.x - center.x), 2) + pow((rad.y - center.y), 2));
	pOut->DrawCirc(center, R, FigGfxInfo, Selected);
}