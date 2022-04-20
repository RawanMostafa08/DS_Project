#include "Company.h"
#include<string>
using namespace std;
Company::Company()
{
	CurrentTime.SetHour(0);
	CurrentTime.SetDay(0);
}

void Company::SystemLoad()
{
	in.open("test.txt");
	if (in.is_open())
	{
		int x, y, z;
		in >> x >> y >> z;
		int NS, SS, VS;
		in >> NS >> SS >> VS;
		int NC, SC, VC;
		in >> NC >> SC >> VC;
		int j, CN, CS, CV;
		in >> j >> CN >> CS >> CV;
		while (x > 0 || y > 0 || z > 0)
		{
			if (x > 0)
			{
				Truck t('N', NS, NC, j, CN);
				NT.enqueue(t);
				x--;
			}
			else if (y > 0)
			{
				Truck t('S', SS, SC, j, CS);
				ZT.enqueue(t);
				y--;
			}
			else if (z > 0)
			{
				Truck t('V', VS, VC, j, CV);
				VT.enqueue(t);
				z--;
			}
		}
		in >> AutoP >> MaxW; //x contains AutoP && y contains MaxW
		in >> z; //z contains no. of events
		char c; //character to read from the file to determine type of the event
		string d;
		string h;
		Time T;
		int id, lt;
		float dist, cost;
		double em;
		while (z > 0)
		{
			in >> c;
			if (c == 'R')
			{
				in >> c;
				in >> d;
				in.ignore();
				in >> h;
				in >> id >> dist >> lt >> cost;
				T.SetDay(stoi(d));
				T.SetHour(stoi(h));
				Event* R = new ReadyEvent(c,T,id,dist,lt,cost);
				E.enqueue(R);
			}
			else if (c == 'X')
			{
				in >> d;
				in.ignore();
				in >> h;
				in >> id;
				T.SetDay(stoi(d));
				T.SetHour(stoi(h));
				Event* C = new CancellationEvent(T,id);
				E.enqueue(C);
			}
			else if (c == 'P')
			{
				in >> d;
				in.ignore();
				in >> h;
				in >> id;
				in>> em;
				T.SetDay(stoi(d));
				T.SetHour(stoi(h));
				Event* P = new PromotionEvent(T,id,em);
				E.enqueue(P);
			}
			z--;
		}
	}
	in.close();
}

void Company::Check()
{
	//Each Hour Check for Events
	Event* Ev;
	Cargo* C;
	int id;
	if (E.peek(Ev))
		if (Ev->GetEventTime() == CurrentTime)
		{
			Ev->Execute(C, id);
			if (dynamic_cast<ReadyEvent*>(Ev))
			{
				CreateReadyCargo(C);
			}
			else if (dynamic_cast<CancellationEvent*>(Ev))
			{
				CancelNormalCargo(id);
			}
			else if (dynamic_cast<PromotionEvent*>(Ev))
			{
				Promote(dynamic_cast<PromotionEvent*>(Ev)->GetExtraMoney(), id);
			}
			E.dequeue(Ev);
			delete Ev;
			Check();
		}
		else
			return;
	return;
}

void Company::UpdateCargos_Trucks()
{
	
}

//void Company::UpdateTrucks()
//{
//}

void Company::CollectStat()
{
	/*Cargo* c;
	Time WaitSum;
	LinkedQueue<Cargo*>aux;
	while (!DelvCargo.isEmpty())
	{
		DelvCargo.dequeue(c);
		WaitSum = WaitSum + c->GetWaitTime();
		aux.enqueue(c);
	}
	while (!aux.isEmpty())
	{
		aux.dequeue(c);
		DelvCargo.enqueue(c, (c->GetReadyTime() * 0.3) + (0.4 * c->GetDelvDistance()) + (0.3 * c->GetCost()));
	}
	Time avgWait = WaitSum / DelvCargo.GetCount();
	out << "Cargos : " << DelvCargo.GetCount() << "	[" << "N : " << NC.GetCount() << ", S : " << ZC.GetCount() << ", V : " << VC.GetCount() << "]" << endl;
	out << "Cargo Avg Wait = " << to_string(avgWait.GetDay()) + ":" + to_string(avgWait.GetHour()) << endl;*/
}

void Company::PrintDetails()
{
}

void Company::SystemSave()
{
	/*Cargo* c;
	out.open("test.txt");
	if (out.is_open())
	{
		out << "CDT		ID		PT		WT		TID" << endl;
		while (!DelvCargo.isEmpty())
		{
			DelvCargo.dequeue(c);
			out << c->GetDelvTimeS() << "	" << c->GetID() << "	" << c->GetReadyTimeS() << "	" << c->GetWaitTimeS() << "		" << c->GetMyTruckID() << endl;
		}
		out << "............................" << endl;
		out << "............................" << endl;
		CollectStat();
	}*/
}

void Company::Promote(double d,int id)
{
	NormalCargo* N = new NormalCargo;
	N->SetId(id);
	if (WaitingN.Find(N))
	{
		VIPCargo* V = new VIPCargo;
		V->SetPromoted(N,d);
		float p = (V->GetReadyTime() * 0.3) + (0.4 * V->GetDelvDistance()) + (0.3 * V->GetCost());
		WaitingV.enqueue(V, p);
		/*WaitingN.DeleteNode(N);*/
	}
	else
	{
		return;
	}
}

void Company::CreateReadyCargo(Cargo* C)
{
	if (C->GetCargoType() == 'N')
	{
		C->SetMaxW(MaxW);
		dynamic_cast<NormalCargo*>(C)->SetAutoP(AutoP);
		/*WaitingN.InsertEnd(dynamic_cast<NormalCargo*>(C));*/
	}	
	else if (C->GetCargoType() == 'S')
	{
		C->SetMaxW(MaxW);
		WaitingS.enqueue(dynamic_cast<SpecialCargo*>(C));
	}
	else if (C->GetCargoType() == 'V')
	{
		C->SetMaxW(MaxW);
		float p = (C->GetReadyTime() * 0.3) + (0.4 * C->GetDelvDistance()) + (0.3 * C->GetCost());
		WaitingV.enqueue(dynamic_cast<VIPCargo*>(C), p);
	}
}

void Company::CancelNormalCargo(int id)
{
	NormalCargo* N= new NormalCargo;
	N->SetId(id);
	if (WaitingN.Find(N))
	{
		/*WaitingN.DeleteNode(N);*/
	}
	else
	{
		return;
	}
}

void Company::AdvanceCurrentTime()
{
	CurrentTime = CurrentTime + 1;
}

/*istream& operator >>(istream& input, Time& t)
{
	int x, y;
	input >> x;
	input.ignore();
	input >> y;
	t.SetHour(y);
	t.SetDay(x);
	return input;
}*/

bool Company::EventIsEmpty()
{
	return E.isEmpty();
}
bool Company::IsInWorkingHours()
{
	if (CurrentTime.GetHour() < 5 || CurrentTime.GetHour() > 23)
		return true;
	return false;
}

LinkedList<NormalCargo*>* Company::GetNWait()
{
	return &WaitingN;
}

LinkedQueue<NormalCargo*>* Company::GetNLoad()
{
	return &LoadingN;
}

Node<NormalCargo*> Company::GetNMove()
{
	return Node<NormalCargo*>();
}

Node<NormalCargo*> Company::GetNDelv()
{
	return Node<NormalCargo*>();
}

Node<VIPCargo*> Company::GetVWait()
{
	return Node<VIPCargo*>();
}

Node<VIPCargo*> Company::GetVLoad()
{
	return Node<VIPCargo*>();
}

Node<VIPCargo*> Company::GetVMove()
{
	return Node<VIPCargo*>();
}

Node<VIPCargo*> Company::GetVDelv()
{
	return Node<VIPCargo*>();
}

Node<SpecialCargo*> Company::GetSWait()
{
	return Node<SpecialCargo*>();
}

Node<SpecialCargo*> Company::GetSLoad()
{
	return Node<SpecialCargo*>();
}

Node<SpecialCargo*> Company::GetSMove()
{
	return Node<SpecialCargo*>();
}

Node<SpecialCargo*> Company::GetSDelv()
{
	return Node<SpecialCargo*>();
}

//void Company::Assign()
//{
//	if (AssignTime.GetHour() < 5 || AssignTime.GetHour() > 23)
//		return;
//	else
//	{
//		NormalCargo* NormC; Truck NormT; NC.peek(NormC); NT.peek(NormT);
//		if (NormC->GetWaitTime() > NormC->GetMaxW() || NormC->GetWaitTime() == NormC->GetMaxW())
//		{
//			NC.dequeue(NormC);
//			NT.dequeue(NormT);
//			NormT.LoadCargo(NormC);
//			DelvTruck.enqueue(NormT, NormT.GetDelvTime());
//		}
//		else
//		{
//			for (int i = 0; i < NormT.GetTC(); i++)
//			{
//				//NC.
//			}
//		}
//	}
//
//}



