#include"nhanvien.h";
using namespace std;
int main()
{
	
	int n = 0;
	char y = 'c';
	Menu a;
	do
	{
		a.menu();
		cout << "Xin moi chon " << endl;
		cin >> n;
		cin.ignore();
		switch (n)
		{
		case 1:a.CASE1(); break;
		case 2: a.CASE2(); break;
		case 3: a.CASE3(); break;
		case 4: a.CASE4(); break;
		case 5: a.CASE5(); break;
		case 6: a.CASE6(); break;
		case 7:a.CASE7(); break;
		default:
			cout << "Khong hop le, moi nhan C de tiep tuc" << endl;
			putchar(y);
			break;
		}
	} while (n == 1 || n == 2 || y == 'c' || n == 3 || n == 4 || n == 5 || n == 6 || n == 7);

}