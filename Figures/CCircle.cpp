#include "CCircle.h"

CCircle::CCircle(const Point& P1 , const Point& P2,const GfxInfo & FigureGfxInfo ):CFigure(FigureGfxInfo)
{
	center = P1;
	circum = P2;
	rad = sqrt(pow((circum.x - center.x), 2) + pow((circum.y - center.y), 2));
	ID = -999; // take any wrong id until be put in figlist
	Area = 3.14 *rad*rad;
}

void CCircle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("Figure Data->");
	pOut->DrawString(120, 667, "Radius :");
	pOut->DrawInt(185, 667, rad);
	pOut->DrawString(217, 667, "Area :");
	pOut->DrawInt(270, 667, Area);
	pOut->DrawString(325, 667, "ID :");
	pOut->DrawInt(357, 667, Area);

}


void CCircle::Draw(Output* pOut) const
{

	pOut->DrawCirc(center, rad, FigGfxInfo, Selected);
}

figures CCircle::FigType() const
{
	return circle;
}


bool CCircle::check(int x,int y) const
{
	int d;
	d= sqrt(pow((x - center.x), 2) + pow((y - center.y), 2));
	if (d <= rad)
	{
		return true;
	}
	else 
		return false;

}


void CCircle::Save(ofstream &fOut) const
{

	fOut << left << setw(15) << "CIRCLE" << setw(5) << ID << setw(8) << center.x << setw(8) << center.y;
	fOut << setw(36) << rad << setw(18) << FigGfxInfo.DrawClr.getColorName()<< setw(18);
	(FigGfxInfo.isFilled) ? fOut << FigGfxInfo.FillClr.getColorName() : fOut << "NO_FILL";
	fOut << FigGfxInfo.BorderWidth << endl;

}
bool  CCircle::InDrawingArea() const
{
	if (center.y > UI.ToolBarHeight && center.y < (UI.height - UI.StatusBarHeight) && center.x - rad >= 0 && center.x + rad < UI.width - 70 && center.y - rad > UI.ToolBarHeight && center.y + rad < UI.height - UI.StatusBarHeight)
	{
		return true;
	}
	else
		return false;
}
BlockingDirection CCircle::Move(int x, int y)
{
	center.x += x;
	center.y += y;
	BlockingDirection tmp = No_Block;

	 if (!this->InDrawingArea())
	 {
		 if (center.x + rad > UI.width - UI.ColorsBarWidth || center.x - rad < 0)
			 tmp = Block_in_X_Direction;
		 if (center.y - rad < UI.ToolBarHeight || center.y + rad > UI.height - UI.StatusBarHeight)
		 {
			 if (tmp == No_Block)
				 tmp = Block_in_Y_Direction;
			 else
				 tmp = Block_in_XY_Direction;
		 }
	 }
	 return tmp;
}

CFigure * CCircle::CreateCopy() const
{
	return new CCircle(*this);
}


void CCircle::Load(ifstream & Infile)
{
	string temp; // this string will be used several time to read strings from file
	Infile >> temp; ID = stoi(temp);
	Infile >> temp; center.x = stoi(temp);
	Infile >> temp; center.y = stoi(temp);
	Infile >> temp; rad = stoi(temp);
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

Point CCircle::CentroidOfFigure() const
{
	return center;
}


CCircle::~CCircle()
{
}
