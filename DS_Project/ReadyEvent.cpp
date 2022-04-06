#include "ReadyEvent.h"

//Ready event line has the following information :
//▪ R(letter R at the beginning of the line) means a cargo ready event.
//▪ TYP is the cargo type(N : normal, S : special, V : VIP).
//▪ ET is the event time.
//▪ ID is a unique sequence number that identifies each cargo.
//▪ DIST is the cargo distance(in kilometers)
//▪ LT Time(in hours) to load or unload the cargo.
//▪ Cost is the cargo cost.


ReadyEvent::ReadyEvent()
{
	TYP = NULL;
	EventLetter = 'R';
}
void ReadyEvent::PrintInfo()
{
	out.open("t.txt");
	if (out.is_open())
	{
		out << EventLetter << "\t" << TYP->GetCargoType() << "\t";
		out << GetEventTime() << "\t"<< TYP->GetID()<< "\t"<<TYP->GetDelvDistance()<< "\t"<<TYP->GetLoadTime();
		out << TYP->GetCost() << endl;
		out.close();
	}
	else
	{
	}
}
void ReadyEvent::Execute()
{
	//Initially prints only
	PrintInfo();
}