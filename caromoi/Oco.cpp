#include "stdafx.h"
#include "Oco.h"


Oco::Oco()
{
}
void Oco::drawchu(CClientDC *pdc)
{
	int xmoi = (this->getA().x + this->getC().x)/2 - 10;
	int ymoi = (this->getA().y + this->getC().y) / 2 - 10;
	pdc->MoveTo(xmoi, ymoi);
	if (giatri == 1)
		pdc->TextOutW(xmoi, ymoi, CString("X"));
	if(giatri == 2)
		pdc->TextOutW(xmoi, ymoi, CString("O"));
}

Oco::~Oco()
{
}
