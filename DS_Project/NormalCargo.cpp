#include "NormalCargo.h"

void NormalCargo::SetAutoP(int A)
{
	AutoP = A;
}

int NormalCargo::GetAutoPLeft()
{
	return 0;
}

bool NormalCargo::operator==(const NormalCargo & Temp) const
{
	if (ID == Temp.GetID())
		return true;
	return false;
}
