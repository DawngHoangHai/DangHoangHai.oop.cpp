#include<iostream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;
class giaoVien
{
	private:
	char hoteen[30];
	int tuoi;
	char bangcap[20],chuyennganh[20];
	float bacluong;
	public:
	friend istream &operator >> (istream &is,giaoVien &gv)
	{
		fflush(stdin);
		cout<<"\n\t - Nhap ho ten :";is.getline(gv.hoteen,30);
		cout<<"\n\t - Nhap vao so tuoi :";is>>gv.tuoi;
		fflush(stdin);
		cout<<"\n\t - Nhap vao bang cap :";is.getline(gv.bangcap,20);
		cout<<"\n\t - Nhap vao chuyen nganh :";is.getline(gv.chuyennganh,20);
		cout<<"\n\t - Nhap vao bac luong :";is>>gv.bacluong;
		return is;
	}
	float tienluong()
	{
		return bacluong * 610;
		
	} 
	friend ostream operator << (ostream &os,giaoVien &gv)
	{
		os<<setw(20)<<gv.hoteen
		<<setw(15)<<gv.tuoi
		<<setw(20)<<gv.bangcap
		<<setw(20)<<gv.chuyennganh
		<<setw(15)<<gv.bacluong
		<<setw(15)<<gv.tienluong()<<endl;
	}
	char * getchuyennganh()
	{
		return chuyennganh;
	}
};
void note()
{
	cout<<"\n+--------------------------------------------------------------------------------------------------------------------------------------------+\n";
	cout<<setw(20)<<"HO TEN"
		<<setw(15)<<"TUOI"
		<<setw(20)<<"BANG CAP"
		<<setw(20)<<"CHUYEN NGANH"
		<<setw(15)<<"BAC LUONG"
		<<setw(15)<<"TIEN LUONG";
	cout<<"\n+--------------------------------------------------------------------------------------------------------------------------------------------+\n";
	
}
void sapxep(giaoVien gv[],int &n)
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmpi(gv[i].getchuyennganh(),gv[j].getchuyennganh())>0)
			{
				giaoVien tg = gv[i];
				gv[i] = gv[j];
				gv[j] = tg;
			}
		}
	}
	cout<<"\n DANH SACH SAP XEP TANG DAN THEO CHUYEN NGANH LA \n";
	note();
	for(int i=0;i<n;i++)
	{
		cout<<gv[i];
	}
}
int main()
{
	int n;
	cout<<"\n Nhap vao so luong giao vien :";cin>>n;
	giaoVien *gv = new giaoVien[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\n- Nhap vao giao vien  thu ["<<i+1<<"] :\n";
		cin>>gv[i];
	}
	
	sapxep(gv,n);
}