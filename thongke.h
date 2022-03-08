#include "veHinh.h"
#include "input_output.h"

typedef struct KetQua
{
	int stt;
	string lop;
	int sx;
	int gioi;
	int kha;
	int tb;
	int yeu;
} kq;

void laysoluongsv(vector<sv> s, int &cn1, int &cn2, int &bd, int &an, int &pt);
void vebang(int x, int y);
void bangsv(int x, int y, int cn1, int cn2, int bd, int an, int pt);
void SoDo(int x, int y, int max);
void vecot(int x, int y, string s, int max, int gt);
void layketqua(vector<sv> s, kq &kQ);
void inthongkekq(kq kQ);
void bangkq(int x, int y, int sx, int gioi, int kha, int tb, int kem);
void thongketheo0(vector<sv> s);
void thongketheo1(vector<sv> s);