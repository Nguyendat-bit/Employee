#pragma once
#include<ctime>
#include<iostream>
#include<stdio.h>
#include<sstream>
#include<fstream>
using namespace std;


	class Date	// BASE CLASS DATE
	{
	private:
		string date;
	public:
		int validate(string datt);
		void nhap();
		string getDate();
		void setdate(string date);
	};
	class Diemdanh :public Date		// DIEMDANH // DELi CLASS
	{
	private:
		string Trangthai;
	public:

		void diemdanh(string id);
		void diemdanhnow(string id);
		string get_tt();
		int checl_tt(string tt);// Kiem tra trang thai di lam 
		void set_tt(string trangthai);
		int checkdate(string id, string date, string* TT); // Kiem tra ngay diem danh  co bi trung khong 
	};
	class Person		// Base CLASS PERSON
	{
	private:
		string hovaten;
		Date birth;
		string adress;
	public:
		void nhap();
		string getname();
		string getbirth();
		string getadress();
		void setName(string name);
		void setbirth(string date, int i);
		void setadr(string adress, int i);
	};
	class Employee :public Person // Deli CLASS 
	{
	private:
		string id;
		string team;
		int check = 0; // so ngay diem danh duoc luu vao ; 
		Diemdanh* cr = new Diemdanh[31];
	public:
		string getddstring(int i);
		void setcheck(int n);
		void nhap();
		string getid();
		int getcheck();
		void getdd(int i);				// Trang thai diem danh, neu Nghi se danh dau X
		string getddall(int i);		//Lay THong tin trang thai diem danh
		string getteam();
		void diemdanh_1(int i, string id);		// diem danh tng cr
		void setid(string id);
		void setteam(string team, int i);
		void diemdanh(int i, string date, string TT);
	};
	class Check
	{
	private:
		string file;		//Da co file san text.txt
	public:
		Check();
		void setFILE(string name);
		int checkid(string id);  // Kiem tra xem co trung ma Nhan Vien khong
	};
	class search
	{
	private:
		string file;	//Da co file san 
	public:
		search();
		void setFile(string name);
		Employee Searcheid(string id); // search theo id
		void Searchnv(string name);// search theo ten nhan vien
		void Searchall(); //alll
		void Searchteam(string team); // search theo team
	};
	class Other
	{
	private:
		string file;	//Da co file san List.txt
	public:
		void InALL(Employee p, int n = 0);
		void getdatefile(Employee* p);
		void Printfdd(Employee p, int n = 0);
		void autoFile();
		void autoFileup();
		void Printfddup(Employee p, int n = 0);
		void Lich(int day, int month, int year);
		void setFile(string file);	// thay doi File
		void History(Employee a, int i);						// Lich su diem danh 
		void Print(Employee p);		// Xuat ra man hinh 
		void Printfcvs(Employee p, int n); // Xuat ket qua ra file csv	n la so ngay da duoc diem danh
	};
	class Menu	 // Chua xong 
	{
	private:
		bool button;
	public:
		void menu()
		{
			system("cls");
			cout << "============================================== \n";
			cout << "= 1 - Nhap thong tin nhan vien               = \n";
			cout << "= 2 - Tim thong tin nhan vien                = \n";
			cout << "= 3 - Diem danh sach nhan vien               = \n";
			cout << "= 4 - Lich Su diem danh                      = \n";
			cout << "= 5 - Tim Thong tin nhan vien theo Ten       = \n";
			cout << "= 6 - Tim Thong tin nhan vien theo Bo phan   = \n";
			cout << "= 7 - Tim Tat Ca Thong tin nhan vien         = \n";
			cout << "============================================== \n";
		}
		void CASE1()
		{
			char key;
			int n = 0;
			cout << "Moi nhap thong tin nhan vien \n";
			Employee a;
			a.nhap();
			Other file;
			file.setFile("ImportData.csv");
			file.Printfcvs(a, n);
			cout << "Diem danh cho nhan vien vua nhap ? (Y/N)" << endl;
			cin >> key;
			switch (key)
			{
			case 'Y':
			{
				string id = a.getid();
				cout << "==================================Diem Danh==================================\n";
				int  key;
				bool lol = true;
				cout << "1.Diem danh theo ngay hien tai \n2.Diem Danh theo ngay thang bat ki \n";
				cin >> key;
				cin.ignore();
				while (lol)
				{
					switch (key)
					{
					case 2:
					{
						lol = false;
						cout << "So ngay diem danh \n";
						cin >> n;
						cin.ignore();
						for (int i = 0; i < n; i++)
						{
							a.diemdanh_1(i, id);
							file.History(a, i);
						}
					}
					break;
					case 1:
					{
						lol = false;
						a.diemdanh_1(-1, id);
						file.History(a, 0);

					}break;
					}
					system("pause");
				}
				file.setFile("Diemdanh.txt");
				file.Printfdd(a, n);
			}break;
			}

		}
		void CASE2()
		{
			string id;
			cout << "Moi nhap ma nhan vien can tim kiem: ";
			getline(cin, id);
			Check* p = new Check;
			p->setFILE("ImportData.csv");
			while (p->checkid(id) != 0) {
				cout << "Ma nhan vien khong ton tai \n";
				cout << "Moi ban nhap lai ma nhan vien can tim kiem: ";
				getline(cin, id);
			}
			cout << "Thong tin cua nhan vien co ma nhan vien: " << id << endl;
			Other a;
			search b;
			b.setFile("ImportData.csv");
			a.Print(b.Searcheid(id));
			system("pause");
			system("pasue");
		}
		void CASE3()
		{
			int n = 1;
			string id;
			Check a;
			Other c;
			search d;
			a.setFILE("ImportData.csv");
			d.setFile("ImportData.csv");
			cout << "Nhap ma nhan vien \n";
			getline(cin, id);
			while (a.checkid(id) != 0)
			{
				cout << "Ma so nhan vien khong khong ton tai\n";
				cout << "Moi ban nhap lai ma nhan vien can tim kiem: ";
				getline(cin, id);
			}
			Employee e = d.Searcheid(id);
			c.Print(d.Searcheid(id));
			cout << "==================================Diem Danh==================================\n";
			int  key;
			bool lol = true;
			cout << "1.Diem danh theo ngay hien tai \n2.Diem Danh theo ngay thang bat ki \n";
			cin >> key;
			cin.ignore();
			while (lol)
			{
				switch (key)
				{
				case 2:
				{
					lol = false;
					cout << "So ngay diem danh \n";
					cin >> n;
					cin.ignore();
					for (int i = 0; i < n; i++)
					{
						e.diemdanh_1(i, id);
						c.History(e, i);
					}
				}
				break;
				case 1:
				{
					lol = false;
					e.diemdanh_1(-1, id);
					c.History(e, 0);

				}break;
				}
				system("pause");
			}
			c.setFile("Diemdanh.txt");
			c.Printfdd(e, n);
		}
		void CASE4()
		{
			cout << "==================================LICH SU DIEM DANH !==================================" << endl;
			string line;
			ifstream fileInput("history.txt", ios::in);
			if (fileInput.is_open())
			{
				while (!fileInput.eof())
				{
					getline(fileInput, line);
					string epl = line;
					cout << epl << endl;
				}

			}
			system("pause");

		}
		void CASE5()
		{
			string name;
			cout << "Nhap Ten nhan vien ";
			getline(cin, name);
			search a;
			a.setFile("ImportData.csv");
			a.Searchnv(name);
			system("pause");
		}
		void CASE6()
		{
			string team;
			cout << "Nhap bo phan can tim " << endl;
			getline(cin, team);
			search a;
			a.setFile("ImportData.csv");
			a.Searchteam(team);
			cout << "Da in ra cac file thong tin nhan vien thuoc bo phan " << team << endl; 
			cout << "Xin moi mo file trong thu muc Team" << endl; 
			system("pause");
		}
		void CASE7()
		{
			search a;
			a.setFile("ImportData.csv");
			a.Searchall();
			cout << "Da in tat ca cac file thong tin cua toan bo nhan vien " << endl; 
			cout << "Xin moi mo file trong thuc muc ALL" << endl;
			system("pause");
		}
	};
	string UTC();
