#include"CNGborderwidth.h"
#include<iostream>
CNGborderwidth :: CNGborderwidth (ApplicationManager *pApp) : Action (pApp)
{
}
ActionState CNGborderwidth :: ReadActionParameters()
{
	
	pOut->PrintMessage(" Please enter pen width of these options (1/3/5/7/9/11 )");
	string S= pIn->GetSrting(pOut);
	Pen=stoi(S);
	return Successful;
}


void CNGborderwidth :: Execute ()
{
	ReadActionParameters();
	if(pManager->countselected()>0)
		pManager->change_PenWidth_Action(Pen);
	else
	{
	UI.PenWidth=Pen;
	}
}
CNGborderwidth :: ~ CNGborderwidth()
{
}