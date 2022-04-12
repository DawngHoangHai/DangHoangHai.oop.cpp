#include<iostream>
#include<string>
#include<iomanip>
//#include<string.h>
using namespace std;
class NGUOI
{
	protected:
	string hoten;
	int namsinh;
	public:
		void nhap()
		{
			fflush(stdin);
			cout<<"\n\t - Nhap vao ho ten :";getline(cin,hoten);
			cout<<"\n\t - Nhap vao nam sinh :";cin>>namsinh;
		}
		void xuat()
		{
			cout<<setw(20)<<hoten
			<<setw(15)<<namsinh;
		}
	
};
class THISINH : public NGUOI 
{
	protected:
		long sobaodanh;
		float dt,dl,dh;
	public:
		void nhap()
		{
			NGUOI::nhap();
			cout<<"\n\t - NHap vao so bao danh :";cin>>sobaodanh;
			cout<<"\n\t - Nhap vao diem toan :";cin>>dt;
			cout<<"\n\t - Nhap vao diem ly :";cin>>dl;
			cout<<"\n\t - Nhap vao diem hoa :";cin>>dh;
		}
		long double tongdiem()
		{
			return (dt+dl+dh)/3;
		}
		void xuat()
		{
			NGUOI::xuat();
			cout<<setw(20)<<sobaodanh
			<<setw(15)<<dt
			<<setw(15)<<dl
			<<setw(15)<<dh
			<<setw(15)<<tongdiem();
			cout<<"\n+-------------------------------------------------------------------------------------------------------------------------------+\n";
		}
		 long getsobaodanh()
		 {
 			return sobaodanh;
 		}
		
};
void nhap_mang(THISINH ts[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n - Nhap vao thi sinh thu ["<<i+1<<"] :\n";
		ts[i].nhap();
	}
}
void tieude()
{
	cout<<"\n+-------------------------------------------------------------------------------------------------------------------------------+\n";
	cout<<setw(20)<<"HO TEN"
		<<setw(15)<<"NAM SINH"
		<<setw(20)<<"SO B DANH"
		<<setw(15)<<"DIEM TOAN"
		<<setw(15)<<"DIEM LY"
		<<setw(15)<<"DIEM HOA"
		<<setw(15)<<"TONG DIEM";
	cout<<"\n+-------------------------------------------------------------------------------------------------------------------------------+\n";

}
void xuat_mang(THISINH ts[],int &n)
{
	tieude();
	for(int i=0;i<n;i++)
	{
		ts[i].xuat();
	}
}
void tangdan(THISINH ts[],int &n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(ts[i].tongdiem() > ts[j].tongdiem())
			{
				THISINH tg = ts[i];
				ts[i] = ts[j];
				ts[j] = tg;
			}
		}
	}
	cout<<"\n\t\t DANH SACH SAP XEP TANG DAN THEO TONG DIEM \n";
	xuat_mang(ts,n);
}
void timkiem(THISINH ts[],int &n)
{
	nhapdulieu:
	long sobaodanhtk,dem=0;
	cout<<"\n - Nhap vao so bao danh de tim kiem :";cin>>sobaodanhtk;
	cout<<"\n\t\t THI SINH VUA TIM KIEM DK LA \n";
	tieude();
	for(int i=0;i<n;i++)
	{
		if(ts[i].getsobaodanh() == sobaodanhtk)
		{
			ts[i].xuat();
			dem ++;
		}
	}
	if(dem ==0)
	{
		cout<<"\n\t\t SO BAO DANH VUA NHAP K CO \n";
		cout<<"\t\t    \1\1Nhap lai di \1\1";
		goto nhapdulieu;
	}
}
int main()
{
	int n;
	cout<<"\n Nhap vao so luong thi sinh :";cin>>n;
	THISINH *ts = new THISINH[n];
	nhap_mang(ts,n);
	system("cls");
	tangdan(ts,n);
	timkiem(ts,n);
}