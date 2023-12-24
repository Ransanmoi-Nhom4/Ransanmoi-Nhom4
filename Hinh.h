#pragma once
class Hinh
{
public:
	int x1, y1, x2, y2;
	Hinh();
	Hinh(int mx1, int my1, int mx2, int my2);
	void virtual vehinh(CClientDC* pdc);
	void virtual dichtrai(int d);
	void virtual dichphai(int d);
	void virtual dichlen(int d);
	void virtual dichxuong(int d);
	int virtual kttronghinh(CPoint p);
};

