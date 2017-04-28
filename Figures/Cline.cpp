#include "Cline.h"
Cline::Cline(const Point& P1,const Point& P2,const GfxInfo& FigureGfxInfo , int figs_count ) :CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
	if ((P1.x - P2.x) != 0)
	slope = float((P1.y - P2.y)) / float(P1.x - P2.x);
	else slope = -1;

	length = sqrt(pow((start.x - end.x), 2) + pow((start.y - end.y), 2));
	ID = figs_count + 1;
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
	if (start.y > UI.ToolBarHeight && start.y < UI.height - UI.StatusBarHeight && end.y > UI.ToolBarHeight && end.y < UI.height - UI.StatusBarHeight && start.x < UI.width - 70 && end.x < UI.width - 70)
	{
		return true;
	}
	else return false;



}
void Cline::Move(int x, int y)
{
	int startx = start.x + x;
	int starty = start.y + y;
	int endx = end.x + x;
	int endy = end.y + y;

	if (starty > UI.ToolBarHeight && starty < UI.height - UI.StatusBarHeight && endy > UI.ToolBarHeight && endy < UI.height - UI.StatusBarHeight && startx < UI.width - 70 && endx < UI.width - 70)
	{
		start.x += x;
		start.y += y;
		end.x += x;
		end.y += y;
	}



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
