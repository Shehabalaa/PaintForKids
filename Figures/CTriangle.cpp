#include "CTriangle.h"
#include<cmath>

CTriangle::CTriangle(const Point& P1, const Point& P2 , const Point& P3, const GfxInfo& FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	corner1 = P1;
	corner2 = P2;
	corner3 = P3;
	ID = -999; // take any wrong id until be put in figlist
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

void CTriangle::SetRandomCoord(int X_begin, int X_end, int Y_begin, int Y_end)
{
	int New_X = 0, New_Y = 0;
	int min_x_indx = 0, min_y_indx = 0;
	int max_x_indx = 0, max_y_indx = 0;
	Point *arr[3] = { &corner1,&corner2,&corner3 };

	// i will work on min_X_point and adjust the other points_X_coord depeding on that
	// then on min_Y_point adjust the other points_Y_coord depeding on that

	for (int i = 1; i < 3; i++)
	{
		if (arr[i]->x < arr[min_x_indx]->x)
			min_x_indx = i;
		else if (arr[i]->x > arr[max_x_indx]->x)
			max_x_indx = i;

		if (arr[i]->y < arr[min_y_indx]->x)
			min_y_indx = i;
		else if (arr[i]->y > arr[max_y_indx]->y)
			max_y_indx = i;

	}

	// moving all points taking min_x as ref
	X_end -= (arr[max_x_indx]->x - arr[min_x_indx]->x);
	New_X = rand() % (X_end - X_begin + 1) + X_begin;
	for (int i = 0; i < 3; i++)
	{
		arr[i]->x += New_X - arr[min_x_indx]->x;
	}

	// moving all points taking min_y as ref

	Y_end -= (arr[max_y_indx]->y - arr[min_y_indx]->y);
	New_Y = rand() % (Y_end - Y_begin + 1) + Y_begin;
	for (int i = 0; i < 3; i++)
	{
		arr[i]->y += New_Y - arr[min_y_indx]->y;
	}

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
	if (corner1.y > UI.ToolBarHeight  && corner1.y < UI.height - UI.StatusBarHeight -1 && corner2.y > UI.ToolBarHeight && corner2.y < UI.height - UI.StatusBarHeight -1 && corner3.y > UI.ToolBarHeight && corner3.y < UI.height - UI.StatusBarHeight -1 && corner1.x < UI.width - UI.ColorsBarWidth -1 && corner2.x < UI.width - UI.ColorsBarWidth -1 && corner3.x < UI.width - UI.ColorsBarWidth -1 && corner1.x >0 && corner2.x > 0 && corner3.x > 0 )
	{
		return true;
	}
	else 
		return false;

}

BlockingDirection CTriangle::Move(int x, int y)
{
	BlockingDirection tmp = No_Block;
	corner1.x += x;
	corner1.y += y;
	corner2.x += x;
	corner2.y += y;
	corner3.x += x;
	corner3.y += y;

	if (!this->InDrawingArea())
	{
		if (corner1.x > UI.width - UI.ColorsBarWidth -2 || corner1.x < 0 || corner2.x > UI.width - UI.ColorsBarWidth -2 || corner2.x < 0 || corner3.x > UI.width - UI.ColorsBarWidth -2 || corner3.x < 0)
			tmp = Block_in_X_Direction;

		if (corner1.y < UI.ToolBarHeight || corner1.y > UI.height - UI.StatusBarHeight -2 || corner2.y < UI.ToolBarHeight || corner2.y > UI.height - UI.StatusBarHeight -2 || corner3.y < UI.ToolBarHeight || corner3.y > UI.height - UI.StatusBarHeight -2)
			if (tmp == No_Block)
				tmp = Block_in_Y_Direction;
			else
				tmp = Block_in_XY_Direction;
	}

	return tmp;

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
