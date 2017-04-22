
#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CTriangle: public CFigure
{
private:
	Point corner1;
	Point corner2;
	Point corner3;

public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool check(int, int);
	virtual figures FigType();
	virtual void Save(ofstream &) const;
};

#endif