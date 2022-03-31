#include<iostream.h>
#include<iomanip.h>
#include<string.h>
void nhap_mang(int a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n - NHAP VAO VI TRI THU ["<<i+1<<"]:";
		cin>>a[i];
	}
}

void xuat_mang(int a[],int &n)
{
	cout<<"\n DANH SACH MANG VUA NHAP LA :\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];
	}
	cout<<endl;
}
void in_nguoc(int a[],int &n)
{
	cout<<"\n DANH SACH VUA NHAP NHUNG NGUOC LAI LA :\n";
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int tg = a[i];
			a[i] = a[j];
			a[j] = tg;
		}
		cout<<"\t"<<a[i];
	}
}
void tim_kiem(int a[],int&n)
{
	int s,dem =0;
	cout<<"\n - Nhap vao so nguyen de kiem tra :";cin>>s;
	cout<<"\n SO VUA TIM KIEM LA :\n";
	for(int i=0;i<n;i++)
	{
		if(a[i]  == s)
		{
			cout<<"\t"<<a[i];
			dem++;
		}
	}
	if(dem ==0)
	{
		cout<<"\n \2SO VUA NHAP K CO TRONG MANG\2 \n";
	}
}
void sap_xep_tang(int a[],int &n)
{
	cout<<"\n DANH SACH TANG DAN LA :\n";
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i] > a[j])
			{
				int tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
		cout<<"\t"<<a[i];
	}
	
}
int main()
{
	int n;
	cout<<"\n - NHAP VAO SO MANG :";cin>>n;
	int a[50];
	nhap_mang(a,n);
	xuat_mang(a,n);
	in_nguoc(a,n);
	tim_kiem(a,n);
	sap_xep_tang(a,n);
}