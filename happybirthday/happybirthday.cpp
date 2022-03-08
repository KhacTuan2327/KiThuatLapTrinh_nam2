#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include<ctime>
#include <vector>
#include "windows.h" 
using namespace std;

//Vào trang wed : https://www.ascii-art-generator.org/ để chuyển ảnh sang file .txt


void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void tamsu(string a) {
	for (int i = 0; i <= sizeof(a); i++) {
		cout << a[i]; Sleep(100);
	}
}
string d = "Ngay mot thien than chao doi!";
string d1 = "Sinh nhat vui ve nha Thi Beo!";
string d2 = "Chuc tuoi 20 cua em ngap tran";
string d3 = " niem vui,luon luon hanh phuc";
string d5 = "Yeu thuonggggggggggggggggg <3";
string d6 = "Dung video thoi, met quaaa :(";
int main()
{
	char iu=1;
	while (true)
	{
		system("cls");
		
		Sleep(1000);
		if (iu)
		{
			
			cout << endl;
			//tamsu(d1);
			cout << endl;
			vector <int> A;
			A.push_back(7);
			A.push_back(12);
			A.push_back(14);
			A.push_back(10);
			while (true)
			{
				int i = 0;
				SetColor(A.at(10 % A.size()));

				ifstream file;
				file.open("C:/ns.txt", ios_base::in); //import file thì copy đường dẫn rồi đổi \ thành \\ hoặc /
				string line;
				while (getline(file, line)) {
					cout << line << endl;
					Sleep(300);
				}
				file.close();
				tamsu(d);
				cout << endl;
				cout << endl;
				tamsu(d1);
				
				cout <<"\n"<< endl;
				cout << "\nTEST DA!" << endl;
				SetColor(A.at(12 % A.size()));

				//============ Ảnh thứ 2,3,4... thì copy từ "ifstream file" tới "file.close();" rồi đổi tên "file" và "line" lại ===========
				ifstream file2;
				file2.open("C:/banner.txt", ios_base::in);
				string line2;
				while (getline(file2, line2)) {
					cout << line2 << endl;
					Sleep(30);
				}
				file2.close();
				cout << endl;
				cout << endl;
				cout << "\nO, xinh theee, nua ne" << endl;
				cout << endl;
				cout << endl;
				tamsu(d2);
				tamsu(d3);
				cout << endl;
				cout << endl;
				SetColor(A.at(220 % A.size()));
				ifstream file3;
				file3.open("C:/cuoi.txt", ios_base::in);
				string line3;
				while (getline(file3, line3)) {
					cout << line3 << endl;
					Sleep(30);
				}
				file3.close();
				cout << endl;
				cout << endl;
				tamsu(d5);
				cout << endl;
				cout << endl;
				SetColor(A.at(10 % A.size()));
				ifstream file6;
				file6.open("C:/yeu.txt", ios_base::in);
				string line6;
				while (getline(file6, line6)) {
					cout << line6 << endl;
					Sleep(30);
				}
				file6.close();
				cout << endl;
				cout << endl;
				tamsu(d6);
				cout << endl;
				cout << endl;
				SetColor(A.at(5 % A.size()));
				ifstream file5;
				file5.open("C:/tim.txt", ios_base::in);
				string line5;
				while (getline(file5, line5)) {
					cout << line5 << endl;
					Sleep(200);
				}
				SetColor(A.at(10 % A.size()));
				file5.close();
				cout << endl;
				cout << endl;
				break;
			}
			iu = 0;
			_getch();
		}
		else
		{
			cout << "\t\tSAI ROI ;((" << endl << endl;
			system("pause");
		}
	}
}