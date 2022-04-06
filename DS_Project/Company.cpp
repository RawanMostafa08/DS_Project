#include "Company.h"

Company::Company()
{
}

void Company::SystemLoad()
{
	int x, y, z;
	in >> x >> y >> z;
	int NS, SS, VS;
	in >> NS >> SS >> VS;
	int NC, SC, VC;
	in >> NC >> SC >> VC;
	int j, CN, CS, CV;
	in >> j >> CN >> CS >> CV;
	while (x>0 || y>0 || z>0)
	{
		if (x>0)
		{
			Truck t('N', NS, NC, j, CN);
			T.InsertBeg(t);
			x--;
		}
		if (y>0)
		{
			Truck t('S', SS, SC, j, CS);
			T.InsertBeg(t);
			y--;
		}
		if (z>0)
		{
			Truck t('V', VS, VC, j, CV);
			T.InsertBeg(t);
			z--;
		}
	}
	in >> x >> y; //x contains AutoP && y contains MaxW
	in >> z; //z contains no. of events
	char c; //character to read from the file to determine type of the event
	while (z > 0)
	{
		in >> c;
		if (c == 'R')
		{
			Event* R = new ReadyEvent;
			E.enqueue(R);
		}
		if (c == 'X')
		{
			Event* C = new CancellationEvent;
			E.enqueue(C);
		}
		if (c == 'P')
		{
			Event* P = new PromotionEvent;
			E.enqueue(P);
		}
		z--;
	}
}

void Company::Check()
{
}

void Company::Assign()
{
}

void Company::UpdateCargos()
{
}

void Company::UpdateTrucks()
{
}

void Company::CollectStat()
{
}

void Company::PrintDetails()
{
}

void Company::SystemSave()
{
}
