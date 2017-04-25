#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
	void ClearColorArea() const; // Utility fucntion only used by createplaytool bar when switching to play mode
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBars() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void SetBGColor(color);
	window * GetWindow();
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	
	
	///Make similar functions for drawing all other figures.
	void DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;
	void DrawTri(Point P1, Point P2, Point p3, GfxInfo RectGfxInfo, bool selected = false) const;
	void DrawCirc(Point P1, int R, GfxInfo RectGfxInfo, bool selected = false) const;
	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	void DrawInt(const int iX, const int iY, const long);
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	
	~Output();
};

#endif