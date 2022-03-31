#include<iostream.h>
class soPhuc
{
	private:
	int phanthuc,phanao;
	public:
	void nhap()
	{
		cout<<"\nNhap vao phan thuc :";cin>>phanthuc;
		cout<<"\nNhap vao phan ao :";cin>>phanao;
	}
	void xuat()
	{
		cout<<"\nA = "<<phanthuc <<" + "<<phanao<<" *j"<<endl;
	}
	
	int getphanthuc()
	{
		return phanthuc;
	}
	
	int getphanao()
	{
		return phanao;
	}
};
int main()
{
	soPhuc sp[2];
	for(int i=0;i<2;i++)
	{
		cout<<"\nNHAP VAO SO PHUC THU "<<i+1<<":";
		sp[i].nhap();
	}
	cout<<"\nTONG CUA 2 SO PHUC LA :"<<sp[0].getphanthuc() + sp[1].getphanthuc() <<" + "<<sp[0].getphanao() + sp[1].getphanao() <<" *j"<<endl;
	cout<<"\nHIEU CUA 2 SO PHUC LA :"<<sp[0].getphanthuc() - sp[1].getphanthuc() <<" + "<<"("<<sp[0].getphanao() - sp[1].getphanao()<<")" <<" *j"<<endl;
	cout<<"\nTICH CUA 2 SO PHUC LA :"<<sp[0].getphanthuc() * sp[1].getphanthuc() <<" + "<<sp[0].getphanao() * sp[1].getphanao() <<" *j"<<endl;
//	cout<<"\nTHUONG CUA 2 SO PHUC LA :"<<sp[0].getphanthuc() - sp[1].getphanthuc() <<" - "<<sp[0].getphanao() - sp[1].getphanao() <<" *j"<<endl;
	
}