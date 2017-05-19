#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class Cline: public CFigure
{
private:
	Point start;
	Point end;
	float slope;
	float length;
public:
	Cline(const Point& = Point(), const Point& = Point(),const GfxInfo& = GfxInfo());
	virtual void Draw(Output* pOut) const;
	virtual figures FigType() const;
	virtual bool check(int, int) const;
	virtual void Save(ofstream &) const;
	virtual bool InDrawingArea() const;
	virtual void Load(ifstream &Infile);
	virtual bool Resize(float ratio);
	virtual BlockingDirection Move(int x, int y);
	virtual CFigure * CreateCopy() const;
	virtual Point CentroidOfFigure() const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void MovetoRandomCoord(int, int, int, int);
	virtual void SetRandomParameter(int, int, int, int);
	void UpdateArea();
	virtual ~Cline();
};


#endif