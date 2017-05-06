#include "LoadAction.h"


LoadAction::LoadAction(ApplicationManager * pApp):Action(pApp)
{
}

ActionState LoadAction::ReadActionParameters()
{

	pOut->PrintMessage("Please Enter name of file to load graph from!");
	File_Name=pIn->GetSrting(pOut);

	if (File_Name.find(".txt") == string::npos)
	{
		File_Name += ".txt";
	}

	return Successful;
}

void LoadAction::Execute()
{
	// firstly ask user to save graph if isnot saved
	if (!pManager->GetIfListSaved())
	{
		pOut->PrintMessage("Do you want to save graph before loading another?(Y,n)");
		string temp = pIn->GetSrting(pOut); // this temp just read user replay
		if (!(temp[0] == 'n' || temp[0] == 'N'))
		{
			pManager->ExecuteAction(SAVE);
			if (pManager->GetIfListSaved())
			{
				pOut->PrintMessage("Data Saved successfully Press Enter to continue");
				string temp = pIn->GetSrting(pOut); // this temp just read user replay
			}
			else
			{
				pOut->PrintMessage("Current Graph isn't Saved Press Enter to continue");
				string temp = pIn->GetSrting(pOut); // this temp just read user replay
			}

		}
	}
	pManager->CleanFiglist(); // cleaning fig list preparing to refill it


	ReadActionParameters(); //read file_name
	InFile.open(File_Name,ios::in);// opening file
	while(!InFile.is_open())
	{
		if (ActionFailedEvent()) // if true user want to keep going
		{
			ReadActionParameters(); //read file_name
			InFile.open(File_Name, ios::in); // opening file
		}
		else
			return;

	} 

	pManager->LoadAll(InFile); // saving all figures information to file
	pOut->PrintMessage("Data successfully loaded");
	InFile.close();

}


bool LoadAction::ActionFailedEvent()
{
	pOut->PrintMessage("Error:File isn't found, Try again?(Y/n)");;
	string temp = pIn->GetSrting(pOut);
	if ('n' == temp[0] || 'N' == temp[0])
	{
		pOut->PrintMessage("LoadActionCanceled!");
		return false;
	}
	else
		return true;
}


LoadAction::~LoadAction()
{
}
