
#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class Cline: public CFigure
{
private:
	Point start;
	Point end;
	float slope;
	int length;
public:
	Cline(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual figures FigType();
	virtual bool check(int, int);
};

#endif