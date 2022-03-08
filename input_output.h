#include "veHinh.h"
#include <fstream>
#include <cstdio>
#pragma once
using namespace std;

struct NgaySinh
{
	int ngay;
	int thang;
	int nam;
};
typedef NgaySinh ns;
struct hoten
{
	string ho;
	string ten;
};
typedef hoten ht;
struct SinhVien
{
	string maLop;
	int maSv;
	ht hoTen;
	string hten;
	ns nSinh;
	float dtb;
	int sttlop;
};
typedef SinhVien sv;
// Ham xu ly ngay sinh
bool namNhuan(int year);
int checkNgaySinh(ns ngSinh);
void nhapNgaySinh(ns &ngSinh);
// Ham them thong tin sinh vien
sv nhapSv(int &masvmoi, int k);
void nhapDiem(float &d);
void themhoso(vector<sv> &s, int &masvmoi, int k);
void inputfile(vector<sv> &ds);
void outputfile(vector<sv> s);
void indanhsach(int j, vector<sv> s);
void khungindanhsach(vector<sv> s);
void InManHinh(vector<sv> s, int &chonHienThi);