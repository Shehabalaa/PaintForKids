
#ifndef CRECT_H
#define CRECT_H
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(const Point& = Point(),const Point& = Point(),const GfxInfo& = GfxInfo() ,int = -2 );
	virtual void Draw(Output* pOut) const;
	virtual figures FigType() const;
	virtual bool check(int, int) const;
	virtual void Save(ofstream &) const;
	virtual void Load(ifstream &Infile);
	virtual bool InDrawingArea() const;
	virtual ~CRectangle();
};

#endif