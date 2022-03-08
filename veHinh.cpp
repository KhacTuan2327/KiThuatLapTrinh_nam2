#include "input_output.h"
#include <conio.h>
#include "sort.h"
#include "search.h"
#include "thongke.h"
int chonHienThi;
int loaiSx;
int loaitk;
vector<sv> s;
int masvmoi;
//
void tenct()
{
	for (int i = 1; i < 4; i++)
	{
			ShowCur(0);
			TextColor(i);
			Sleep(200);
			gotoxy(44, 14);
			cout << "\t  _|_|      _|    _|    _|_|    _|      _|      _|    _|      _|" << endl;
			Sleep(200);
			gotoxy(44, 15);
			cout << "\t_|    _|    _|    _|  _|    _|  _|_|    _|      _|      _|  _|" << endl;
			gotoxy(44, 16);
			cout << "\t_|  _|_|    _|    _|  _|_|_|_|  _|  _|  _|      _|        _|      " << endl;
			Sleep(200);
			gotoxy(44, 17);
			cout << "\t_|    _|    _|    _|  _|    _|  _|    _|_|      _|        _|      " << endl;
			gotoxy(44, 18);
			cout << "\t  _|_|  _|    _|_|    _|    _|  _|      _|      _|_|_|_|  _|      " << endl;
			gotoxy(40, 19);
			cout << endl;
			gotoxy(40, 20);
			cout << "  _|_|_|  _|_|_|  _|      _|  _|    _|      _|      _|  _|_|_|  _|_|_|_|  _|      _| " << endl;
			gotoxy(40, 21);
			cout << "_|          _|    _|_|    _|  _|    _|      _|      _|    _|    _|        _|_|    _|  " << endl;
			Sleep(200);
			gotoxy(40, 22);
			cout << "  _|_|      _|    _|  _|  _|  _|_|_|_|      _|      _|    _|    _|_|_|    _|  _|  _|  " << endl;
			gotoxy(40, 23);
			cout << "      _|    _|    _|    _|_|  _|    _|        _|  _|      _|    _|        _|    _|_|  " << endl;
			gotoxy(40, 24);
			cout << "_|_|_|    _|_|_|  _|      _|  _|    _|          _|      _|_|_|  _|_|_|_|  _|      _|  " << endl;
	}
	system("cls");
	TextColor(WHITE);
	gotoxy(75, 20);
	cout << "Nhan phim bat ki..." << endl;
}
void tacgia()
{
	gotoxy(3, 18);
	cout << "\t\t	 __  __   _______ \n";
	cout << "\t\t	|  " << char(92) << "/  | |__   __|     /" << char(92) << " \n";
	cout << "\t\t	| " << char(92) << "  / |    | |       /  " << char(92) << " \n";
	cout << "\t\t	| |" << char(92) << "/| |    | |      / /" << char(92) << " " << char(92) << " \n";
	cout << "\t\t	| |  | |    | |     / ____ " << char(92) << " \n";
	cout << "\t\t	|_|  |_|    |_|    /_/    " << char(92) << "_" << char(92) << " \n";
	gotoxy(23, 27);
	cout << "\t      TRINH KHAC TUAN" << endl;
	gotoxy(15, 29);
	cout << "\t\tAN NINH HE THONG THONG TIN - K55" << endl;
}
//
void createBox(int x, int y, int w, int h, int b_color, string t)
{
	SetColor(b_color);
	for (int i = y + 1; i < y + h; i++)
	{
		gotoxy(x + 1, i);
		cout << "                     ";
	}
	int canGiua = (w - t.length()) / 2;
	gotoxy(x + canGiua + 1, y + 1);
	cout << t;
	if (h <= 1 || w <= 1)
		return;
	for (int i = x; i < x + w; i++)
	{
		gotoxy(i, y);
		cout << char(205);
		gotoxy(i, y + h);
		cout << char(205);
	}
	for (int i = y; i < y + h; i++)
	{
		gotoxy(x, i);
		cout << char(186);
		gotoxy(x + w, i);
		cout << char(186);
	}
	gotoxy(x, y);
	cout << char(201);
	gotoxy(x + w, y);
	cout << char(187);
	gotoxy(x, y + h);
	cout << char(200);
	gotoxy(x + w, y + h);
	cout << char(188);
}
//
void boxInfo()
{
	ShowCur(false);
	TextColor(121);
	for (int i = 11; i < 36; i++)
	{
		gotoxy(30, i);
		for (int j = 0; j < 70; j++)
		{
			cout << " ";
		}
	}
	gotoxy(33, 18);
	cout << "Ma lop:";
	gotoxy(33, 13);
	cout << "Ma sinh vien:";
	gotoxy(61, 19);
	TextColor(121);
	gotoxy(33, 23);
	cout << "Ho ten:";
	gotoxy(33, 28);
	cout << "Ngay sinh";
	gotoxy(33, 33);
	cout << "Diem trung binh:";
	TextColor(240);
	gotoxy(60, 33);
	for (int i = 0; i < 39; i++)
	{
		cout << " ";
	}
	gotoxy(60, 13);
	for (int i = 0; i < 39; i++)
	{
		cout << " ";
	}
	gotoxy(60, 18);
	for (int i = 0; i < 39; i++)
	{
		cout << " ";
	}
	gotoxy(60, 23);
	for (int i = 0; i < 39; i++)
	{
		cout << " ";
	}
	gotoxy(60, 28);
	for (int i = 0; i < 39; i++)
	{
		cout << " ";
	}
	gotoxy(63, 28);
	cout << "/";
	gotoxy(66, 28);
	cout << "/";
	TextColor(247);
	gotoxy(61, 28);
	cout << "dd";
	gotoxy(64, 28);
	cout << "mm";
	gotoxy(67, 28);
	cout << "yyyy";
}
//
void createMainMenu()
{
	inputfile(s);
	masvmoi = s.size() + 10001;
MENU:
	string t[6] = {"THEM MOI HO SO",
				   "IN DANH SACH",
				   "SAP XEP",
				   "TIM KIEM",
				   "THONG KE",
				   "THOAT"};
	int x=90, y = 15, w = 20, h = 2;

	// cai dat
	ShowCur(false);
	int k = 0;
	int px = x, py = y; // toa do thanh sang
	int xcu = px, ycu = py;
	for (int i = 0; i < 6; i++)
	{
		createBox(x, y + i * 3, w, h, 11, t[i]);
	}
	pickBox(xcu, ycu, w, h, 120, dauCach(t[k]));
	tacgia();
	int pause = true;
	while (pause)
	{
		char kb_hit = _getch();
		if (kb_hit == -32)
		{
			kb_hit = _getch();
			if (kb_hit == KEY_DOWN)
			{
				if (py != y + 3 * 5)
				{
					createBox(px, py, w, h, 11, t[k]);
					py += 3;
					k++;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y;
					k = 0;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
			else if (kb_hit == KEY_UP)
			{
				if (py != y)
				{
					createBox(px, py, w, h, 11, t[k]);
					py -= 3;
					k--;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y + 3 * 5;
					k = 5;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
		}
		else if (kb_hit == ENTER)
		{
			if (k == 0)
			{
				system("cls");
				menuAdd();
				goto MENU;
			}
			else if (k == 1)
			{
				menuOut();
				goto MENU;
			}
			if (k == 2)
			{
				system("cls");
				menuTypeSort();
				goto MENU;
			}
			else if (k == 3)
			{
				system("cls");
				menuTypeSearch();
				goto MENU;
			}
			else if (k == 4)
			{
				system("cls");
				menuThongKe();
				goto MENU;
			}
			else if (k == 5)
			{
				esc();
			}
		}
	}
}
//
void pickBox(int x, int y, int w, int h, int bgColor, string t)
{
	TextColor(bgColor);
	gotoxy(x + 1, y + 1);
	cout << left << setw(w - 1) << t;
	TextColor(11);
}
//
void menuAdd()
{
ADD:
	int x=90, y = 15, w = 20, h = 2;
	string t[3] = {"THEM TU FILE",
				   "NHAP THEM",
				   "QUAY LAI"};
	ShowCur(false);
	int k = 0;
	int px = x, py = y; // toa do thanh sang
	int xcu = px, ycu = py;

	for (int i = 0; i < 3; i++)
	{
		createBox(x, y + i * 3, w, h, 11, t[i]);
	}
	pickBox(xcu, ycu, w, h, 120, dauCach(t[k]));
	tacgia();
	while (true)
	{
		char kb_hit = _getch();
		if (kb_hit == -32)
		{
			kb_hit = _getch();
			if (kb_hit == KEY_DOWN)
			{
				if (py != y + 3 * 2)
				{
					createBox(px, py, w, h, 11, t[k]);
					py += 3;
					k++;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y;
					k = 0;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
			else if (kb_hit == KEY_UP)
			{
				if (py != y)
				{
					createBox(px, py, w, h, 11, t[k]);
					py -= 3;
					k--;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y + 3 * 2;
					k = 2;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
		}
		else if (kb_hit == ENTER)
		{
			if (k == 1)
			{
				system("cls");
				menuLop();
				goto ADD;
			}
			else if (k == 0)
			{
				gotoxy(111, 16);
				cout << "-->";
				createBox(114, 15, 30, 2, GREEN, "NHAP DU LIEU THANH CONG!");
				getchar();
				system("cls");
				goto ADD;
			}
			else if (k == 2)
			{
				system("cls");
				return;
			}
		}
	}
}
//
void menuLop()
{
CLASS:
	tacgia();
	string t[6] = {"CNTT1 : 001",
				   "CNTT2 : 002",
				   "BDANTT: 003",
				   "ANHTTT: 004",
				   "PTDL: 005",
				   "QUAY LAI"};
	int x=90, y = 15, w = 20, h = 2;
	ShowCur(false);
	int k = 0;
	int px = x, py = y; // toa do thanh sang
	int xcu = px, ycu = py;
	for (int i = 0; i < 6; i++)
	{
		createBox(x, y + i * 3, w, h, 11, t[i]);
	}
	pickBox(xcu, ycu, w, h, 120, dauCach(t[k]));
	tacgia();
	int pause = true;
	while (pause)
	{
		char kb_hit = _getch();
		if (kb_hit == -32)
		{
			kb_hit = _getch();
			if (kb_hit == KEY_DOWN)
			{
				if (py != y + 3 * 5)
				{
					createBox(px, py, w, h, 11, t[k]);
					py += 3;
					k++;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y;
					k = 0;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
			else if (kb_hit == KEY_UP)
			{
				if (py != y)
				{
					createBox(px, py, w, h, 11, t[k]);
					py -= 3;
					k--;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y + 3 * 5;
					k = 5;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
		}
		else if (kb_hit == ENTER)
		{
			if (k == 0 || k == 1 || k == 2 || k == 3 || k == 4)
			{
				system("cls");
				switch (k)
				{
				case 0:
					themhoso(s, masvmoi, k);
					break;
				case 1:
					themhoso(s, masvmoi, k);
					break;
				case 2:
					themhoso(s, masvmoi, k);
					break;
				case 3:
					themhoso(s, masvmoi, k);
					break;
				case 4:
					themhoso(s, masvmoi, k);
					break;
				}
				system("cls");
				goto CLASS;
			}
			else if (k == 5)
			{
				system("cls");
				return;
			}
		}
	}
}
//
void menuOut()
{
Out:
	string t[2] = {"IN RA MAN HINH", "GHI RA FILE"};
	int pick = 0;
	int x = 115, y = 18;
	TextColor(WHITE);
	gotoxy(115, 17);
	cout << "<<Back";
	gotoxy(111, 19);
	cout << "<-->";
	for (int i = 0; i < 2; i++)
	{
		createBox(x, y + i * 3, 20, 2, 11, t[i]);
	}
	pickBox(x, y, 20, 2, 120, dauCach(t[0]));
	char c = _getch();
	while (c != 13)
	{
		if (c == -32)
		{
			c = _getch();
			if (c == 72)
			{
				if (pick == 0)
				{
					createBox(x, y + pick * 3, 20, 2, 11, t[pick]);
					pick = 1;
					pickBox(x, y + pick * 3, 20, 2, 120, dauCach(t[pick]));
				}
				else
				{
					createBox(x, y + pick * 3, 20, 2, 11, t[pick]);
					pick = pick - 1;
					pickBox(x, y + pick * 3, 20, 2, 120, dauCach(t[pick]));
				}
			}
			if (c == 80)
			{
				if (pick == 1)
				{
					createBox(x, y + pick * 3, 20, 2, 11, t[pick]);
					pick = 0;
					pickBox(x, y + pick * 3, 20, 2, 120, dauCach(t[pick]));
				}
				else
				{
					createBox(x, y + pick * 3, 20, 2, 11, t[pick]);
					pick = pick + 1;
					pickBox(x, y + pick * 3, 20, 2, 120, dauCach(t[pick]));
				}
			}
			if (c == KEY_LEFT)
			{
				system("cls");
				return;
			}
		}
		if (c == ESC)
		{
			system("cls");
			return;
		}
		c = _getch();
	}
	if (pick == 1)
	{
		outputfile(s);
		system("cls");
		return;
	}
	chonHienThi = 0;
	InManHinh(s, chonHienThi);
	goto Out;
}
//
void menuTypeSort()
{
TYPESORT:
	int x=90, y = 15, w = 20, h = 2;
	string t[5] = {"SX CHON",
				   "SX CHEN",
				   "SX NOI BOT",
				   "SX NHANH",
				   "QUAY LAI"};
	ShowCur(false);
	int k = 0;
	int px = x, py = y; // toa do thanh sang
	int xcu = px, ycu = py;

	for (int i = 0; i < 5; i++)
	{
		createBox(x, y + i * 3, w, h, 11, t[i]);
	}
	pickBox(xcu, ycu, w, h, 120, dauCach(t[k]));
	tacgia();
	while (true)
	{
		char kb_hit = _getch();
		if (kb_hit == -32)
		{
			kb_hit = _getch();
			if (kb_hit == KEY_DOWN)
			{
				if (py != y + 3 * 4)
				{
					createBox(px, py, w, h, 11, t[k]);
					py += 3;
					k++;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y;
					k = 0;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
			else if (kb_hit == KEY_UP)
			{
				if (py != y)
				{
					createBox(px, py, w, h, 11, t[k]);
					py -= 3;
					k--;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y + 3 * 4;
					k = 4;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
		}
		else if (kb_hit == ENTER)
		{
			if (k == 0 || k == 1 || k == 2 || k == 3)
			{
				switch (k)
				{
				case 0:
				{
					loaiSx = 0;
					break;
				}
				case 1:
				{
					loaiSx = 1;
					break;
				}
				case 2:
				{
					loaiSx = 2;
					break;
				}
				case 3:
				{
					loaiSx = 3;
					break;
				}
				}
				menuSort();
				goto TYPESORT;
			}
			if (k == 4)
			{
				system("cls");
				return;
			}
		}
	}
}
//
void menuSort()
{
SORT:
	chonHienThi = 1;
	int x=90, y = 15, w = 20, h = 2;
	string t[5] = {"MA SV", "HO TEN", "NGAY SINH", "DTB", "QUAY LAI"};
	ShowCur(false);
	int k = 0;
	int px = x, py = y; // toa do thanh sang
	int xcu = px, ycu = py;

	for (int i = 0; i < 5; i++)
	{
		createBox(x, y + i * 3, w, h, 11, t[i]);
	}
	pickBox(xcu, ycu, w, h, 120, dauCach(t[k]));
	tacgia();
	while (true)
	{
		char kb_hit = _getch();
		if (kb_hit == -32)
		{
			kb_hit = _getch();
			if (kb_hit == KEY_DOWN)
			{
				if (py != y + 3 * 4)
				{
					createBox(px, py, w, h, 11, t[k]);
					py += 3;
					k++;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y;
					k = 0;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
			else if (kb_hit == KEY_UP)
			{
				if (py != y)
				{
					createBox(px, py, w, h, 11, t[k]);
					py -= 3;
					k--;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y + 3 * 4;
					k = 4;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
		}
		else if (kb_hit == ENTER)
		{
			if (k == 0 || k == 1 || k == 2 || k == 3)
			{
				switch (k)
				{
				case 0:
				{
					if (loaiSx == 0)
					{
						sxchonmasv(s);
					}
					else if (loaiSx == 1)
					{
						sxchenmasv(s);
					}
					else if (loaiSx == 2)
					{
						sxnoibotmasv(s);
					}
					else if (loaiSx == 3)
					{
						quicksortmasv(s, 0, s.size() - 1);
					}
					InManHinh(s, chonHienThi);
					break;
				}
				case 1:
				{
					if (loaiSx == 0)
					{
						sxchonhoten(s);
					}
					else if (loaiSx == 1)
					{
						sxchenhoten(s);
					}
					else if (loaiSx == 2)
					{
						sxnoibothoten(s);
					}
					else if (loaiSx == 3)
					{
						quicksorthoten(s, 0, s.size() - 1);
					}
					InManHinh(s, chonHienThi);
					break;
				}
				case 2:
				{
					if (loaiSx == 0)
					{
						sxchonnsinh(s);
					}
					else if (loaiSx == 1)
					{
						sxchennsinh(s);
					}
					else if (loaiSx == 2)
					{
						sxnoibotnsinh(s);
					}
					else if (loaiSx == 3)
					{
						quicksortnsinh(s, 0, s.size() - 1);
						sxchonnsinh(s);
					}
					InManHinh(s, chonHienThi);
					break;
				}
				case 3:
				{
					if (loaiSx == 0)
					{
						sxchondtb(s);
					}
					else if (loaiSx == 1)
					{
						sxchendtb(s);
					}
					else if (loaiSx == 2)
					{
						sxnoibotdtb(s);
					}
					else if (loaiSx == 3)
					{
						quicksortdtb(s, 0, s.size() - 1);
						sxchondtb(s);
					}
					InManHinh(s, chonHienThi);
					break;
				}
				}
				goto SORT;
			}
			else if (k == 4)
			{
				system("cls");
				return;
			}
		}
	}
}
//
void menuTypeSearch()
{
TYPESEARCH:
	string t[3] = {"TUAN TU",
				   "NHI PHAN",
				   "QUAY LAI"};
	int x=90, y = 15, w = 20, h = 2;
	ShowCur(false);
	int k = 0;
	int px = x, py = y; // toa do thanh sang
	int xcu = px, ycu = py;

	for (int i = 0; i < 3; i++)
	{
		createBox(x, y + i * 3, w, h, 11, t[i]);
	}
	pickBox(xcu, ycu, w, h, 120, dauCach(t[k]));
	tacgia();
	while (true)
	{
		char kb_hit = _getch();
		if (kb_hit == -32)
		{
			kb_hit = _getch();
			if (kb_hit == KEY_DOWN)
			{
				if (py != y + 3 * 2)
				{
					createBox(px, py, w, h, 11, t[k]);
					py += 3;
					k++;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y;
					k = 0;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
			else if (kb_hit == KEY_UP)
			{
				if (py != y)
				{
					createBox(px, py, w, h, 11, t[k]);
					py -= 3;
					k--;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y + 3 * 2;
					k = 2;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
		}
		else if (kb_hit == ENTER)
		{
			if (k == 0)
			{
				loaitk = 0;
				menuSearch();
				goto TYPESEARCH;
			}
			else if (k == 1)
			{
				loaitk = 1;
				menuktSx();
				goto TYPESEARCH;
			}
			else if (k == 2)
			{
				system("cls");
				return;
			}
		}
	}
}
//
void menuSearch()
{
SEARCH:
	chonHienThi = 2;
	string t[6] = {"MA LOP",
				   "MA SINH VIEN",
				   "HO VA TEN",
				   "NGAY SINH",
				   "DIEM TRUNG BINH",
				   "QUAY LAI"};
	int x=90, y = 15, w = 20, h = 2;
	// cai dat
	ShowCur(false);
	int k = 0;
	int px = x, py = y; // toa do thanh sang
	int xcu = px, ycu = py;
	for (int i = 0; i < 6; i++)
	{
		createBox(x, y + i * 3, w, h, 11, t[i]);
	}
	pickBox(xcu, ycu, w, h, 120, dauCach(t[k]));
	tacgia();
	int pause = true;
	while (pause)
	{
		char kb_hit = _getch();
		if (kb_hit == -32)
		{
			kb_hit = _getch();
			if (kb_hit == KEY_DOWN)
			{
				if (py != y + 3 * 5)
				{
					createBox(px, py, w, h, 11, t[k]);
					py += 3;
					k++;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y;
					k = 0;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
			else if (kb_hit == KEY_UP)
			{
				if (py != y)
				{
					createBox(px, py, w, h, 11, t[k]);
					py -= 3;
					k--;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y + 3 * 5;
					k = 5;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
		}
		else if (kb_hit == ENTER)
		{
			if (k == 0)
			{
				system("cls");
				tklop(loaitk, s, chonHienThi);
				goto SEARCH;
			}
			else if (k == 1)
			{
				system("cls");
				tkmasv(loaitk, s, chonHienThi);
				goto SEARCH;
			}
			if (k == 2)
			{
				system("cls");
				tkhoten(loaitk, s, chonHienThi);
				goto SEARCH;
			}
			else if (k == 3)
			{
				system("cls");
				tknsinh(loaitk, s, chonHienThi);
				goto SEARCH;
			}
			else if (k == 4)
			{
				system("cls");
				tkdtb(loaitk, s, chonHienThi);
				goto SEARCH;
			}
			else if (k == 5)
			{
				system("cls");
				return;
			}
		}
	}
}
//
void menuktSx()
{
TEST:
	system("cls");
	bangtbao("BAN DA SAP XEP CHUA?");
	TextColor(WHITE);
	gotoxy(55, 26);
	cout << "nhan ESC de ve menu loai tim kiem";
	int x = 50, y = 20, w = 20, h = 2;
	int dodich = 22;
	string t[2] = {"DA SAP XEP", "CHUA SAP XEP"};
	int pick = 0;
	for (int i = 0; i < 2; i++)
	{
		createBox(x + i * dodich, y, w, h, 11, t[i]);
	}
	pickBox(x, y, w, h, 120, dauCach(t[0]));
	char c = _getch();
	while (c != 13)
	{
		if (c == -32)
		{
			c = _getch();
			if (c == KEY_LEFT)
			{
				if (pick == 0)
				{
					createBox(x + pick * dodich, y, w, h, 11, t[pick]);
					pick = 1;
					pickBox(x + pick * dodich, y, w, h, 120, dauCach(t[pick]));
				}
				else
				{
					createBox(x + pick * dodich, y, w, h, 11, t[pick]);
					pick = pick - 1;
					pickBox(x + pick * dodich, y, w, h, 120, dauCach(t[pick]));
				}
			}
			if (c == KEY_RIGHT)
			{
				if (pick == 1)
				{
					createBox(x + pick * dodich, y, w, h, 11, t[pick]);
					pick = 0;
					pickBox(x + pick * dodich, y, w, h, 120, dauCach(t[pick]));
				}
				else
				{
					createBox(x + pick * dodich, y, w, h, 11, t[pick]);
					pick = pick + 1;
					pickBox(x + pick * dodich, y, w, h, 120, dauCach(t[pick]));
				}
			}
		}
		if (c == ESC)
		{
			system("cls");
			return;
		}
		c = _getch();
	}
	if (pick == 0)
	{
		system("cls");
		menuSearch();
		goto TEST;
	}
	else if (pick == 1)
	{
		system("cls");
		bangtbao("VUI LONG SAP XEP TRUOC!");
		_getch();
		system("cls");
		return;
	}
}
//
void menuThongKe()
{
TKE:
	string t[3] = {"TAT CA",
				   "TUNG LOP",
				   "QUAY LAI"};
	int x=90, y = 15, w = 20, h = 2;
	ShowCur(false);
	int k = 0;
	int px = x, py = y; // toa do thanh sang
	int xcu = px, ycu = py;

	for (int i = 0; i < 3; i++)
	{
		createBox(x, y + i * 3, w, h, 11, t[i]);
	}
	pickBox(xcu, ycu, w, h, 120, dauCach(t[k]));
	tacgia();
	while (true)
	{
		char kb_hit = _getch();
		if (kb_hit == -32)
		{
			kb_hit = _getch();
			if (kb_hit == KEY_DOWN)
			{
				if (py != y + 3 * 2)
				{
					createBox(px, py, w, h, 11, t[k]);
					py += 3;
					k++;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y;
					k = 0;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
			else if (kb_hit == KEY_UP)
			{
				if (py != y)
				{
					createBox(px, py, w, h, 11, t[k]);
					py -= 3;
					k--;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
				else
				{
					createBox(px, py, w, h, 11, t[k]);
					py = y + 3 * 2;
					k = 2;
					pickBox(px, py, w, h, 120, dauCach(t[k]));
				}
			}
		}
		else if (kb_hit == ENTER)
		{
			if (k == 0)
			{
				thongketheo0(s);
				system("cls");
				goto TKE;
			}
			else if (k == 1)
			{
				thongketheo1(s);
				system("cls");
				goto TKE;
			}
			else if (k == 2)
			{
				system("cls");
				return;
			}
		}
	}
}
//
void esc()
{
	HWND myConsole = GetConsoleWindow();
	ShowWindow(myConsole, 0);
	ExitProcess(0);
}
//
string dauCach(string t)
{
	string x = " ";
	int chinh = (20 - t.length()) / 2;
	for (int i = 0; i < chinh; i++)
	{
		t = x + t;
	}
	return t;
}
void dauGachNgang(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << char(196);
	}
}
void dauGachDoc(int n, int x, int y)
{
	for (int i = 1; i < n; i++)
	{
		gotoxy(x, y + i);
		cout << char(179);
	}
}
void InTieuDe(string s, int x)
{
	TextColor(int(x / 16) * 16 + 6);
	system("cls");
	gotoxy(16, 2);
	for (int i = 0; i < 100; i++)
		cout << "=";
	int k = s.size();
	gotoxy(15 + (100 - k + 4) / 2, 2);
	cout << "  " << s << "  ";
	TextColor(x);
}
