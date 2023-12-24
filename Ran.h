#pragma once
#include "Hcn.h"
#include "Tron.h"
#define D 30

class Ran
{
public:
	Hcn dau;
	Tron duoi[100];
	int n;
	int sethem;
	Ran();
	Ran(int mx, int my);
	void vehinh(CClientDC* pdc);
	void dichtrai();
	void dichphai();
	void dichlen();
	void dichxuong();
	void doicho();
	void tangduoi();
	void tangduoito();
	int ktdaudungduoi();
};

