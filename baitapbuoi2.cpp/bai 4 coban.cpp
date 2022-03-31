#include<iostream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;
struct HANGHOA
{
	char ma[8],tenhang[30];
	int soluong;
	float dongia;
	long long double thanhtien;
	
};
void nhap(HANGHOA hh[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n - NHAP VAO HANG HOA THU ["<<i+1<<"] :\n";
		fflush(stdin);
		cout<<"\n\t - Nhap vao ma hang hoa :";cin.getline(hh[i].ma,8);
		cout<<"\n\t - Nhap vao ten hang hoa :";cin.getline(hh[i].tenhang,30);
		cout<<"\n\t - Nhap vao so luong hang hoa :";cin>>hh[i].soluong;
		cout<<"\n\t - Nhap vao don gia hang hoa :";cin>>hh[i].dongia;
		hh[i].thanhtien = (hh[i].soluong * hh[i].dongia );
	}
	
}
void note()
{
	cout<<"\n+-------------------------------------------------------------------------------------------------+\n";
	cout<<setw(15)<<"MA"
		<<setw(20)<<"TEN HANG"
		<<setw(15)<<"SO LUONG"
		<<setw(20)<<"DON GIA"
		<<setw(20)<<"THANH TIEN";
	cout<<"\n+-------------------------------------------------------------------------------------------------+\n";

}
void xuat(HANGHOA hh[],int&n)
{
	note();
	for(int i=0;i<n;i++)
	{
		cout<<setw(15)<<hh[i].ma
		<<setw(20)<<hh[i].tenhang
		<<setw(15)<<hh[i].soluong
		<<setw(20)<<hh[i].dongia
		<<setw(20)<<hh[i].thanhtien<<endl;
	}
}
void tim(HANGHOA hh[],int &n)
{
	bool k_t = false;
	cout<<"\n\2 DANH SACH DON GIA  < 50000 LA \2\n";
	note();
	for(int i=0;i<n;i++)
	{
		if(hh[i].dongia <= 50000)
		{
			k_t = true;
			cout<<setw(15)<<hh[i].ma
			<<setw(20)<<hh[i].tenhang
			<<setw(15)<<hh[i].soluong
			<<setw(20)<<hh[i].dongia
			<<setw(20)<<hh[i].thanhtien<<endl;
		}
	}
	if(k_t == false)
	{
		cout<<"\n-->> DANH SACH KHONG CO DON GIA NAO < 50000\2\2 \n";
	}
}
int main()
{
	int n;
	cout<<"\n - NHAP VAO SO LUONG NHAN VIEN :";cin>>n;
	HANGHOA *hh = new HANGHOA[n];
	nhap(hh,n);
	system("cls");
	cout<<"\n\2 DANH SACH VUA NHAP VAO LA \2\n";
	xuat(hh,n);
	tim(hh,n);
}