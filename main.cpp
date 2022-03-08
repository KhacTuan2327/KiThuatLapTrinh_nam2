#include "veHinh.h"
#include "input_output.h"
#include "sort.h"
#include "search.h"
#include "thongke.h"
int main()
{
	resizeConsole(1080, 780);
	DisableCtrButton(0, 0, 1);
	DisableResizeWindow();
	tenct();
	_getch();
	system("cls");
	createMainMenu();
	return 0;
}