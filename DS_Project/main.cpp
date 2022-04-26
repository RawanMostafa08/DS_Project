#include"UI.h"

void Simulator()
{
	UI* I = new UI;
	I->ProgramInterface();	
	delete I;
}
int main()
{
	Simulator();
	return 0;
}