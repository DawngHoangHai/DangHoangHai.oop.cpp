#include<iostream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;
struct date
{
	int ngay,thang,nam;
};
class KHACHHANG
{
	private:
		char hoten[30];
		date ngaysinh;
		char socm[10];
		char hokhau[50];
	public:
		friend istream &operator >> (istream &is ,KHACHHANG &kh)
		{
			fflush(stdin);
			cout<<"\n\t - Nhap vao hoten :";is.getline(kh.hoten,30);
			cout<<"\n\t - Nhap vao ngay sinh :";is>>kh.ngaysinh.ngay;
			cout<<"\n\t - Nhap vao thang sinh :";is>>kh.ngaysinh.thang;
			cout<<"\n\t - Nhap vao nam sinh :";is>>kh.ngaysinh.nam;
			fflush(stdin);
			cout<<"\n\t - Nhap vao so chung minh :";is.getline(kh.socm,10);
			cout<<"\n\t - Nhap vao ho khau :";is.getline(kh.hokhau,50);
			return is;
		}
		
	
		char * gethokhau()
		{
			return hokhau;
		}
		int gettuoi()
		{
			return (2022 - ngaysinh.nam);
		}
		friend ostream &operator << (ostream &os ,KHACHHANG & kh)
		{
			os<<setw(20)<<kh.hoten
			<<setw(15)<<kh.ngaysinh.ngay
			<<setw(1)<<"-"
			<<setw(2)<<kh.ngaysinh.thang
			<<setw(1)<<"-"
			<<setw(2)<<kh.ngaysinh.nam
			<<setw(15)<<kh.socm
			<<setw(20)<<kh.hokhau
			<<setw(15)<<kh.gettuoi()<<endl;
			return os;
		}
		
};
void nhap(KHACHHANG kh[] ,int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n - Nhap vao khach hang thu ["<<i+1<<"] :\n";
		cin>>kh[i];
	}
}

void xuat(KHACHHANG kh[] ,int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<kh[i];
	}
}
void tim(KHACHHANG kh[],int &n)
{
	cout<<"\n DANH SACH KHACH HANG HO KHAU O HA NOI LA \n";
	for(int i=0;i<n;i++)
	{
		if(strcmpi(kh[i].gethokhau() ,"HA NOI")==0)
		{
			cout<<kh[i];
		}
	}
}
void sapxep(KHACHHANG kh[],int &n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(kh[i].gettuoi() < kh[j].gettuoi())
			{
				KHACHHANG tmg =kh[i];
				kh[i] = kh[j];
				kh[j] = tmg;
			}
		}
	}
	cout<<"\n DANH SACH SAP XEP GIAM DAN THEO TUOI LA \n";
	xuat(kh,n);
}
int main()
{
	int n;
	cout<<"\nNhap vao so luong khach hang :";cin>>n;
	KHACHHANG *kh = new KHACHHANG[n];
	nhap(kh,n);
	tim(kh,n);
	sapxep(kh,n);
}