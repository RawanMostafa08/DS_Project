#include "UI.h"
#include<iostream>
using namespace std;
//Current Time(Day:Hour) :70 : 9
//7 Waiting Cargos : [110, 113] (116, 118) {119, 112, 114}
//------------------------------------------------------ -
//4 Loading Trucks : 5[3, 4, 12, 15] 1(6) 7{9, 11} 2[5, 7]
//------------------------------------------------------ -
//4 Empty Trucks : [4] , (10), [6], { 8 }
//------------------------------------------------------ -
//5 Moving Cargos : 7[45, 52] 12{34, 77, 80}
//------------------------------------------------------ -
//2 In - Checkup Trucks : [2] { 3 }
//------------------------------------------------------ -
//3 Delivered Cargos : {5}[4](1)


UI::UI()
{
	C = new Company;
}
void UI::ProgramInterface()
{
	C->SystemLoad();
	int count = 0;
	char c;
	cout << "Select Program Mode: Interactive Mode or Step-By-Step Mode(I or S or s)" << endl;
	cin >> c;
	switch (c)
	{ 
		case('I'):
		{
			char input;
			Print();
			while (!C->EventIsEmpty() || !C->AllDelivered())
			{
				C->AdvanceCurrentTime();
				if (C->IsInWorkingHours())
				{
					C->Check();
					C->UpdateCargos_Trucks(count);
					if (count < 5)
						count++;
					else if (count == 5)
						count = 0;
				}
				cout << "Enter an input" << endl;
				cin >> input;
				Print();
			}
			delete C;
			break;
		}
		case('S'):
		{
			Print();
			while (!C->EventIsEmpty() || !C->AllDelivered())
			{
				C->AdvanceCurrentTime();
				if (C->IsInWorkingHours())
				{
					C->Check();
					C->UpdateCargos_Trucks(count);
					if (count < 5)
						count++;
					else if (count == 5)
						count = 0;
				}
				Sleep(1000);
				Print();
			}
			delete C;
			break;
		}
		case('s'):
		{
			cout << "Silent Mode" << endl;
			cout << "Simulation Starts..." << endl;
			cout << "Simulation ends, Output file created" << endl;
			delete C;
			break;
		}
	}	
}

void UI::Print()
{
	int n = 0;
	int *NWListId=new int[C->GetNWait()->GetCount()];
	int *SWListId=new int[C->GetSWait()->GetCount()];
	int *VWListId=new int[C->GetVWait()->GetCount()];
	int *NMListId=new int[C->GetNMove()->GetCount()];
	int *SMListId=new int[C->GetSMove()->GetCount()];
	int *VMListId=new int[C->GetVMove()->GetCount()];
	int *NDListId=new int[C->GetNDelv()->GetCount()];
	int *SDListId=new int[C->GetSDelv()->GetCount()];
	int *VDListId=new int[C->GetVDelv()->GetCount()];
	C->GetNWListId(NWListId,n);
	C->GetSWListId(SWListId,n);
	C->GetVWListId(VWListId,n);
	C->GetNMListId(NMListId,n);
	C->GetSMListId(SMListId,n);
	C->GetVMListId(VMListId,n);
	C->GetNDListId(NDListId,n);
	C->GetSDListId(SDListId,n);
	C->GetVDListId(VDListId,n);

	/// Truck ID arrays
	/// //////////////////////////////////////////////////
	int* NWTListId = new int[C->GetNWaitT()->GetCount()];
	int* SWTListId = new int[C->GetSWaitT()->GetCount()];
	int* VWTListId = new int[C->GetVWaitT()->GetCount()];
	int* NLTListId = new int[C->GetNLoadT()->GetCount()];
	int* SLTListId = new int[C->GetSLoadT()->GetCount()];
	int* VLTListId = new int[C->GetVLoadT()->GetCount()];
	int* NCTListId = new int[C->GetNCheckT()->GetCount()];
	int* SCTListId = new int[C->GetSCheckT()->GetCount()];
	int* VCTListId = new int[C->GetVCheckT()->GetCount()];
	 C->GetNWTListId(NWTListId,n);
	 C->GetSWTListId(SWTListId,n);
	 C->GetVWTListId(VWTListId,n);
	 C->GetNLTListId(NLTListId,n);
	 C->GetSLTListId(SLTListId,n);
	 C->GetVLTListId(VLTListId,n);
	 C->GetNCTListId(NCTListId,n);
	 C->GetSCTListId(SCTListId,n);
	 C->GetVCTListId(VCTListId,n);
	
	/// ////////////////////////////////////////////////
	
	cout << "Current Time(Day:Hour) :" << C->GetCurrTime() << endl;
	int cw = C->GetNWait()->GetCount()+ C->GetSWait()->GetCount()+ C->GetVWait()->GetCount();
	cout << cw <<" Waiting Cargos : [";
	if (C->GetNWait()->GetCount() > 0)
	{
		for (int i = 0; i < (C->GetNWait()->GetCount()) - 1; i++)
		{
			cout << NWListId[i] << ",";
		}
		cout << NWListId[C->GetNWait()->GetCount()-1];
	}
	cout << "] (";
	if (C->GetSWait()->GetCount())
	{
		for (int i = 0; i < (C->GetSWait()->GetCount()) - 1; i++)
		{
			cout << SWListId[i] << ",";
		}
		cout << SWListId[C->GetSWait()->GetCount()-1];
	}
	cout << ") {";
	if (C->GetVWait()->GetCount())
	{
		for (int i = 0; i < (C->GetVWait()->GetCount()) - 1; i++)
		{
			cout << VWListId[i] << ",";
		}
		cout << VWListId[C->GetVWait()->GetCount()-1];
	}
	cout << "}" << endl;
	cout << "------------------------------------------------------ -" << endl;
	/*//////////////////////////////////////////////////*/
	int clt = C->GetNLoadT()->GetCount() + C->GetSLoadT()->GetCount() + C->GetVLoadT()->GetCount();
	cout << clt << " Loading Trucks : [";
	if (C->GetNLoadT()->GetCount() > 0)
	{
		for (int i = 0; i < (C->GetNLoadT()->GetCount()) - 1; i++)
		{
			cout << NLTListId[i] << ",";
		}
		cout << NLTListId[C->GetNLoadT()->GetCount() - 1];
	}
	cout << "] (";
	if (C->GetSLoadT()->GetCount())
	{
		for (int i = 0; i < (C->GetSLoadT()->GetCount()) - 1; i++)
		{
			cout << SLTListId[i] << ",";
		}
		cout << SLTListId[C->GetSLoadT()->GetCount() - 1];
	}
	cout << ") {";
	if (C->GetVLoadT()->GetCount())
	{
		for (int i = 0; i < (C->GetVLoadT()->GetCount()) - 1; i++)
		{
			cout << VLTListId[i] << ",";
		}
		cout << VLTListId[C->GetVLoadT()->GetCount() - 1];
	}
	cout << "}" << endl;
	cout << "------------------------------------------------------ -" << endl;
	/*//////////////////////////////////////////////////*/
	int cwt = C->GetNWaitT()->GetCount() + C->GetSWaitT()->GetCount() + C->GetVWaitT()->GetCount();
	cout << cwt << " Empty Trucks : [";
	if (C->GetNWaitT()->GetCount() > 0)
	{
		for (int i = 0; i < (C->GetNWaitT()->GetCount()) - 1; i++)
		{
			cout << NWTListId[i] << ",";
		}
		cout << NWTListId[C->GetNWaitT()->GetCount() - 1];
	}
	cout << "] (";
	if (C->GetSWaitT()->GetCount())
	{
		for (int i = 0; i < (C->GetSWaitT()->GetCount()) - 1; i++)
		{
			cout << SWTListId[i] << ",";
		}
		cout << SWTListId[C->GetSWaitT()->GetCount() - 1];
	}
	cout << ") {";
	if (C->GetVWaitT()->GetCount())
	{
		for (int i = 0; i < (C->GetVWaitT()->GetCount()) - 1; i++)
		{
			cout << VWTListId[i] << ",";
		}
		cout << VWTListId[C->GetVWaitT()->GetCount() - 1];
	}
	cout << "}" << endl;
	cout << "------------------------------------------------------ -" << endl;

	/*//////////////////////////////////////////////////*/

	/*//////////////////////////////////////////////////*/
	int cm = C->GetNMove()->GetCount() + C->GetSMove()->GetCount() + C->GetVMove()->GetCount();
	cout << cm << " Moving Cargos : [";
	if (C->GetNMove()->GetCount())
	{
		for (int i = 0; i < (C->GetNMove()->GetCount()) - 1; i++)
		{
			cout << NMListId[i] << ",";
		}
		cout << NMListId[C->GetNMove()->GetCount()-1];
	}
	cout << "] (";
	if (C->GetSMove()->GetCount())
	{
		for (int i = 0; i < (C->GetSMove()->GetCount()) - 1; i++)
		{
			cout << SMListId[i] << ",";
		}
		cout << SMListId[C->GetSMove()->GetCount()-1];
	}
	cout << ") {";
	if (C->GetVMove()->GetCount())
	{
		for (int i = 0; i < (C->GetVMove()->GetCount()) - 1; i++)
		{
			cout << VMListId[i] << ",";
		}
		cout << VMListId[C->GetVMove()->GetCount()-1];
	}
	cout << "}" << endl;
	cout << "-------------------------------------------------------" << endl;
	/*//////////////////////////////////////////////*/
	int cct = C->GetNCheckT()->GetCount() + C->GetSCheckT()->GetCount() + C->GetVCheckT()->GetCount();
	cout << cct << " In-Checkup Trucks : [";
	if (C->GetNCheckT()->GetCount() > 0)
	{
		for (int i = 0; i < (C->GetNCheckT()->GetCount()) - 1; i++)
		{
			cout << NCTListId[i] << ",";
		}
		cout << NCTListId[C->GetNCheckT()->GetCount() - 1];
	}
	cout << "] (";
	if (C->GetSCheckT()->GetCount())
	{
		for (int i = 0; i < (C->GetSCheckT()->GetCount()) - 1; i++)
		{
			cout << SCTListId[i] << ",";
		}
		cout << SCTListId[C->GetSCheckT()->GetCount() - 1];
	}
	cout << ") {";
	if (C->GetVCheckT()->GetCount())
	{
		for (int i = 0; i < (C->GetVCheckT()->GetCount()) - 1; i++)
		{
			cout << VCTListId[i] << ",";
		}
		cout << VCTListId[C->GetVCheckT()->GetCount() - 1];
	}
	cout << "}" << endl;
	cout << "------------------------------------------------------ -" << endl;
	/*///////////////////////////////////////////////*/
	int cd = C->GetNDelv()->GetCount() + C->GetSDelv()->GetCount() + C->GetVDelv()->GetCount();
	cout << cd << " Delivered Cargos : [";
	if (C->GetNDelv()->GetCount())
	{
		for (int i = 0; i < (C->GetNDelv()->GetCount()) - 1; i++)
		{
			cout << NDListId[i] << ",";
		}
		cout << NDListId[C->GetNDelv()->GetCount()-1];
	}
	cout << "] (";
	if (C->GetSDelv()->GetCount())
	{
		for (int i = 0; i < (C->GetSDelv()->GetCount()) - 1; i++)
		{
			cout << SDListId[i] << ",";
		}
		cout << SDListId[C->GetSDelv()->GetCount()-1];
	}
	cout << ") {";
	if (C->GetVDelv()->GetCount())
	{
		for (int i = 0; i < (C->GetVDelv()->GetCount()) - 1; i++)
		{
			cout << VDListId[i] << ",";
		}
		cout << VDListId[C->GetVDelv()->GetCount()-1];
	}
	cout << "}" << endl;
	////////////////////////
	delete[]NWListId;
	delete[]SWListId;
	delete[]VWListId;
	delete[]NMListId;
	delete[]SMListId;
	delete[]VMListId;
	delete[]NDListId; 
	delete[]SDListId;
	delete[]VDListId;
	////////////////////////
	delete[]NWTListId;
	delete[]SWTListId;
	delete[]VWTListId;
	delete[]NLTListId;
	delete[]SLTListId;
	delete[]VLTListId;
	delete[]NCTListId;
	delete[]SCTListId;
	delete[]VCTListId;
	////////////////////////
}

