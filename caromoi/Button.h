#pragma once
#include "HCN.h"
class Button :
	public HCN
{
public:
	CString text;
	Button();
	~Button();
	int draw(CClientDC *pdc);
};

