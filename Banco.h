#pragma once
#include "Hcn.h"
#include "Ran.h"
#include "Moi.h"
#include <MMsystem.h> // them nhac

#define XDAU 50
#define YDAU 50
#define RONG 600


class Banco
{
public:
	int dk, diem;
	int level;
	int huong;
	int thang;
	Hcn dv;
	Ran ran;
	Moi moi;
	Moi moito;
	Banco();
	void vehinh(CClientDC* pdc);
	void capnhathinh(CClientDC* pdc);
	void randichuyen(CClientDC* pdc);
	void kiemtrabien();
	void batdau();
	int rananmoi();
	void taomoi();
	void taomoito();
	void ktdungduoi();
};

