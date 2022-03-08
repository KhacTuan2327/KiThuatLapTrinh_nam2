#include "thongke.h"

void laysoluongsv(vector<sv> s, int &cn1, int &cn2, int &bd, int &an, int &pt)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].sttlop == 1)
		{
			cn1 += 1;
		}
		if (s[i].sttlop == 2)
		{
			cn2 += 1;
		}
		if (s[i].sttlop == 3)
		{
			bd += 1;
		}
		if (s[i].sttlop == 4)
		{
			an += 1;
		}
		if (s[i].sttlop == 5)
		{
			pt += 1;
		}
	}
}
void vebang(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		gotoxy(16, y + 2 * i);
		for (int j = 0; j < 100; j++)
		{
			{
				cout << char(196);
			}
		}
	}
	gotoxy(x, y);
	cout << char(218);
	gotoxy(x, y + 2);
	cout << char(195);
	gotoxy(x, y + 4);
	cout << char(195);
	for (int i = 0; i < 3; i++)
	{
		gotoxy(x, y + 1 + 2 * i);
		cout << char(179);
		gotoxy(x + 99, y + 1 + 2 * i);
		cout << char(179);
		gotoxy(x + 19, y + 1 + 2 * i);
		cout << char(179);
	}
	gotoxy(x, y + 6);
	cout << char(192);
	gotoxy(x + 99, y + 2);
	cout << char(180);
	gotoxy(x + 99, y + 4);
	cout << char(180);
	gotoxy(x + 99, y + 6);
	cout << char(217);
	gotoxy(x + 99, y);
	cout << char(191);
	gotoxy(19 + x, y);
	cout << char(194);
	gotoxy(x + 19, y + 2);
	cout << char(197);
	gotoxy(x + 19, y + 2);
	cout << char(197);
	gotoxy(x + 19, y + 6);
	cout << char(193);
	for (int i = 0; i < 5; i++)
	{
		gotoxy(x + 19 + 16 * i, y);
		cout << char(194);
		gotoxy(x + 19 + 16 * i, y + 6);
		cout << char(193);
		gotoxy(x + 19 + 16 * i, y + 2);
		cout << char(197);
		gotoxy(x + 19 + 16 * i, y + 4);
		cout << char(197);
		for (int j = 0; j < 3; j++)
		{
			gotoxy(x + 19 + 16 * i, y + 1 + 2 * j);
			cout << char(179);
		}
	}
	gotoxy(x + 5, y + 3);
	cout << "So luong";
	gotoxy(x + 5, y + 5);
	cout << "Ti le";
}
void bangsv(int x, int y, int cn1, int cn2, int bd, int an, int pt)
{
	int k = 1;
	int tong = cn1 + cn2 + bd + an + pt;
	double Tile_cn1, Tile_cn2, Tile_bd, Tile_an, Tile_pt;
	Tile_cn1 = double(cn1) / double(tong) * 100;
	Tile_cn2 = double(cn2) / double(tong) * 100;
	Tile_bd = double(bd) / double(tong) * 100;
	Tile_an = double(an) / double(tong) * 100;
	Tile_pt = double(pt) / double(tong) * 100;
	vebang(x, y);
	gotoxy(x + 5, y + 1);
	cout << "Lop";
	gotoxy(x + 9 + 16 * k, y + 1);
	cout << "CNTT1";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << cn1;
	if (Tile_cn1 < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_cn1 << " %";
	k++;
	gotoxy(x + 9 + 16 * k, y + 1);
	cout << "CNTT2";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << cn2;
	if (Tile_cn2 < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_cn2 << " %";
	k++;
	gotoxy(x + 9 + 16 * k, y + 1);
	cout << "BDATTT";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << bd;
	if (Tile_bd < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_bd << " %";
	k++;
	gotoxy(x + 9 + 16 * k, y + 1);
	cout << "ANHTTT";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << an;
	if (Tile_an < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_an << " %";
	k++;
	gotoxy(x + 10 + 16 * k, y + 1);
	cout << "PTDL";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << pt;
	if (Tile_pt < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_pt << " %";
}
void SoDo(int x, int y, int max)
{
	gotoxy(x - 13, y + 9);
	cout << "So hoc vien";
	gotoxy(x, y + 9);
	cout << char(30);
	int khoang = max / 5;
	for (int i = 0; i < 28; i++)
	{
		gotoxy(x, y + i + 10);
		cout << char(179);
	}
	for (int i = 0; i < 5; i++)
	{
		gotoxy(x - 4, y + 5 * i + 13);
		cout << khoang * (5 - i);
		gotoxy(x + 1, y + 5 * i + 3 + 10);
		for (int j = 0; j < 80; j++)
		{
			cout << "-";
		}
	}
	gotoxy(x + 1, y + 5 * 5 + 13);
	for (int i = 0; i < 80; i++)
	{
		cout << char(196);
	}
	gotoxy(x + 81, y + 5 * 5 + 13);
	cout << char(16);
	gotoxy(x, y + 5 * 5 + 13);
	cout << char(192);
}
void vecot(int x, int y, string s, int max, int gt)
{
	int gt_moi = double(gt * 100) / double(max);
	gt_moi = round(gt_moi);//round(a): Làm tròn giá trị của a
	double cao = double(25) / 100 * gt_moi;
	int up = 0;
	TextColor(12);
	if (cao > 0)
	{
		gotoxy(x + 14, y + 5 * 5 + 13);
		cout << char(223) << char(223) << char(223);
	}
	for (double i = 1; i <= cao; i += 0.5)
	{
		if (up % 2 == 0)
		{
			gotoxy(x + 14, y + 5 * 5 + 13 - int(i));
			cout << char(220) << char(220) << char(220);
			up += 1;
		}
		else
		{
			gotoxy(x + 14, y + 5 * 5 + 13 - int(i));
			cout << char(219) << char(219) << char(219);
			up += 1;
		}
	}
	TextColor(11);
	if (gt >= 100)
	{
		gotoxy(x + 14, y + 5 * 5 + 13 - int(cao) - 1);
	}
	else
	{
		gotoxy(x + 15, y + 5 * 5 + 13 - int(cao) - 1);
	}
	cout << gt;
	int n = s.length();
	gotoxy(x + 15 - n / 2, y + 5 * 5 + 13 + 1);
	cout << s;
}
void layketqua(vector<sv> s, kq &kQ)
{
	kQ.sx = 0;
	kQ.gioi = 0;
	kQ.kha = 0;
	kQ.tb = 0;
	kQ.yeu = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].maLop == kQ.lop)
		{
			if (s[i].dtb >= 9)
			{
				kQ.sx++;
				continue;
			}
			else if (s[i].dtb >= 8)
			{
				kQ.gioi++;
				continue;
			}
			else if (s[i].dtb >= 7)
			{
				kQ.kha++;
				continue;
			}
			else if (s[i].dtb >= 5)
			{
				kQ.tb++;
				continue;
			}
			else
			{
				kQ.yeu++;
			}
		}
	}
}
void bangkq(int x, int y, int sx, int gioi, int kha, int tb, int yeu)
{
	int k = 1;
	int tong = sx + gioi + kha + tb + yeu;
	double Tile_sx, Tile_gioi, Tile_kha, Tile_tb, Tile_yeu;
	Tile_sx = double(sx) / double(tong) * 100;
	Tile_gioi = double(gioi) / double(tong) * 100;
	Tile_kha = double(kha) / double(tong) * 100;
	Tile_tb = double(tb) / double(tong) * 100;
	Tile_yeu = double(yeu) / double(tong) * 100;
	vebang(x, y);
	gotoxy(x + 5, y + 1);
	cout << "Hoc luc";
	gotoxy(x + 8 + 16 * k, y + 1);
	cout << "SUAT SAC";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << sx;
	if (Tile_sx < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_sx << " %";
	k++;
	gotoxy(x + 9 + 16 * k, y + 1);
	cout << "GIOI";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << gioi;
	if (Tile_gioi < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_gioi << " %";
	k++;
	gotoxy(x + 10 + 16 * k, y + 1);
	cout << "KHA";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << kha;
	if (Tile_kha < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_kha << " %";
	k++;
	gotoxy(x + 6 + 16 * k, y + 1);
	cout << "TRUNG BINH";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << tb;
	if (Tile_tb < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_tb << " %";
	k++;
	gotoxy(x + 10 + 16 * k, y + 1);
	cout << "YEU";
	gotoxy(x + 10 + 16 * k, y + 3);
	cout << yeu;
	if (Tile_yeu < 10)
	{
		gotoxy(x + 9 + 16 * k, y + 5);
	}
	else
	{
		gotoxy(x + 8 + 16 * k, y + 5);
	}
	cout << fixed << setprecision(2) << Tile_yeu << " %";
}
void inthongkekq(kq kQ)
{
	string s = "LOP " + kQ.lop;
	int x = 16, y = 5;
	int k = 0;
	TextColor(11);
	InTieuDe(s, 11);
	gotoxy(8, 4);
	cout << "Nhan Esc de thoat";
	gotoxy(115, 4);
	cout << "Total: " << kQ.sx + kQ.gioi + kQ.kha + kQ.tb + kQ.yeu;
	bangkq(x, y, kQ.sx, kQ.gioi, kQ.kha, kQ.tb, kQ.yeu);
	int max = kQ.sx;
	if (kQ.gioi > max)
		max = kQ.gioi;
	if (kQ.kha > max)
		max = kQ.kha;
	if (kQ.tb > max)
		max = kQ.tb;
	if (kQ.yeu > max)
		max = kQ.yeu;
	max = (max / 50 + 1) * 50;
	x += 10;
	SoDo(x, y, max);
	vecot(x + 14 * k, y, "SUAT SAC", max, kQ.sx);
	k++;
	vecot(x + 14 * k, y, "GIOI", max, kQ.gioi);
	k++;
	vecot(x + 14 * k, y, "KHA", max, kQ.kha);
	k++;
	vecot(x + 14 * k, y, "TRUNG BINH", max, kQ.tb);
	k++;
	vecot(x + 14 * k, y, "YEU", max, kQ.yeu);
	k++;
	gotoxy(50, 46);
	cout << "BANG THONG KE THEO KET QUA LOP " << kQ.lop;
	TextColor(15);
	gotoxy(4, 48);
	cout << "<---- Lop truoc";
	gotoxy(115, 48);
	cout << "Lop sau ---->";
	gotoxy(1, 1);
}
void thongketheo0(vector<sv> s)
{
	int x = 16, y = 5;
	int k = 0;
	TextColor(11);
	InTieuDe("THONG KE THEO TAT CA SINH VIEN", 11);
	int cn1 = 0, cn2 = 0, bd = 0, an = 0, pt = 0;
	laysoluongsv(s, cn1, cn2, bd, an, pt);
	bangsv(x, y, cn1, cn2, bd, an, pt);
	gotoxy(8, 4);
	cout << "Nhan Esc de thoat";
	gotoxy(115, 4);
	cout << "Total: " << cn1 + cn2 + bd + an + pt;
	int max = cn1;
	if (cn2 > max)
		max = cn2;
	if (bd > max)
		max = bd;
	if (an > max)
		max = an;
	if (pt > max)
		max = pt;
	max = (max / 50 + 1) * 50;
	x += 10;
	SoDo(x, y, max);
	vecot(x + 14 * k, y, "CNTT1", max, cn1);
	k++;
	vecot(x + 14 * k, y, "CNTT2", max, cn2);
	k++;
	vecot(x + 14 * k, y, "BDATTT", max, bd);
	k++;
	vecot(x + 14 * k, y, "ANHTTT", max, an);
	k++;
	vecot(x + 14 * k, y, "PTDL", max, pt);
	k++;
	gotoxy(51, 46);
	cout << "BANG THONG KE SO LUONG SINH VIEN";
	gotoxy(1, 1);
	while (true)
	{
		char c = _getch();
		if (c == 27)
			return;
	}
}
void thongketheo1(vector<sv> s)
{
	kq kq[5];
	// kq[0].stt = 0;
	// kq[1].stt = 1;
	// kq[2].stt = 2;
	// kq[3].stt = 3;
	// kq[4].stt = 4;
	kq[0].lop = "CNTT1";
	kq[1].lop = "CNTT2";
	kq[2].lop = "BDATTT";
	kq[3].lop = "ANHTTT";
	kq[4].lop = "PTDL";
	for (int i = 0; i < 5; i++)
	{
		layketqua(s, kq[i]);
	}
	inthongkekq(kq[0]);
	int pick = 0;
	while (true)
	{
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 72 || c == 75)
			{
				if (pick == 0)
				{
					pick = 4;
					inthongkekq(kq[pick]);
				}
				else
				{
					pick = pick - 1;
					inthongkekq(kq[pick]);
				}
			}
			if (c == 80 || c == 77)
			{
				if (pick == 4)
				{
					pick = 0;
					inthongkekq(kq[pick]);
				}
				else
				{
					pick = pick + 1;
					inthongkekq(kq[pick]);
				}
			}
		}
		if (c == 27)
		{
			return;
		}
	}
}