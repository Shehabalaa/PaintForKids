#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};
enum ColorMenuItem //for drawing fillg background colors
{
	black,
	green,
	yellow,
	blue,
	red,
	brown,
	orange,
	colors_num
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_LINE,		//Line item in menu
	ITM_RECT,		//Recangle item in menu
	ITM_TRI,		//Triangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_CHNG_DRAW_CLR, // Changing draw color
	ITM_CHNG_FILL_CLR, // Changing fill color
	ITM_CHNG_BORDER_WIDTH, // Changing border width
	ITM_CHNG_BK_CLR,   // Changing background color
	ITM_DELETE,        // Deleting item(s) from graph
	ITM_MOVE,			// Moving item(s)
	ITM_ROTATE,         // Rotating item(s)
	ITM_RESIZE,			// Resising item(s)
	ITM_ZOOMIN,			// Zooming item(s) in
	ITM_ZOOMOUT,		// Zooming item(s) out
	ITM_COPY,			// Coping item(s)
	ITM_CUT,			// Cutting item(s)
	ITM_PASTE,			// Pasting item(s)
	ITM_UNDO,			// Undo action
	ITM_REDO,			// Redo action
	ITM_SAVE,			// Saving item(s)
	ITM_LOAD,			// Loading item(s)
	ITM_TOPLAY,			// Switching to play mode
	//TODO: Add more items names here
	ITM_EXIT1,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_PICK,
	ITM_SCRAMBLE,
	ITM_TODRAW,
	ITM_EXIT2,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif