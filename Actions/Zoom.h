#ifndef ZOOM_H
#define ZOOM_H
#include "..\Actions\Action.h"
#include "..\ApplicationManager\ApplicationManager.h"
class Zoom :public Action 
{
private :
	float Percentage;
public :
	Zoom(ApplicationManager* pApp);
	~Zoom();
	virtual ActionState ReadActionParameters();
	virtual void Execute();


};
#endif