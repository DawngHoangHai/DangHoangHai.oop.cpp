#include<iostream.h>
#include<iomanip.h>
#include<string.h>
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
	char hokhau[20];
	public:
	void nhap()
	{
		fflush(stdin);
		cout<<"\n\t - Nhap vao ho ten :";cin.getline(hoten,30);
		cout<<"\n\t - Nhap vao ngay sinh :";cin>>ngaysinh.ngay;
		cout<<"\n\t - Nhap vao thang sinh :";cin>>ngaysinh.thang;
		cout<<"\n\t - Nhap vao nam sinh :";cin>>ngaysinh.nam;
		fflush(stdin);
		cout<<"\n\t - Nhap vao so cm :";cin.getline(socm,10);
		cout<<"\n\t - Nhap vao ho khau :";cin.getline(hokhau,20);
		
	}
	void xuat()
	{
		cout<<"\n\tHO TEN :"<<hoten<<"\tNGAY SINH :"
		<<ngaysinh.ngay<<setw(1)<<"/"
		<<setw(2)<<ngaysinh.thang<<setw(1)<<"/"
		<<setw(2)<<ngaysinh.nam
		<<"\t SO CM :"<<socm<<"\t HO KHAU :"<<hokhau<<endl;
	}
	char * gethoten()
	{
		return hoten;
	}
	int getthang()
	{
		return ngaysinh.thang;
	}
	
};
void nhap_khachhang(KHACHHANG kh[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap vao khach hang thu ["<<i+1<<"] :\n";
		kh[i].nhap();
	}
}

void xuat_khachhang(KHACHHANG kh[],int &n)
{
	
	for(int i=0;i<n;i++)
	{
		kh[i].xuat();
	}
}
void sapxep(KHACHHANG kh[],int &n)
{
	cout<<"\n DANH SACH SAP XEP TANG THEO TEN LA \n";
	for (int i=0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(strcmpi(kh[i].gethoten(),kh[j].gethoten())>0)
			{
				KHACHHANG tg = kh[i];
				kh[i] = kh[j];
				kh[j] = tg;
			}	
		}
		kh[i].xuat();
	}
}
void timkiem(KHACHHANG kh[],int &n)
{
	cout<<"\n DANH SACH KHACH HANG SINH NHAT THANG 12 LA \n";
	for(int i=0;i<n;i++)
	{
		if(kh[i].getthang() == 12)
		{
			kh[i].xuat();
		}
	}
}
int main()
{
	int n;
	
	KHACHHANG kh[20],a;
	//a.nhap();
	//a.xuat();
	cout<<"\nNhap vao so khach hang la :";cin>>n;
	nhap_khachhang(kh,n);
	cout<<"\n DANH SACH VUA NHAP VAO LA \n";
	xuat_khachhang(kh,n);
	sapxep(kh,n);
	timkiem(kh,n);
	
	
}