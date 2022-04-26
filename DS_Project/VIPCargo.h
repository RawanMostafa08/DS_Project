#pragma once
#include "Cargo.h"
#include"NormalCargo.h"
class VIPCargo :
    public Cargo

{
    float Priority;
public:
   void SetPromoted(NormalCargo*,double);
   void SetPriority();
   float GetPriority();
};

