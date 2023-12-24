#include "pch.h"
#include "Ran.h"

Ran::Ran()
{
	sethem = 0;
	int mx = 0; 
	int my = 0;
	n = 1;
	dau = Hcn(mx, my, mx + D, my + D);
	duoi[0] = Tron(dau.x1, dau.y2, dau.x1 + D, dau.y2 + D);
}

Ran::Ran(int mx, int my)
{
	sethem = 0;
	n = 1;
	dau = Hcn(mx, my, mx + D, my + D);
	duoi[0] = Tron(dau.x1, dau.y2, dau.x1 + D, dau.y2 + D);
}

void Ran::vehinh(CClientDC* pdc)
{
	dau.vedau(pdc);
	for (int i = 0; i < n; i++)
		duoi[i].veduoi(pdc);
}

void Ran::dichtrai()
{
	doicho();
	dau.dichtrai(D);
}

void Ran::dichphai()
{
	doicho();
	dau.dichphai(D);
}

void Ran::dichlen()
{
	doicho();
	dau.dichlen(D);
}

void Ran::dichxuong()
{
	doicho();
	dau.dichxuong(D);
}

void Ran::doicho()
{

	if (sethem == 2)
	{
		n += 2;
		sethem = 0;
	}
	if (sethem == 1)
	{
		n++;
		sethem = 0;
	}
	for (int i = n - 1; i > 0; i--)
	{
		duoi[i].x1 = duoi[i - 1].x1;
		duoi[i].y1 = duoi[i - 1].y1;
		duoi[i].x2 = duoi[i - 1].x2;
		duoi[i].y2 = duoi[i - 1].y2;
		duoi[i].thietlaptam();
	}
	duoi[0].x1 = dau.x1;
	duoi[0].y1 = dau.y1;
	duoi[0].x2 = dau.x2;
	duoi[0].y2 = dau.y2;
	duoi[0].thietlaptam();
}

void Ran::tangduoi()
{
	sethem = 1;
}

void Ran::tangduoito()
{
	sethem = 2;
}

int Ran::ktdaudungduoi()
{
	int mx = (dau.x1 + dau.x2) / 2;
	int my = (dau.y1 + dau.y2) / 2;
	CPoint p = CPoint(mx, my);
	for (int i = 0; i < n; i++)
	{
		if (duoi[i].kttronghinh(p) == 1)
			return 1;
	}
	return 0;
}
