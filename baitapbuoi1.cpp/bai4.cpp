#include<iostream.h>
#include<iomanip.h>
using namespace std;
int main()
{
	int n; 
	cout << " Nhap so dong : ";
	cin >> n;
	for(int i=n; i>=1; i--)
	{
		cout << setw(5);
		for (int j=1; j<=i; j++)
		{
	     	cout << "*";
		}
	cout << endl;
	}
	return 0;
}