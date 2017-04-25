#include "SaveAction.h"


SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
}

SaveAction::~SaveAction()
{
}

void SaveAction::Execute()
{
	ReadActionParameters(); //read file_name
	OutFile.open(file_name, ios::out); // opening file
	while (!OutFile.is_open())
	{

		if (ActionFailedEvent()) // if true user want to keep going
		{
			ReadActionParameters(); //read file_name
			OutFile.open(file_name, ios::out); // opening file
		}
		else
			return;
	} 
	pManager->SaveAll(OutFile); // saving all figures information to file
	pOut->PrintMessage("Data successfully Saved in "+file_name);

	OutFile.close();
}

bool SaveAction::ActionFailedEvent()
{
	pOut->PrintMessage("Error:File name is wrong, Try again?(Y/n)");;
	string temp = pIn->GetSrting(pOut);
	if ('n' == temp[0]|| 'N' == temp[0])
	{
		pOut->PrintMessage("SaveActionCanceled!");
		return false;
	}
	else
		return true;
}
void SaveAction::ReadActionParameters()
{
	pOut->PrintMessage("Please Enter filename!");
	file_name=pIn->GetSrting(pOut);
	if (file_name.find(".txt") == string::npos)
	{
		file_name += ".txt";
	}

}