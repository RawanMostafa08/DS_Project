#pragma once
#include "Event.h"
//#include"NormalCargo.h"

class PromotionEvent :
    public Event
{
public:
   PromotionEvent();
    void PrintInfo(int,double);
    virtual void Execute(int, double,bool);
    /*void SetExtraMoney(double);
    double GetExtraMoney();*/
};

