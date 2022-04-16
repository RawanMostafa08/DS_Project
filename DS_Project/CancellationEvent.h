#pragma once
#include "Event.h"
#include"NormalCargo.h"
class CancellationEvent :
    public Event
{

public:
    CancellationEvent();
   /* void PrintInfo();*/
    virtual void Execute();

};

