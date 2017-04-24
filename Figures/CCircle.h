
#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point center;
	Point circum;
	int rad;

public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual figures FigType();
	virtual bool check(int x,int y);
	virtual void Save(ofstream &) const;
	virtual bool InDrawingArea();
};



#endif