#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\Global_Colors.h"
#include<fstream>
//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BORDER_WIDTH, //Change Border width
	CHNG_BK_CLR,	//Change background color
	SELECT,
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	UNDO,			//Undo an Action
	REDO,			//Redo an Action
	//SEND_BACK,		//Send a figure to the back of all figures
	//BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,   //A click on the playing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place 

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
	ZOOMIN,          //Zoom in
	ZOOMOUT,		//Zoom out
	COPY,			// Copy Figure(s) to clipboard
	CUT,			// Copy Figure(s) to clipboard and remove it form figlist
	PASTE,	// Paste Figure(s) from clipboard to figlist
	Color_Palette,
	PICK,
	SCRAMBLE,
	PICK_TYPE,
	PICK_FILL,
	PICK_TYPEFILL,
	PICK_AREA,
	PICKED_rec,
	PICKED_Line,
	PICKED_Circ,
	PICKED_Tri,
	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{
	Point() :x(0), y(0) {} // default constructor
	int x,y; 
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	GfxInfo( ) :DrawClr(BLUE), FillClr(GREEN), isFilled(false), BorderWidth(2) {} // default constructor
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWidth;	//Width of figure borders

};

enum Colors {
	
	SELECT_BLACK_COLOR,
	SELECT_GREEN_COLOR,
	SELECT_YELLOW_COLOR,
	SELECT_BLUE_COLOR,
	SELECT_RED_COLOR,
	SELECT_BROWN_COLOR,
	SELECT_ORANGE_COLOR,
	SELECT_ROSE_COLOR,
	SELECT_LIGHT_COLOR,
	SELECT_LIME_COLOR,
	SELECT_WHITE_COLOR,
	SELECT_NON_COLOR,
	EMPTY2,

};


enum figures {

	line,
	rec,
	tri,
	circle

};

enum BlockingDirection // this enum used to indcate stop moving in certain direction due to end of drawing area
{
	Block_in_X_Direction,
	Block_in_Y_Direction,
	Block_in_XY_Direction,
	No_Block
};

enum ActionState // this enum will help to make some decions while excuting actions
{
	Successful,
	Just_Canceled,
	Canceled_And_Switched_To_Another_One

};
#endif