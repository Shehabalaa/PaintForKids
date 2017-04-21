
#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class Cline: public CFigure
{
private:
	Point start;
	Point end;

public:
	Cline(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif