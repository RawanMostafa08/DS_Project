#pragma once
#include <iostream>
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
	int MaxW; //hours starts from ready time
	int MyTruckID;
	Time WaitTime;
	Time DelvTime;
	//float AssignTime;
	Time MoveTime;
public:
	/*Cargo(int);*/
	void SetReadyTime(Time);
	void SetLoadTime(float);
	void SetDelvDistance(float);
	void SetCost(double);
	void SetId(int);
	void SetDelvTime(Time);
	void SetMyTruckID(int);
	/*string GetReadyTime(); */
	Time GetReadyTime();
	string GetReadyTimeS();
	float GetLoadTime();
	float GetDelvDistance();
	double GetCost();
	int GetID();
	Time GetDelvTime();
	string GetDelvTimeS();
	int GetMyTruckID();
	virtual void SetCargoType(char);
	char GetCargoType();
	void SetMaxW(int);
	int GetMaxW();
	void SetLoaded(bool);
	bool GetLoaded();
	/*Time GetMoveTime();*/
	Time GetWaitTime();
	string GetWaitTimeS();
};

