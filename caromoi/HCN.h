#pragma once
class HCN
{
private:
	int x1, x2, y1, y2;
public:
	HCN(int x1, int y1, int x2, int y2);
	void thietlap(int x1, int y1, int x2, int y2);
	CPoint getA();
	CPoint getC();
	void draw(CClientDC * pdc);
	int tronghinh(CPoint p);
	HCN();
	~HCN();
};

