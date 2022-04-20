#pragma once
#include "Event.h"

class PromotionEvent :
    public Event
{
    double ExtraMoney;
public:
    PromotionEvent(Time,int,double);
    virtual void Execute(Cargo*&,int&);
     double GetExtraMoney();
    //void SetExtraMoney(double);
    /* void PrintInfo(int,double);*/
};

