
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
	Cline(const Point& = Point(), const Point& = Point(),const GfxInfo& = GfxInfo() ,int = -2);
	virtual void Draw(Output* pOut) const;
	virtual figures FigType() const;
	virtual bool check(int, int) const;
	virtual void Save(ofstream &) const;
	virtual bool InDrawingArea() const;
	virtual void Load(ifstream &Infile);
	virtual ~Cline();
};

#endif