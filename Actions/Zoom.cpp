#include"Zoom.h"
Zoom :: Zoom (ApplicationManager* pApp):Action(pApp)
{
}
ActionState Zoom::ReadActionParameters()
{

	pOut->PrintMessage("Which Percentage do you want to resize your figure(s)");
	pOut->CreateZoomBar();
	Percentage = pIn->GetZoomPercentage();
	return Successful;
}

void Zoom :: Execute ()
{
	ReadActionParameters();
	if (Percentage>0)
		UI.ZoomFactor = Percentage;
	else {
		pOut->PrintMessage("you didn't choose a percentage ");
	}
}
Zoom :: ~ Zoom ()
{}