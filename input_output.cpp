#include "input_output.h"
//
bool namNhuan(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) ||
			(year % 400 == 0));
}
int checkNgaySinh(ns date)
{
	if (date.nam <= 2021 && date.nam >= 1900)
	{
		if (date.thang > 0 && date.ngay > 0)
		{
			switch (date.thang)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (date.ngay <= 31)
				{
					return 1;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (date.ngay <= 30)
				{
					return 1;
				}
				break;
			case 2:
				if ((namNhuan(date.nam) && date.ngay <= 29) || (!namNhuan(date.nam) && date.ngay <= 28))
				{
					return 1;
				}
				break;
			}
			return 0;
		}
	}
	return 0;
}
void nhapNgaySinh(sv &s)
{
	do
	{
		gotoxy(61, 28);
		cout << "dd/mm/yyyy";
		gotoxy(61, 28);
		cin >> s.nSinh.ngay;
		gotoxy(64, 28);
		cin >> s.nSinh.thang;
		gotoxy(67, 28);
		cin >> s.nSinh.nam;
	} while (checkNgaySinh(s.nSinh) != 1);
}
//
void nhapDiem(float &d)
{
	bool check = false;
	do
	{
		gotoxy(61, 33);
		cout << "0.00";
		gotoxy(61, 33);
		cin >> d;
		if (d >= 0 && d <= 10)
		{
			check = true;
		}
	} while (!check);
}
//
sv nhapSv(int &masvmoi, int k)
{
	ShowCur(1);
	TextColor(240);
	sv s;
	s.maSv = masvmoi++;
	gotoxy(61, 13);
	cout << s.maSv;
	gotoxy(61, 18);
	fflush(stdin);
	switch (k)
	{
	case 0:
		s.maLop = "CNTT1";
		s.sttlop = 1;
		gotoxy(61, 18);
		cout << s.maLop;
		break;
	case 1:
		s.maLop = "CNTT2";
		s.sttlop = 2;
		gotoxy(61, 18);
		cout << s.maLop;
		break;
	case 2:
		s.maLop = "BDATTT";
		s.sttlop = 3;
		gotoxy(61, 18);
		cout << s.maLop;
		break;
	case 3:
		s.maLop = "ANHTTT";
		s.sttlop = 4;
		gotoxy(61, 18);
		cout << s.maLop;
		break;
	case 4:
		s.maLop = "PTDL";
		s.sttlop = 5;
		gotoxy(61, 18);
		cout << s.maLop;
		break;
	default:
		break;
	}
	gotoxy(61, 23);
	cout << "Ho: ";
	cin.ignore();
	getline(cin, s.hoTen.ho);
	gotoxy(80, 23);
	cout << "Ten: ";
	getline(cin, s.hoTen.ten);
	nhapNgaySinh(s);
	nhapDiem(s.dtb);
	return s;
}
void themhoso(vector<sv> &s, int &masvmoi, int k)
{
	boxInfo();
	TextColor(121);
	gotoxy(53, 11);
	cout << "Nhap thong tin sinh vien";
	TextColor(240);
	sv sv = nhapSv(masvmoi, k);
	s.push_back(sv);
	TextColor(0);
}
void inputfile(vector<sv> &ds)
{
	fstream f;
	f.open("dssv.inp.txt", ios::in);
	string masv;
	string d, m, y;
	string dTB;
	string sttLop;
	sv s;
	while (!f.eof()) // (1)
	{
		getline(f, sttLop, ',');
		s.sttlop = atoi(sttLop.c_str());
		getline(f, s.maLop, ',');
		getline(f, masv, ',');
		s.maSv = atoi(masv.c_str());
		getline(f, s.hoTen.ho, ',');
		getline(f, s.hoTen.ten, ',');
		getline(f, d, '/');
		s.nSinh.ngay = atoi(d.c_str());
		getline(f, m, '/');
		s.nSinh.thang = atoi(m.c_str());
		getline(f, y, ',');
		s.nSinh.nam = atoi(y.c_str());
		getline(f, dTB);
		s.dtb = stof(dTB.c_str());
		ds.push_back(s);
	}
	f.close();
}
void outputfile(vector<sv> s)
{
	ofstream outf;
	outf.open("dssv.outp.txt");
	if (!outf)
	{
		cout << "Khong the mo file";
	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			outf << s[i].maLop << ", "
				 << s[i].maSv << ", "
				 << s[i].hoTen.ho << ", "
				 << s[i].hoTen.ten << ", "
				 << s[i].nSinh.ngay << "/"
				 << s[i].nSinh.thang << "/"
				 << s[i].nSinh.nam << ", ";
			if (int(s[i].dtb * 10) % 10 != 0)
			{
				outf << s[i].dtb << endl;
			}
			else
			{
				outf << s[i].dtb << ".0" << endl;
			}
		}
	}
}
void khungindanhsach(vector<sv> s)
{
	ShowCur(0);
	TextColor(240);
	InTieuDe("DANH SACH SINH  VIEN", 240);
	gotoxy(5, 4);
	cout << "Nhan Esc de thoat";
	gotoxy(115, 4);
	cout << "Total: " << s.size();
	for (int j = 0; j < 3; j++)
	{
		gotoxy(5, 5 + j);
		if (j == 0 || j == 2)
		{
			for (int i = 0; i < 121; i++)
			{
				cout << "-";
			}
		}
	}
	gotoxy(8, 6);
	cout << "STT";
	gotoxy(18, 6);
	cout << "Ma lop";
	gotoxy(32, 6);
	cout << "Ma sinh vien";
	gotoxy(62, 6);
	cout << "Ho va ten";
	gotoxy(88, 6);
	cout << "Ngay sinh";
	gotoxy(106, 6);
	cout << "Diem trung binh";
	gotoxy(14, 6);
	cout << "|";
	gotoxy(27, 6);
	cout << "|";
	gotoxy(48, 6);
	cout << "|";
	gotoxy(84, 6);
	cout << "|";
	gotoxy(100, 6);
	cout << "|";
}
void indanhsach(int j, vector<sv> s)
{
	khungindanhsach(s);
	for (int i = 0; i < 15; i++)
	{
		if (j * 15 + i == s.size())
		{
			break;
		}
		gotoxy(5, 9 + 2 * i);
		for (int k = 0; k < 121; k++)
		{
			cout << "-";
		}
		gotoxy(14, 8 + i * 2);
		cout << "|";
		gotoxy(27, 8 + 2 * i);
		cout << "|";
		gotoxy(48, 8 + 2 * i);
		cout << "|";
		gotoxy(84, 8 + 2 * i);
		cout << "|";
		gotoxy(100, 8 + 2 * i);
		cout << "|";
		gotoxy(8, 8 + 2 * i);
		cout << j * 15 + i + 1;
		gotoxy(18, 8 + 2 * i);
		cout << s[j * 15 + i].maLop;
		gotoxy(32, 8 + 2 * i);
		cout << s[j * 15 + i].maSv;
		gotoxy(55, 8 + 2 * i);
		cout << s[j * 15 + i].hoTen.ho << " " << s[j * 15 + i].hoTen.ten;
		gotoxy(87, 8 + 2 * i);
		if (s[j * 15 + i].nSinh.ngay < 10)
			cout << "0" << s[j * 15 + i].nSinh.ngay << "/";
		else
			cout << s[j * 15 + i].nSinh.ngay << "/";
		if (s[j * 15 + i].nSinh.thang < 10)
			cout << "0" << s[j * 15 + i].nSinh.thang << "/";
		else
			cout << s[j * 15 + i].nSinh.thang << "/";
		cout << s[j * 15 + i].nSinh.nam;
		gotoxy(111, 8 + 2 * i);
		if (int(s[j * 15 + i].dtb * 10) % 10 != 0)
		{
			cout << s[j * 15 + i].dtb;
		}
		else
		{
			cout << s[j * 15 + i].dtb << ".0";
		}
	}
	gotoxy(65, 39);
	cout << j + 1 << "/" << s.size() / 15 + 1;
	return;
}
void InManHinh(vector<sv> s, int &chonHienThi)
{
	int j_max = s.size() / 15;
	int j = 0;
	indanhsach(j, s);
	while (true)
	{
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == KEY_DOWN || c == KEY_RIGHT)
			{
				if (j == j_max)
				{
					j = 0;
					indanhsach(j, s);
				}
				else
				{
					j++;
					indanhsach(j, s);
				}
			}
			if (c == KEY_UP || c == KEY_LEFT)
			{
				if (j == 0)
				{
					j = j_max;
					indanhsach(j, s);
				}
				else
				{
					j--;
					indanhsach(j, s);
				}
			}
		}
		if (c == ESC)
		{
			TextColor(0);
			system("cls");
			if (chonHienThi == 0)
			{
				return;
			}
			else if (chonHienThi == 1)
			{
				return;
			}
			else if (chonHienThi == 2)
			{
				return;
			}
		}
	}
}