#include "Cline.h"
Cline::Cline(const Point& P1,const Point& P2,const GfxInfo& FigureGfxInfo ) :CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
	if ((P1.x - P2.x) != 0)
	slope = float((P1.y - P2.y)) / float(P1.x - P2.x);
	else slope = -1;

	length = sqrt(pow((start.x - end.x), 2) + pow((start.y - end.y), 2));
	ID = -999; // take any wrong id until be put in figlist
}





 void Cline::PrintInfo(Output* pOut) const
 {
	 pOut->DrawString(230, 667, "Radius :");
	 pOut->DrawInt(270, 667, 5);

 }

 void Cline::SetRandomCoord(int X_begin, int X_end, int Y_begin, int Y_end)
 {
	 int New_X = 0, New_Y = 0;
	 int min_x_indx = 0, min_y_indx = 0;
	 int max_x_indx = 0, max_y_indx = 0;
	 Point *arr[2] = { &start,&end };

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


void Cline::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(start, end, FigGfxInfo, Selected);
}

figures Cline::FigType() const
{
	return line;
}
bool Cline::check(int x, int y) const
{
	if (slope == -1)
	{
		
		if ((y > start.y && y < end.y) || (y<start.y && y>end.y))
			 return true;
		if (start.x == end.x && abs(end.x - x) < 2 && start.y == end.y && abs(end.y - y) <2) // if line just a point this cals.- abd abs to make it easy to select just point :D
			return true;
		
	}
	else if (slope == 0)
	{
		if ((x > start.x && x < end.x) || (x<start.x && x>end.x))
			return true;
	}
	else
	{
		float slope2 = float(y - start.y) / float(x - start.x);
		if (abs(slope - slope2) < 3)
		{
			float l1 = sqrt(pow((x - start.x), 2) + pow((y - start.y), 2));
			float l2 = sqrt(pow((x - end.x), 2) + pow((y - end.y), 2));
			if (abs((l1 + l2) - length) <= 1)
				return true;
			else return false;
		}
	}
	return false;

}


void Cline::Save(ofstream & fOut) const
{
	fOut << left << setw(15) << "LINE" << setw(5) << ID << setw(8) << start.x << setw(8) << start.y;
	fOut << setw(8) << end.x << setw(28) << end.y << setw(36) << FigGfxInfo.DrawClr.getColorName();
	fOut << FigGfxInfo.BorderWidth << endl;
}

bool  Cline::InDrawingArea() const
{
	if (start.y > UI.ToolBarHeight +1 && start.y < UI.height - UI.StatusBarHeight  && end.y > UI.ToolBarHeight +1 && end.y < (UI.height - UI.StatusBarHeight -1) && start.x < UI.width - UI.ColorsBarWidth -1 && end.x < UI.width - UI.ColorsBarWidth -1 && start.x >0 && end.x >0)
	{
		return true;
	}
	else 
		return false;



}
BlockingDirection Cline::Move(int x, int y)
{
	BlockingDirection tmp = No_Block;
	start.x += x;
	start.y += y;
	end.x += x;
	end.y += y;

	if (!this->InDrawingArea())
	{
		if (start.x > UI.width - UI.ColorsBarWidth -1 || start.x < 0 || end.x > UI.width - UI.ColorsBarWidth -1 || end.x < 0)
			tmp = Block_in_X_Direction;

		if (start.y < UI.ToolBarHeight +1 || start.y > UI.height - UI.StatusBarHeight -2  || end.y < UI.ToolBarHeight +1 || end.y > UI.height - UI.StatusBarHeight -2)
			if (tmp == No_Block)
				tmp = Block_in_Y_Direction;
			else
				tmp = Block_in_XY_Direction;
	}

	return tmp;

	
}

CFigure * Cline::CreateCopy() const
{
	return new Cline(*this);
}

Point Cline::CentroidOfFigure() const
{
	Point p;
	p.x = (start.x + end.x) / 2;
	p.y = (start.y + end.y) / 2;
	return p;
}

void Cline::Load(ifstream & Infile)
{
	string temp; // this string will be used several time to read strings from file
	Infile >> temp; ID = stoi(temp);
	Infile >> temp; start.x = stoi(temp);
	Infile >> temp; start.y = stoi(temp);
	Infile >> temp; end.x = stoi(temp);
	Infile >> temp; end.y = stoi(temp);
	Infile >> temp; FigGfxInfo.DrawClr = color::getColorObject(temp);
	Infile >> temp;  FigGfxInfo.BorderWidth = stoi(temp);

}

Cline::~Cline()
{
}
