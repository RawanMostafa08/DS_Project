#include "Event.h"

Event::Event(int d,int h): EventTime(d,h)
{
}

Event::Event(Time T):EventTime(T)
{
}

Event::Event()
{
}

void Event::SetEventTime(Time T)
{
	EventTime = T;
}

//string Event::GetEventTime()
//{
//	return (to_string(EventTime.GetDay()) + ":" + to_string(EventTime.GetHour()));
//}

Event::~Event()
{
}
