#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo,int );
	virtual void Draw(Output* pOut) const;
	virtual figures FigType();
	virtual bool check(int, int);
	virtual void Save(ofstream &) const;
	virtual bool InDrawingArea();
};

#endif