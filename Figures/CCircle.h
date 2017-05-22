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
	CCircle(const Point& = Point(), const Point& = Point(), const GfxInfo& = GfxInfo());
	virtual void Draw(Output* pOut) const;
	virtual figures FigType() const;
	virtual bool check(int x,int y) const;
	virtual void Save(ofstream &) const;
	virtual bool InDrawingArea() const;
	virtual void Load(ifstream &Infile);
	virtual bool Resize(float ratio);
	virtual BlockingDirection Move(int x, int y);
	virtual CFigure * CreateCopy() const;
	virtual Point CentroidOfFigure() const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void MovetoRandomCoord(int, int, int, int);
	void SetRandomParameter(int, int, int, int);
	virtual void SetScrambleParameter();
	void UpdateArea();
	virtual ~CCircle();
};




#endif