#include "SaveAction.h"


SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
}


ActionState SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (!pManager->GetFigCount())
	{
		pOut->PrintMessage("Error! No Graph to be Saved!");
		Sleep(1000); // give some time to message(userguide )
		return Just_Canceled;
	}

	pOut->PrintMessage("Please Enter filename!(Esc to cancel)");
	file_name = pIn->GetSrting(pOut);

	if (file_name == "")
	{
		pOut->PrintMessage("ActionCanceled");
		return Just_Canceled;
	}

	if (file_name.find(".txt") == string::npos)
	{
		file_name += ".txt";
	}

	return Successful;
}

void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(ReadActionParameters() == Just_Canceled ) //read file_name
		return;

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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
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


SaveAction::~SaveAction()
{
}