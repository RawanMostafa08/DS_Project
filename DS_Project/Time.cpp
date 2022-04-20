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
float Time::operator *(float f)
{
	return f * (this->GetDay() + this->GetHour());
}
Time Time::operator +(Time const& t)
{
	Time res;
	if (t.hour + hour >= 24)
	{
		res.day += t.day;
		res.day++;
		res.hour = t.hour + hour - 24;
	}
	else
	{
		res.hour += t.hour;
		res.day += t.day;
	}
	return res;
}
Time Time::operator /(int n)
{
	Time res;
	int dummy = 0;
	dummy = day * 24 + hour;
	dummy = dummy / n;
	res.day = dummy % 24;
	res.hour = dummy - 24 * res.day;
	return res;
}
Time Time::operator +(int t)
{

	if (t + hour >= 24)
	{
		day++;
		hour = t + hour - 24;
	}
	else
	{
		hour += t;
	}
	return *this;
}
