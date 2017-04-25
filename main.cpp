#include "ApplicationManager/ApplicationManager.h"

int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();
		

	}while(ActType != EXIT );
	

	
	return 0;
}

/// note lma akl figures ttms7 y3ny figcount =0 figlistsaved=true //mashy yahmed y3ny lma klo ytms7o fe del mtnsash t3mlha