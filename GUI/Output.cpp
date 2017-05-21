#include "Output.h"
class Input;

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	UI.width = 1300;
	UI.height = 700;
	UI.ZoomFactor = 1;
	UI.wx = 5;
	UI.wy =5;
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 53.7;   //2zabt 2l icons l width bta3h //Width of each item in toolbar menu and Color Bar
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = BLACK;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames
	UI.ColorsBarHeight = UI.ToolBarHeight+1;		// Height of Color Bar this 1 more good view 
	UI.ColorsBarWidth = 70;		// Width of Color Bar 70 as we draw line of width one to sperate drawing area from colors area
	UI.FilledFigures = false;// default is the non-filled figures
	//ana 2det lohm kyam ibtda2ya f l2wl w b3den 3mlt lhm creation
	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids-team 13");
	
	CreateDrawToolBar();
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




window * Output::GetWindow()
{
	return pWind;
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
	//Clear Status bar by drawing a filled white rectangle // tahis not white ? same code as create ?!!!!
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawModeToolBars() const
{
	//Clear Toolbar by drawing a filled white rectangle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0, UI.width, UI.ToolBarHeight);

}
///////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearPlayModeToolBar() const
{
	//Clear Toolbar by drawing a filled white rectangle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
///////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
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
	ClearPlayModeToolBar();

	
	//Then loading tool bar images
	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under actions toolbar
	pWind->SetPen(BLACK, 1);
	pWind->DrawLine(0, UI.ToolBarHeight-1, UI.width, UI.ToolBarHeight-1);

	/////////////////////////////////////////////////////////////////////


}

void Output::CreateColorsBar() const
{

	////////////////////////////////////////////////////////////////////
	string col[colors_num]; // here we drawing colors menu
	col[ITM_black] = "images\\MenuItems\\black.jpg";
	col[ITM_green] = "images\\MenuItems\\green.jpg";
	col[ITM_blue] = "images\\MenuItems\\blue.jpg";
	col[ITM_red] = "images\\MenuItems\\red.jpg";
	col[ITM_yellow] = "images\\MenuItems\\yellow.jpg";
	col[ITM_brown] = "images\\MenuItems\\brown.jpg";
	col[ITM_orange] = "images\\MenuItems\\orange.jpg";
	col[ITM_LIGHT] = "images\\MenuItems\\light.jpg";
	col[ITM_lime] = "images\\MenuItems\\green.jpg";
	col[ITM_white] = "images\\MenuItems\\white.jpg";
	col[ITM_NON] = "images\\MenuItems\\non-color.jpg";
	//Draw a line parllel to colors toolbar

	

	
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	for (int j = 1;j <= UI.ColorsBarWidth; j++)
	{
	
		if(j==68)
			pWind->DrawRectangle(UI.width - 70, UI.ColorsBarHeight, UI.width, UI.height - UI.StatusBarHeight);
		else
			for (int i = 0; i < colors_num; i++)
				pWind->DrawImage(col[i], UI.width - j, (i*UI.MenuItemWidth) + UI.ToolBarHeight, UI.MenuItemWidth, UI.ToolBarHeight);
	}
	
	if (UI.BkGrndColor == BLUE)
		pWind->SetPen(RED, 1);
	else
		pWind->SetPen(BLUE, 1);
	pWind->DrawLine(UI.width - UI.ColorsBarWidth, UI.ToolBarHeight, UI.width - UI.ColorsBarWidth, UI.height - UI.StatusBarHeight);
	

}

void Output::CreateBorderBar() const
{

	
	string BorderMenueItem[6];
	BorderMenueItem[one] = "images\\MenuItems\\one.jpg";
	BorderMenueItem[three] = "images\\MenuItems\\three.jpg";
	BorderMenueItem[five] = "images\\MenuItems\\five.jpg";
	BorderMenueItem[seven] = "images\\MenuItems\\seven.jpg";
	BorderMenueItem[nine] = "images\\MenuItems\\nine.jpg";
	BorderMenueItem[eleven] = "images\\MenuItems\\eleven.jpg";

	




	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	for (int j = 1; j <= UI.ColorsBarWidth; j++)
	{

		if (j == 68)
			pWind->DrawRectangle(UI.width - 70, UI.ColorsBarHeight, UI.width, UI.height - UI.StatusBarHeight);
		else
			for (int i = 0; i < 6; i++)
				pWind->DrawImage(BorderMenueItem[i], UI.width - j, (i*UI.MenuItemWidth) + UI.ToolBarHeight, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	if (UI.BkGrndColor == BLUE)
		pWind->SetPen(RED, 1);
	else
		pWind->SetPen(BLUE, 1);
	pWind->DrawLine(UI.width - UI.ColorsBarWidth, UI.ToolBarHeight, UI.width - UI.ColorsBarWidth, UI.height - UI.StatusBarHeight);


}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateZoomBar() const
{

	//z stands for zoom 
	/*/a7la comment*/ // mashy ay3m al zref :D
	string ZoomMenueItem[zcount];
	ZoomMenueItem[z10] = "images\\MenuItems\\10.jpg";
	ZoomMenueItem[z25] = "images\\MenuItems\\25.jpg";
	ZoomMenueItem[z50] = "images\\MenuItems\\50.jpg";
	ZoomMenueItem[z75] = "images\\MenuItems\\75.jpg";
	ZoomMenueItem[z100]= "images\\MenuItems\\100.jpg";
	ZoomMenueItem[z125] = "images\\MenuItems\\125.jpg";
	ZoomMenueItem[z150] = "images\\MenuItems\\125.jpg";
		ZoomMenueItem[z175] = "images\\MenuItems\\175.jpg";
		ZoomMenueItem[z200] = "images\\MenuItems\\200.jpg";

	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	for (int j = 1; j <= UI.ColorsBarWidth; j++)
	{

		if (j == 68)
			pWind->DrawRectangle(UI.width - 70, UI.ColorsBarHeight, UI.width, UI.height - UI.StatusBarHeight);
		else
			for (int i = 0; i < zcount; i++)
				pWind->DrawImage(ZoomMenueItem[i], UI.width - j, (i*UI.MenuItemWidth) + UI.ToolBarHeight, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	if (UI.BkGrndColor == BLUE)
		pWind->SetPen(RED, 1);
	else
		pWind->SetPen(BLUE, 1);
	pWind->DrawLine(UI.width - UI.ColorsBarWidth, UI.ToolBarHeight, UI.width - UI.ColorsBarWidth, UI.height - UI.StatusBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateResizeBar() const
{


	string ResizeMenueItem[4];
	ResizeMenueItem[quarter] = "images\\MenuItems\\quarter.jpg";
	ResizeMenueItem[half] = "images\\MenuItems\\half.jpg";
	ResizeMenueItem[double2] = "images\\MenuItems\\double.jpg";
	ResizeMenueItem[quadrible] = "images\\MenuItems\\ddouble.jpg";


	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	for (int j = 1; j <= UI.ColorsBarWidth; j++)
	{

		if (j == 68)
			pWind->DrawRectangle(UI.width - 70, UI.ColorsBarHeight, UI.width, UI.height - UI.StatusBarHeight);
		else
			for (int i = 0; i < 4; i++)
				pWind->DrawImage(ResizeMenueItem[i], UI.width - j, (i*UI.MenuItemWidth) + UI.ToolBarHeight, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	if (UI.BkGrndColor == BLUE)
		pWind->SetPen(RED, 1);
	else
		pWind->SetPen(BLUE, 1);
	pWind->DrawLine(UI.width - UI.ColorsBarWidth, UI.ToolBarHeight, UI.width - UI.ColorsBarWidth, UI.height - UI.StatusBarHeight);


}
//////////////////////////////////////////
void Output::CreateAreaTypeBar() const
{


	string PickByAreaMenueItem[2];
	PickByAreaMenueItem[Max] = "images\\MenuItems\\maximum.jpg";
	PickByAreaMenueItem[Min] = "images\\MenuItems\\minimum.jpg";
	

	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	for (int j = 1; j <= UI.ColorsBarWidth; j++)
	{

		if (j == 68)
			pWind->DrawRectangle(UI.width - 70, UI.ColorsBarHeight, UI.width, (UI.height - UI.StatusBarHeight)+1);
		else
			for (int i = 0; i < 2; i++)
				pWind->DrawImage(PickByAreaMenueItem[i], UI.width - j, (i*UI.MenuItemWidth) + UI.ToolBarHeight, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	if (UI.BkGrndColor == BLUE)
		pWind->SetPen(RED, 1);
	else
		pWind->SetPen(BLUE, 1);
	pWind->DrawLine(UI.width - UI.ColorsBarWidth, UI.ToolBarHeight, UI.width - UI.ColorsBarWidth, UI.height - UI.StatusBarHeight);


}
//////////////////////////////////////////

void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;

	

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICK] = "images\\MenuItems\\FIND.jpg";
	MenuItemImages[ITM_SCRAMBLE] = "images\\MenuItems\\SCRAMBLE.jpg";
	MenuItemImages[ITM_TODRAW] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\exit.jpg";

	
	//Cleaning last mode Tool bars by drawing white area on tool bar and rectangle filled of same bg_color on color area
	ClearDrawModeToolBars();
 
	//Then loading tool bar images
	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
void Output::CreatePickandHideToolBar() const
{

	UI.InterfaceMode = MODE_PICKANDHIDE;


	string MenuItemImages[PickandHide_ITM_COUNT];
	MenuItemImages[ITM_By_Type] = "images\\MenuItems\\bytype.jpg";
	MenuItemImages[ITM_By_Filling_Color] = "images\\MenuItems\\bycolor.jpg";
	MenuItemImages[ITM_By_TypeandFilling_color] = "images\\MenuItems\\bycolortype.jpg";
	MenuItemImages[ITM_By_Area] = "images\\MenuItems\\byarea.jpg";
	MenuItemImages[ITM_Back] = "images\\MenuItems\\switch.jpg";

	//Cleaning last mode Tool bars by drawing white area on tool bar and rectangle filled of same bg_color on color area
	ClearDrawModeToolBars();

	//Then loading tool bar images
	for (int i = 0; i<PickandHide_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);



}
void Output::CreatePickandHideFiguresToolBar() const
{

	string MenuItemImages[PICKTYPE_ITM_COUNT];
	MenuItemImages[ITM_PICK_REC] = "images\\MenuItems\\rec.jpg";
	MenuItemImages[ITM_PICK_LINE] = "images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_PICK_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_PICK_TRI] = "images\\MenuItems\\tri.jpg";
	ClearDrawModeToolBars();

	//Then loading tool bar images
	for (int i = 0; i<PICKTYPE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
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


void Output::SetBGColor(const color& c)
{	UI.BkGrndColor = c;}

void Output::PrintGuideMessages(ActionType ActType)
{


	if (UI.InterfaceMode == MODE_DRAW)
	{
		switch (ActType)
		{
		case DRAW_LINE:
			PrintMessage("Draw a Line");
			break;
		case DRAW_RECT:
			PrintMessage("Draw a Rectangle");
			break;

		case DRAW_TRI:
			PrintMessage("Draw a Triangle");
			break;

		case DRAW_CIRC:
			PrintMessage("Draw a Circle");
			break;

		case CHNG_DRAW_CLR:
			PrintMessage("Change the drawing color");
			break;

		case CHNG_FILL_CLR:
			PrintMessage("Change the filling color");
			break;

		case CHNG_BORDER_WIDTH:
			PrintMessage("Change the border width");
			break;

		case CHNG_BK_CLR:
			PrintMessage("Change the background color");
			break;

		case SELECT:
			PrintMessage("Select figure(s)");
			break;

		case DEL:
			PrintMessage("Delete a figure(s)");
			break;

		case MOVE:
			PrintMessage("Move a figure(s)");
			break;

		case RESIZE:
			PrintMessage("Resize a figure(s)");
			break;

		case ROTATE:
			PrintMessage("Rotate a figure(s)");
			break;

		case UNDO:
			PrintMessage("Undo");
			break;
		case REDO:
			PrintMessage("Redo");
			break;
			/*
			case SEND_BACK:
			PrintMessage("Action: send a figure to the back of all figures ");
			break;

			case BRNG_FRNT:
			PrintMessage("Action: Send a figure to the front of all figures ");
			break;
			*/
		case SAVE:
			PrintMessage("Save the whole graph to a file");
			break;

		case LOAD:
			PrintMessage("Load a graph from a file");
			break;

		case STATUS:
			PrintMessage("Status bar");
			break;

		case TO_PLAY:
			PrintMessage("Switch to Play Mode ");
			break;

		case DRAWING_AREA:
			PrintMessage("Drawing Area");
			break;

		case ZOOMIN:
			PrintMessage("Zoom In");
			break;
		case ZOOMOUT:
			PrintMessage("Zoom Out");
			break;
		case CUT:
			PrintMessage("Cut");
			break;
		case COPY:
			PrintMessage("Copy");
			break;
		case PASTE:
			PrintMessage("Paste");
			break;

		case EMPTY:
			PrintMessage("Empty place in the toolbar");
			break;
		case EXIT:
			PrintMessage("Exit");
			break;
		}
	}
	else if (UI.InterfaceMode == MODE_PLAY)
	{
		switch (ActType)
		{
		case SCRAMBLE:
			PrintMessage("Scramble & find Game");
			break;
		case PICK:
			PrintMessage("Pick & hide Game");
			break;

		case TO_DRAW:
			PrintMessage("Switch to Draw Mode ");
			break;

		case DRAWING_AREA:
			PrintMessage("Playing Area");
			break;
		case EMPTY:
			PrintMessage("Action: Empty place in the toolbar ");
			break;
		case EXIT:
			PrintMessage("Exit");
			break;
		}
	}
	else if (UI.InterfaceMode == MODE_PICKANDHIDE)
	{
		//TODO
		switch (ActType)
		{
		default:
			break;
		}
	}


}


//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{

		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWidth*UI.ZoomFactor);	//Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;


		pWind->DrawRectangle(P1.x*UI.ZoomFactor, P1.y*UI.ZoomFactor, P2.x*UI.ZoomFactor, P2.y*UI.ZoomFactor, style);
}
//LINE
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{

		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = LineGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, LineGfxInfo.BorderWidth*UI.ZoomFactor);	//Set Drawing color & width

		drawstyle style;

			style = FRAME;


		pWind->DrawLine(P1.x*UI.ZoomFactor, P1.y*UI.ZoomFactor, P2.x*UI.ZoomFactor, P2.y*UI.ZoomFactor, style);

}
//Trianlge
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	//check if Tri in drawing area

		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = TriGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, TriGfxInfo.BorderWidth*UI.ZoomFactor);	//Set Drawing color & width

		drawstyle style;
		if (TriGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(TriGfxInfo.FillClr);
		}
		else
			style = FRAME;


		pWind->DrawTriangle(P1.x*UI.ZoomFactor, P1.y*UI.ZoomFactor, P2.x*UI.ZoomFactor, P2.y*UI.ZoomFactor, P3.x*UI.ZoomFactor, P3.y*UI.ZoomFactor, style);


}
//Circle
void Output::DrawCirc(Point P1, int R, GfxInfo CircGfxInfo, bool selected) const
{
	//check if cricle in drawing area
	
		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = CircGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, CircGfxInfo.BorderWidth *UI.ZoomFactor);	//Set Drawing color & width

		drawstyle style;
		if (CircGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(CircGfxInfo.FillClr);
		}
		else
			style = FRAME;


		pWind->DrawCircle(P1.x*UI.ZoomFactor, P1.y*UI.ZoomFactor, R*UI.ZoomFactor, style);

}

void Output::DrawInt(const int iX, const int iY, const long lNumber)
 {
			//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawInteger(iX, iY, lNumber);
	
}

 void Output::DrawString(const int iX, const int iY, const string strText)
 {
	 pWind->DrawString(iX, iY, strText);
 }
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

