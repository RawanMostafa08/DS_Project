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
	LinkedQueue<Truck*>WNT; //waiting trucks, empty
	LinkedQueue<Truck*>WVT;
	LinkedQueue<Truck*>WST;

	LinkedQueue<Truck*> CNT; //checkup trucks
	LinkedQueue<Truck*> CVT;
	LinkedQueue<Truck*> CST;

	LinkedQueue<Truck*>LMNT;  //loading trucks
	LinkedQueue<Truck*>LMVT;
	LinkedQueue<Truck*>LMST;

	//Event Pointers List
	LinkedQueue<Event*>E;

	//In&OutputFile Object
	ifstream in;
	ofstream out;

	//
	Time AssignTime;
	Time CurrentTime;

	//
	int AutoP;
	int MaxW;
	int TotalCargos;
	
public:
	Company();

	//StartUp Functions
	void SystemLoad();

	// Functions Excuted Each Hour Of The System
	void Check();
	/*void Assign();*/
	void UpdateCargos_Trucks(int);
	/*void UpdateTrucks();*/
	void CollectStat();
	void PrintDetails();
	void AdvanceCurrentTime();

	//Output File Function
	void SystemSave();

	void Promote(double,int);
	void CreateReadyCargo(Cargo*);
	void CancelNormalCargo(int);
	

	bool EventIsEmpty();
	bool IsInWorkingHours();

	LinkedList<NormalCargo*>* GetNWait();
	LinkedQueue<NormalCargo*>* GetNLoad();
	PriorityQueue<NormalCargo*>* GetNMove();
	LinkedQueue<NormalCargo*>* GetNDelv();

	PriorityQueue<VIPCargo*>* GetVWait();
	LinkedQueue<VIPCargo*>* GetVLoad();
	PriorityQueue<VIPCargo*>* GetVMove();
	LinkedQueue<VIPCargo*>* GetVDelv();

	LinkedQueue<SpecialCargo*>* GetSWait();
	LinkedQueue<SpecialCargo*>* GetSLoad();
	PriorityQueue<SpecialCargo*>* GetSMove();
	LinkedQueue<SpecialCargo*>* GetSDelv();

	void GetNWListId(int arr[],int &n);
	void GetSWListId(int arr[],int &n);
	void GetVWListId(int arr[],int &n);
	void GetNMListId(int arr[],int &n);
	void GetSMListId(int arr[],int &n);
	void GetVMListId(int arr[],int &n);
	void GetNDListId(int arr[],int &n);
	void GetSDListId(int arr[],int &n);
	void GetVDListId(int arr[],int &n);

	string GetCurrTime();
	bool AllDelivered();
	void GetNWTListId(int arr[], int& n);
	void GetSWTListId(int arr[], int& n);
	void GetVWTListId(int arr[], int& n);
	void GetNLTListId(int arr[], int& n);
	void GetSLTListId(int arr[], int& n);
	void GetVLTListId(int arr[], int& n);
	void GetNCTListId(int arr[], int& n);
	void GetSCTListId(int arr[], int& n);
	void GetVCTListId(int arr[], int& n);

	LinkedQueue<Truck*>* GetNWaitT();
	LinkedQueue<Truck*>* GetSWaitT();
	LinkedQueue<Truck*>* GetVWaitT();

	LinkedQueue<Truck*>* GetNLoadT();
	LinkedQueue<Truck*>* GetSLoadT();
	LinkedQueue<Truck*>* GetVLoadT();

	LinkedQueue<Truck*>* GetNCheckT();
	LinkedQueue<Truck*>* GetSCheckT();
	LinkedQueue<Truck*>* GetVCheckT();

};

