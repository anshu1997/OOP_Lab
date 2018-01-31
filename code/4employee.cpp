#include <bits/stdc++.h>
using namespace std;

class Emp{
protected:
int id;
double total_sales,pay;
public:
Emp(int i,double tot){
total_sales=tot;
id=i;
}
void calc(double comm){
	pay=comm*total_sales/100;
}
void print(){
cout<<"Employee with ID "<<id<<" has a salary of Rs."<<pay<<endl;
}
};


class derEmp:public Emp
{
double basePay;
public:
derEmp(int i,double tot,double bp)
        : Emp(i,tot)
        {
            basePay=bp;
        }
void calc(double comm){
	pay=comm*total_sales/100+basePay;
}
void print(){
cout<<"Employee with ID "<<id<<" has a salary of Rs."<<pay<<endl;
}
};


int main(){
int n,type,idi,total,bpp;
double commi;
cout<<"Enter total number of Employees : ";
cin>>n;
cout<<"Enter value of commission(in percentage) : ";
cin>>commi;
for(int i=0;i<n;i++){
	cout<<"\nFor Employee "<<i+1<<", Enter Type (1 or 2) : ";
        cin>>type;
	if(type==1){
	cout<<"Enter Id, Total Sales and Basic Pay : ";
	 cin>>idi>>total>>bpp;
	 derEmp obj(idi,total,bpp);
	 obj.calc(commi);
	 obj.print(); 
	}
	else if(type==2){
	cout<<"Enter Id and Total Sales : ";
	 cin>>idi>>total;
	 Emp obj(idi,total);
	 obj.calc(commi);
	 obj.print();
	}
 
 }
return 0;
}

