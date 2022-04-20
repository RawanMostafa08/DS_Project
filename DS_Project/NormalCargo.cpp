#include "NormalCargo.h"

void NormalCargo::SetAutoP(int A)
{
	AutoP = A;
}

int NormalCargo::GetAutoPLeft()
{
	return 0;
}

bool NormalCargo::operator==(NormalCargo* &Temp)
{
	if (this->GetID() == Temp->GetID())
		return true;
	else
		return false;
}
