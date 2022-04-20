#include "CancellationEvent.h"

//Cancellation event line has the following information :
//? X(Letter X) means a cargo cancellation event.
//? ED is the event time.
//? ID is the ID of the cargo to be canceled. This ID must be of a normal cargo.

CancellationEvent::CancellationEvent(Time t,int id):Event(t, id)
{
	EventLetter = 'X';
}

void CancellationEvent::Execute(Cargo*& c,int& id)
{
	id = GetCargoID();
}

//void CancellationEvent::PrintInfo()
//{
//	out.open("t.txt");
//	if (out.is_open())
//	{
//		out << EventLetter << "\t" << GetEventTime() << "\t" << TYP->GetID() << endl;
//		out.close();
//	}
//	else
//	{
//	}
//}

