#include "pch.h"
#include "Hinh.h"

Hinh::Hinh()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

Hinh::Hinh(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void Hinh::vehinh(CClientDC* pdc)
{
	return;
}

void Hinh::dichtrai(int d)
{
	x1 = x1 - d;
	x2 = x2 - d;
}

void Hinh::dichphai(int d)
{
	x1 = x1 + d;
	x2 = x2 + d;
}

void Hinh::dichlen(int d)
{
	y1 = y1 - d;
	y2 = y2 - d;
}

void Hinh::dichxuong(int d)
{
	y1 = y1 + d;
	y2 = y2 + d;
}

int Hinh::kttronghinh(CPoint p)
{
	if (p.x > x1 && p.x < x2 && p.y > y1 && p.y < y2)
		return 1;
	else
	{
		return 0;
	}
	
}
