#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include<iomanip>
#include<vector>
#include"../Figures/CFigure.h"
class CFigure;


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	vector<CFigure*> ClipBoard; // Clipboard (list of copied figures)
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
public:	
	bool GraphSaved; // true if newst information already saved in file else otherwise
	ApplicationManager(); 
	~ApplicationManager();
	int GetMaxFigCount() const;
	int GetClipBoardSize() const;
	void UserGuide() const;
	void DeletePickedFigure(CFigure **, int&, CFigure * FIGURE);
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	int countselected();
	void PrintSelected();
	void MoveFigures(int, int);
	int CountFigure(CFigure ** PickList, int size, figures figtype);
	int CountFigure(CFigure ** PickList, int size, figures Type, color c, bool filled);
	int CountFigure(CFigure ** PickList, int size, color c, bool filled);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure *GetFigure(int x, int y, CFigure **, int) const;
	void SaveAll(ofstream &); //Saves whole Graph to a file it is not const to change figlistsaved variable to true
	void LoadAll(ifstream &); //Load Graph from a file
	bool GetIfListSaved() const; //Retrun true of all list with its last information saved else otherwise
	void CleanFiglist(); // Free all fig list memory
	void CleanClipboard(); // Free all Clipboard list memory this fun called befor exit porgram as clipboard private
	int GetFigCount();
	void Resize_Action(float Ratio);
	/////
	void change_border_color_Action(color C);
	void change_PenWidth_Action(int PW);        //PW:Pen Width
	void change_Filled_color_Action(color C);
	void AdjustList(ActionType,CFigure** = NULL,int = 0);
	int CountFigure(figures);
	int CountFigure(color, bool);
	void DeleteAll();
	void CutAll();
	void CopyAll();
	void PasteAll(const Point&);
	CFigure *GetSelectedFigure() const;
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void UpdateInterface(CFigure **,int) const; // over load update inter face with another version
	CFigure** GetDeepCopyFromFigList(int&) const; // this fucn big back a copylist from fig list and writes its size to var sent by ref 
	

};

#endif