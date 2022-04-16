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
Time::Time()
{
}
void Time::PassHour()
{
	hour++;
}
Time Time:: operator - (Time const& t)
{
	Time res;
	res.hour = hour - t.hour;
	res.day = day - t.day;
	return res;
}
bool Time::operator >(Time const& t)
{
	if (day > t.day) return true;
	else if (day < t.day)return false;
	else
	{
		if (hour > t.hour)return true;
	}
	return false;
}
bool Time::operator ==(Time const& t)
{
	if (day == t.day && hour == t.hour) return true;
	return false;
}

