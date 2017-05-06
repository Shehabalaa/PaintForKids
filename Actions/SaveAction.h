#pragma once
#include "Action.h"

class SaveAction:public Action
{
private:
	string file_name; // file name
	ofstream OutFile; // file object
	virtual ActionState ReadActionParameters(); //utility function
	bool ActionFailedEvent(); // utility function
		//This fucntion perform some logic or print messages if action failed
		// it wonot be pure not all action should have action failed not all action failed like EXIT 
		// this func return true if user want to keep going and repeat action and false if i want just break the action
public:
	
	SaveAction(ApplicationManager*);
	~SaveAction();
	virtual void Execute();

};

