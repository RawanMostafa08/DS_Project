#pragma once
#include "Event.h"

class ReadyEvent :
    public Event
{
    Cargo* TYP;
    char CargoType;
    float DIST; //is the cargo distance(in kilometers)
    int LT; //Time(in hours) to load or unload the cargo.
    float Cost; //is the cargo cost.

public:
    ReadyEvent(char,Time,int,float,int,float);
    virtual void Execute(Cargo*&,int&);

    /* void PrintInfo();*/
};

