#pragma once
#include"NormalCargo.h"
#include"VIPCargo.h"
#include"SpecCargo.h"
#include"Truck.h"
#include"Time.h"
#include"LinkedList.h"
#include"Event.h"
#include"UI.h"
class Company
{
	LinkedQueue<NormalCargo>N;
	LinkedQueue<VIPCargo>V;
	LinkedQueue<SpecCargo>Z;
	LinkedList<Truck>T;
	LinkedList<Event*>E;
public:
	Company();
	//StartUp Functions
	void SystemLoad();
	// Functions Excuted Each Hour Of The System
	void Check();
	void Assign();
	void UpdateCargos();
	void UpdateTrucks();
	void CollectStat();
	void PrintDetails();
	//Output File Function
	void SystemSave();
};

