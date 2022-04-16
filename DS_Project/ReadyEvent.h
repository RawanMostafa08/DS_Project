#pragma once
#include "Event.h"

class ReadyEvent :
    public Event
{
    Cargo* TYP;
public:
    ReadyEvent();
    /*void PrintInfo();*/
    virtual void Execute();
};

