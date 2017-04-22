#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "..\DEFS.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	bool FigListSaved; // true if newst information already saved in file else otherwise
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void SaveAll(ofstream &) ; //Saves whole Graph to a file it is not const to change figlistsaved variable to true
	bool GetIfListSaved() const; //Retrun true of all list with its last information saved else otherwise
};

#endif