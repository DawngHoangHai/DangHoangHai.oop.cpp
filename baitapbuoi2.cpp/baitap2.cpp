#include<iostream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;
class GIAOVIEN
{
	private:
		char hoten[30];
		int tuoi;
		char bangcap[20],chuyennganh[20];
		float bacluong;
	public:
		void nhap()
		{
			fflush(stdin);
			cout<<"\n\t - Nhap vao ho ten :";cin.getline(hoten,30);
			cout<<"\n\t - Nhap vao tuoi :";cin>>tuoi;
			fflush(stdin);
			cout<<"\n\t - Nhap vao bang cap :";cin.getline(bangcap,20);
			cout<<"\n\t - Nhap vao chuyen nganh :";cin.getline(chuyennganh,20);
			cout<<"\n\t - Nhap vao bac luong :";cin>>bacluong;
			
		}
		float tinhtien()
		{
			return bacluong * 610;
			
		}
		void xuat()
		{
			cout<<"\n\t HO TEN :"<<hoten<<" TUOI :"<<tuoi
			<<" BANG CAP :"<<bangcap<<" CHUYEN NGANH :"<<chuyennganh
			<<" BACLUONG :"<<bacluong<<" TIEN LUONG :"<<tinhtien()<<endl;
		}
		char * getchuyennganh()
		{
			return chuyennganh;
		}
};
int main()
{
	int n;
	cout<<"\n Nhap vao so luong giao vien :";cin>>n;
	GIAOVIEN gv[50];
	for(int i=0;i<n;i++)
	{
		cout<<"\n NHAP VAO giao vien thu "<<i+1<<" la :\n";
		gv[i].nhap();
	}
	cout<<"\n DANH SACH VUA NHAP VAO LA \n";
	for(int i=0;i<n;i++)
	{
		gv[i].xuat();
	}
	cout<<"\n DANH SACH GIAO VIEN TIEN LUONG < 2000 LA \n";
	for(int i=0;i<n;i++)
	{
		if(gv[i].tinhtien() < 2000)
		{
			gv[i].xuat();
		}
	}
	cout<<"\n DANH SACH SAP XEP THEO CHUYEN NGANH \n";
	for (int i=0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(strcmpi(gv[i].getchuyennganh(),gv[j].getchuyennganh())>0)
			{
				GIAOVIEN tg = gv[i];
				gv[i] = gv[j];
				gv[j] = tg;
			}	
		}
		gv[i].xuat();
	}
	
}
