#include"UI.h"
#include"Company.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
void Simulator()
{
	Company* C = new Company;
	C->SystemLoad();
	while (!C->EventIsEmpty())
	{
		if (C->IsInWorkingHours())
		{
			C->Check();
		}
		C->AdvanceCurrentTime();
		Sleep(1000);
	}

}
int main()
{
	//Sleep(1000);
	int x = 0;
	while (x == 0);
	{
		//continue simulation
	}
	return 0;
}