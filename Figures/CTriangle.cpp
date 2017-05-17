#include "CTriangle.h"
#include<algorithm>
#include<cmath>

CTriangle::CTriangle(const Point& P1, const Point& P2 , const Point& P3, const GfxInfo& FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	corner1 = P1;
	corner2 = P2;
	corner3 = P3;
	ID = -999; // take any wrong id until be put in figlist
	UpdateArea();
}

void CTriangle::UpdateArea()
{
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

bool CTriangle::Resize(float ratio)
{
	Point tmpc1 = corner1;
	Point tmpc2 = corner2;
	Point tmp3 = corner3;
	float X1, Y1, X2, Y2, X3, Y3 = 0;
	Point centre = CentroidOfFigure();
	//X=(ratio-1);

	X1 = (ratio - 1)*(corner1.x - centre.x) + (corner1.x);
	X2 = (ratio - 1)*(corner2.x - centre.x) + (corner2.x);
	X3 = (ratio - 1)*(corner3.x - centre.x) + (corner3.x);
	Y1 = (ratio - 1)*(corner1.y - centre.y) + (corner1.y);
	Y2 = (ratio - 1)*(corner2.y - centre.y) + (corner2.y);
	Y3 = (ratio - 1)*(corner3.y - centre.y) + (corner3.y);
	//double z,w,m;
	//M3mlt4 2l handling of ratio hna
	//z= modf((double)((ratio-1)*X),&w);
	//m=modf((double)((ratio-1)*Y),&w);
	/*	X=(0.5)*(ratio-1);

	X1=X*((corner1.x -corner2.x)+ (corner1.x -corner3.x))+corner1.x;
	X2=X*((corner2.x -corner1.x) + (corner2.x -corner3.x))+corner2.x;
	X3=X*((corner3.x -corner1.x) + (corner3.x -corner2.x))+corner3.x;

	Y1=X*((corner1.y -corner2.y) + (corner1.y -corner3.y))+corner1.y;
	Y2=X*((corner2.y -corner1.y )+ (corner2.y -corner3.y))+corner2.y;
	Y3=X*((corner3.y -corner1.y )+ (corner3.y -corner2.y))+corner3.y;*/

	corner1.x = X1;
	corner1.y = Y1;
	corner2.x = X2;
	corner2.y = Y2;
	corner3.x = X3;
	corner3.y = Y3;
	if (InDrawingArea())
	{
		UpdateArea();
		return true;
	}
	else
	{
		corner1 = tmpc1;
		corner2 = tmpc2;
		corner3 = tmp3;
		return false;
	}

	
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

	string s = "Figure Data->";
	s = s + " Area: ";
	s = s + to_string(Area);
	s = s + " First Corner: (";
	s = s + to_string(corner1.x);
	s = s + ",";
	s = s + to_string(corner2.y);
	s = s + ") ";
	s = s + " Second Corner: (";
	s = s + to_string(corner2.x);
	s = s + ",";
	s = s + to_string(corner2.y);
	s = s + ") ";
	s = s + " Third Corner: (";
	s = s + to_string(corner3.x);
	s = s + ",";
	s = s + to_string(corner3.y);
	s = s + ") ";
	s = s + " ID: ";
	s = s + to_string(ID);

	pOut->PrintMessage(s);
}

void CTriangle::MovetoRandomCoord(int X_begin, int X_end, int Y_begin, int Y_end)
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

		if (arr[i]->y < arr[min_y_indx]->y)
			min_y_indx = i;
		else if (arr[i]->y > arr[max_y_indx]->y)
			max_y_indx = i;

	}

	// moving all points taking min_x as ref
	int Temp = arr[min_x_indx]->x;
	X_end -= (arr[max_x_indx]->x - arr[min_x_indx]->x);
	New_X = rand() % (X_end - X_begin + 1) + X_begin;
	for (int i = 0; i < 3; i++)
	{
		arr[i]->x += New_X - Temp;
	}

	// moving all points taking min_y as ref
	Temp = arr[min_y_indx]->y;
	Y_end -= (arr[max_y_indx]->y - arr[min_y_indx]->y);
	New_Y = rand() % (Y_end - Y_begin + 1) + Y_begin;
	for (int i = 0; i < 3; i++)
	{
		arr[i]->y += New_Y - Temp;
	}

}


void CTriangle::SetRandomParameter(int X_begin, int X_end, int Y_begin, int Y_end)
{
	int d12=0, d13=0, d23=0;
	//do
	//{
		corner1.x = rand() % (X_end - X_begin + 1) + X_begin;
		corner1.y = rand() % (Y_end - Y_begin + 1) + Y_begin;
		corner2.x = rand() % (X_end - X_begin + 1) + X_begin;
		corner2.y = rand() % (Y_end - Y_begin + 1) + Y_begin;
		corner3.x = rand() % (X_end - X_begin + 1) + X_begin;
		corner3.y = rand() % (Y_end - Y_begin + 1) + Y_begin;
		d12 = sqrt(pow((corner1.x - corner2.x), 2) + pow((corner1.y - corner2.y), 2));
		d13 = sqrt(pow((corner1.x - corner3.x), 2) + pow((corner1.y - corner3.y), 2));
		d23 = sqrt(pow((corner3.x - corner2.x), 2) + pow((corner3.y - corner2.y), 2));	
//	} while ((!d12 ||!d13 || !d23) && min(d12,d13)/float(max(d12, d13)) < 1.0/2  && min(d12,d23) / float(max(d12,d23))< 1.0/ 2 && min(d13, d23) / float(max(d13, d23)) < 1.0 / 2);

		UpdateArea();
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
	if (corner1.y > UI.ToolBarHeight  && corner1.y < UI.height - UI.StatusBarHeight -1 && corner2.y > UI.ToolBarHeight && corner2.y < UI.height - UI.StatusBarHeight -1 && corner3.y > UI.ToolBarHeight && corner3.y < UI.height - UI.StatusBarHeight -1 && corner1.x < UI.width -15 && corner2.x < UI.width-15 && corner3.x < UI.width -15 && corner1.x >0 && corner2.x > 0 && corner3.x > 0 )
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
		if (corner1.x > UI.width -15 || corner1.x < 0 || corner2.x > UI.width  -15 || corner2.x < 0 || corner3.x > UI.width -15 || corner3.x < 0)
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
	UpdateArea();

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
