#include "Cline.h"
Cline::Cline(const Point& P1,const Point& P2,const GfxInfo& FigureGfxInfo ) :CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
	if ((P1.x - P2.x) != 0)
	{
		slope = float((P1.y - P2.y)) / float(P1.x - P2.x);
	}
	else
	{
		slope = -9999999999999;
	}
	 UpdateArea();
	 length = Area;
	ID = -999; // take any wrong id until be put in figlist
}

void Cline::UpdateArea()
{
	Area = sqrt(pow((start.x - end.x), 2) + pow((start.y - end.y), 2));
	length = Area;
}


 void Cline::PrintInfo(Output* pOut) const
 {
	 string s = "Figure Data->";
	 s = s + " Length ";
	 s = s + to_string(Area);
	 s = s + " Start Point: (";
	 s = s + to_string(start.x);
	 s = s + ",";
	 s = s + to_string(start.y);
	 s = s + ") ";
	 s = s + " End Point: (";
	 s = s + to_string(end.x);
	 s = s + ",";
	 s = s + to_string(end.y);
	 s = s + ") ";
	 s = s + " ID: ";
	 s = s + to_string(ID);

	 pOut->PrintMessage(s);

 }
 bool Cline::Resize(float ratio)
 {
	 Point tmp1 = start;
	 Point tmp2 = end;
	 float X, Y, X1, Y1, X2, Y2 = 0;
	 //double z, w, m;
	 X = abs(start.x - end.x);
	 Y = abs(start.y - end.y);
	 //z= modf((double)((ratio-1)*X),&w);
	 //m= modf((double)((ratio-1)*Y),&w);
	 if (start.x>end.x)
	 {
		 X1 = (0.5)*(ratio - 1)*X + start.x;
		 X2 = -(0.5)*(ratio - 1)*X + end.x;
	 }
	 else
	 {
		 X1 = -(0.5)*(ratio - 1)*X + start.x;
		 X2 = (0.5)*(ratio - 1)*X + end.x;
	 }
	 if (start.y>end.y)
	 {
		 Y1 = (0.5)*(ratio - 1)*Y + start.y;
		 Y2 = -(0.5)*(ratio - 1)*Y + end.y;
	 }
	 else
	 {
		 Y1 = -(0.5)*(ratio - 1)*Y + start.y;
		 Y2 = (0.5)*(ratio - 1)*Y + end.y;
	 }
	 start.x = X1;
	 start.y = Y1;
	 end.x = X2;
	 end.y = Y2;
	 //more approximations 
	 // Y1=(0.5)*(ratio-1)*Y + start.y+m;
	 //Y2= (0.5)*(ratio-1)*Y - end.y-m;
	 //  X1=(0.5)*(ratio-1)*X + start.x+z;
	 //	X2=(0.5)*(ratio-1)*X + end.x-z;    
	 if (InDrawingArea())
	 {
		 UpdateArea();
		 return true;
	 }
	 else
	 {
		 
		 start = tmp1;
		 end = tmp2;
		 return false;
	 }

 }

 void Cline::MovetoRandomCoord(int X_begin, int X_end, int Y_begin, int Y_end)
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

		 if (arr[i]->y < arr[min_y_indx]->y)
			 min_y_indx = i;
		 else if (arr[i]->y > arr[max_y_indx]->y)
			 max_y_indx = i;

	 }

	 // moving all points taking min_x as ref
	 int Temp = arr[min_x_indx]->x;
	 X_end -= (arr[max_x_indx]->x - arr[min_x_indx]->x);
	 New_X = rand() % (X_end - X_begin + 1) + X_begin;
	 for (int i = 0; i < 2; i++)
	 {
		 arr[i]->x += New_X - Temp;
	 }

	 // moving all points taking min_y as ref
	 Temp = arr[min_y_indx]->y;
	 Y_end -= (arr[max_y_indx]->y - arr[min_y_indx]->y);
	 New_Y = rand() % (Y_end - Y_begin + 1) + Y_begin;
	 for (int i = 0; i < 2; i++)
	 {
		 arr[i]->y += New_Y - Temp;
	 }

 }

 void Cline::SetRandomParameter(int X_begin, int X_end, int Y_begin, int Y_end)
 {
	 start.x = rand() % (X_end - X_begin + 1) + X_begin;
	 start.y = rand() % (Y_end - Y_begin + 1) + Y_begin;
	 end.x = rand() % (X_end - X_begin + 1) + X_begin;
	 end.y = rand() % (Y_end - Y_begin + 1) + Y_begin;

 }

 void Cline::SetScrambleParameter()
 {
	 start.x *= .5;
	 start.y *= .5;
	 end.x *= .5;
	 end.y *= .5;
	 length *= .5;
	 UpdateArea();
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

	if (slope == -9999999999999)
	{
		
		if (y >= start.y*UI.ZoomFactor && y <= end.y*UI.ZoomFactor  && abs(end.x*UI.ZoomFactor - x)<2 || (y<=start.y*UI.ZoomFactor && y>=end.y*UI.ZoomFactor) && abs(end.x*UI.ZoomFactor - x)<2)
			 return true;
		
		
	}
	else if (slope == 0)
	{
		if ((x > start.x*UI.ZoomFactor && x < end.x*UI.ZoomFactor) && abs(end.y*UI.ZoomFactor - y)<2 || (x<start.x*UI.ZoomFactor && x>end.x*UI.ZoomFactor) && abs(end.y*UI.ZoomFactor - y)<2)
			return true;
	}
	else
	{
		float slope2 = float(y - end.y*UI.ZoomFactor) / float(x - end.x*UI.ZoomFactor);
		float slope3 = float(y - start.y*UI.ZoomFactor) / float(x - start.x*UI.ZoomFactor);
		if (abs(abs(slope) - abs(slope2)) < 1 || abs(abs(slope) - abs(slope3) < 1))//if any body wants to make the margin bigger change the 1 to a larger value
		{
			float l1 = sqrt(pow((x - start.x*UI.ZoomFactor), 2) + pow((y - start.y*UI.ZoomFactor), 2));
			float l2 = sqrt(pow((x - end.x*UI.ZoomFactor), 2) + pow((y - end.y*UI.ZoomFactor), 2));
			float ZoomArea= sqrt(pow((start.x*UI.ZoomFactor - end.x*UI.ZoomFactor), 2) + pow((start.y*UI.ZoomFactor - end.y*UI.ZoomFactor), 2));
			if (abs((l1 + l2) - ZoomArea) <= 0.5)
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
	if (start.y > UI.ToolBarHeight +1 && start.y < UI.height - UI.StatusBarHeight  && end.y > UI.ToolBarHeight +1 && end.y < (UI.height - UI.StatusBarHeight -1) && start.x < UI.width -15 && end.x < UI.width -1 && start.x >0 && end.x >0)
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
		if (start.x > UI.width -15 || start.x < 0 || end.x > UI.width -15 || end.x < 0)
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
	UpdateArea();

}


Cline::~Cline()
{
}
