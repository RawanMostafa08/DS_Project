#pragma once
class Time
{
	int hour;
	int day;
public:
	Time(int,int);
	Time();
	void SetHour(int h);
	void SetDay(int d);
	int GetDay();
	int GetHour();
};

