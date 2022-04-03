#pragma once
#include"Time.h"
using namespace std;
class Cargo
{
	Time ReadyTime;
	float LoadTime;
	float UnloadTime;
	float DelvDistance;
	double cost;
	int ID;
	char CargoType;
	bool Loaded;
public:
	Cargo();
	void SetReadyTime(Time);
	void SetLoadTime(float);
	void SetDelvDistance(float);
	void SetCost(double);
	void SetId(int);
	/*string GetReadyTime();*/
	Time GetReadyTime();
	float GetLoadTime();
	float GetDelvDistance();
	double GetCost();
	int GetID();
	virtual void SetCargoType(char)=0;
	char GetCargoType();
};

