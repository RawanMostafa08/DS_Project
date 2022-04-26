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

	void PassHour();
	Time operator - (Time const& t);
	bool operator >(Time const& t);
	bool operator <(Time const& t);
	bool operator ==(Time const& t);
	float operator *(float f);
	Time operator +(Time const& t);
	Time operator /(int n);
	Time operator +(int t);

};
//ostream& operator <<(ostream& output,const Time& t)
//{
//	output << t.GetDay() << ":" << t.GetHour() << endl;
//	return output;
//}

