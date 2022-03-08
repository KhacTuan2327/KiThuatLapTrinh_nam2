#include "veHinh.h"
#include "input_output.h"
void swap(sv &a, sv &b);
int songay(int d, int m, int y); // Tinh so ngay tai tg do den moc thoi gian
void sxtangdtb(vector<sv>& s);
void sxtanghoten(vector<sv>& s);

// Sap xep chon
void sxchonmasv(vector<sv> &s);
void sxchonhoten(vector<sv> &s);
void sxchonnsinh(vector<sv> &s);
void sxchondtb(vector<sv> &s);
// Sap xep chen
void sxchenmasv(vector<sv> &s);
void sxchenhoten(vector<sv> &s);
void sxchennsinh(vector<sv> &s);
void sxchendtb(vector<sv> &s);
// Sap xep noi bot
void sxnoibotmasv(vector<sv> &s);
void sxnoibothoten(vector<sv> &s);
void sxnoibotnsinh(vector<sv> &s);
void sxnoibotdtb(vector<sv> &s);
// Quicksort
int phandoanmasv(vector<sv> &s, int low, int high);
void quicksortmasv(vector<sv> &s, int low, int high);
int phandoanhoten(vector<sv> &s, int low, int high);
void quicksorthoten(vector<sv> &s, int low, int high);
int phandoanns(vector<sv> &s, int low, int high);
void quicksortnsinh(vector<sv> &s, int low, int high);
int phandoandtb(vector<sv> &s, int low, int high);
void quicksortdtb(vector<sv> &s, int low, int high);