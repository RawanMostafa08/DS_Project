#pragma once
#include"Time.h"
#include"NormalCargo.h"
#include"SpecialCargo.h"
#include"VIPCargo.h"
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
	Event(Time,int);
	Event();
	virtual void Execute(Cargo*&,int&) = 0;
	void SetCargoID(int);
	int GetCargoID();
	Time GetEventTime();
	virtual ~Event();

	//void SetEventTime(Time);
	
};

