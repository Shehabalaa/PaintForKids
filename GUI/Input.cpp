#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const 
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


void Input::GetPointClickedv2(int & x, int & y) const
{

	int x1=0, y1=0, x2=100, y2=100;

	while (abs(x1 - x2)>5 || abs(y1 - y2)>5) // 5 for aprox. as mouse usually moves slightly while clicking
	{
		do
		{
			pWind->GetMouseCoord(x1, y1);
		} while (pWind->GetButtonState(LEFT_BUTTON, x1, y1) == BUTTON_UP);

		do
		{
			pWind->GetMouseCoord(x2, y2);

		} while (pWind->GetButtonState(LEFT_BUTTON, x2, y2) == BUTTON_DOWN);

	}
	x = x1;
	y = y1;
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

		else if (y >= 0 && y > UI.ToolBarHeight && x > UI.width - 70)
		{

			return Color_Palette;

		}
	}
	else if (UI.InterfaceMode == MODE_PLAY)//GUI is in PLAY mode    // eldraw
	{
	
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
			case ITM_TODRAW:	return TO_DRAW;
			case ITM_EXIT2:return EXIT;

				//ME : TODO write here 2l actions 3la 7asab 2l icons w 3adadha ..w nktbha bl tarteeb zi 2l enum
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}
	else if (UI.InterfaceMode == MODE_PICKANDHIDE)
	{

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_By_Type: return PICK_TYPE;
			case ITM_By_Filling_Color: return PICK_FILL; 
			case ITM_By_TypeandFilling_color: return PICK_TYPEFILL;
			case ITM_By_Area: return PICK_AREA;
			case ITM_Back:return TO_PLAY;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}
		//[2] User clicks on the drawing area
		else if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}
ActionType Input::SeeAction(int x,int y) const
{
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

		else if (y >= 0 && y > UI.ToolBarHeight && x > UI.width - 70)
		{

			return Color_Palette;

		}
	}
	else if (UI.InterfaceMode == MODE_PLAY)//GUI is in PLAY mode    // eldraw
	{

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
			case ITM_TODRAW:	return TO_DRAW;
			case ITM_EXIT2:return EXIT;

				//ME : TODO write here 2l actions 3la 7asab 2l icons w 3adadha ..w nktbha bl tarteeb zi 2l enum
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}
	else if (UI.InterfaceMode == MODE_PICKANDHIDE)
	{

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_By_Type: return PICK_TYPE;
			case ITM_By_Filling_Color: return PICK_FILL;
			case ITM_By_TypeandFilling_color: return PICK_TYPEFILL;
			case ITM_By_Area: return PICK_AREA;
			case ITM_Back:return TO_PLAY;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}
		//[2] User clicks on the drawing area
		else if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
}
Colors Input::GetColor()
{
	int x, y;
	pWind->WaitMouseClick(x, y);
	if (y >= 0 && y > UI.ToolBarHeight && x > UI.width - 70)
	{
		int Clicked = ((y - UI.ToolBarHeight) / UI.MenuItemWidth);

		switch (Clicked)
		{
		case ITM_black:	return SELECT_BLACK_COLOR;
		case ITM_green:	return SELECT_GREEN_COLOR;
		case ITM_yellow:	return SELECT_YELLOW_COLOR;
		case ITM_red:	return SELECT_RED_COLOR;
		case ITM_blue:	return SELECT_BLUE_COLOR;
		case ITM_brown: return SELECT_BROWN_COLOR;
		case ITM_orange: return SELECT_ORANGE_COLOR;
		case ITM_rose: return SELECT_ROSE_COLOR;
		case ITM_grey: return SELECT_GREY_COLOR;
		case ITM_lime: return SELECT_LIME_COLOR;
		case ITM_white: return SELECT_WHITE_COLOR;
		default: return EMPTY2;

		}
	}

}


int Input::GetBorder()
{
	int x, y;
	pWind->WaitMouseClick(x, y);
	if (y >= 0 && y > UI.ToolBarHeight && x > UI.width - 70)
	{
		int Clicked = ((y - UI.ToolBarHeight) / UI.MenuItemWidth);

		switch (Clicked)
		{
		case one:	return 1;
		case three:	return 3;
		case five:	return 5;
		case seven:	return 7;
		case nine:	return 9;
		case eleven: return 11;
	
		default: return -1;

		}
	}
	else return -1;


}

float Input::GetResizeRatio()
{
	int x, y;
	pWind->WaitMouseClick(x, y);
	if (y >= 0 && y > UI.ToolBarHeight && x > UI.width - 70)
	{
		int Clicked = ((y - UI.ToolBarHeight) / UI.MenuItemWidth);

		switch (Clicked)
		{
		case quarter:	return 0.25;
		case half:	return 0.5;
		case double2:	return 2;
		case quadrible:	return 4;
		default: return -1;

		}
	}
	return -1;
}
float Input::GetZoomPercentage()
{
	int x, y;
	pWind->WaitMouseClick(x, y);
	if (y >= 0 && y > UI.ToolBarHeight && x > UI.width - 70)
	{
		int Clicked = ((y - UI.ToolBarHeight) / UI.MenuItemWidth);

		switch (Clicked)
		{
		case z10:	return 0.10;
		case z25:	return 0.25;
		case z50:	return 0.50;
		case z75:	return 0.75;
		case z100:	return 1;
		case z125:	return 1.25;
		case z150:	return 1.5;
		case z200:	return 2;

		default: return -1;

		}
	}
	return -1;
}
/////////////////////////////////

Input::~Input()
{
}
