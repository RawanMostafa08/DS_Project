#include "Cargo.h"
//#include <string>
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

int Cargo::GetID()
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

Time Cargo::GetMaxW()
{
	return MaxWait;
}

Time Cargo::GetWaitTime()
{
	return  MoveTime - ReadyTime;
}
