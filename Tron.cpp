#include "pch.h"
#include "Tron.h"

void Tron::thietlaptam()
{
	o.x = (x1 + x2) / 2;
	o.y = (y1 + y2) / 2;
	int r1 = (x2 - x1) / 2;
	int r2 = (y2 - y1) / 2;
	if (r1 < r2)
	{
		r = r1;
	}
	else
	{
		r = r2;
	}
}

void Tron::vehinh(CClientDC* pdc)
{
	pdc->Ellipse(o.x - r, o.y - r, o.x + r, o.y + r);
}

void Tron::veduoi(CClientDC* pdc)
{
	srand(time(0));
	int r = 0;
	int g = 0;
	int b = 0;
	r = rand() ;
	g = rand() ;
	b = rand() ;

	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen* pOldPen = pdc->SelectObject(&pen);
	CBrush myBrush(RGB(r, g, b));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);
	Tron::vehinh(pdc);
	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);
}
