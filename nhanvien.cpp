#include "nhanvien.h";

using namespace std;
int Date::validate(string datt)
{
	stringstream ss(datt);
	int day, month, year;

	ss >> day >> month >> year;
	if (year >= 1970 && year <= 3000)
	{
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
			return 1;
		else
			if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 0 && day <= 30)
				return 1;
			else
				if (month == 2)
				{
					if ((year % 4 == 0 || year % 400 == 0) && day > 0 && day <= 29)
						return 1;
					else if (day > 0 && day < 30)return 1;
				}
				else
					return 0;
	}
	else
		return 0;
	return 0;
}
void Date::nhap()
{
	getline(cin, this->date);
	while (validate(this->date) == 0)
	{
		cout << "Ban chua nhap dung dinh dang ngay thang, VD: 14 5 1999 \n";
		cout << "Xin moi nhap lai ngay thang: ";
		getline(cin, this->date);
	}
}
void Employee::diemdanh_1(int i,string id)
{
	if (i == -1)this->cr[0].diemdanhnow(id);
	else
	this->cr[i].diemdanh(id);
}
string Date::getDate()
{
	return date;
}
void Date::setdate(string date)
{
	this->date = date;
}
void Diemdanh::diemdanhnow(string id)
{
	bool ac = true;
	string TT; //Trang thai 
	time_t now = time(0);
	tm ltm; 
	errno_t result = localtime_s(&ltm, &now);
	stringstream ss; 
	ss << ltm.tm_mday  << " " << ltm.tm_mon + 1 << " " << ltm.tm_year + 1900;
	cout << "Today: " << ss.str() << endl;
	if (this->checkdate(id, ss.str(), &TT) == 0)
	{
		cout << "Hom nay da duoc diem danh voi trang thai " << TT << endl; 
		return; 
	}
	else this->setdate(ss.str());
	while (ac)
	{
		cout << "1.DL: Di lam \t2.DLNN: di lam nua ngay \t3.N: nghi\t4.NP: nghi phep \n";
		getline(cin, this->Trangthai);
		while (checl_tt(this->Trangthai) == 0)
		{
			cout << "Ban chua nhap dung dinh dang , VD: NL\n";
			getline(cin, this->Trangthai);
		}
		cout << "Ban chac quyet dinh cua minh ? Nhan Y/N ";
		char a = 'b';
		while (a != 'Y' && a != 'N')
		{
			a = getchar();
			cin.ignore();
		}
		if (a == 'Y')ac = false;

	}
	cout << "LOL" << endl; 
}
void Diemdanh::diemdanh(string id)
{
	time_t now = time(0);
	tm ltm;
	errno_t result = localtime_s(&ltm, &now); 
	int day = ltm.tm_mday, month = ltm.tm_mon + 1, year = ltm.tm_year + 1900;
	int day1, month1, year1; 
	bool ac = true; 
	cout << "Nhap ngay thang " << endl;
	this->nhap();
	string date = this->getDate(),TT;
	stringstream	 ss(date);
	ss >> day1 >> month1 >> year1;
	while (year1 >= year && month1 >= month && day1 > day)
	{
		cout << "Qua ngay qui dinh !" << endl; 
		cout << "Xin moi nhap lai " << endl; 
		this->nhap();
		date = this->getDate();
		stringstream	 ss(date);
		ss >> day1 >> month1 >> year1;
	}
	while (this->checkdate(id, date, &TT) == 0)
	{
			cout << date << " Da duoc diem danh voi trang thai " << TT << endl;
			cout << "Xin moi nhap lai " << endl;
			this->nhap();
			date = this->getDate();
	}
	while (ac)
	{
		cout << "1.DL: Di lam \t2.DLNN: di lam nua ngay \t3.N: nghi\t4.NP: nghi phep \n";
		getline(cin, this->Trangthai);
		while (checl_tt(this->Trangthai) == 0)
		{
			cout << "Ban chua nhap dung dinh dang , VD: NL\n";
			getline(cin, this->Trangthai);
		}
		cout << "Ban chac quyet dinh cua minh ? Nhan Y/N "; 
		char a = 'b'; 
		while (a != 'Y' && a != 'N')
		{
			a = getchar();
			cin.ignore();
		}
		if (a == 'Y')ac = false;
		
	}
}
int Diemdanh::checl_tt (string tt) // Kiem tra trang thai di lam 
{
	if (tt == "DL" || tt == "DLNN" || tt == "N" || tt == "NP")
		return 1;
	else return 0;
}
void Diemdanh::set_tt(string trangthai)
{
	this->Trangthai = trangthai;
}
void Person::nhap()
{
	cout << "Nhap Ho va Ten: ";
	getline(cin, this->hovaten);
	cout << "Nhap Ngay thang nam sinh ";
	this->birth.nhap();
	cout << "Nhap dia chi noi o : ";
	getline(cin, this->adress);
	while (this->adress.empty())
	{
		cout << "Dia chi khong duoc bo trong \n";
		cout << "Moi ban nhap lai dia chi \n";
		getline(cin, this->adress);
	}
}
void Employee::nhap()
{
	Check* p = new Check;
	p->setFILE("ImportData.csv");
	cout << "Nhap ma nhan vien: ";
	getline(cin, this->id);
	while (p->checkid(this->id) == 0)									//KIEM TRA co trung ma nhan vien khong
	{
		cout << "Ma nhan vien bi trung, moi ban nhap lai:  \n";
		cout << "Nhap ma nhan vien(VD: 01): ";
		getline(cin, this->id);
	}
	Person::nhap();
	cout << "Nhap bo phan cong tac: ";
	getline(cin, this->team);
	while (this->team.empty())
	{
		cout << "Bo phan cong tac khong duoc bo trong \n";
		cout << "Moi ban nhap lai bo phan cong tac \n";
		getline(cin, this->team);
	}
}
void Check:: setFILE(string name)
{
	this->file = name;
}
int Check::checkid(string id)  // Kiem tra xem co trung ma Nhan Vien khong
{

	string line;
	ifstream fileInput(this->file, ios::in);
	if (fileInput.is_open())
	{
		string str = id;
		while (!fileInput.eof())
		{
			getline(fileInput, line);
			string epl = line;
			istringstream stm(epl);
			string token;
			getline(stm, token, ',');
			if (token == str)
			{
				return 0;
			}

		}
	}
	return 1;
}
Check::Check()
{
	this->file = "text.txt";
}
search::search()
{
	this->file = "";
}
void search::setFile(string name)
{
	this->file = name;
}
void Person::setName(string name)
{
	this->hovaten = name;
}
void  Person::setbirth(string date,int i)
{
	stringstream ss(date), s;
	string temp;
	getline(ss, temp, '/');
	s << temp << " ";
	getline(ss, temp, '/');
	s << temp << " ";
	getline(ss, temp, '/');
	s << temp << " ";
	string date1 = s.str();
	if (this->birth.validate(date1) == 0)
	{
		this->birth.setdate("Loi Dinh Dang dd/mm/yy");
		cout << "Dong " << i << " Loi dinh dang dd/mm/yy" << endl;
	}		//Loi dinh dang neu validate == 0
	else this->birth.setdate(date);
}
void  Person::setadr(string adress,int i)
{
	if (adress == "" || adress == " ")
	{
		this->adress = "Khong co dia chi nha";
		cout << "Dong " << i << " Khong co dia chi nha " << endl;
	}// Loi ko co dia chi
	else this->adress = adress;
}
void Employee::setid(string id)
{
	this->id = id;
}
void Employee::setteam(string team,int i)
{
	//this->team = team;
	if (team == "" || team == " ")
	{
		this->team = "Khong co bo phan";
		cout << "Dong " << i << " Khong co bo phan " << endl;
	}// loi ko co bo phan
	else this->team = team;
}
void Employee::setcheck(int n)
{
	this->check = n;
}
void Employee::diemdanh(int i, string date, string TT) // gan diemdanh
{
	this->cr[i].setdate(date);
	this->cr[i].set_tt(TT);
}
string Employee::getid()
{
	return this->id;
}
int Employee::getcheck()
{
	return this->check;
}
string Diemdanh::get_tt()
{
	return this->Trangthai;
}
void Employee::getdd(int i)
{
	//
	 cout << this->cr[i].getDate() << ": " << this->cr[i].get_tt();
}
string Employee::getddstring(int i)
{
	//
	stringstream ss; 
	ss << this->cr[i].getDate() << ": " << this->cr[i].get_tt() << endl;
	return ss.str();
}
string Employee::getddall(int i)	
{
	stringstream ss;
	ss << this->cr[i].getDate() << ":" << this->cr[i].get_tt();
	return ss.str();
}
string Person::getbirth()
{
	//
	return this->birth.getDate();
}
string Person::getadress()
{
	return this->adress;
}
string Person::getname()
{
	return this->hovaten;
}
string Employee::getteam()
{
	return this->team;
}
Employee search::Searcheid(string id)
{
	int count = 0;	// Dem so dong
	Other file;;
	Employee* p = new Employee;
	string line;
	ifstream fileinput(this->file, ios::in);
	while (!fileinput.eof())
	{
		count++;
		getline(fileinput, line);
		if (count != 1)
		{
			string epl = line;
			istringstream stm(epl);
			string token;
			getline(stm, token, ',');
			if (token == id)
			{
				p->setid(id);
				getline(stm, token, ',');
				p->setName(token);
				getline(stm, token, ',');
				p->setbirth(token, count);
				getline(stm, token, ',');
				p->setadr(token, count);
				getline(stm, token, ',');
				p->setteam(token, count);
				getline(stm, token, ',');
				file.getdatefile(p);
			}
		}
		
	}
	return *p;
}
void Other::Print(Employee p)													// Ham In ra thong tin (Bai 2)
{
	cout << "Ma NV: " << p.getid() << endl;
	cout << "Ten NV: " << p.getname() << endl;
	cout << "Ngay thang nam sinh: " << p.getbirth() << endl;
	cout << "Dia chi: " << p.getadress() << endl;
	cout << "Bo phan cong tac: " << p.getteam() << endl;
	if (p.getcheck() == 0)
	{
		cout << "Khong co du lieu diem danh cua nhan vien" << endl;
	}
	else
	{
		cout << "=================Thong Ke Diem danh=================" << endl;
		int n = p.getcheck();
		for (int i = 0; i < n; i++)
		{
			
			cout << p.getddall(i);
		}
	}
}
void search::Searchnv(string name)
{
	Other file;
	int DEM =0,count = 0;	//Dem so dong
	string line;
	ifstream fileinput(this->file, ios::in);
	string str = name;
	while (!fileinput.eof())
	{
		Employee* p = new Employee;
		count++;
		getline(fileinput, line);
		if (count != 1)
		{
			string epl = line;
			istringstream stm(epl);
			string token;
			getline(stm, token, ',');
			string id = token;
			getline(stm, token, ',');
			if (token == str)
			{
				p->setid(id);
				p->setName(name);
				getline(stm, token, ',');
				p->setbirth(token, count);
				getline(stm, token, ',');
				p->setadr(token, count);
				getline(stm, token, ',');
				p->setteam(token, count);
				getline(stm, token, ',');
				file.getdatefile(p);
				string name = "Search by name\\" + p->getname() + "||" + p->getid(); +".txt";
				int n = p->getcheck();
				file.setFile(name);
				file.InALL(*p, n);
				DEM++;
			}
		}
	}
	if (DEM == 0)cout << "===> Khong co ten nhan vien can tim <===" << endl;
}
void search::Searchall() //alll
{
	int count = 0;
	string line;
	ifstream fileinput(this->file, ios::in);
	while (!fileinput.eof())
	{
		Other a; 
		Employee* p = new Employee;
		count++;
		getline(fileinput, line);
		if (count != 1)
		{
			string epl = line;
			istringstream stm(epl);
			string token;
			getline(stm, token, ',');

			p->setid(token);
			getline(stm, token, ',');
			p->setName(token);
			getline(stm, token, ',');
			p->setbirth(token, count);
			getline(stm, token, ',');
			p->setadr(token, count);
			getline(stm, token, ',');
			p->setteam(token, count);
			getline(stm, token, ',');
			a.getdatefile(p);
			string name =  "Search all\\"  + p->getname() + ".txt";
			int n = p->getcheck();
			a.setFile(name);
			a.InALL(*p, n);
		}
	}
	
}
void search::Searchteam(string team)
{
	Other a;
	int DEM = 0 ,count = 1;			// Dem so dong
	Employee* p = new Employee;
	string line;
	ifstream fileinput(this->file, ios::in);
	string str = team;
	while (!fileinput.eof())
	{
		count++;
		getline(fileinput, line);
		string epl = line;
		istringstream stm(epl);
		string token;
		getline(stm, token, ',');
		string id = token;
		getline(stm, token, ',');
		string name = token;
		getline(stm, token, ',');
		string birth = token;
		getline(stm, token, ',');
		string add = token;
		getline(stm, token, ',');
		if (token == str)
		{
			p->setid(id);
			p->setName(name);
			p->setbirth(birth, count);
			p->setadr(add, count);
			p->setteam(token, count);
			getline(stm, token, ',');
			a.getdatefile(p);
			string ssl  ="Search by team\\" + team + "\\" + p->getname() + ".txt";
			int n = p->getcheck();
			a.setFile(ssl);
			a.InALL(*p, n);
			DEM++;
		}
	}
	if (DEM == 0)cout << "===> Khong co bo phan ma ban can tim <===" << endl;
}
void Other::setFile(string file)
{
	this->file = file;
}
void Other::History(Employee a, int i)		//  luu vao File history.txt;
{
	ofstream output("history.txt", ios::app);
	output << "Ma NV: " << a.getid() << " Ho va Ten: " << a.getname() << " || Diem danh: " << a.getddall(i) << "|| " << UTC();
	if (i == 0)
	{
		output << ": UTC " << endl;
	}else output << ": Admin" << endl ;
	cout << "Da duoc diem danh: ";
	a.getdd(i);
	cout << " ||  " << UTC();
	if (i == 0)cout << ": UTC " << endl;
	else cout << ": Admin" << endl; 
}
void Other::Printfdd(Employee p,int n )
{
	ofstream myfile(this->file, ios::app);
	myfile << p.getid() << ',' << n;
	if (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			myfile << ',' << p.getddall(i);
		}
		myfile << endl;
		return;
	}
	if (n == 0)myfile << endl;
}
void Other::Printfddup(Employee p, int n)
{
	ofstream myfile(this->file, ios::app,ios::in);
	myfile << p.getid() << ',' << n;
	if (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			myfile << ',' << p.getddall(i);
		}
		myfile << endl;
		return;
	}
	if (n == 0)myfile << endl;
}
void Other::Printfcvs(Employee p,int n = 0)
{
	ofstream myfile(this->file, ios::app);
	myfile << p.getid() << ',' << p.getname() << ',' << p.getbirth() << ',' << p.getadress() << ',' << p.getteam() << ',' << n;
	if (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			myfile << ',' << p.getddall(i);
		}
		myfile << endl; 
		return; 
	}
	if (n == 0)myfile << endl;
}
void Other::InALL(Employee p, int n)
{
	ofstream myfile(this->file, ios::app| ios::in);
	myfile << "Ma NV: " << p.getid() << endl;
	myfile << "Ten NV: " << p.getname() << endl;
	myfile << "Ngay thang nam sinh: " << p.getbirth() << endl;
	myfile << "Dia chi: " << p.getadress() << endl;
	myfile << "Bo phan cong tac: " << p.getteam() << endl;
	if (p.getcheck() == 0)
	{
		myfile << "Khong co du lieu diem danh cua nhan vien" << endl;
	}
	else
	{
		myfile << "=================Thong Ke Diem danh=================" << endl;
		int n = p.getcheck();
		for (int i = 0; i < n; i++)
		{
			myfile << p.getddstring(i);
		}
	}
}
void Other::autoFile()
{
	int count = 0;
	string line; 
	ifstream fileinput(this->file, ios::in);
	while (!fileinput.eof())
	{
		Employee* p = new Employee;
		count++;
		
			getline(fileinput, line);
			if (count != 1)
			{
				string epl = line;
				istringstream stm(epl);
				string token;
				getline(stm, token, ',');
				if (token != "")
				{
					p->setid(token);
					getline(stm, token, ',');
					getline(stm, token, ',');
					getline(stm, token, ',');
					getline(stm, token, ',');
					getline(stm, token, ',');
					stringstream ss(token);
					int n;
					ss >> n;
					if (n == 0)
					{
						p->setcheck(n);
					}
					else
					{
						p->setcheck(n);
						for (int i = 0; i < n; i++)
						{
							getline(stm, token, ':');
							string tok = token;
							getline(stm, token, ',');
							p->diemdanh(i, tok, token);
						}
					}
					Other a;
					a.setFile("Diemdanh.txt");
					a.Printfdd(*p);
				}
			}
		
	}
}
void Other::autoFileup()
{
	int count = 0;
	string line;
	ifstream fileinput(this->file, ios::in);
	while (!fileinput.eof())
	{
		Employee* p = new Employee;
		count++;

		getline(fileinput, line);
		if (count != 1)
		{
			string epl = line;
			istringstream stm(epl);
			string token;
			getline(stm, token, ',');

			p->setid(token);
			getline(stm, token, ',');
			getline(stm, token, ',');
			getline(stm, token, ',');
			getline(stm, token, ',');
			getline(stm, token, ',');
			stringstream ss(token);
			int n;
			ss >> n;
			if (n == 0)
			{
				p->setcheck(n);
			}
			else
			{
				p->setcheck(n);
				for (int i = 0; i < n; i++)
				{
					getline(stm, token, ':');
					string tok = token;
					getline(stm, token, ',');
					p->diemdanh(i, tok, token);
				}
			}
			Other a;
			a.setFile("Diemdanh.txt");
			a.Printfddup(*p);
		}

	}
}
string  UTC()
{
	
		time_t now = time(0);
		tm ltm;
		errno_t result = localtime_s(&ltm, &now);
		stringstream ss;
		ss << ltm.tm_mday  << '/' << ltm.tm_mon +1<< '/' << ltm.tm_year + 1900 << " Time:  " << 1 + ltm.tm_hour << ':' << 1 + ltm.tm_min << ':' << 1 +ltm.tm_sec;
		string date = ss.str();
		return date;
}
 int Diemdanh::checkdate( string id, string date,string *TT)
{
	 /*
		Kiem tra xem date da duoc dinh danh chua ;
	 */
	string line,file = "Diemdanh.txt";
	ifstream myfile(file, ios::in);
	while (!myfile.eof())
	{
		getline(myfile, line);
		string token,ep1 = line;
		istringstream stm(ep1);
		getline(stm, token, ',');
		if (token == id)
		{
			int n;
			getline(stm, token, ',');
			stringstream ss(token);
			ss >> n;
			if (n != 0)
			{
				for (int i = 0; i < n; i++)
				{
					getline(stm, token, ':');
					string tok = token;
					getline(stm, token, ',');
					*TT = token;
					if (tok == date)return 0;
				}
			}
		}
	}
	return 1; 
}
 void Other::getdatefile(Employee *p)
 {

	 string id = p->getid();
	 string line, file = "Diemdanh.txt";
	 ifstream myfile(file, ios::in);
	 while (!myfile.eof())
	 {
		 getline(myfile, line);
		 string token, ep1 = line;
		 istringstream stm(ep1);
		 getline(stm, token, ',');
		 if (token == id)
		 {
			 int n;
			 getline(stm, token, ',');
			 stringstream ss(token);
			 ss >> n;
			 if (n == 0)
			 {
				 p->setcheck(n);
			 }
			 else
			 {
				 p->setcheck(n);
				 for (int i = 0; i < n; i++)
				 {
					 getline(stm, token, ':');
					 string tok = token;
					 getline(stm, token, ',');
					 p->diemdanh(i, tok, token);
				 }
			 }
		 }
	 }
 }
