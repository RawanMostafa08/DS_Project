#pragma once
#include"NormalCargo.h"
#include"VIPCargo.h"
#include"SpecialCargo.h"
//#include"NormalTruck.h"
//#include"SpecialTruck.h"
//#include"VIPTruck.h"
#include"Truck.h"
#include"Time.h"
#include"ArrayStack.h"
//#include"Event.h"
#include"ReadyEvent.h"
#include"CancellationEvent.h"
#include"PriorityQueue.h"
#include"PromotionEvent.h"
#include"UI.h"
class Company
{
	//Cargo Lists
	LinkedQueue<NormalCargo>NC;
	LinkedQueue<VIPCargo>VC;
	LinkedQueue<SpecialCargo>ZC;
	/*LinkedQueue<NormalCargo>N;
	LinkedQueue<SpecialCargo>S;
	LinkedQueue<VIPCargo>V;*/
	  
	//Truck Lists
	LinkedQueue<Truck>NT;
	LinkedQueue<Truck>VT;
	LinkedQueue<Truck>ZT;
	PriorityQueue<Truck> DelvTruck;
	/*LinkedList<NormalTruck>NT;
	LinkedList<SpecialTruck>ST;
	LinkedList<VIPTruck>VT;*/
	/*ArrayStack<Truck>T;*/

	//Event Pointer
	LinkedQueue<Event*>E;
	//InputFile Object
	ifstream in;
	//
	Time AssignTime;
	
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

