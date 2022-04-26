#include "Cargo.h"
#include <string>
void Cargo::SetReadyTime(Time T)
{
	ReadyTime = T;
}
void Cargo::SetLoadTime(float L)
{
	LoadTime = L;
}

void Cargo::SetDelvDistance(float D)
{
	DelvDistance = D;
}

void Cargo::SetCost(double C)
{
	cost = C;
}

void Cargo::SetId(int I)
{
	ID = I;
}
Time Cargo::GetReadyTime()
{
	return ReadyTime;
}

//string Cargo::GetReadyTime()
//{
//	return (to_string(ReadyTime.GetDay()) + ":" + to_string(ReadyTime.GetHour()));
//}

float Cargo::GetLoadTime()
{
	return LoadTime;
}

float Cargo::GetDelvDistance()
{
	return DelvDistance;
}

double Cargo::GetCost()
{
	return cost;
}

int Cargo::GetID() const
{
	return ID;
}

void Cargo::SetCargoType(char c)
{
	CargoType = c;
}

char Cargo::GetCargoType()
{
	return CargoType;
}

void Cargo::SetMaxW(int M)
{
	MaxW = M;
}

int Cargo::GetMaxW()
{
	return MaxW;
}

Time Cargo::GetWaitTime()
{
	return  MoveTime - ReadyTime;
}

void Cargo::SetLoaded(bool l)
{
	Loaded = l;
}

bool Cargo::GetLoaded()
{
	return Loaded;
}
void Cargo::SetDelvTime(Time t)
{
	DelvTime = t;
}
void Cargo::SetMyTruckID(int id)
{
	MyTruckID = id;
}
Time  Cargo::GetDelvTime()
{
	return DelvTime;
}
int Cargo::GetMyTruckID()
{
	return MyTruckID;
}
string  Cargo::GetWaitTimeS()
{
	return (to_string(WaitTime.GetDay()) + ":" + to_string(WaitTime.GetHour()));
}

string  Cargo::GetDelvTimeS()
{
	return (to_string(DelvTime.GetDay()) + ":" + to_string(DelvTime.GetHour()));
}
string  Cargo::GetReadyTimeS()
{
	return (to_string(ReadyTime.GetDay()) + ":" + to_string(ReadyTime.GetHour()));
}