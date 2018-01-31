#include <bits/stdc++.h>
using namespace std;

class machine{
int hund,fhund,twoth;

public:
machine(){
hund=0;
fhund=0;
twoth=0;
} 

machine(int a,int b,int c){
hund=c;
fhund=b;
twoth=a;
} 

int get_hu(){
return hund;}
int get_fhu(){
return fhund;}
int get_twot(){
return twoth;
}
void inc_count(int x,int type){
if(type==100)
  hund+=x;

if(type==500)
  fhund+=x;

if(type==2000)
  twoth+=x;
}
void dec_count(int x,int type){
if(type==100)
  hund-=x;

if(type==500)
  fhund-=x;

if(type==2000)
  twoth-=x;
}

};
///////////////////////////////////////////////////////////////////////////////////////////////
class user{
int acno;
int pass;
double accbal;
public:
int get_acno(){
	return acno;
}
int get_pass(){
	return pass;
}
user(){
acno=0;
pass=0;
accbal=0;
} 

user(int a,int p,double bal){
acno=a;
pass=p;
accbal=bal;
} 
double youBal(){
return accbal;
}
void bal_update(int x,int withdep){
if(withdep==1){
accbal-=x;
}
if(withdep==2){
accbal+=x;
}
}
////////////////////////////////////////////////////////////////////////////////////////
int withraw(int cash,machine m){
int dummy=cash;
int two=cash/2000;int number1=0;
cash=cash%2000;

int fh=cash/500;int number2=0;
cash=cash%500;

int hun=cash/100;int number3=0;
cash=cash%100;


        while((m.get_twot()>0)&&(two>0)){
	//cout<<"You get the withrawal in notes of denomination 2000 "<<endl;
	++number1;
	two--;
	m.dec_count(1,2000);
	 }

        two*=4;
        
	while((m.get_hu()>0)&&(two>0)){
	//cout<<"You get the withrawal in notes of denomination 500 "<<endl;
	++number2;
	two--;
	m.dec_count(1,500);
	 }

	two*=5;

	while((m.get_hu()>0)&&(two>0)){
	//cout<<"You get the withrawal in notes of denomination 100 "<<endl;
	++number3;
	two--;
	m.dec_count(1,100);
	 }

	if(two!=0)
	   {return 0;
		}


	while((m.get_fhu()>0)&&(fh>0)){
	//cout<<"You get the withrawal in notes of denomination 500 "<<endl;
	++number2;
	fh--;
	m.dec_count(1,500);
	 }

	fh*=5;

	while((m.get_hu()>0)&&(fh>0)){
	//cout<<"You get the withrawal in notes of denomination 100 "<<endl;
	++number3;
	fh--;
	m.dec_count(1,100);
	 }

	if(fh!=0)
	   {return 0;
		}

	while((m.get_hu()>0)&&(hun>0)){
	//cout<<"You get the withrawal in notes of denomination 100 "<<endl;
	++number3;
	hun--;
	m.dec_count(1,100);
	 }

	if(hun!=0)
	   {return 0;
		}

	 bal_update(dummy,1);

         cout<<"You are paid in \n"<<number1<<" two thousand notes; \n"<<number2<<" five hundred notes; \n"<<number3<<" hundred notes; \n"<<endl;
	cout<<"Your balance: "<<youBal()<<endl;
         return 1;
}
////////////////////////////////////////////////////////////////////////
void deposit(int x,int y,int z, machine m)
	{
		m.inc_count(x,2000);
		m.inc_count(y,500);
		m.inc_count(z,100);
                bal_update(2000*x+500*y+100*z,2);
	}

};

int main(){
vector <user> p;
machine mm;
int t,u,i=0;	
int m,n,d;double ba;
do{
	cout<<"Enter Choice:\n1.New User Sign Up\n2.User Log in\n3.Admin ATM machine\n4.Exit\n";
cin>>t;
switch(t){
	case 1:{
			cout<<"Create your account by entering the Ac/No, Password and Available Balance:\n";
			cin>>m>>n>>ba;
			user person(m,n,ba);
			p.push_back(person);
		break;
	}
	case 2:{
		int flag=0;
		cout<<"Enter your Ac/No and Password\n";
		cin>>m>>n;
		for(i=0;i<p.size();i++){
			if((m==p[i].get_acno())&&(n==p[i].get_pass()))
				{flag=1;break;
				}
		}
		if(flag){
			do{
				cout<<"Enter Choice:\n1.Check Balance\n2.Withraw Cash\n3.Deposit Cash\n4.Exit\n";
				cin>>u;
				switch(u){
					case 1:{
						cout<<"Your balance: "<<p[i].youBal()<<endl;	
						break;
					}
					case 2:{
						cout<<"Enter the amount you want to withraw: ";
						cin>>ba;
						if(p[i].youBal()>=ba){
						if(p[i].withraw(ba,mm)==0)
						  cout<<"Please enter in correct denominations, the ATM is short of cash\n"<<endl;	
						}
						else{
							cout<<"Not enough balance in your Account\n";
						}
						
						break;
					}
					case 3:{
						cout<<"Enter the amount you want to deposit: \n";
						cout<<"Enter the number of Rs.2000, Rs.500 and Rs.100 notes:\n";
						cin>>m>>n>>d;
						p[i].deposit(m,n,d,mm);	
						break;
					}
				}	
			}while(u!=4);	
		}
		else{
			cout<<"Account Number and Password do not match!\n";
		}
		
		break;
	}
	case 3:{
		
		cout<<"Enter the number of Rs.2000, Rs.500 and Rs.100 notes in this ATM machine:\n";
		cin>>m>>n>>d;
		machine sbi(m,n,d);
		mm=sbi;
		break;
	}
}	
}while(t!=4);


return 0;

}

