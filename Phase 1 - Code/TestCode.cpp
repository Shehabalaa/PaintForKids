#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes



int main()
{
	int x, y; int R;

	//Create Input and Output objects to test
	Output *pOut = new Output();;
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


								///////////////////////////////////////////////////////////////////////////////////
								// TEST 1:	
								//			Create The FULL Tool bar, the drawing area and the status bar	
								//			This has already been done through the constrcutor of class Output
								///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


								///////////////////////////////////////////////////////////////////////////////////
								// TEST 2:	
								//			Drawing all the Figures with all possible states: 
								//			Non-filled, Filled, and highlighted in both cases			
								///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2, P3;


	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

								// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 4;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.FillClr = BLUEVIOLET;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Line Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Line, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

								///TODO: Add code to draw Line, Normal and Highlighted
	pOut->PrintMessage("Drawing a Normal line ,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawLine(P1, P2, gfxInfo, false);

	pOut->PrintMessage("Drawing a  line ==> Highlighted , Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawLine(P1, P2, gfxInfo, true);


	//////////////////////////////////////////////////////
	pOut->PrintMessage("Drawing a Line Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

								///TODO: Add code to draw Triangle in all possible states
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click Three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawTri(P1, P2, P3, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTri(P1, P2, P3, gfxInfo, true);


	// 2.1.3 - Drawing a filled Trinagle
	pOut->PrintMessage("Drawing a Triangle ==> filled,  Click Three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	gfxInfo.BorderWdth = 4;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.FillClr = BLUEVIOLET;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawTri(P1, P2, P3, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled Triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTri(P1, P2, P3, gfxInfo, true);

	////////////////////////////////////////////////////////
	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

								///TODO: Add code to draw Circle in all possible states
								// 2.1.1 - Drawing non-filled Circle
	pOut->PrintMessage("Drawing a Circle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	R = sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2));
	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawCirc(P1, R, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled Circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCirc(P1, R, gfxInfo, true);


	// 2.1.3 - Drawing a filled Circle
	pOut->PrintMessage("Drawing a Circle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	R = sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2));

	gfxInfo.BorderWdth = 4;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.FillClr = BLUEVIOLET;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawCirc(P1, R, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled Circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCirc(P1, R, gfxInfo, true);
	//////////////////////////////////////////////////////
	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();
	////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings Please Enter some strings:");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the stirng clear the status bar
	// 3- print on the status bar "You Entered" then print the string
	string temp="You Entered: ";
	temp += pIn->GetSrting(pOut);
	pOut->PrintMessage(temp);
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();
		if (UI.InterfaceMode == MODE_DRAW)
		{
			switch (ActType)
			{
			case DRAW_LINE:
				pOut->PrintMessage("Action: Draw a Line , Click anywhere");
				break;
			case DRAW_RECT:
				pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
				break;

			case DRAW_TRI:
				pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
				break;

			case DRAW_CIRC:
				pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
				break;

			case CHNG_DRAW_CLR:
				pOut->PrintMessage("Action: Change the drawing color , Click anywhere");
				break;

			case CHNG_FILL_CLR:
				pOut->PrintMessage("Action: Change the filling color , Click anywhere");
				break;

			case CHNG_BORDER_WIDTH:
				pOut->PrintMessage("Action: Change the border width , Click anywhere");
				break;

			case CHNG_BK_CLR:
				pOut->PrintMessage("Action: Change the background color , Click anywhere");
				break;

			case DEL:
				pOut->PrintMessage("Action: Delete a figure , Click anywhere");
				break;

			case MOVE:
				pOut->PrintMessage("Action: Move a figure , Click anywhere");
				break;

			case RESIZE:
				pOut->PrintMessage("Action: Resize a figure , Click anywhere");
				break;

			case ROTATE:
				pOut->PrintMessage("Action: Rotate a figure , Click anywhere");
				break;

			case UNDO:
				pOut->PrintMessage("Action: Undo , Click anywhere");
				break;
			case REDO:
				pOut->PrintMessage("Action: Redo , Click anywhere");
				break;
			/*
			case SEND_BACK:
				pOut->PrintMessage("Action: send a figure to the back of all figures , Click anywhere");
				break;

			case BRNG_FRNT:
				pOut->PrintMessage("Action: Send a figure to the front of all figures , Click anywhere");
				break;
			*/
			case SAVE:
				pOut->PrintMessage("Action: Save the whole graph to a file , Click anywhere");
				break;

			case LOAD:
				pOut->PrintMessage("Action: Load a graph from a file , Click anywhere");
				break;

			case STATUS:
				pOut->PrintMessage("Action: Status bar , Click anywhere");
				break;

			case TO_DRAW:
				pOut->PrintMessage("Action: Draw Mode , Click anywhere");
				break;

			case TO_PLAY:
				pOut->CreatePlayToolBar();
				pOut->PrintMessage("Action: Welcome to Play Mode , Click anywhere");
				break;

			case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

			case ZOOMIN:
				pOut->PrintMessage("Action: Zoom In , Click anywhere");
				break;
			case ZOOMOUT:
				pOut->PrintMessage("Action: Zoom Out , Click anywhere");
				break;
			case CUT:
				pOut->PrintMessage("Action: Cut , Click anywhere");
				break;
			case COPY:
				pOut->PrintMessage("Action: Copy , Click anywhere");
				break;
			case PASTE:
				pOut->PrintMessage("Action: Paste , Click anywhere");
				break;

			case EMPTY:
				pOut->PrintMessage("Action: Empty place in the toolbar , Click anywhere");
				break;

			case SELECT_BLACK_COLOR:
				pOut->PrintMessage("Action: Selection Black , Click anywhere");
				break;
			case SELECT_GREEN_COLOR:
				pOut->PrintMessage("Action: Selection GREEN , Click anywhere");
				break;
			case SELECT_YELLOW_COLOR:
				pOut->PrintMessage("Action: Selection YELLOW , Click anywhere");
				break;
			case SELECT_BLUE_COLOR:
				pOut->PrintMessage("Action: Selection BLUE , Click anywhere");
				break;
			case SELECT_RED_COLOR:
				pOut->PrintMessage("Action: Selection RED , Click anywhere");
				break;

			case SELECT_BROWN_COLOR:
				pOut->PrintMessage("Action: Selection BROWN , Click anywhere");
				break;
			case SELECT_ORANGE_COLOR:
				pOut->PrintMessage("Action: Selection ORANGE , Click anywhere");
				break;
			case EMPTY2:
				pOut->PrintMessage("Action: Empty place in color tool bar , Click anywhere");
				break;



			case EXIT1:
				break;
			}
		}
		else if (MODE_PLAY)
		{
			switch (ActType)
			{
			case SCRAMBLE:
				pOut->PrintMessage("Action: Scramble & find , Click anywhere");
				break;
			case PICK:
				pOut->PrintMessage("Action: Pick & hide , Click anywhere");
				break;

			case TODRAW:
				pOut->CreateDrawToolBars();
				pOut->PrintMessage("Action: Welcome to Draw Mode , Click anywhere");
				break;

			case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Playing Area, Click anywhere");
				break;
			case EMPTY:
				pOut->PrintMessage("Action: Empty place in the toolbar , Click anywhere");
				break;

			case EXIT2:
				break;
			}
		}
		
	
	} while (ActType != EXIT1&&ActType != EXIT2);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
	return 0;
}
