#pragma once
#include "Truck.h"
Truck::Truck()
{
}

bool Truck::UnLoad(Cargo* c)
{
	
	while (CargoNo != 0)
	{
		CargoNo--;
		Cargos.dequeue(c);
		return true;
	}
	return false;
}

Truck::Truck(char c,int NS,int NC,int j,int CN,int ID)
{
	SetTruckType(c);
	SetTruckSpeed(NS);
	SetTruckCap(NC);
	SetJ(j);
	SetCheckTime(CN);
	SetId(ID);
}

void Truck::SetJ(int j)
{
	if (j <= 0)
		J = 1;
	else J = j;
}

int Truck::GetJ()
{
	return J;
	return 0;
}

void Truck::SetCargoNo(int a)
{
	if (a < 0)
		CargoNo = 0;
	else CargoNo = a;
}

void Truck::SetCountJ(int b)
{
	if (b < 0)
		CountJ = 0;
	else CountJ = b;
}

void Truck::SetCheckTime(float t)
{
	if (t < 0)
		CheckTime = 1;
	else CheckTime = t;
}

void Truck::SetTruckSpeed(int s)
{
	if (s < 0)
		s = 0;
	else TruckSpeed = s;
}

int Truck::GetCargoNo()
{
	return CargoNo;
}

void Truck::SetTruckCap(int c)
{
	if (c > 0)
		TruckCap = c;
}

int Truck::GetTruckCap()
{
	return TruckCap;
}

int Truck::GetCountJ()
{
	return CountJ;
}

float Truck::GetCheckTime()
{
	return CheckTime;
}

int Truck::GetTruckSpeed()
{
	return TruckSpeed;
}

void Truck::SetId(int ID)
{
	id = ID;
}

int Truck::GetID()
{
	return id;
}

bool Truck::IsLoaded()
{
	if (CargoNo == TruckCap)
		return true;
	return false;
}

void Truck::SetTruckType(char c)
{
	TruckType = c;
}

char Truck::GetTruckType()
{
	return TruckType;
}

bool Truck::LoadCargo(Cargo* c)
{


	if (!IsLoaded())
	{
		TotLoadTime += c->GetLoadTime();
		if (CargoNo == 0)
			MaxDistCargo = c->GetDelvDistance();
		else if (c->GetDelvDistance() > MaxDistCargo)
			MaxDistCargo = c->GetDelvDistance();


		Cargos.enqueue(c);
		CargoNo++;
		if (IsLoaded())
		{
			SetDelvTime(MaxDistCargo, TotLoadTime);
			return false;
		}
		return true;

	}
}

float Truck::GetDelvTime()
{
	return DelvTime;
}

void Truck::SetDelvTime(float d, float t)
{
	DelvTime = 2 * (d / TruckSpeed) + t;
}

int Truck::GetTC()
{
	return TruckCap;
}

//void Truck::SetDelvTime(float d)
//{
//	if (d > 0)
//		DelvTime = d;
//
//}
//bool Truck::LoadCargo(Cargo c)
//{
//	if (CargoNo == TruckCap)
//		return false;
//	else
//	{
//		Cargos.enqueue(c);
//		CargoNo++;
//		return true;
//	}
//}
//void Truck::SetJ(int j)
//{
//	if (j <= 0)
//		J = 1;
//	else J = j;
//}
//int Truck::GetJ()
//{
//	return J;
//	return 0;
//}
//void Truck::SetCargoNo(int a)
//{
//	if (a < 0)
//		CargoNo = 0;
//	else CargoNo = a;
//}
//
//void Truck::SetCountJ(int b)
//{
//	if (b < 0)
//		CountJ = 0;
//	else CountJ = b;
//}

//void Truck::SetCheckTime(float t)
//{
//	if (t < 0)
//		CheckTime = 1;
//	else CheckTime = t;
//}
//
//void Truck::SetTruckSpeed(float s)
//{
//	if (s < 0)
//		s = 0;
//	else TruckSpeed = s;
//}
//
//int Truck::GetCargoNo()
//{
//	return CargoNo;
//}
//
//int Truck::GetCountJ()
//{
//	return CountJ;
//}
//
//float Truck::GetCheckTime()
//{
//	return CheckTime;
//}
//
//float Truck::GetTruckSpeed()
//{
//	return TruckSpeed;
//}
//
//
//bool Truck::IsLoaded()
//{
//	if (CargoNo == TruckCap)
//		return true;
//	return false;
//}

//in class company
////bool Truck::GoDelivery(Truck* T)
////{
////	if (T->IsLoaded())
////	{
////		//dequeue from waiting Trucks to delivery
////		return true;
////	}
////	return false;
////}
// /////////////////////////////////////////////
////void Truck::GoCheckup(Truck* T)
////{
////		Maintenance.enqueue(T);
////}
// ////////////////////////////////////
////void Truck::returnTruck(Truck* T)
////{
////	if (T->CountJ == J)
////		GoCheckUp(T);
////	else //enqueue in waiting Trucks
////}



