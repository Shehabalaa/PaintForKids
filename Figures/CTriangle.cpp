#include "CTriangle.h"
#include<cmath>

CTriangle::CTriangle(const Point& P1, const Point& P2 , const Point& P3, const GfxInfo& FigureGfxInfo, int figs_count) : CFigure(FigureGfxInfo)
{
	corner1 = P1;
	corner2 = P2;
	corner3 = P3;
	ID = figs_count + 1;
	Area = abs((corner1.x*corner2.y + corner2.x*corner3.y + corner3.x*corner1.y - corner1.y*corner2.x - corner2.y*corner3.x - corner3.y*corner1.x) / 2);
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(corner1, corner2,corner3, FigGfxInfo, Selected);
}
figures  CTriangle::FigType() const
{
	return tri;
}

bool CTriangle::check(int x, int y) const
{
	
	double  area1, area2, area3, sum;
	area1 = abs((x*corner2.y + corner2.x*corner3.y + corner3.x*y - y*corner2.x - corner2.y*corner3.x - corner3.y*x) / 2);
	area2 = abs((corner1.x*y + x*corner3.y + corner3.x*corner1.y - corner1.y*x - y*corner3.x - corner3.y*corner1.x) / 2);
	area3 = abs((corner1.x*corner2.y + corner2.x*y + x*corner1.y - corner1.y*corner2.x - corner2.y*x - y*corner1.x) / 2);

	sum = area1 + area2 + area3;
	if (abs(sum - Area)<5)
		return true;
	else
		return false;
}

void CTriangle::PrintInfo(Output* pOut) const
{
	 pOut->DrawString(230, 667, "Radius :");
	 pOut->DrawInt(270, 667, 5);
}

void CTriangle::Save(ofstream &fOut) const

{
	fOut << left << setw(15) << "TRIANGLE" << setw(5) << ID << setw(8) << corner1.x << setw(8) << corner1.y;
	fOut << setw(8) << corner2.x << setw(8) << corner2.y << setw(8) << corner3.x << setw(12) << corner3.y;
	fOut << setw(18) << FigGfxInfo.DrawClr.getColorName() << setw(18);
	(FigGfxInfo.isFilled) ? fOut << FigGfxInfo.FillClr.getColorName() : fOut << "NO_FILL";
	fOut << FigGfxInfo.BorderWidth << endl;
		
}
bool CTriangle::InDrawingArea() const
{
	if (corner1.y > UI.ToolBarHeight && corner1.y < UI.height - UI.StatusBarHeight && corner2.y > UI.ToolBarHeight && corner2.y < UI.height - UI.StatusBarHeight && corner3.y > UI.ToolBarHeight && corner3.y < UI.height - UI.StatusBarHeight  && corner1.x < UI.width - 70 && corner2.x < UI.width - 70 && corner3.x < UI.width - 70)
	{
		return true;
	}
	else return false;

}

BlockingDirection CTriangle::Move(int x, int y)
{
	corner1.x += x;
	corner1.y += y;
	corner2.x += x;
	corner2.y += y;
	corner3.x += x;
	corner3.y += y;

	return (No_Block);

}

void CTriangle::Load(ifstream & Infile)
{
	string temp; // this string will be used several time to read strings from file
	Infile >> temp; ID = stoi(temp);
	Infile >> temp; corner1.x = stoi(temp);
	Infile >> temp; corner1.y = stoi(temp);
	Infile >> temp; corner2.x = stoi(temp);
	Infile >> temp; corner2.y = stoi(temp);
	Infile >> temp; corner3.x = stoi(temp);
	Infile >> temp; corner3.y = stoi(temp);
	Infile >> temp; FigGfxInfo.DrawClr = color::getColorObject(temp);
	Infile >> temp;

	if (temp == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = color::getColorObject(temp);
	}
	Infile >> temp;  FigGfxInfo.BorderWidth = stoi(temp);

}

CFigure * CTriangle::CreateCopy() const
{
	return new CTriangle(*this);
}

Point CTriangle::CentroidOfFigure() const
{
	Point p;
	p.x = (corner1.x + corner2.x + corner3.x) / 3;
	p.y = (corner1.y + corner2.y + corner3.y) / 3;
	return p;
}




CTriangle::~CTriangle()
{
}
