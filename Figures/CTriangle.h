
#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include<cmath>
class CTriangle: public CFigure
{
private:
	Point corner1;
	Point corner2;
	Point corner3;

public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual figures FigType();
	virtual bool check(int, int);
	virtual void Save(ofstream &) const;
};

#endif