#pragma once
#include"Company.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
class UI
{
	Company* C;
public:
	UI();
	void Print();
	void ProgramInterface();
};