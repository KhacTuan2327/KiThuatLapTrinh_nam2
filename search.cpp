#include "search.h"
#include "sort.h"
#include <stdio.h>

void bangtbao(string tb)
{
	TextColor(121);
	for (int i = 12; i < 17; i++)
	{
		gotoxy(33, i);
		for (int j = 0; j < 70; j++)
		{
			cout << " ";
		}
	}
	gotoxy(60, 14);
	cout << tb;
	TextColor(0);
}
void bangtimkiem()
{
	TextColor(121);
	for (int i = 12; i < 17; i++)
	{
		gotoxy(33, i);
		for (int j = 0; j < 70; j++)
		{
			cout << " ";
		}
	}
	TextColor(240);
	gotoxy(63, 14);
	for (int i = 0; i < 39; i++)
	{
		cout << " ";
	}
	TextColor(121);
	gotoxy(36, 14);
}

// Tim kiem ma lop
void tkttmalop(string lop, vector<sv> s, int &chonHienThi)
{
	int n = s.size();
	vector<sv> sv1;
	for (int i = 0; i < n; i++)
	{
		if (lop == s[i].maLop)
		{
			sv1.push_back(s[i]);
		}
	}
	if (sv1.size() == 0)
	{
		bangtbao("KHONG CO LOP NAY");
		_getch();
		system("cls");
		return;
	}
	InManHinh(sv1, chonHienThi);
}

void tknpmalop(int stt,string lop,vector<sv> s, int low, int high, int &chonHienThi)
{
	if ((low > high))
	{
		bangtbao("KHONG CO SINH VIEN");
		_getch();
		system("cls");
		return;
	}
	else {
		if (stt != s[(low + high) / 2].sttlop)
		{
			if (stt < s[(low + high) / 2].sttlop)
			{
				tknpmalop(stt, lop,s, low, (low + high) / 2 - 1, chonHienThi);
				return;
			}
			else
			{
				tknpmalop(stt, lop,s, (low + high) / 2 + 1, high, chonHienThi);
				return;
			}
		}
	}
	vector<sv> sv1;
	for (int i = (low + high) / 2+1; stt == s[i].sttlop; i--)
	{
		if (i <= 0)
			break;
		sv1.push_back(s[i]);
	}
	for (int i = (low + high) / 2 + 1; stt == s[i].sttlop+1; i++)
	{
		if (i == s.size())
			break;
		sv1.push_back(s[i]);
	}
	InManHinh(sv1, chonHienThi);
}
void tklop(int loaitk, vector<sv> s, int &chonHienThi)
{
	int stt;
	string lop=" ";
	if (loaitk == 0)
	{
		gotoxy(50, 10);
		cout << "CNTT1  CNTT2  BDATTT  ANHTTT  PTDL" << endl;
		bangtimkiem();
		cout << "Nhap ten lop: ";
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		fflush(stdin);
		cin >> lop;
		ShowCur(0);
		tkttmalop(lop, s, chonHienThi);
	}
	else if (loaitk == 1)
	{
		sxlop(s);
		gotoxy(50, 10);
		cout << "1:CNTT1  2:CNTT2  3:BDATTT  4:ANHTTT  5:PTDL" << endl;
		bangtimkiem();
		cout << "Nhap ma lop: ";
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		cin >> stt;
		fflush(stdin);
		ShowCur(0);
		tknpmalop(stt,lop,s, 0, s.size(), chonHienThi);
	}
}

// Tim kiem ma sinh vien
void tkttmasv(int masv, vector<sv> s, int &chonHienThi)
{
	int n = s.size();
	vector<sv> sv1;
	for (int i = 0; i < n; i++)
	{
		if (masv == s[i].maSv)
		{
			sv1.push_back(s[i]);
		}
	}
	if (sv1.size() == 0)
	{
		bangtbao("KHONG CO SINH VIEN");
		_getch();
		system("cls");
		return;
	}
	InManHinh(sv1, chonHienThi);
}
void tknpmasv(int masv, vector<sv> s, int low, int high, int &chonHienThi)
{
	if (low > high)
	{
		bangtbao("KHONG CO SINH VIEN");
		_getch();
		system("cls");
		return;
	}
	if (masv != s[(low + high) / 2].maSv)
	{
		if (masv < s[(low + high) / 2].maSv)
		{
			tknpmasv(masv, s, low, (low + high) / 2 - 1, chonHienThi);
			return;
		}
		else
		{
			tknpmasv(masv, s, (low + high) / 2 + 1, high, chonHienThi);
			return;
		}
	}
	vector<sv> sv1;
	for (int i = (low + high) / 2; masv == s[i].maSv; i--)
	{
		if (i < 0)
			break;
		sv1.push_back(s[i]);
	}
	for (int i = (low + high) / 2 + 1; masv == s[i].maSv; i++)
	{
		if (i == s.size())
			break;
		sv1.push_back(s[i]);
	}
	InManHinh(sv1, chonHienThi);
}
void tkmasv(int loaitk, vector<sv> s, int &chonHienThi)
{
	int masv;
	if (loaitk == 0)
	{
		bangtimkiem();
		cout << "Nhap ma sinh vien: ";
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		fflush(stdin);
		cin >> masv;
		ShowCur(0);
		tkttmasv(masv, s, chonHienThi);
	}
	else if (loaitk == 1)
	{
		sxnoibotmasv(s);
		bangtimkiem();
		cout << "Nhap ma sinh vien: ";
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		fflush(stdin);
		cin >> masv;
		ShowCur(0);
		tknpmasv(masv, s, 0, s.size(), chonHienThi);
	}
}

// Tim kiem diem trung binh
void tkttdtb(float diem, vector<sv> s, int &chonHienThi)
{
	int n = s.size();
	vector<sv> sv1;
	for (int i = 0; i < n; i++)
	{
		if (diem == s[i].dtb)
		{
			sv1.push_back(s[i]);
		}
	}
	if (sv1.size() == 0)
	{
		bangtbao("KHONG CO SINH VIEN");
		_getch();
		system("cls");
		return;
	}
	InManHinh(sv1, chonHienThi);
}
void tknpdtb(float diem, vector<sv> s, int low, int high, int &chonHienThi)
{
	if (low > high)
	{
		bangtbao("KHONG CO SINH VIEN");
		_getch();
		system("cls");
		return;
	}
	if (diem != s[(low + high) / 2].dtb)
	{
		if (diem < s[(low + high) / 2].dtb)
		{
			tknpdtb(diem, s, low, (low + high) / 2 - 1, chonHienThi);
			return;
		}
		else
		{
			tknpdtb(diem, s, (low + high) / 2 + 1, high, chonHienThi);
			return;
		}
	}
	vector<sv> sv1;
	for (int i = (low + high) / 2; diem == s[i].dtb; i--)
	{
		if (i < 0)
			break;
		sv1.push_back(s[i]);
	}
	for (int i = (low + high) / 2 + 1; diem == s[i].dtb; i++)
	{
		if (i == s.size())
			break;
		sv1.push_back(s[i]);
	}
	InManHinh(sv1, chonHienThi);
}
void tkdtb(int loaitk, vector<sv> s, int &chonHienThi)
{
	float dtB;
	if (loaitk == 0)
	{
		bangtimkiem();
		cout << "Nhap diem trung binh: ";
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		fflush(stdin);
		cin >> dtB;
		ShowCur(0);
		tkttdtb(dtB, s, chonHienThi);
	}
	else if (loaitk == 1)
	{
		sxtangdtb(s);
		bangtimkiem();
		cout << "Nhap diem trung binh: ";
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		fflush(stdin);
		cin >> dtB;
		ShowCur(0);
		tknpdtb(dtB, s, 0, s.size(), chonHienThi);
	}
}

// Tim kiem ngay sinh
void bangnsinh(ns &d)
{
	TextColor(121);
	for (int i = 12; i < 17; i++)
	{
		gotoxy(29, i);
		for (int j = 0; j < 70; j++)
		{
			cout << " ";
		}
	}
	gotoxy(33, 14);
	cout << "Nhap ngay sinh: ";
	TextColor(240);
	gotoxy(55, 14);
	for (int i = 0; i < 35; i++)
	{
		cout << " ";
	}
	do
	{
		gotoxy(63, 14);
		cout << "dd/mm/yyyy";
		gotoxy(63, 14);
		cin >> d.ngay;
		gotoxy(66, 14);
		cin >> d.thang;
		gotoxy(69, 14);
		cin >> d.nam;
	} while (checkNgaySinh(d) != 1);
}
void tkttnsinh(ns d, vector<sv> s, int &chonHienThi)
{
	int n = s.size();
	vector<sv> sv1;
	for (int i = 0; i < n; i++)
	{
		if (songay(d.ngay, d.thang, d.nam) == songay(s[i].nSinh.ngay, s[i].nSinh.thang, s[i].nSinh.nam))
		{
			sv1.push_back(s[i]);
		}
	}
	if (sv1.size() == 0)
	{
		bangtbao("KHONG CO SINH VIEN");
		_getch();
		system("cls");
		return;
	}
	InManHinh(sv1, chonHienThi);
}
void tknpnsinh(ns d, vector<sv> s, int low, int high, int &chonHienThi)
{
	if (low > high)
	{
		bangtbao("KHONG CO SINH VIEN");
		_getch();
		system("cls");
		return;
	}
	if (songay(d.ngay, d.thang, d.nam) != songay(s[(low + high) / 2].nSinh.ngay, s[(low + high) / 2].nSinh.thang, s[(low + high) / 2].nSinh.nam))
	{
		if (songay(d.ngay, d.thang, d.nam) < songay(s[(low + high) / 2].nSinh.ngay, s[(low + high) / 2].nSinh.thang, s[(low + high) / 2].nSinh.nam))
		{
			tknpnsinh(d, s, low, (low + high) / 2 - 1, chonHienThi);
			return;
		}
		else
		{
			tknpnsinh(d, s, (low + high) / 2 + 1, high, chonHienThi);
			return;
		}
	}
	vector<sv> sv1;
	for (int i = (low + high) / 2; (songay(d.ngay, d.thang, d.nam) == songay(s[i].nSinh.ngay, s[i].nSinh.thang, s[i].nSinh.nam)); i--)
	{
		if (i < 0)
			break;
		sv1.push_back(s[i]);
	}
	for (int i = (low + high) / 2 + 1; (songay(d.ngay, d.thang, d.nam) == songay(s[i].nSinh.ngay, s[i].nSinh.thang, s[i].nSinh.nam)); i++)
	{
		if (i == s.size())
			break;
		sv1.push_back(s[i]);
	}
	InManHinh(sv1, chonHienThi);
}
void tknsinh(int loaitk, vector<sv> s, int &chonHienThi)
{
	ns d;
	if (loaitk == 0)
	{
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		fflush(stdin);
		bangnsinh(d);
		ShowCur(0);
		tkttnsinh(d, s, chonHienThi);
	}
	else if (loaitk == 1)
	{
		sxchonnsinh(s);
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		fflush(stdin);
		bangnsinh(d);
		ShowCur(0);
		tknpnsinh(d, s, 0, s.size(), chonHienThi);
	}
}

// Tim kiem ho ten
void tktthoten(char ht[], vector<sv> s, int &chonHienThi)
{
	int n = s.size();
	vector<sv> sv1;
	string hoten;
	for (int i = 0; i < n; i++)
	{
		hoten = s[i].hoTen.ho + " " + s[i].hoTen.ten;
		char *hTen = new char[hoten.length() + 1];
		strcpy_s(hTen, hoten.length() + 1, hoten.c_str());
		if (strcmp(hTen, ht) == 0)
		{
			sv1.push_back(s[i]);
		}
	}
	if (sv1.size() == 0)
	{
		bangtbao("KHONG CO SINH VIEN");
		_getch();
		system("cls");
		return;
	}
	InManHinh(sv1, chonHienThi);
}
void tknphoten(char ht[], string hoten, vector<sv> s, int low, int high, int &chonHienThi)
{
	if (low > high)
	{
		bangtbao("KHONG CO SINH VIEN");
		_getch();
		system("cls");
		return;
	}
	string hoten0 = s[(low + high) / 2].hoTen.ho + " " + s[(low + high) / 2].hoTen.ten;
	s[(low + high) / 2].hten = s[(low + high) / 2].hoTen.ho + " " + s[(low + high) / 2].hoTen.ten;
	if (hoten== s[(low + high) / 2].hten)
	{
		if (s[(low + high) / 2].hten > hoten)
		{
			tknphoten(ht, hoten,s, low, (low + high) / 2 - 1, chonHienThi);
			return;
		}
		else
		{
			tknphoten(ht,hoten ,s,(low + high) / 2 + 1, high, chonHienThi);
			return;
		}
	}
	vector<sv> sv1;
	for (int i = (low + high) / 2; hoten == s[(low + high) / 2].hten; i--)
	{
		if (i < 0)
			break;
		sv1.push_back(s[i]);
	}
	s[((low + high) / 2) + 1].hten = s[((low + high) / 2) + 1].hoTen.ho + " " + s[((low + high) / 2) + 1].hoTen.ten;
	for (int i = (low + high) / 2 + 1; s[((low + high) / 2) + 1].hten==hoten; i++)
	{
		if (i == s.size())
			break;
		sv1.push_back(s[i]);
	}
	InManHinh(sv1, chonHienThi);
}
void tkhoten(int loaitk, vector<sv> s, int &chonHienThi)
{
	char ht[50];
	string hoten;
	if (loaitk == 0)
	{
		bangtimkiem();
		cout << "Nhap ho ten can tim: ";
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		fflush(stdin);
		gets_s(ht);
		ShowCur(0);
		tktthoten(ht, s, chonHienThi);
	}
	else if (loaitk == 1)
	{
		sxtanghoten(s);
		bangtimkiem();
		cout << "Nhap ho ten can tim: ";
		TextColor(240);
		gotoxy(64, 14);
		ShowCur(1);
		fflush(stdin);
		gets_s(ht);
//		getline(cin, hoten);
		ShowCur(0);
		tktthoten(ht, s, chonHienThi);
//		tknphoten(ht, hoten,s, 0, s.size(), chonHienThi);
	}
}