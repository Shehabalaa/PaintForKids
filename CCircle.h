
#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point center;
	Point rad;

public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif