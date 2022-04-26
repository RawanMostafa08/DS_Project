#include "Company.h"
#include<string>
using namespace std;
Company::Company()
{
	AutoP = 0;
	MaxW = 0;
	TotalCargos = 0;
	CurrentTime.SetHour(0);
	CurrentTime.SetDay(0);
}

void Company::SystemLoad()
{
	in.open("test.txt");
	if (in.is_open())
	{
		Truck* nT, * sT, * vT;
		int x, y, z;
		int tID=1;
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
				nT=new Truck ('N', NS, NC, j, CN,tID);
				tID++;
				WNT.enqueue(nT);
				x--;
			}
			if (y > 0)
			{
				sT=new Truck ('S', SS, SC, j, CS,tID);
				tID++;
				WST.enqueue(sT);
				y--;
			}
			if (z > 0)
			{

				vT=new Truck ('V', VS, VC, j, CV,tID);
				tID++;
				WVT.enqueue(vT);
				z--;
			}
		}
		in >> AutoP >> MaxW; //x contains AutoP && y contains MaxW
		in >> z; //z contains no. of events
		char c; //character to read from the file to determine type of the event
		int d;
		int h;
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
				T.SetDay(d);
				T.SetHour(h);
				Event* R = new ReadyEvent(c,T,id,dist,lt,cost);
				E.enqueue(R);
			}
			else if (c == 'X')
			{
				in >> d;
				in.ignore();
				in >> h;
				in >> id;
				T.SetDay(d);
				T.SetHour(h);
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
				T.SetDay(d);
				T.SetHour(h);
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
	{
		//if (Ev->GetEventTime() < CurrentTime)
		//{
		//	E.dequeue(Ev);
		//	delete Ev;
		//	Check();
		//}
		if (Ev->GetEventTime() == CurrentTime || Ev->GetEventTime() < CurrentTime)
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
	}
}

void Company::UpdateCargos_Trucks(int c)
{
	NormalCargo* N=nullptr;
	SpecialCargo* S= nullptr;
	VIPCargo* V= nullptr;
	//if (WaitingN.GetCount() > 0)
	//{
	//	WaitingN.DeleteFirst(N);
	//	MovingN.enqueue(N,1 ); //((N->GetDelvTime().GetDay() * 24) + N->GetDelvTime().GetHour())
	//}
	//if (WaitingS.GetCount() > 0)
	//{
	//	WaitingS.dequeue(S);
	//	MovingS.enqueue(S, 1); //((S->GetDelvTime().GetDay() * 24) + S->GetDelvTime().GetHour())
	//}
	//if (WaitingV.GetCount() > 0)
	//{
	//	WaitingV.dequeue(V);
	//	MovingV.enqueue(V,1 ); //((V->GetDelvTime().GetDay() * 24) + V->GetDelvTime().GetHour())
	//}
	if (c == 5)
	{
		if (WaitingN.GetCount() > 0)//MovingN.GetCount() > 0
		{
			//MovingN.dequeue(N);
			WaitingN.DeleteFirst(N);
			DeliveredN.enqueue(N);
		}
		if (WaitingS.GetCount() > 0)//MovingS.GetCount() > 0
		{
			//MovingS.dequeue(S);
			WaitingS.dequeue(S);
			DeliveredS.enqueue(S);
		}
		if (WaitingV.GetCount() > 0)//MovingV.GetCount() > 0
		{
			//MovingV.dequeue(V);
			WaitingV.dequeue(V);
			DeliveredV.enqueue(V);
		}
	}

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
	NormalCargo* n = N;
	N->SetId(id);
	if (WaitingN.Find(N))
	{
		VIPCargo* V = new VIPCargo;
		V->SetPromoted(N,d);
		V->SetPriority();
		WaitingV.enqueue(V, V->GetPriority(),1);
		WaitingN.DeleteNode(N);
		delete n;
	}
	else
	{
		delete n;
		return;
	}
}

void Company::CreateReadyCargo(Cargo* C)
{
	if (C->GetCargoType() == 'N')
	{
		C->SetMaxW(MaxW);
		dynamic_cast<NormalCargo*>(C)->SetAutoP(AutoP);
		WaitingN.InsertEnd(dynamic_cast<NormalCargo*>(C));
	}	
	else if (C->GetCargoType() == 'S')
	{
		C->SetMaxW(MaxW);
		WaitingS.enqueue(dynamic_cast<SpecialCargo*>(C));
	}
	else if (C->GetCargoType() == 'V')
	{
		C->SetMaxW(MaxW);
		dynamic_cast<VIPCargo*>(C)->SetPriority();
		/*float p = (C->GetReadyTime() * 0.3) + (0.4 * C->GetDelvDistance()) + (0.3 * C->GetCost());*/
		WaitingV.enqueue(dynamic_cast<VIPCargo*>(C), dynamic_cast<VIPCargo*>(C)->GetPriority(),1);
	}
	TotalCargos++;
}

void Company::CancelNormalCargo(int id)
{
	NormalCargo* N= new NormalCargo;
	NormalCargo* n = N;
	N->SetId(id);
	if (WaitingN.Find(N))
	{
		WaitingN.DeleteNode(N);
		delete n;
		TotalCargos--;
	}
	else
	{
		delete n;
		return;
	}
}

void Company::AdvanceCurrentTime()
{
	CurrentTime = CurrentTime + 1;
}

bool Company::EventIsEmpty()
{
	return E.isEmpty();
}
bool Company::IsInWorkingHours()
{
	if (CurrentTime.GetHour() >= 5 && CurrentTime.GetHour() <= 23)
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

PriorityQueue<NormalCargo*>* Company::GetNMove()
{
	return &MovingN;
}

LinkedQueue<NormalCargo*>* Company::GetNDelv()
{
	return &DeliveredN;
}

PriorityQueue<VIPCargo*>* Company::GetVWait()
{
	return &WaitingV;
}

LinkedQueue<VIPCargo*>* Company::GetVLoad()
{
	return &LoadingV;
}

PriorityQueue<VIPCargo*>* Company::GetVMove()
{
	return &MovingV;
}

LinkedQueue<VIPCargo*>* Company::GetVDelv()
{
	return &DeliveredV;
}

LinkedQueue<SpecialCargo*>* Company::GetSWait()
{
	return &WaitingS;
}

LinkedQueue<SpecialCargo*>* Company::GetSLoad()
{
	return &LoadingS;
}

PriorityQueue<SpecialCargo*>* Company::GetSMove()
{
	return &MovingS;
}

LinkedQueue<SpecialCargo*>* Company::GetSDelv()
{
	return &DeliveredS;
}

string Company::GetCurrTime()
{
	return to_string(CurrentTime.GetDay())+" : "+ to_string(CurrentTime.GetHour());
}

void Company::GetNWListId(int arr[], int& n)
{
	n = WaitingN.GetCount();
	NormalCargo* aux;
	for (int i = 0; i < n; i++)
	{
		WaitingN.DeleteFirst(aux);
		arr[i]= aux->GetID();
		WaitingN.InsertEnd(aux);
	}
}

void Company::GetSWListId(int arr[], int& n)
{
	n = WaitingS.GetCount();
	SpecialCargo* aux;
	for (int i = 0; i < n; i++)
	{
		WaitingS.dequeue(aux);
		arr[i] = aux->GetID();
		WaitingS.enqueue(aux);
	}
}

void Company::GetVWListId(int arr[], int& n)
{
	n = WaitingV.GetCount();
	LinkedQueue<VIPCargo*> V;
	VIPCargo* aux;
	for (int i = 0; i < n; i++)
	{
		WaitingV.dequeue(aux);
		arr[i] = aux->GetID();
		V.enqueue(aux);
	}
	for (int i = 0; i < n; i++)
	{
		V.dequeue(aux);
		WaitingV.enqueue(aux, aux->GetPriority(),1);
	}

}

void Company::GetNMListId(int arr[], int& n)
{
	n = MovingN.GetCount();
	NormalCargo* aux;
	for (int i = 0; i < n; i++)
	{
		MovingN.dequeue(aux);
		arr[i] = aux->GetID();
		MovingN.enqueue(aux, 1,0); //aux->GetDelvTime().GetDay() * 24 + aux->GetDelvTime().GetHour()
	}
}

void Company::GetSMListId(int arr[], int& n)
{
	n = MovingS.GetCount();
	SpecialCargo* aux;
	for (int i = 0; i < n; i++)
	{
		MovingS.dequeue(aux);
		arr[i] = aux->GetID();
		MovingS.enqueue(aux, 1,0); //aux->GetDelvTime().GetDay() * 24 + aux->GetDelvTime().GetHour()
	}
}

void Company::GetVMListId(int arr[], int& n)
{
	n = MovingV.GetCount();
	VIPCargo* aux;
	for (int i = 0; i < n; i++)
	{
		MovingV.dequeue(aux);
		arr[i] = aux->GetID();
		MovingV.enqueue(aux,1,0); //aux->GetDelvTime().GetDay() * 24 + aux->GetDelvTime().GetHour()
	}
}

void Company::GetNDListId(int arr[], int& n)
{
	n = DeliveredN.GetCount();
	NormalCargo* aux;
	for (int i = 0; i < n; i++)
	{
		DeliveredN.dequeue(aux);
		arr[i] = aux->GetID();
		DeliveredN.enqueue(aux);
	}
}

void Company::GetSDListId(int arr[], int& n)
{
	n = DeliveredS.GetCount();
	SpecialCargo* aux;
	for (int i = 0; i < n; i++)
	{
		DeliveredS.dequeue(aux);
		arr[i] = aux->GetID();
		DeliveredS.enqueue(aux);
	}
}

void Company::GetVDListId(int arr[], int& n)
{
	n = DeliveredV.GetCount();
	VIPCargo* aux;
	for (int i = 0; i < n; i++)
	{
		DeliveredV.dequeue(aux);
		arr[i] = aux->GetID();
		DeliveredV.enqueue(aux);
	}
}

bool Company::AllDelivered()
{
	return (TotalCargos == DeliveredN.GetCount() + DeliveredS.GetCount() + DeliveredV.GetCount());
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
void Company::GetNWTListId(int arr[], int& n)
{
	n = WNT.GetCount();
	Truck* aux;
	for (int i = 0; i < n; i++)
	{
		WNT.dequeue(aux);
		arr[i] = aux->GetID();
		WNT.enqueue(aux);
	}
}

void Company::GetSWTListId(int arr[], int& n)
{
	n = WST.GetCount();
	Truck* aux;
	for (int i = 0; i < n; i++)
	{
		WST.dequeue(aux);
		arr[i] = aux->GetID();
		WST.enqueue(aux);
	}
}

void Company::GetVWTListId(int arr[], int& n)
{
	n = WVT.GetCount();
	Truck* aux;
	for (int i = 0; i < n; i++)
	{
		WVT.dequeue(aux);
		arr[i] = aux->GetID();
		WVT.enqueue(aux);
	}

}

void Company::GetNLTListId(int arr[], int& n)
{
	n = LMNT.GetCount();
	Truck* aux;
	for (int i = 0; i < n; i++)
	{
		LMNT.dequeue(aux);
		arr[i] = aux->GetID();
		LMNT.enqueue(aux); 
	}
}

void Company::GetSLTListId(int arr[], int& n)
{
	n = LMST.GetCount();
	Truck* aux;
	for (int i = 0; i < n; i++)
	{
		LMST.dequeue(aux);
		arr[i] = aux->GetID();
		LMST.enqueue(aux); 
	}
}

void Company::GetVLTListId(int arr[], int& n)
{
	n = LMVT.GetCount();
	Truck* aux;
	for (int i = 0; i < n; i++)
	{
		LMVT.dequeue(aux);
		arr[i] = aux->GetID();
		LMVT.enqueue(aux); 
	}
}

void Company::GetNCTListId(int arr[], int& n)
{
	n = CNT.GetCount();
	Truck* aux;
	for (int i = 0; i < n; i++)
	{
		CNT.dequeue(aux);
		arr[i] = aux->GetID();
		CNT.enqueue(aux);
	}
}

void Company::GetSCTListId(int arr[], int& n)
{
	n = CST.GetCount();
	Truck* aux;
	for (int i = 0; i < n; i++)
	{
		CST.dequeue(aux);
		arr[i] = aux->GetID();
		CST.enqueue(aux);
	}
}
//
void Company::GetVCTListId(int arr[], int& n)
{
	n = CVT.GetCount();
	Truck* aux;
	for (int i = 0; i < n; i++)
	{
		CVT.dequeue(aux);
		arr[i] = aux->GetID();
		CVT.enqueue(aux);
	}
}

LinkedQueue<Truck*>* Company::GetNWaitT()
{
	return &WNT;
}

LinkedQueue<Truck*>* Company::GetSWaitT()
{
	return &WST;
}

LinkedQueue<Truck*>* Company::GetVWaitT()
{
	return &WVT;
}

LinkedQueue<Truck*>* Company::GetNLoadT()
{
	return &LMNT;
}

LinkedQueue<Truck*>* Company::GetSLoadT()
{
	return &LMST;
}

LinkedQueue<Truck*>* Company::GetVLoadT()
{
	return &LMVT;
}

LinkedQueue<Truck*>* Company::GetNCheckT()
{
	return &CNT;
}

LinkedQueue<Truck*>* Company::GetSCheckT()
{
	return &CST;
}

LinkedQueue<Truck*>* Company::GetVCheckT()
{
	return &CVT;
}


