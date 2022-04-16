#include "CancellationEvent.h"

CancellationEvent::CancellationEvent()
{
	EventLetter = 'X';
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

void CancellationEvent::Execute()
{
	/*PrintInfo();*/
}


