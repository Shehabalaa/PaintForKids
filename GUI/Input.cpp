#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const                          //????
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8 && Label.size()>0)	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else if (Key != 8)
			Label += Key;
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_LINE:	return DRAW_LINE;
			case ITM_RECT:	return DRAW_RECT;
			case ITM_TRI:	return DRAW_TRI;
			case ITM_CIRC:	return DRAW_CIRC;
			case ITM_CHNG_DRAW_CLR: return CHNG_DRAW_CLR;
			case ITM_CHNG_FILL_CLR:	return CHNG_FILL_CLR;
			case ITM_CHNG_BORDER_WIDTH:return CHNG_BORDER_WIDTH;
			case ITM_CHNG_BK_CLR:	return CHNG_BK_CLR;
			case ITM_SELECT: return SELECT;
			case ITM_DELETE:	return DEL;
			case ITM_MOVE:	return MOVE;
			case ITM_RESIZE:	return RESIZE;
			case ITM_ROTATE:   return ROTATE;
			case ITM_ZOOMIN:	return ZOOMIN;
			case ITM_ZOOMOUT: return ZOOMOUT;
			case ITM_COPY:	return COPY;
			case ITM_CUT:	return CUT;
			case ITM_PASTE:	return PASTE;
			case ITM_UNDO:return UNDO;
			case ITM_REDO:return REDO;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_TOPLAY:return TO_PLAY;
			case ITM_EXIT1:return EXIT;


				//kml dool
				//ME : TODO write here 2l actions 3la 7asab 2l icons w 3adadha ..w nktbha bl tarteeb zi 2l enum


			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		else if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight  && x < UI.width - 70)
		{
			return DRAWING_AREA;
		}
		else if (y >= UI.height - UI.StatusBarHeight) //[3] User clicks on the status bar
			return STATUS;

		else
		{

			int ClickedItemOrder = ((y - UI.ToolBarHeight) / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_black:	return SELECT_BLACK_COLOR;
			case ITM_green:	return SELECT_GREEN_COLOR;
			case ITM_yellow:	return SELECT_YELLOW_COLOR;
			case ITM_red:	return SELECT_RED_COLOR;
			case ITM_blue:	return SELECT_BLUE_COLOR;
			case ITM_brown: return SELECT_BROWN_COLOR;
			case ITM_orange: return SELECT_ORANGE_COLOR;
			default: return EMPTY2;

			}
		}
	}
	else //GUI is in PLAY mode    // eldraw
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PICK:	return PICK;
			case ITM_SCRAMBLE:	return SCRAMBLE;
			case ITM_TODRAW:	return TODRAW;
			case ITM_EXIT2:return EXIT;

				//ME : TODO write here 2l actions 3la 7asab 2l icons w 3adadha ..w nktbha bl tarteeb zi 2l enum
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}


}

/////////////////////////////////

Input::~Input()
{
}
