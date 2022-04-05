#pragma once
#include "Cargo.h"
#include "PromotionEvent.h"

class NormalCargo :
    public Cargo
{
    int AutoP; //days starts from prep time
public:
    void Promote(int,double,bool);
    void Cancel(int ID);
};

