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
	LinkedQueue<Cargo*> Cargos;
	char TruckType;
	int id;
protected:
	/*int CargoNo;*/
	int CountJ;
	/*float CheckTime;*/
	/*float TruckSpeed;
	float DelvTime;*/
	float MaxDistCargo;
	float TotLoadTime;
	//LinkedQueue<Cargo*> Cargos;
	//int TruckCap;
	//int J;
	int Status; // 0->waiting		1->delivery		2->checkup
	int type; //0->vip		1->normal		2->special
	//int CargoNo;
	/*int CountJ;*/
//	float CheckTime;
//	float TruckSpeed;
//	float DelvTime;
//	LinkedQueue<Cargo*> Cargos;
//	int TruckCap;
//	int J;
	//int Status; // 0->waiting		1->delivery		2->checkup
	//int type; //0->vip		1->normal		2->special
public:
	Truck(char,int,int,int,int,int);
	Truck();
	bool LoadCargo(Cargo* c);
	bool UnLoad(Cargo* c);
	bool IsLoaded();
	
	void SetTruckType(char);
	char GetTruckType();

	void SetTruckSpeed(int);
	int GetTruckSpeed();

	void SetId(int);
	int GetID();

	void SetJ(int j);
	int GetJ();

	void SetCargoNo(int a);
	int GetCargoNo();
	
	/*void SetDelvTime(float d);*/
	float GetDelvTime();
	void SetDelvTime(float m, float n);

	void SetTruckCap(int);
	int GetTruckCap();

	void SetCountJ(int b);
	int GetCountJ();

	void SetCheckTime(float t);
	float GetCheckTime();
	
	int GetTC();
	

	////////////////////////////////////////////////////
	///*bool GoCheckup(Truck* T);
	//bool GoDelivery(Truck* T);
	//void returnTruck(Truck* T);*/
};


