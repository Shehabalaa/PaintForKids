#ifndef ACTION_H
#define ACTION_H

#include"../ApplicationManager/ApplicationManager.h"



//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	Output *pOut;	//Actions needs AppMngr to do their job( like getting pionter to ouput obj.)
	Input *pIn;	//Actions needs AppMngr to do their job( like getting pionter to input obj.)
public:

	Action(ApplicationManager *pApp) { pManager = pApp; pOut = pApp->GetOutput(); pIn = pApp->GetInput();	}	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;

	//To undo this action (code depends on action type)
	//virtual void Undo()=0;

	//To redo this action (code depends on action type)
	//virtual void Redo()=0;

};

#endif