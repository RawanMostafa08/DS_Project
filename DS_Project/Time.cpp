#include "Time.h"
void Time::SetHour(int h)
{
	if (h >= 0 && h < 24)
		hour = h;
}
void Time::SetDay(int d)
{
		day= d;
}
int Time::GetDay()
{
	return day;
}
int Time::GetHour()
{
	return hour;
}
Time::Time(int h, int d)
{
	SetDay(d); SetHour(h);
}

