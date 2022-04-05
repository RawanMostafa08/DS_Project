#pragma once
#include "Truck.h"

bool Truck::LoadCargo(Cargo c)
{
	if (CargoNo == TruckCap)
		return false;
	else
	{
		Cargos.enqueue(c);
		CargoNo++;
		return true;
	}
}

bool Truck::UnLoad()
{
	Cargo c;
	while (CargoNo != 0)
	{
		CargoNo--;
		Cargos.dequeue(c);
		return true;
	}
	return false;
}