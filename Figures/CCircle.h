#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point center;
	Point circum;
	int rad;

public:
	CCircle(const Point& = Point(), const Point& = Point(), const GfxInfo& = GfxInfo(),int = -2);
	virtual void Draw(Output* pOut) const;
	virtual figures FigType() const;
	virtual bool check(int x,int y) const;
	virtual void Save(ofstream &) const;
	virtual bool InDrawingArea() const;
	virtual void Load(ifstream &Infile);
	virtual void Move(int x, int y);
	virtual void PrintInfo(Output* pOut) const;
	virtual ~CCircle();
};



#endif