#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class sanPham
{
	protected:
		char masp[10];
		char tensp[20];
		float dongia;
	public:
	
	
		sanPham(char *masp = "",char * tensp ="",float dongia = 0)
		{
			strcpy(this->masp,tensp);
			strcpy(this->tensp,tensp);
			this->dongia = dongia;
		}
		~sanPham(){
			
		}
		
		
		void nhap()
		{
			fflush(stdin);
			cout<<"\n\t - Nhap vao ma sp :";cin.getline(masp,10);
			cout<<"\n\t - Nhap vao ten sp :";cin.getline(tensp,10);
			cout<<"\n\t - Nhap vao don gia :";cin>>dongia;
		}
		
		
		void xuat()
		{
			cout<<"\t\t|"
			<<setw(15)<<masp
			<<setw(20)<<tensp
			<<setw(15)<<dongia<<" VND";
		}
		
		char * getma()
		{
			return masp;
		}
		
		float getdongia()
		{
			return dongia;
		}
		char * getten()
		{
			return tensp;
		}
};
struct date
{
	int ngay,thang,nam;
};
class thuoc : public sanPham
{
	protected:
		char loaithuoc[20];
		date hsd;
		char thanhphan[20];
	public:
	
	
		thuoc(char *loaithuoc = "",int ngay = 0,int thang = 0,int nam = 0,char * thanhphan = "")
		:sanPham(masp,tensp,dongia)
		{
			strcpy(this->loaithuoc , loaithuoc);
			this->hsd.ngay = ngay;
			this->hsd.thang = thang;
			this->hsd.nam = nam;
			strcpy(this->thanhphan ,thanhphan );
		}
		
		~thuoc()
		{
			
		}
		
		
		friend istream &operator >> (istream & is,thuoc &a)
		{
			a.sanPham::nhap();
			cin.ignore();
			cout<<"\n\t - Nhap vao loai thuoc :";is.getline(a.loaithuoc,20);
			cout<<"\n\t - Nhap vao ngay sd :";is>>a.hsd.ngay;
			cout<<"\n\t - Nhap vao thang sd :";is>>a.hsd.thang;
			cout<<"\n\t - Nhap vao nam sd :";is>>a.hsd.nam;
			cin.ignore();
			cout<<"\n\t - Nhap vao thanh phan thuoc :";is.getline(a.thanhphan,20);
			return is;
		}
		
		
		float tinhgiasauthue()
		{
			return  getdongia() + (getdongia()* 0.1);
		}
		
		bool operator > (float &a)
		{
			return this->getdongia() > a;
		}
		
		friend ostream &operator <<(ostream &os,thuoc &a)
		{
			a.sanPham::xuat();
			os<<setw(20)<<a.loaithuoc
			<<setw(13)<<a.hsd.ngay
			<<setw(1)<<"/"
			<<setw(2)<<a.hsd.thang
			<<setw(1)<<"/"
			<<setw(2)<<a.hsd.nam
			<<setw(20)<<a.thanhphan
			<<setw(15)<<a.tinhgiasauthue()<<" VND"<<setw(4)<<"|";
			os<<"\n\t\t+-----------------------------------------------------------------------------------------------------------------------------------------+\n";
			return os;
		}
		
		char * getthanhphan()
		{
			return thanhphan;
		}
};
void haideptrai()
{
	cout<<"\n\t\t+-----------------------------------------------------------------------------------------------------------------------------------------+\n";
	cout<<"\t\t|"
			<<setw(15)<<"MA SP"
			<<setw(20)<<"TEN SP"
			<<setw(20)<<"GIA TRUOC"
			<<setw(20)<<"LOAI"
			<<setw(20)<<"HAN S D"
			<<setw(20)<<"THANH PHAN"
			<<setw(19)<<"GIA SAU"<<setw(4)<<"|";
	cout<<"\n\t\t+-----------------------------------------------------------------------------------------------------------------------------------------+\n";
}


void nhap_dulieu(thuoc a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n - Nhap vao thuoc ["<<i+1<<"] :\n";
		cin>>a[i];
	}
}

void xuat_dulieu(thuoc a[],int &n)
{
	haideptrai();
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}

void timma(thuoc a[],int &n)
{
	nhapdulieu:
	char matimkiem[10];
	cin.ignore();
	cout<<"\n - Nhap vao ma de tim kiem a :";cin.getline(matimkiem,10);
	cout<<"\n\t\t\t MA VUA TIM KIEM DK LA \n";
	haideptrai();
	int kt = 0;
	for(int i=0;i<n;i++)
	{
		if(strcmpi(a[i].getma(),matimkiem)==0)
		{
			cout<<a[i];
			kt  ++;
		}
	}
	if(kt  == 0)
	{
		cout<<"\n\t\t\t \2MA NHAP K CO TRONG MANG\2	\n ";
		goto nhapdulieu;
	}
}
void timthanhphan(thuoc a[],int &n)
{
	int kt = 0;
	cout<<"\n\t\t\t THANH PHAN PARACETAMOL TRONG DANH SACH \n";
	haideptrai();
	for(int i=0;i<n;i++)
	{
		if(strcmpi(a[i].getthanhphan(),"Paracetamol")==0)
		{
			cout<<a[i];
			kt ++;
		}
	}
	if(kt == 0)
	{
		cout<<"\n\t\t\t \2\2 DANH SACH K CO THANH PHAN PARACETAMOL \2\2 \n";
	}
}

void sapxep(thuoc a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((a[i].getdongia() >= 200000 && a[j].getdongia() >= 200000)
			&&(strcmpi(a[i].getten(),a[j].getten())==0))
			{
				thuoc trungcagian = a[i];
				a[i]  = a[j];
				a[j]  = trungcagian;
			}
		}
	}
	cout<<"\n\t\t DANH SACH DON GIA > 200.000 VA TANG DAN THEO TEN LA \n";
	xuat_dulieu(a,n);
}
int main()
{
	int n,luachon;;
	cout<<"\n Nhap vao so luong :";cin>>n;
	thuoc *a = new thuoc[n+1];
	nhap_dulieu(a,n);
	while(1)
	{
		cout<<"\n (1.xuat , 2.tim ma , 3.tim thanh phan paracetamol ,4 dem don gia 500.000 , 5.sap xep .6 exit) \n";
		cout<<"\nNhap vao lua chon :";cin>>luachon;
		while(luachon >6 || luachon <1 )
		{
			cout<<"\nNhap lai  lua chon di ban :";cin>>luachon;
		}
		if(luachon == 1)
		{
			system("cls");
			cout<<"\n\t\t\t DANH SACH VUA NHAP LA \n";
			xuat_dulieu(a,n);
		}
		if(luachon ==2)
		{
			system("cls");
			timma(a,n);
		}
		if(luachon ==3)
		{
			system("cls");
			timthanhphan(a,n);
		}
		if(luachon ==4)
		{
			system("cls");
			cout<<"\n CHUA LAM DUOC \n";
		}
		if(luachon ==5)
		{
			system("cls");
			sapxep(a,n);
		}
		if(luachon ==6 )
		{
			cout<<"\n KET THUC \n";
			break;
		}
	}	
}
