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

	Point middle;
	middle.x = (Corner1.x + Corner2.x) / 2;
	middle.y = (Corner1.y + Corner2.y) / 2;
	float distance; // distance between corner and center
	distance = sqrt(pow((Corner1.x - middle.x), 2) + pow((Corner1.y - middle.y), 2));


	float dis = sqrt(pow((x - middle.x), 2) + pow((y - middle.y), 2)); // distance between clicked point and center



	if (dis<=distance)
	{
		return true;
	}
	else return false;



}


void CRectangle::Save(ofstream & fOut) const
{
	-fOut << left << setw(14) << "RECTANGLE" /*<< setw(10) << ID*/ << setw(12) << Corner1.x << setw(14) << Corner1.y;
	-fOut << setw(16) << Corner2.x << setw(18) << Corner2.y << setw(23) << FigGfxInfo.DrawClr.getColorName() << setw(28) << FigGfxInfo.FillClr.getColorName() << endl;

}