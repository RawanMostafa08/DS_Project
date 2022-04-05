#include "NormalCargo.h"
#
void NormalCargo::Promote(int ID ,double EM,bool L)
{
	PromotionEvent* P=new PromotionEvent;
	P->Execute(/*ID,EM,L*/);
}

void NormalCargo::Cancel(int ID)
{

}
