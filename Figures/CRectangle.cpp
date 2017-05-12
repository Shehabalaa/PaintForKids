#include "CRectangle.h"

CRectangle::CRectangle(const Point& P1, const Point& P2,const GfxInfo& FigureGfxInfo  ):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID = -999; // take any wrong id until be put in figlist
}
bool CRectangle::Resize(float ratio)
{
	Point tmpc1 = Corner1;
	Point tmpc2 = Corner2;

	float X = 0, Y = 0, X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
	//double z,w,m;
	X = abs(Corner1.x - Corner2.x);
	Y = abs(Corner1.y - Corner2.y);
	//z= modf((double)((ratio-1)*X),&w);
	//m= modf((double)((ratio-1)*Y),&w);

	if (Corner1.x >Corner2.x)
	{
		X1 = (0.5)*(ratio - 1)*X + Corner1.x;
		X2 = -(0.5)*(ratio - 1)*X + Corner2.x;
	}
	else
	{
		X1 = -(0.5)*(ratio - 1)*X + Corner1.x;
		X2 = (0.5)*(ratio - 1)*X + Corner2.x;
	}

	if (Corner1.y >Corner2.y)
	{
		Y1 = (0.5)*(ratio - 1)*Y + Corner1.y;
		Y2 = -(0.5)*(ratio - 1)*Y + Corner2.y;
	}
	else
	{
		Y1 = -(0.5)*(ratio - 1)*Y + Corner1.y;
		Y2 = (0.5)*(ratio - 1)*Y + Corner2.y;
	}

	/*
	X1=(0.5)*(ratio-1)*X+ Corner1.x+z;
	X2=(0.5)*(ratio-1)*X+ Corner2.x-z;
	Y1=(0.5)*(ratio-1)*Y+ Corner1.y+m;
	Y2= (0.5)*(ratio-1)*Y+ Corner2.y-m;
	/*/
	(Corner1.x) = X1;
	(Corner1.y) = Y1;
	(Corner2.x) = X2;
	(Corner2.y) = Y2;
	if (InDrawingArea())
		return true;
	else
	{
		Corner1 = tmpc1;
		Corner2 = tmpc2;
		return false;
	}
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
	string s = "Figure Data->";
	s = s + " Area: ";
	s = s + to_string(Area);
	s = s + " First Corner: (";
	s = s + to_string(Corner1.x);
	s = s + ",";
	s = s + to_string(Corner2.y);
	s = s + ") ";
	s = s + " Second Corner: (";
	s = s + to_string(Corner2.x);
	s = s + ",";
	s = s + to_string(Corner2.y);
	s = s + ") ";
	s = s + " ID: ";
	s = s + to_string(ID);

	pOut->PrintMessage(s);


}

void CRectangle::SetRandomCoord(int X_begin, int X_end, int Y_begin, int Y_end)
{
	int New_X = 0, New_Y = 0;
	int min_x_indx = 0, min_y_indx = 0;
	int max_x_indx = 0, max_y_indx = 0;
	Point *arr[2] = {&Corner1,&Corner2};

	// i will work on min_X_point and adjust the other point_X_coord depeding on that
	// then on min_Y_point adjust the other point_Y_coord depeding on that

	for (int i = 1; i < 2; i++)
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
	for (int i = 0; i < 2; i++)
	{
		arr[i]->x += New_X - arr[min_x_indx]->x;
	}

	// moving all points taking min_y as ref

	Y_end -= (arr[max_y_indx]->y - arr[min_y_indx]->y);
	New_Y = rand() % (Y_end - Y_begin + 1) + Y_begin;
	for (int i = 0; i < 2; i++)
	{
		arr[i]->y += New_Y - arr[min_y_indx]->y;
	}

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
	if (Corner1.y > UI.ToolBarHeight && Corner1.y < UI.height - UI.StatusBarHeight && Corner2.y > UI.ToolBarHeight && Corner2.y < UI.height - UI.StatusBarHeight && Corner1.x < UI.width - UI.ColorsBarWidth && Corner2.x < UI.width - UI.ColorsBarWidth  && Corner1.x >0 && Corner2.x >0)
	{
		return true;
	}
	else return false;
}
BlockingDirection CRectangle::Move(int x, int y)
{
	BlockingDirection tmp = No_Block;
	Corner1.x += x;
	Corner1.y += y;
	Corner2.x += x;
	Corner2.y += y;
	if (!this->InDrawingArea())
	{
		if (Corner2.x > UI.width - UI.ColorsBarWidth || Corner2.x < 0|| Corner1.x > UI.width - UI.ColorsBarWidth || Corner1.x < 0)
			tmp= Block_in_X_Direction;

		if (Corner2.y < UI.ToolBarHeight || Corner2.y > UI.height - UI.StatusBarHeight || Corner1.y < UI.ToolBarHeight || Corner1.y > UI.height - UI.StatusBarHeight)
			if(tmp==No_Block)
				tmp= Block_in_Y_Direction;
			else
				tmp = Block_in_XY_Direction;
	}

	return tmp;
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
