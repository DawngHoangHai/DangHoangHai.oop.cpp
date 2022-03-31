#include<iostream.h>
using namespace std;
int main()
{
	int n;
	int tongtien = 1;
	cout << " Nhap so KW dien tieu thu : ";
	cin >> n;
	if (n >= 0 && n <= 100)
	{
		tongtien = n*2000;
	}
	else if (n >= 101 && n <= 200)
	{
		tongtien = n*2500;
	}
	else if (n >= 201 && n <= 300)
	{
		tongtien = n*3000;
	}
	else
	{
		tongtien = n*5000;
	}
	cout << " --->Tong so tien dien la : "<< tongtien << endl;
	return 0;
}