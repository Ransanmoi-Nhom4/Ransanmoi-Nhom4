#include "pch.h"
#include "Banco.h"


Banco::Banco()
{
	dk = 0;
	diem = 0;
	level = 0;
	thang = 1;
	huong = 38;
	dv = Hcn(XDAU, YDAU, XDAU + RONG, YDAU + RONG);
	ran = Ran(XDAU + 10 * D, YDAU + 10 * D);
	moi = Moi(XDAU + 5 * D, YDAU + 10 * D, XDAU + 6 * D, YDAU + 11 * D);
	if (diem >= 5 && diem % 5 == 0)
	{
		moito = Moi(XDAU + 1 * D, YDAU + 2 * D, XDAU + 3 * D, YDAU + 5 * D);
	}
}

void Banco::vehinh(CClientDC* pdc)
{
	CString strdiem;
	CString strlevel;
	CString strten;


	pdc->SetTextColor(RGB(0, 100, 0));
	strdiem.Format(_T("Diem: %d  "), diem);
	pdc->TextOutW(XDAU + RONG + 100, YDAU + RONG / 6, strdiem);

	pdc->SetTextColor(RGB(0, 100, 0));
	strlevel.Format(_T("Level: %d  "), level);
	pdc->TextOutW(XDAU + RONG + 100, YDAU + RONG / 15, strlevel);

	pdc->SetTextColor(RGB(200, 0, 0));
	strten.Format(_T("TRO CHOI RAN SAN MOI"));
	pdc->TextOutW(XDAU + RONG / 3, YDAU / 2, strten);

	dv.vekhung(pdc);
	ran.vehinh(pdc);
	moi.vehinh(pdc);


	if (diem >= 5 && diem % 5 == 0)
	{
		moi.vehinh(pdc);
		moito.vemoito(pdc);
	}


	if (thang == -1)
	{
		ran.dau.vedau(pdc);
		PlaySound(TEXT("D:\\FLOWER\\LTHDT\\gameransanmoi\\nhacthua"), NULL, SND_ASYNC);
		CString strthua;
		pdc->SetTextColor(RGB(0, 0, 0));
		strthua.Format(_T("BAN DA AN DUOI - TRO CHOI KET THUC"));
		pdc->TextOutW(XDAU + 4 * D, YDAU + 9 * D, strthua);
		dk = 0;

	}

	if (level == 5)
	{
		CString strkq;
		pdc->SetTextColor(RGB(0, 0, 0));
		strkq.Format(_T("BAN DA DAT LEVEL CAO NHAT"));
		pdc->TextOutW(XDAU + 5 * D, YDAU + 9 * D, strkq);
		dk = 0;
	}
}

void Banco::capnhathinh(CClientDC* pdc)
{
	while (dk == 1)
	{
		vehinh(pdc);
		Sleep(30);
	}
}

void Banco::randichuyen(CClientDC* pdc)
{
	while (dk == 1)
	{
		if (huong == 38)
		{
			ran.dichlen();
		}
		if (huong == 37)
		{
			ran.dichtrai();
		}
		if (huong == 39) 
		{
			ran.dichphai();
		}
		if (huong == 40) 
		{
			ran.dichxuong();
		}
		rananmoi();
		kiemtrabien();
		ktdungduoi();
		vehinh(pdc);
		Sleep(450 - 80 * level);
	}
}

void Banco::kiemtrabien()
{
	if (ran.dau.y2 <= dv.y1) // bien tren
	{
		ran.dau.y2 = dv.y2;
		ran.dau.y1 = dv.y2 - D;
	}
	if (ran.dau.x2 <= dv.x1) // bien trai
	{
		ran.dau.x2 = dv.x2;
		ran.dau.x1 = dv.x2 - D;
	}
	if (ran.dau.x1 >= dv.x2) // bien phai
	{
		ran.dau.x1 = dv.x1;
		ran.dau.x2 = dv.x1 + D;
	}
	if (ran.dau.y1 >= dv.y2) // bien duoi
	{
		ran.dau.y1 = dv.y1;
		ran.dau.y2 = dv.y1 + D;
	}
}

void Banco::batdau()
{
	dk = 1;
	diem = 0;
	level = 0;
}

int Banco::rananmoi()
{
	int mx = (ran.dau.x1 + ran.dau.x2) / 2;
	int my = (ran.dau.y1 + ran.dau.y2) / 2;
	if (moi.kttronghinh(CPoint(mx, my)) == 1 || moito.kttronghinh(CPoint(mx, my)) == 1)
	{
		PlaySound(TEXT("D:\\FLOWER\\LTHDT\\gameransanmoi\\Downward whistle.wav"), NULL, SND_ASYNC);
		if (moito.kttronghinh(CPoint(mx, my)) == 1)
		{
			diem += 2;
			ran.tangduoito();
		}
		else
		{
			diem++;
			ran.tangduoi();
		}
		level = int(diem / 10);
		Sleep(30);
		taomoi();
		if (diem % 5 == 0)
		{
			taomoito();
			taomoi();
		}

		return 1;
	}
	else
		return 0;
}



void Banco::taomoi()
{
		int g = RONG / D;
		int r = rand() % g;
		int mx = XDAU + r * D;
		r = rand() % g;
		int my = YDAU + r * D;
		while (mx == moi.x1 && my == moi.x2)
		{
			r = rand() % g;
			mx = XDAU + r * D;
			r = rand() % g;
			my = YDAU + r * D;
		}
		moi = Moi(mx, my, mx + D, my + D);
}

void Banco::taomoito()
{
	if (dk = 1 && diem >= 5 && diem % 5 == 0)
	{
		int g = RONG / D;
		int r = rand() % g;
		int mx = XDAU + r * D;
		r = rand() % g;
		int my = YDAU + r * D;
		my = YDAU + r * D;

		moito = Moi(mx, my, mx + D, my + D);
	}
}




void Banco::ktdungduoi()
{
	if (ran.ktdaudungduoi() == 1)
	{
		dk = 0;
		thang = -1;
	}
}
