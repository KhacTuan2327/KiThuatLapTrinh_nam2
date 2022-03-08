#include "veHinh.h"
#include "input_output.h"

void bangtbao(string tb);
void bangtimkiem();
// Tim kiem ma lop
void sxlop(vector<sv>& s);
void tkttmalop(string malop, vector<sv> s, int &chonHienThi);
void tknpmalop(int stt, string lop,vector<sv> s, int low, int high, int &chonHienThi);
void tklop(int loaitk, vector<sv> s, int &chonHienThi);

// Tim kiem ma sinh vien
void tkttmasv(int masv, vector<sv> s, int &chonHienThi);
void tknpmasv(int masv, vector<sv> s, int low, int high, int &chonHienThi);
void tkmasv(int loaitk, vector<sv> s, int &chonHienThi);

// Tim kiem diem trung binh
void tkttdtb(float diem, vector<sv> s, int &chonHienThi);
void tknpdtb(float diem, vector<sv> s, int low, int high, int &chonHienThi);
void tkdtb(int loaitk, vector<sv> s, int &chonHienThi);

// Tim kiem ngay sinh
void bangnsinh(ns &d);
void tkttnsinh(ns d, vector<sv> s, int &chonHienThi);
void tknpnsinh(ns d, vector<sv> s, int low, int high, int &chonHienThi);
void tknsinh(int loaitk, vector<sv> s, int &chonHienThi);

// Tim kiem ho ten
void tktthoten(char ht[], vector<sv> s, int &chonHienThi);
void tknphoten(char ht[], string hoten,vector<sv> s, int low, int high, int &chonHienThi);
void tkhoten(int loaitk, vector<sv> s, int &chonHienThi);