#pragma once
#include "Event.h"

class CancellationEvent :
    public Event
{

public:
    CancellationEvent(Time,int);
    virtual void Execute(Cargo*&,int&);

    /* void PrintInfo();*/
};

