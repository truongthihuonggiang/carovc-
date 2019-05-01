#include "stdafx.h"
#include "Button.h"


Button::Button()
{
}


Button::~Button()
{
}


int Button::draw(CClientDC *pdc)
{
	// TODO: Add your implementation code here.
	pdc->Rectangle(getA().x, getA().y, getC().x, getC().y);
	pdc->TextOutW(getA().x+ 15, getA().y+15, text);
	return 0;
}
