#include "Output.h"
class Input;

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 53.7;   //2zabt 2l icons l width bta3h
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = BLACK;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	//ana 2det lohm kyam ibtda2ya f l2wl w b3den 3mlt lhm creation
	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids -team 13");
	
	CreateDrawToolBars();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);   
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBars() const
{
	// Here we have 2 tool bars
	// 1. actions toolbar
	// 2. colors toolbar

	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg"; //
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rec.jpg";//
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\tri.jpg";//
	MenuItemImages[ITM_CIRC]="images\\MenuItems\\circle.jpg";//
	MenuItemImages[ITM_CHNG_DRAW_CLR]="images\\MenuItems\\colord.jpg";//
	MenuItemImages[ITM_CHNG_FILL_CLR]="images\\MenuItems\\colorf.jpg";//
	MenuItemImages[ITM_CHNG_BK_CLR] = "images\\MenuItems\\colorbg.jpg";//
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";//
	MenuItemImages[ITM_DELETE]="images\\MenuItems\\delete.jpg";//
	MenuItemImages[ITM_MOVE]="images\\MenuItems\\move.jpg";//
	MenuItemImages[ITM_RESIZE]="images\\MenuItems\\resize.jpg";//
	MenuItemImages[ITM_ZOOMIN] = "images\\MenuItems\\zoomin.jpg";//
	MenuItemImages[ITM_ZOOMOUT] = "images\\MenuItems\\zoomout.jpg";//
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";//
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg"; //
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";//
	MenuItemImages[ITM_SAVE]="images\\MenuItems\\save.jpg";//
	MenuItemImages[ITM_LOAD]="images\\MenuItems\\load.jpg";//
	MenuItemImages[ITM_TOPLAY]="images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_EXIT1] = "images\\MenuItems\\exit.jpg";//
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\rotate.jpg"; 
	MenuItemImages[ITM_CHNG_BORDER_WIDTH] = "images\\MenuItems\\bwidth.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//First drawing white area to clear last toolbar
	pWind->DrawImage("images\\MenuItems\\Blank.jpg", 0, 0, UI.width, UI.ToolBarHeight);

	//Then loading tool bar images

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under actions toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	string col[colors_num]; // here we drawing colors coulom
	col[ITM_black] = "images\\MenuItems\\black.jpg";
	col[ITM_green] = "images\\MenuItems\\green.jpg";
	col[ITM_blue] = "images\\MenuItems\\blue.jpg";
	col[ITM_red] = "images\\MenuItems\\red.jpg";
	col[ITM_yellow] = "images\\MenuItems\\yellow.jpg";
	col[ITM_brown] = "images\\MenuItems\\brown.jpg";
	col[ITM_orange] = "images\\MenuItems\\orange.jpg";

	for (int i = 0; i<colors_num; i++)
		pWind->DrawImage(col[i], UI.width-69, (i*UI.MenuItemWidth) + UI.ToolBarHeight +4 , UI.MenuItemWidth, UI.ToolBarHeight);

	

	//Draw a line parllel to colors toolbar
	if(UI.BkGrndColor == BLUE)
		pWind->SetPen(RED, 1);
	else
		pWind->SetPen(BLUE, 1);

	pWind->DrawLine(UI.width-70, UI.ToolBarHeight, UI.width-70, UI.height-UI.StatusBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;

	///TODO: write code to create Play mode menu

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICK] = "images\\MenuItems\\FIND.jpg";
	MenuItemImages[ITM_SCRAMBLE] = "images\\MenuItems\\SCRAMBLE.jpg";
	MenuItemImages[ITM_TODRAW] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\exit.jpg";

	
	//First drawing white area to clear last toolbar
	pWind->DrawImage("images\\MenuItems\\Blank.jpg", 0, 0, UI.width, UI.ToolBarHeight);
	
	ClearColorArea();// Clearing colors list its no more needed
 
	//Then loading tool bar images
	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearColorArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(UI.width - 71, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
/////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width - 70, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	//check if rectangle in drawing area
	if (P1.y > UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight && P2.y > UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight && P1.x< UI.width - 70 && P2.x< UI.width - 70)
	{
		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;


		pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);


	}
	else
	{

		int x = 0, y = 0;
		PrintMessage("Wrong Points!!! Figure Out of Drawing Area!!!,Click to continue");
		
		
	}
	
}
//LINE
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	//check if Line in drawing area
	if (P1.y > UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight && P2.y > UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight && P1.x< UI.width - 70 && P2.x < UI.width - 70)
	{


		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = LineGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (LineGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(LineGfxInfo.FillClr);
		}
		else
			style = FRAME;


		pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
	}
	else
	{
		int x = 0, y = 0;
		PrintMessage("Wrong Points!!! Figure Out of Drawing Area!!!,Click to continue");
		pWind->WaitMouseClick(x, y);
		ClearStatusBar();
		


		
	}

}
//Trianlge
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	//check if Tri in drawing area
	if (P1.y > UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight && P2.y > UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight && P3.y > UI.ToolBarHeight && P3.y < UI.height - UI.StatusBarHeight  && P1.x< UI.width - 70 && P2.x < UI.width - 70 && P3.x < UI.width - 70)
	{
		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = TriGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (TriGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(TriGfxInfo.FillClr);
		}
		else
			style = FRAME;


		pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	}
	else
	{
		int x = 0, y = 0;
		PrintMessage("Wrong Points!!! Figure Out of Drawing Area!!!,Click to continue");
	
		pWind->WaitMouseClick(x, y);
		ClearStatusBar();
	}

}
//Circle
void Output::DrawCirc(Point P1, int R, GfxInfo CircGfxInfo, bool selected) const
{
	//check if cricle in drawing area
	if (P1.y > UI.ToolBarHeight && P1.y < (UI.height - UI.StatusBarHeight) && P1.x - R >= 0 && P1.x+R < UI.width-70 &&  P1.y - R > UI.ToolBarHeight && P1.y + R < UI.height - UI.StatusBarHeight )
	{
		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = CircGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (CircGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(CircGfxInfo.FillClr);
		}
		else
			style = FRAME;


		pWind->DrawCircle(P1.x, P1.y, R, style);
	}
	else
	{
		int x = 0, y = 0;
		PrintMessage("Wrong Points!!! Figure Out of Drawing Area!!!,Click to continue");
		pWind->WaitMouseClick(x, y);
		ClearStatusBar();
	}

}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

