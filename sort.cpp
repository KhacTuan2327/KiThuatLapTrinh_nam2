#include "sort.h"

void swap(sv &a, sv &b)
{
    sv tmp = a;
    a = b;
    b = tmp;
}
int songay(int d, int m, int y)
{
    if (m < 3)
    {
        y--;
        m += 12;
    }
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
void sxtangdtb(vector<sv>& s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (s[j].dtb < s[min_idx].dtb)
                min_idx = j;
        swap(s[min_idx], s[i]);
    }
}
void sxlop(vector<sv>& s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (s[j].sttlop < s[min_idx].sttlop)
                min_idx = j;
        swap(s[min_idx], s[i]);
    }
}
void sxtanghoten(vector<sv>& s) {
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        s[i].hten = s[i].hoTen.ho + " " + s[i].hoTen.ten;
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (s[j].hten < s[min_idx].hten)
                min_idx = j;
        swap(s[min_idx], s[i]);
    }
}
// sap xep chon
void sxchonmasv(vector<sv> &s)
{
    int n = s.size(), i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (s[j].maSv < s[min_idx].maSv)
                min_idx = j;
        }
        swap(s[min_idx], s[i]);
    }
}
void sxchonhoten(vector<sv> &s)
{
    int n = s.size(), i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (s[j].hoTen.ten < s[min_idx].hoTen.ten)
            {
                min_idx = j;
            }
            else if (s[j].hoTen.ten == s[min_idx].hoTen.ten)
            {
                if (s[j].hoTen.ho < s[min_idx].hoTen.ho)
                {
                    min_idx = j;
                }
            }
        }
        swap(s[min_idx], s[i]);
    }
}
void sxchonnsinh(vector<sv> &s)
{
    int n = s.size(), i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (songay(s[j].nSinh.ngay, s[j].nSinh.thang, s[j].nSinh.nam) < songay(s[min_idx].nSinh.ngay, s[min_idx].nSinh.thang, s[min_idx].nSinh.nam))
                min_idx = j;
        }
        swap(s[min_idx], s[i]);
    }
}
void sxchondtb(vector<sv> &s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (s[j].dtb > s[min_idx].dtb)
                min_idx = j;
        swap(s[min_idx], s[i]);
    }
}
// Sap xep chen
void sxchenmasv(vector<sv> &s)
{ // sap xep tang dan ma sv
    int n = s.size();
    int key;
    for (int i = 1; i < n; i++)
    {
        key = s[i].maSv;
        sv sv1;
        sv1 = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].maSv > key)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = sv1;
    }
}
void sxchenhoten(vector<sv> &s)
{
    int n = s.size();
    string key, key1;
    for (int i = 1; i < n; i++)
    {
        key = s[i].hoTen.ten;
        key1 = s[i].hoTen.ho;
        sv sv1;
        sv1 = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].hoTen.ten > key)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = sv1;
    }
}
void sxchennsinh(vector<sv> &s)
{ // sap xep tang dan ngay sinh
    int n = s.size();
    int key;
    for (int i = 1; i < n; i++)
    {
        key = songay(s[i].nSinh.ngay, s[i].nSinh.thang, s[i].nSinh.nam);
        sv sv1;
        sv1 = s[i];
        int j = i - 1;
        while (j >= 0 && songay(s[j].nSinh.ngay, s[j].nSinh.thang, s[j].nSinh.nam) > key)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = sv1;
    }
}
void sxchendtb(vector<sv> &s)
{ // sap xep giam dan diem trung binh
    int n = s.size();
    float key;
    for (int i = 1; i < n; i++)
    {
        key = s[i].dtb;
        sv sv1;
        sv1 = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].dtb < key)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = sv1;
    }
}

// Sap xep noi bot
void sxnoibotmasv(vector<sv> &s)
{
    int n = s.size();
    bool haveSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        haveSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].maSv > s[j + 1].maSv)
            {
                swap(s[j], s[j + 1]);
                haveSwap = true;
            }
        }
        if (haveSwap == false)
        {
            break;
        }
    }
}
void sxnoibothoten(vector<sv> &s)
{
    int n = s.size();
    bool haveSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        haveSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].hoTen.ten > s[j + 1].hoTen.ten)
            {
                swap(s[j], s[j + 1]);
                haveSwap = true;
            }
            else if (s[j].hoTen.ten == s[j + 1].hoTen.ten)
            {
                if (s[j].hoTen.ho > s[j + 1].hoTen.ho)
                {
                    swap(s[j], s[j + 1]);
                    haveSwap = true;
                }
            }
        }
        if (haveSwap == false)
        {
            break;
        }
    }
}
void sxnoibotnsinh(vector<sv> &s)
{
    int n = s.size();
    bool haveSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        haveSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (songay(s[j].nSinh.ngay, s[j].nSinh.thang, s[j].nSinh.nam) > songay(s[j + 1].nSinh.ngay, s[j + 1].nSinh.thang, s[j + 1].nSinh.nam))
            {
                swap(s[j], s[j + 1]);
                haveSwap = true;
            }
        }
        if (haveSwap == false)
        {
            break;
        }
    }
}
void sxnoibotdtb(vector<sv> &s)
{
    int n = s.size();
    bool haveSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        haveSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].dtb < s[j + 1].dtb)
            {
                swap(s[j], s[j + 1]);
                haveSwap = true;
            }
        }
        if (haveSwap == false)
        {
            break;
        }
    }
}

// Quick Sort
int phandoanmasv(vector<sv> &s, int low, int high)
{
    sv sv1 = s[high];
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && s[left].maSv < sv1.maSv)
            left++;
        while (right >= left && s[right].maSv > sv1.maSv)
            right--;
        if (left >= right)
            break;
        swap(s[left], s[right]);
        left++;
        right--;
    }
    swap(s[left], s[high]);
    return left;
}
void quicksortmasv(vector<sv> &s, int low, int high)
{
    if (low < high)
    {
        int chia = phandoanmasv(s, low, high);
        quicksortmasv(s, low, chia - 1);
        quicksortmasv(s, chia + 1, high);
    }
}
int phandoanhoten(vector<sv> &s, int low, int high)
{
    sv sv1 = s[high];
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && s[left].hoTen.ten < sv1.hoTen.ten)
            left++;
        while (right >= left && s[right].hoTen.ten > sv1.hoTen.ten)
            right--;
        if (left >= right)
            break;
        swap(s[left], s[right]);
        left++;
        right--;
    }
    swap(s[left], s[high]);
    return left;
}
void quicksorthoten(vector<sv> &s, int low, int high)
{
    if (low < high)
    {
        int chia = phandoanhoten(s, low, high);
        quicksorthoten(s, low, chia - 1);
        quicksorthoten(s, chia + 1, high);
    }
}
int phandoanns(vector<sv> &s, int low, int high)
{
    sv sv1 = s[high];
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && songay(s[left].nSinh.ngay, s[left].nSinh.thang, s[left].nSinh.nam) < songay(sv1.nSinh.ngay, sv1.nSinh.thang, sv1.nSinh.nam))
            left++;
        while (right >= left && songay(s[right].nSinh.ngay, s[right].nSinh.thang, s[right].nSinh.nam) > songay(sv1.nSinh.ngay, sv1.nSinh.thang, sv1.nSinh.nam))
            right--;
        if (left >= right)
            break;
        swap(s[left], s[right]);
        left++;
        right--;
    }
    swap(s[left], s[high]);
    return left;
}
void quicksortnsinh(vector<sv> &s, int low, int high)
{
    if (low < high)
    {
        int chia = phandoanmasv(s, low, high);
        quicksortnsinh(s, low, chia - 1);
        quicksortnsinh(s, chia + 1, high);
    }
}
int phandoandtb(vector<sv> &s, int low, int high)
{
    sv sv1 = s[high];
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && s[left].dtb < sv1.dtb)
            left++;
        while (right >= left && s[right].dtb > sv1.dtb)
            right--;
        if (left >= right)
            break;
        swap(s[left], s[right]);
        left++;
        right--;
    }
    swap(s[left], s[high]);
    return left;
}
void quicksortdtb(vector<sv> &s, int low, int high)
{
    if (low < high)
    {
        int chia = phandoanmasv(s, low, high);
        quicksortdtb(s, low, chia - 1);
        quicksortdtb(s, chia + 1, high);
    }
}