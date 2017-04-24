#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"
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
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
	ZOOMIN,          //Zoom in
	ZOOMOUT,		//Zoom out
	COPY,			// Copy Figure(s) to clipboard
	CUT,			// Copy Figure(s) to clipboard and remove it form figlist
	PASTE,			// Paste Figure(s) from clipboard to figlist
	PICK,
	SCRAMBLE,
	TODRAW,
	SELECT_BLACK_COLOR,
	SELECT_GREEN_COLOR,
	SELECT_YELLOW_COLOR,
	SELECT_BLUE_COLOR,
	SELECT_RED_COLOR,
	SELECT_BROWN_COLOR,
	SELECT_ORANGE_COLOR,
	EMPTY2 //empty on colors bar
	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};


enum figures {

	line,
	rec,
	tri,
	circle

};

#endif