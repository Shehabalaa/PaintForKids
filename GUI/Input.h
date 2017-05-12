#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"


class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting(Output* pO) const ;	 //Returns a string entered by the user
	void GetPointClickedv2(int &x, int &y) const;//Get coordinate where user clicks but this func doesnot change mouse queue this means mouse click will remain in queue

	ActionType GetUserAction() const; //Read the user click and map to an action
	ActionType SeeAction(int,int) const; //only retruns user action give coord
	Colors GetColor();
	~Input();
};

#endif