#include<iostream.h>
using namespace std;
int main()
{
	int thu;
	cout << " Nhap vao thu trong tuan : ";
	cin >> thu;
	switch(thu)
	{
		case 1: 
			cout << " 1.Sunday !!! \n";
			break;
		case 2: 
			cout << " 2.Monday !!! \n";
			break;
		case 3: 
			cout << " 3.Tuesday !!! \n";
			break;
		case 4: 
			cout << " 4.Wednesday !!! \n";
			break;
		case 5: 
			cout << " 5.Thursday !!! \n";
			break;
		case 6: 
			cout << " 6.Friday !!! \n";
			break;
		case 7: 
			cout << " 7.Saturday !!! \n";
			break;
		default: 
			cout << " thu khong hop le -- Moi ban nhap la !!! \n";
			break;
	}
	return 0;
}



