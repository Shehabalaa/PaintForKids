#ifndef CRECTANGLE_H
#define CRECTANLGE_H
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(const Point& = Point(),const Point& = Point(),const GfxInfo& = GfxInfo());
	virtual void Draw(Output* pOut) const;
	virtual figures FigType() const;
	virtual bool check(int, int) const;
	virtual void Save(ofstream &) const;
	virtual void Load(ifstream &Infile);
	virtual bool InDrawingArea() const;
	virtual BlockingDirection Move(int x, int y);
	virtual CFigure * CreateCopy() const;
	virtual bool Resize(float ratio);
	virtual Point CentroidOfFigure() const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void MovetoRandomCoord(int, int, int, int);
	virtual void SetRandomParameter(int, int, int, int);
	void UpdateArea();
	virtual ~CRectangle();
};


#endif