#include "..\Actions\Resize.h"




Resize::Resize( ApplicationManager * pApp ): Action( pApp)
{}

ActionState Resize :: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Which ratio do you want to resize your figure(s)");
	pOut->CreateResizeBar();
	ResizeRatio = pIn->GetResizeRatio();
	
	 return Successful;
}
void Resize :: Execute() 
{
	if (pManager->countselected())
	{
		Output* pOut = pManager->GetOutput();
		ReadActionParameters();
		if (ResizeRatio > 0)
		{
			pManager->Resize_Action(ResizeRatio);
		}
		else
		{
			pOut->PrintMessage("you didn't choose a ratio");
		}
	}
	else {
		pManager->GetOutput()->PrintMessage("No Slected Figures to be Resized");
		Sleep(1000);
	}
}
Resize ::~Resize()
{}