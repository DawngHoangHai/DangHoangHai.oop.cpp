#include<iostream.h>
using namespace std;

int main()
{
    int n; 
	int s = 1;
	cout << " Nhap n : ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
	    s = s * 2 * i;
	}
	cout<< " Tich 2 * 4 * 6 * ... *2n la : " << s << endl;
	return 0;
}