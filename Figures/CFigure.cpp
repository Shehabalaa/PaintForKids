#include "CFigure.h"

int CFigure::ForID = 1;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}
void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}
void CFigure::ChngBorderWidth(int PenWidth)
{
	FigGfxInfo.BorderWidth = PenWidth;
}
color CFigure::GetDrawClr() const
{
	return FigGfxInfo.DrawClr;
}
color CFigure::GetFillClr()const
{
	return FigGfxInfo.FillClr;
}

int CFigure::GetArea() const
{
	return Area; 
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

bool CFigure::IsFilled() const
{
	return FigGfxInfo.isFilled;
}




void CFigure::SetID()
{
	ID = ForID++;
}

void CFigure::SetID(int id)
{
	ID = id;
}


void CFigure::UpdateArea()
{
}

int CFigure::GetID() const
{
	return ID;
}

CFigure::~CFigure()
{
}


