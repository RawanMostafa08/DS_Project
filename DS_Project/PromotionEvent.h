#pragma once
#include "Event.h"
//#include"NormalCargo.h"

class PromotionEvent :
    public Event
{
    double ExtraMoney;
public:
   PromotionEvent();
   /* void PrintInfo(int,double);*/
    virtual void Execute();
    void SetExtraMoney(double);
    double GetExtraMoney();
};

