#include "CCircle.h"
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	circum = P2;
	rad = sqrt(pow((circum.x - center.x), 2) + pow((circum.y - center.y), 2));
	//ID =
}


void CCircle::Draw(Output* pOut) const
{

	pOut->DrawCirc(center, rad, FigGfxInfo, Selected);
}

figures CCircle::FigType()
{
	return circle;
}


bool CCircle::check(int x,int y)
{
	int d;
	d= sqrt(pow((x - center.x), 2) + pow((y - center.y), 2));
	if (d <= rad)
	{
		return true;
	}
	else return false;

}