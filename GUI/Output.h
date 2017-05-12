#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"


class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		
	
	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreateColorsBar() const; // create olors bar with animation 
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreatePickandHideToolBar() const; //  draw the pick and hide toolbar
	void CreatePickandHideFiguresToolBar() const;
	void CreateStatusBar() const;	//create the status bar
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearDrawModeToolBars() const; // Clears the DrawModeToolBars (Colors bar and toolbar)
	void ClearPlayModeToolBar() const; // Clears the PlayModeToolBar 
	void SetBGColor(const color&); // Changing BackGround Color
	void PrintGuideMessages(ActionType); // this func guide user by tracking mouse and printing messages
	window * GetWindow();
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	
	
	///Make similar functions for drawing all other figures.
	void DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;
	void DrawTri(Point P1, Point P2, Point p3, GfxInfo RectGfxInfo, bool selected = false) const;
	void DrawCirc(Point P1, int R, GfxInfo RectGfxInfo, bool selected = false) const;
	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	void DrawInt(const int iX, const int iY, const long);
	void DrawString(const int iX, const int iY, const string strText);

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	
	~Output();
};

#endif