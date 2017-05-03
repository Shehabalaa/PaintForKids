#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\DEFS.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	int Area; // Figure Area
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual void Draw(Output* pOut) const  = 0;	  //Draw the figure
	virtual BlockingDirection Move(int ,int)=0;     //Move the figure this enum will idicate that while moving figure gets out of drawing area in a certian direction
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual CFigure * CreateCopy() const = 0;// this fucntion create a copy form figure and return upcasted pointer to base of this copy

	virtual figures FigType() const=0;

	virtual bool InDrawingArea() const = 0;

	virtual bool check(int,int) const = 0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure

	virtual void Save(ofstream &OutFile) const = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual Point CentroidOfFigure() const = 0; // Returns the centre(x,y) of figure as the kind as of the figure
	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar

	virtual ~CFigure(); // virtual destructor to avoid delete with pointer to figure and hold address of real fig(rec,tri,...) in heap

};


#endif