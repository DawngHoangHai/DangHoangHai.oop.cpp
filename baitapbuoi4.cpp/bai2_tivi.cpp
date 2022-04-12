#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
class sanPham
{
	protected:
		string masp;
		string tensanphan;
		int namsx;
	public:
		void nhap()
		{
			fflush(stdin);
			cout<<"\n - Nhap vao ma san pham :";getline(cin,masp);
			cout<<"\n - Nhap vao ten san pham :";getline(cin,tensanphan);
			cout<<"\n - Nhap vao nam san xuat :";cin>>namsx;
		}
		void xuat()
		{
			cout<<setw(20)<<masp
			<<setw(20)<<tensanphan
			<<setw(15)<<namsx;
		}
	
};
class tiVi : public sanPham
{
	protected:
		float chieudai,chieurong;
	public:
		void nhap()
		{
			sanPham::nhap();
			cout<<"\n - Nhap vao chieu dai tivi :";cin>>chieudai;
			cout<<"\n - Nhap vao chieu rong tivi :";cin>>chieurong;
		}
		float dientich()
		{
			return chieudai * chieurong;
		}
		void xuat()
		{
			sanPham::xuat();
			cout<<setw(15)<<chieudai<<" cm"
				<<setw(15)<<chieurong<<" cm"
				<<setw(15)<<dientich()<<" cm";
			cout<<"\n+------------------------------------------------------------------------------------------------------------------+\n";
		}
};
void nhap_tivi(tiVi a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n - Nhap vao TiVi thu ("<<i+1<<") :\n";
		a[i].nhap();
	}
}
void note()
{
	cout<<"\n+------------------------------------------------------------------------------------------------------------------+\n";
	cout<<setw(20)<<"MA SP"
			<<setw(20)<<"TEN SP"
			<<setw(15)<<"NAM SX"
			<<setw(18)<<"CHIEU DAI"
			<<setw(18)<<"CHIEU RONG"
			<<setw(18)<<"DIEN TICH";
	cout<<"\n+------------------------------------------------------------------------------------------------------------------+\n";

}
void xuat_tivi(tiVi a[],int &n)
{
	note();
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
}
void sapxep(tiVi a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(a[i].dientich() > a[j].dientich())
			{
				tiVi tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
	cout<<"\n\t\t DANH SACH SAP XEP TANG THEO DIEN TICH \n";
	xuat_tivi(a,n);
}
int main()
{
	int n;
	cout<<"\nNhap vao so luong san pham :";cin>>n;
	tiVi *sp = new tiVi[n];
	nhap_tivi(sp,n);
	system("cls");
	cout<<"\n\t\t DANH SACH	TI VI VUA NHAP LA \n";
	xuat_tivi(sp,n);
	sapxep(sp,n);
	return 0;
}