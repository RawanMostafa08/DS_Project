#pragma once
#include"QueueADT.h"
#include"LinkedQueue.h"
#include"Cargo.h"

class Truck
{
	int TruckCap;
	int CargoNo;
	int J;
	float checkTime;
	float TruckSpeed;
	float DelvTime;
	LinkedQueue<Cargo> Cargos;
public:
	bool LoadCargo(Cargo c);
	bool UnLoad();
};