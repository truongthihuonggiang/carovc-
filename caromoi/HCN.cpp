#include "stdafx.h"
#include "HCN.h"


HCN::HCN()
{
}

HCN::HCN(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void HCN::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void HCN::draw(CClientDC *pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);

}
CPoint HCN::getA()
{
	return CPoint(x1, y1);
}
CPoint HCN::getC()
{
	return CPoint(x2, y2);
}
int HCN::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
} 
HCN::~HCN()
{
}
