#ifndef EXITACTION_H
#define EXITACTION_H
#include"Action.h"

class ExitAction:public Action
{
private:
	bool Answer; //this indicates user replay if want to save whole graph before leaving or not if it isnot already saved
public:
	ExitAction(ApplicationManager *);
	~ExitAction();
	virtual void Execute();
	virtual void ReadActionParameters();
};

#endif // !EXITACTION_H
