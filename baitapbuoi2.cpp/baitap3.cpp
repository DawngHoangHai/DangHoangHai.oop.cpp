#include<iostream.h>
#include<string.h>
using namespace std;
class daThuc
{
	public:
		int a,b,c,d;
	public :
		daThuc(int a = 0,int b = 0,int c = 0,int d = 0)
		{
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
		}
		~daThuc(){}
		void nhap()
		{
			cout<<"\n\t - Nhap vao bac 3 :";cin>>a;
			cout<<"\n\t - Nhap vao bac 2 :";cin>>b;
			cout<<"\n\t - Nhap vao bac 1 :";cin>>c;
			cout<<"\n\t - Nhap vao bac 0 :";cin>>d;
		}
		 void xuat()
		 {
 			cout<<"\t"<<a<<"x3 +"<<b<<"x2 +"<<c<<"x +"<<d<<endl;	
 			}
			
};
int main()
{
	
	daThuc dt[2];
	for(int i=0;i<2;i++)
	{
		cout<<"\nNHAP VAO DA THUC "<<i+1<<" :\n";
		dt[i].nhap();
	}
	cout<<"\n TONG 2 DA THUC LA :\t";
	cout<<"("<<dt[0].a + dt[1].a <<"x3 ) + "<<"("<<dt[0].b + dt[1].b<<"x2 ) + "<<"("<<dt[0].c + dt[1].c<<"x ) + "<<"("<<dt[0].d + dt[1].d<<") = 0 "<<endl;
	
}