#include "mylib.h"
#include <cstdlib>
#include <ctime>
#include<dos.h>
// tao cac menu
void tacgia();
void tenct();
void createBox(int x, int y, int w, int h, int b_color, string t);
void pickBox(int x, int y, int w, int h, int bgColor, string t);
void boxInfo();
void createMainMenu();
void menuAdd();
void menuLop();
void menuOut();
void menuTypeSort();
void menuSort();
void menuTypeSearch();
void menuSearch();
void menuThongKe();
void menuktSx();//Kiem tra nguoi dung da sap xep hay chua de tim kiem nhi phan
void esc();
// tao cac khung hien thi
// dem them dau cach cho chuoi
string dauCach(string t);
void dauGachNgang(int n);
void dauGachDoc(int n, int x, int y);
void InTieuDe(string s, int x);
