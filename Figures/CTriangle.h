#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CFigure.h"
#include<cmath>
class CTriangle: public CFigure
{
private:
	Point corner1;
	Point corner2;
	Point corner3;

public:
	CTriangle(const Point& = Point(), const Point& = Point(), const Point& = Point(),const GfxInfo& = GfxInfo());
	virtual void Draw(Output* pOut) const;
	virtual figures FigType() const;
	virtual bool check(int, int) const;
	virtual void Save(ofstream &) const;
	virtual bool InDrawingArea() const;
	virtual BlockingDirection Move(int x, int y);
	virtual void Load(ifstream &Infile);
	virtual CFigure * CreateCopy() const;
	virtual Point CentroidOfFigure() const;
	virtual bool Resize(float ratio);
	virtual void PrintInfo(Output* pOut) const;
	virtual void MovetoRandomCoord(int, int, int, int);
	void SetRandomParameter(int, int, int, int);
	 ~CTriangle();
};


#endif