#include "pch.h"
#include "Moi.h"

void Moi::vehinh(CClientDC* pdc)
{
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen* pOldPen = pdc->SelectObject(&pen);
	CBrush myBrush(RGB(0, 255, 0));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);
	Tron::vehinh(pdc);
	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);
}

void Moi::vemoito(CClientDC* pdc)
{
	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen* pOldPen = pdc->SelectObject(&pen);
	CBrush myBrush(RGB(700, 0, 0));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);
	Tron::vehinh(pdc);
	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);
}