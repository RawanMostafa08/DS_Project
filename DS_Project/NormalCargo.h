#pragma once
#include "Cargo.h"

class NormalCargo :
    public Cargo
{
   int AutoP; //days starts from prep time
public:
    void SetAutoP(int);
    int GetAutoPLeft();
    bool operator ==( const NormalCargo &) const;
};

