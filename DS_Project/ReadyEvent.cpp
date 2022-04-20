#include "ReadyEvent.h"

//Ready event line has the following information :
//▪ R(letter R at the beginning of the line) means a cargo ready event.
//▪ TYP is the cargo type(N : normal, S : special, V : VIP).
//▪ ET is the event time.
//▪ ID is a unique sequence number that identifies each cargo.
//▪ DIST is the cargo distance(in kilometers)
//▪ LT Time(in hours) to load or unload the cargo.
//▪ Cost is the cargo cost.

ReadyEvent::ReadyEvent(char c, Time t,int id,float dist,int lt,float cost):Event(t,id)
{
	TYP = NULL;
	EventLetter = 'R';
	//
	CargoType = c;
	DIST = dist;
	LT = lt;
	Cost = cost;
}

void ReadyEvent::Execute(Cargo*& C,int& id)
{
	if (CargoType == 'N')
		TYP = new NormalCargo;
	else if (CargoType == 'S')
		TYP = new SpecialCargo;
	else
		TYP = new VIPCargo;
	TYP->SetCargoType(CargoType);
	TYP->SetId(GetCargoID());
	TYP->SetDelvDistance(DIST);
	TYP->SetLoadTime(LT);
	TYP->SetCost(Cost);
	TYP->SetReadyTime(GetEventTime());
	C = TYP;
}

//void ReadyEvent::PrintInfo()
//{
//	out.open("t.txt");
//	if (out.is_open())
//	{
//		out << EventLetter << "\t" << TYP->GetCargoType() << "\t";
//		out << GetEventTime() << "\t"<< TYP->GetID()<< "\t"<<TYP->GetDelvDistance()<< "\t"<<TYP->GetLoadTime();
//		out << TYP->GetCost() << endl;
//		out.close();
//	}
//	else
//	{
//	}
//}