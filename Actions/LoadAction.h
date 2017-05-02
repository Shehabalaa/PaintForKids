#pragma once
#include "Action.h"

class LoadAction :public Action
{
private:
	string File_Name;// Name of file that will be loaded
	ifstream InFile;// object that will be used to read form file
	bool ActionFailedEvent(); // utility function
							  //This fucntion perform some logic or print messages if action failed
							  // it wonot be pure virtual not all action should have action failed not all action failed like EXIT 
							  // this func return true if user want to keep going and repeat action and false if i want just break the action
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	~LoadAction();

};
