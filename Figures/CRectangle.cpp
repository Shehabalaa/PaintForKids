#include "CRectangle.h"

CRectangle::CRectangle(const Point& P1, const Point& P2,const GfxInfo& FigureGfxInfo , int figs_count ):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID = figs_count + 1;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
figures  CRectangle::FigType() const
{
	return rec;
}
bool CRectangle::check(int x, int y) const
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


void CRectangle::PrintInfo(Output* pOut) const
{
	pOut->DrawString(230, 667, "Radius :");
	pOut->DrawInt(270, 667, 5);


}

void CRectangle::Save(ofstream & fOut) const
{
	fOut << left << setw(15) << "RECTANGLE" << setw(5) << ID << setw(8) << Corner1.x << setw(8) << Corner1.y;
	fOut << setw(8) << Corner2.x << setw(28) << Corner2.y << setw(18) << FigGfxInfo.DrawClr.getColorName() << setw(18);
	(FigGfxInfo.isFilled) ? fOut << FigGfxInfo.FillClr.getColorName() : fOut << "NO_FILL";
	fOut << FigGfxInfo.BorderWidth << endl;

}
bool CRectangle::InDrawingArea() const
{
	if (Corner1.y > UI.ToolBarHeight && Corner1.y < UI.height - UI.StatusBarHeight && Corner2.y > UI.ToolBarHeight && Corner2.y < UI.height - UI.StatusBarHeight && Corner1.x < UI.width - 70 && Corner2.x < UI.width - 70)
	{
		return true;
	}
	else return false;
}
void CRectangle::Move(int x, int y)
{
	int Corner1x = Corner1.x+x;
	int Corner1y = Corner1.y+y;
	int Corner2x = Corner2.x +x;
	int Corner2y = Corner2.y +y;

	if (Corner1y > UI.ToolBarHeight && Corner1y < UI.height - UI.StatusBarHeight && Corner2y > UI.ToolBarHeight && Corner2y < UI.height - UI.StatusBarHeight && Corner1x < UI.width - 70 && Corner2x < UI.width - 70)
	{
		Corner1.x += x;
		Corner1.y += y;
		Corner2.x += x;
		Corner2.y += y;
	}

}

CFigure * CRectangle::CreateCopy() const
{
	return new CRectangle(*this);
}

Point CRectangle::CentroidOfFigure() const
{
	Point p;
	p.x = (Corner1.x + Corner2.x) / 2;
	p.y = (Corner1.y + Corner2.y) / 2;
	return p;

}

void CRectangle::Load(ifstream & Infile)
{
	string temp; // this string will be used several time to read strings from file
	Infile >> temp; ID = stoi(temp);
	Infile >> temp; Corner1.x = stoi(temp);
	Infile >> temp; Corner1.y = stoi(temp);
	Infile >> temp; Corner2.x = stoi(temp);
	Infile >> temp; Corner2.y = stoi(temp);
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

CRectangle::~CRectangle()
{
}
