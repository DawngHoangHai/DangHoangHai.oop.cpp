#include <iostream.h>
#include<string.h>
#include<iomanip.h>
#include<string>
using namespace std;
class anPham
{
	protected:
		string ten;
		float giathanh;
	public:
	virtual	void nhap()
		{
			fflush(stdin);
			cout<<"\n\t - Nhap vao ten :";getline(cin,ten);
			cout<<"\n\t - Nhap vao gia thanh :";cin>>giathanh;
		}
	virtual	void xuat()
		{
			cout<<setw(20)<<ten
				<<setw(15)<<giathanh<<" VND";
		}
	string getten()
	{
		return ten;
	}
};
class Sach : public anPham
{
	protected:
		int sotrang;
	public:
	virtual	void nhap()
		{
			anPham::nhap();
			cout<<"\n\t - Nhap so trang :";cin>>sotrang;
		}
	virtual	void xuat()
		{
			anPham::xuat();
			cout<<setw(13)<<sotrang<<" TRANG"<<endl;;	
		}
	int getsotrang()
	{
		return sotrang;
	}
};
class dia_CD : public anPham
{
	protected:
		float sophut;
	public:
	virtual	void nhap()
		{
			anPham::nhap();
			cout<<"\n\t - Nhap vao so phut :";cin>>sophut;
		}
	virtual void xuat()
		{
			anPham::xuat();
			cout<<setw(13)<<sophut<<" phut"<<endl;
		}
};

int main(int argc, char *argv[])
{
	int n,luachon;	
	while(1)
	{
		cout<<"\n 1.SACH , 2.DIA CD , 3.EXIT \n";
		cout<<"\nNhap vao lua chon :";cin>>luachon;
		if(luachon == 1)
		{
			cout<<"\nNhap vao so quan sach :";cin>>n;
			Sach *a = new Sach[n];
			for(int i=0;i<n;i++)
			{
				cout<<"\n - So sach thu ["<<i+1<<"] : \n";
				a[i].nhap();
			}
			cout<<"\n DANH SACH QUAN SACH VUA NHAP VAO LA \n";
			for(int i=0;i<n;i++)
			{
				a[i].xuat();
			}
			cout<<"\n QUAN SACH HON 500 TRANG LA \n";
			for(int i=0;i<n;i++)
			{
				if(a[i].getsotrang() > 500)
				{
					a[i].xuat();
				}
			}
		}
		if(luachon == 2)
		{
			cout<<"\nNhap vao so dia CD :";cin>>n;
			dia_CD *a = new dia_CD[n];
			for(int i=0;i<n;i++)
			{
				cout<<"\n - So dia CD thu ["<<i+1<<"] : \n";
				a[i].nhap();
			}
			cout<<"\n DANH SACH DIA CD VUA NHAP VAO LA \n";
			for(int i=0;i<n;i++)
			{
				a[i].xuat();
			}
			
		}
		if(luachon == 3)
		{
			cout<<"\nBAN DUNG ";
			break;
		}
	}
	
	return 0;
}