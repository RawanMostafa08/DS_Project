#pragma once
#include "Cargo.h"
#include"NormalCargo.h"
class VIPCargo :
    public Cargo
{
public:
   void SetPromoted(NormalCargo*,double);
};

