#include <Windows.h>
#include "marcro.h"
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
// thay doi kich thuoc cua so console
void resizeConsole(int width, int height);

// tra ve vi tri toa do x hien tai cua con tro dang dung(tren cot doc)
int wherex(void);

// tra ve vi tri toa do y hien tai cua con tro dang dung(tren cot ngang)
int wherey(void);

// ....... set mau cua nen chu....................
void SetBGColor(WORD color);
void TextColor(int x);
// dua con tro den toa do x:y
void gotoxy(int x, int y);

// An/ Hien con tro nhap nhay trong console
void ShowCur(bool CursorVisibility);

// Dat mau cho chu
void SetColor(WORD color);

// Xoa toan bo noi dung cua so console
void cls(HANDLE hConsole);

void clrscr();

// chu chuyen ve mau vang
void normalTextColor();

// nen chu chuyen ve xanh  va chu chuyen ve mau vang
void normalBGColor();

/// Ham tra ve vi tri con tro tren console
char getCursorChar();

/// Function which reads character at specific coordinates
char readChar(int x, int y);

//
void DisableCtrButton(bool Close, bool Min, bool Max);

//
void DisableResizeWindow();