#include "PromotionEvent.h"

PromotionEvent::PromotionEvent()
{
	EventLetter = 'P';
}

void PromotionEvent::PrintInfo(int ID, double EM)
{
	out.open("t.txt");
	if (out.is_open())
	{
		out << EventLetter << "\t" << GetEventTime() << "\t" << ID << "\t" << EM << endl;
		out.close();
	}
	else
	{
	}
}

void PromotionEvent::Execute(/*int ID,double EM,bool L*/)
{

	/*PrintInfo(ID,EM);*/
}

//void PromotionEvent::SetExtraMoney(double D)
//{
//	ExtraMoney = D;
//}
//
//double PromotionEvent::GetExtraMoney()
//{
//	return ExtraMoney;
//}
