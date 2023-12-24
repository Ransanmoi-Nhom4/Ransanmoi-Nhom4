#include "pch.h"
#include "Hcn.h"

void Hcn::vehinh(CClientDC* pdc)
{
	CPen pen(PS_SOLID, 3, RGB(0, 0, 0));
	CPen* pOldPen = pdc->SelectObject(&pen);
	CBrush myBrush(RGB(255, 255, 255));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);
	pdc->Rectangle(x1, y1, x2, y2);
	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);

}

void Hcn::vedau(CClientDC* pdc)
{
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen* pOldPen = pdc->SelectObject(&pen);
	CBrush myBrush(RGB(255, 255, 0));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);
	pdc->Rectangle(x1, y1, x2, y2);
	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);
}

void Hcn::vekhung(CClientDC* pdc)
{
	CPen pen(PS_SOLID, 3, RGB(0, 0, 0));
	CPen* pOldPen = pdc->SelectObject(&pen);
	CBrush myBrush(RGB(255, 240, 245));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);
	pdc->Rectangle(x1, y1, x2, y2);
	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);
}
