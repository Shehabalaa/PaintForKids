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
	bool GetPointClickedv2(int &x, int &y) const;//Get coordinate where user clicks but this func delete node from mouse queue if it is in drawing area or status and return true and keep it otherwise and return false 

	ActionType GetUserAction(int =-2,int =-2) const; //Read the user click and map to an action
	Colors GetColor();
	int GetBorder();
	float GetResizeRatio();
	float GetZoomPercentage();
	int GetAreaType();
	~Input();
};

#endif