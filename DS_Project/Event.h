#pragma once
#include"Time.h"
#include"Cargo.h"
//#include <string>
#include<fstream>
using namespace std;

class Event
{
	Time EventTime;
	int CargoID;
protected:
	char EventLetter;
	/*ofstream out;*/
public:
	Event(int,int);
	Event(Time);
	Event();
	virtual void Execute() = 0;
	void SetEventTime(Time);
	Time GetEventTime();
	virtual ~Event();
};

