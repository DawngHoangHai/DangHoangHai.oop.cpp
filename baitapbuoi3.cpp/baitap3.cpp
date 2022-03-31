#include<iostream.h>
#include<string.h>
using namespace std;
class DATHUC
{
	public:
		int bac3,bac2,bac1,bac0;
	public:
		DATHUC(int a =0,int b = 0,int c = 0,int d = 0)
		{
			this->bac3 = a;
			this->bac2 = b;
			this->bac1 = c;
			this->bac0 = d;
		}
		~DATHUC(){}
		
		void nhap()
		{
			cout<<"\n\t - NHap vao bac 3 = ";cin>>bac3;
			cout<<"\n\t - NHap vao bac 2 = ";cin>>bac2;
			cout<<"\n\t - NHap vao bac 1 = ";cin>>bac1;
			cout<<"\n\t - NHap vao bac 0 = ";cin>>bac0;
			
		}
};
int main()
{
	DATHUC dt[2];
	for(int i=0;i<2;i++)
	{
		cout<<"\n - NHap vao da  thuc thu "<<i+1<<":\n";
		dt[i].nhap();
	}
	cout<<"\n TONG 2 DA THUC LA :\t";
	cout<<"("<<dt[0].bac3 + dt[1].bac3 <<"x3 ) + "<<"("<<dt[0].bac2 + dt[1].bac2<<"x2 ) + "<<"("<<dt[0].bac1 + dt[1].bac1<<"x ) + "<<"("<<dt[0].bac0 + dt[1].bac0<<") = 0 "<<endl;
	cout<<"\n HIEU 2 DA THUC LA :\t";
	cout<<"("<<dt[0].bac3 - dt[1].bac3 <<"x3 ) + "<<"("<<dt[0].bac2 - dt[1].bac2<<"x2 ) + "<<"("<<dt[0].bac1 - dt[1].bac1<<"x ) + "<<"("<<dt[0].bac0 - dt[1].bac0<<") = 0 "<<endl;
	
}