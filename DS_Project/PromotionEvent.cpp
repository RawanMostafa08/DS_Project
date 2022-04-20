#include "PromotionEvent.h"

//Promotion event line has the following information :
//? P(Letter P) means a cargo promotion event.
//? ED is the event time.
//? ID is the ID of the cargo to be promoted to VIP.This ID must be of a
//normal cargo.
//? ExtraMoney : Extra money for promotion

PromotionEvent::PromotionEvent(Time t, int id, double em):Event(t, id)
{
	EventLetter = 'P';
	ExtraMoney = em;
}


void PromotionEvent::Execute(Cargo*& c,int& id)
{
	id = GetCargoID();
}

//void PromotionEvent::SetExtraMoney(double D)
//{
//	ExtraMoney = D;
//}
//
double PromotionEvent::GetExtraMoney()
{
	return ExtraMoney;
}
// 
//void PromotionEvent::PrintInfo(int ID, double EM)
//{
//	out.open("t.txt");
//	if (out.is_open())
//	{
//		out << EventLetter << "\t" << GetEventTime() << "\t" << ID << "\t" << EM << endl;
//		out.close();
//	}
//	else
//	{
//	}
//}