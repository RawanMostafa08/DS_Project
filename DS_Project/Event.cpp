#include "Event.h"

Event::Event(int d,int h): EventTime(d,h)
{
}

Event::Event(Time T, int id):EventTime(T)
{
	SetCargoID(id);
}

Event::Event()
{
}

void Event::SetCargoID(int id)
{
	CargoID = id;
}

int Event::GetCargoID()
{
	return CargoID;
}

Time Event::GetEventTime()
{
	return EventTime;
}

Event::~Event()
{
}

//void SetEventTime(Time);
//
//string Event::GetEventTime()
//{
//	return (to_string(EventTime.GetDay()) + ":" + to_string(EventTime.GetHour()));
//}
