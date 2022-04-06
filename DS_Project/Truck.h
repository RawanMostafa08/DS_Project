#pragma once
#include"QueueADT.h"
#include"LinkedQueue.h"
#include"Cargo.h"

class Truck
{
	int TruckCap;
	int CargoNo;
	int J;
	float CheckTime;
	float TruckSpeed;
	float DelvTime;
	LinkedQueue<Cargo> Cargos;
	char TruckType;
protected:
	//int CargoNo;
	int CountJ;
//	float CheckTime;
//	float TruckSpeed;
//	float DelvTime;
//	LinkedQueue<Cargo*> Cargos;
//	int TruckCap;
//	int J;
	int Status; // 0->waiting		1->delivery		2->checkup
	int type; //0->vip		1->normal		2->special
public:
	Truck(char,int,int,int,int);
	Truck();
	bool LoadCargo(Cargo c);
	bool UnLoad();
	bool IsLoaded();
	
	void SetTruckType(char);
	char GetTruckType();

	void SetTruckSpeed(int);
	int GetTruckSpeed();

	void SetJ(int j);
	int GetJ();

	void SetCargoNo(int a);
	int GetCargoNo();
	
	void SetDelvTime(float d);


	void SetTruckCap(int);
	int GetTruckCap();

	void SetCountJ(int b);
	int GetCountJ();

	void SetCheckTime(float t);
	float GetCheckTime();
	


	////////////////////////////////////////////////////
	///*bool GoCheckup(Truck* T);
	//bool GoDelivery(Truck* T);
	//void returnTruck(Truck* T);*/
};


