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
#include"ArrayStack.h"
//#include"Event.h"
#include"ReadyEvent.h"
#include"CancellationEvent.h"
#include"PriorityQueue.h"
#include"PromotionEvent.h"
class Company
{
	//Cargo Lists
	LinkedList<NormalCargo*>WaitingN;
	LinkedQueue<NormalCargo*>LoadingN;
	PriorityQueue<NormalCargo*>MovingN;
	LinkedQueue<NormalCargo*>DeliveredN;

	LinkedQueue<SpecialCargo*>WaitingS;
	LinkedQueue<SpecialCargo*>LoadingS;
	PriorityQueue<SpecialCargo*>MovingS;
	LinkedQueue<SpecialCargo*>DeliveredS;

	PriorityQueue<VIPCargo*>WaitingV;
	LinkedQueue<VIPCargo*>LoadingV;
	PriorityQueue<VIPCargo*>MovingV;
	LinkedQueue<VIPCargo*>DeliveredV;

	//Truck Lists
	LinkedQueue<Truck>NT;
	LinkedQueue<Truck>VT;
	LinkedQueue<Truck>ZT;
	PriorityQueue<Truck> DelvTruck;
	//Event Pointer
	LinkedQueue<Event*>E;
	//InputFile Object
	ifstream in;
	ofstream out;
	//
	Time AssignTime;
	Time CurrentTime;
	int AutoP;
	int MaxW;
	
public:
	Company();
	//StartUp Functions
	void SystemLoad();
	// Functions Excuted Each Hour Of The System
	void Check();
	/*void Assign();*/
	void UpdateCargos_Trucks();
	/*void UpdateTrucks();*/
	void CollectStat();
	void PrintDetails();
	//Output File Function
	void SystemSave();
	void Promote(double,int);
	void CreateReadyCargo(Cargo*);
	void CancelNormalCargo(int);
	void AdvanceCurrentTime();
	bool EventIsEmpty();
	bool IsInWorkingHours();
	LinkedList<NormalCargo*>* GetNWait();
	LinkedQueue<NormalCargo*>* GetNLoad();
	Node<NormalCargo*> GetNMove();
	Node<NormalCargo*> GetNDelv();
	Node<VIPCargo*> GetVWait();
	Node<VIPCargo*> GetVLoad();
	Node<VIPCargo*> GetVMove();
	Node<VIPCargo*> GetVDelv();
	Node<SpecialCargo*> GetSWait();
	Node<SpecialCargo*> GetSLoad();
	Node<SpecialCargo*> GetSMove();
	Node<SpecialCargo*> GetSDelv();
};

