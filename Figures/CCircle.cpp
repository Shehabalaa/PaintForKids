#include "CCircle.h"
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo,int fig) :CFigure(FigureGfxInfo)
{
	center = P1;
	circum = P2;
	rad = sqrt(pow((circum.x - center.x), 2) + pow((circum.y - center.y), 2));
	ID = fig + 13;
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

void CCircle::Save(ofstream &fOut) const
{

	fOut << left << setw(5) << "CIRCLE" << setw(10) << ID << setw(12) << center.x << setw(14) << center.y;
	fOut << setw(16) << rad << setw(21) << FigGfxInfo.DrawClr.getColorName() << setw(26) << FigGfxInfo.FillClr.getColorName() << endl;
}
bool  CCircle::InDrawingArea()
{
	if (center.y > UI.ToolBarHeight && center.y < (UI.height - UI.StatusBarHeight) && center.x - rad >= 0 && center.x + rad < UI.width - 70 && center.y - rad > UI.ToolBarHeight && center.y + rad < UI.height - UI.StatusBarHeight)
	{
		return true;
	}
	else return false;
}