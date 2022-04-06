#pragma once
#include"NormalCargo.h"
#include"VIPCargo.h"
#include"SpecialCargo.h"
//#include"NormalTruck.h"
//#include"SpecialTruck.h"
//#include"VIPTruck.h"
#include"Truck.h"
#include"Time.h"
#include"LinkedList.h"
//#include"Event.h"
#include"ReadyEvent.h"
#include"CancellationEvent.h"
#include"PromotionEvent.h"
#include"UI.h"
class Company
{
	//Cargo Lists
	LinkedQueue<NormalCargo>N;
	LinkedQueue<SpecialCargo>S;
	LinkedQueue<VIPCargo>V;
	//Truck Lists
	/*LinkedList<NormalTruck>NT;
	LinkedList<SpecialTruck>ST;
	LinkedList<VIPTruck>VT;*/
	LinkedList<Truck>T;
	//Event Pointer
	LinkedQueue<Event*>E;
	//InputFile Object
	ifstream in;
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

