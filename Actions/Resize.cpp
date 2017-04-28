#include "..\Actions\Resize.h"



///leh m3aml4 destructor ?? fe add rect 
Resize::Resize( ApplicationManager * pApp ): Action( pApp)
{}

void Resize :: ReadActionParameters()
{
	Output * pOut= pManager->GetOutput();
	Input * pIn =pManager->GetInput();
	pOut->PrintMessage("Which ratio do you want to resize your figure(s),Choose one of those (2 / 4/ 0.5 / 0.25)");
	float x=stof(pIn->GetSrting(pOut));
	while(x!=2 && x!= 4 && x!=0.25 && x!=0.5)
	{
		pOut->PrintMessage("Error : You didn't choose from previous RATIOS baka !! choose again (2 / 4 / 0.5 / 0.25)");
	}
    ResizeRatio = x ;
	 pOut->ClearStatusBar();
}
void Resize :: Execute() 
{
	ReadActionParameters();
	//pManager->Resize_Action(ResizeRatio);
}
Resize ::~Resize()
{}