#pragma once
#include "Event.h"
#include"NormalCargo.h"
class CancellationEvent :
    public Event
{
    NormalCargo* TYP;
public:
    CancellationEvent();
    void PrintInfo();
    virtual void Execute();
};

