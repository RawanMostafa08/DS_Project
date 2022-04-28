#include "VIPCargo.h"

void VIPCargo::SetPromoted(NormalCargo* N, double em)
{
	SetReadyTime(N->GetReadyTime());
	SetLoadTime(N->GetLoadTime());
	SetDelvDistance(N->GetDelvDistance());
	SetCost(N->GetCost() + em);
	SetId(N->GetID());
	SetCargoType('V');
	SetLoaded(false);
	SetMaxW(N->GetMaxW());
	return;
}

void VIPCargo::SetPriority()
{
	Priority=(0.4 * DelvDistance) + (0.3 * cost) - (ReadyTime * 0.3);
}

float VIPCargo::GetPriority()
{
	return Priority;
}
