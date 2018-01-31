#include <bits/stdc++.h>
using namespace std;
class student
{
private:
	int minSalary;
	int company_selected;
	int isselected;
        double cgpa;
	int salary_f;
public:
void set_values(int sal,double cg)
	{
		isselected=0;
		minSalary = sal;
		cgpa=cg;
		salary_f=0;
	}
void add_company_selected(int a)
	{
		company_selected=a;
	}
void set_placement_status()
	{
		isselected=1;
	}
void set_sal(int z)
	{
		salary_f=z;
	}
int get_placement_status()
	{
	return(isselected);
	}
int get_company_selected()
	{
		return(company_selected);
	}
int get_min_salary()
	{
		return(minSalary);
	}
int get_sal()
	{
		return(salary_f);
	}
double get_cgpa()
	{
		return(cgpa);
	}
};
class company
{
private:
	int maxJoboffers,id;
	set < pair<double,int> > selected_students;
public:
int offeredSalary;

void set_values(int a,int b,int i)
	{
		id=i;
		offeredSalary=a;
		maxJoboffers=b;
	}

void add_student_selected(int a,double cc)
	{
                selected_students.insert(make_pair(cc,a));
	}

set < pair<double,int> > get_student_selected()
	{
		return(selected_students);
	}

void set_offers()
	{
		maxJoboffers = maxJoboffers - 1;
	}

int get_offers()
	{
		return(maxJoboffers);
	}

int salary()
	{
		return(offeredSalary);
	}
int get_id(){
	return(id);
}
};

bool operator<(company const & a, company const & b)
{
    return b.offeredSalary < a.offeredSalary;
}

int main()
{
	int candidates,companies,i,j,k,p;
	double ss;
	cout<<"Number of Candidates:";
	cin>>candidates;
	cout<<"Number of Companies:";
	cin>>companies;
	student s[1001];
	company c[1001];
	for(i=0;i<candidates;i++)
	{
		cout<<"Minimum expected salary and cgpa of student "<<i+1<<":";
		cin>>k>>ss;
		s[i].set_values(k,ss);
	}
	for(i=0;i<companies;i++)
	{
		cout<<"Enter Offered Salary of Company "<<i+1<<":";
		cin>>j;
		cout<<"Enter the maximum Job Offers available with the Company :";
		cin>>k;
		c[i].set_values(j,k,i+1);
	}

        sort(c, c+companies);cout<<endl;
        
	for(i=0;i<candidates;i++)
	{
		for(j=0;j<companies;j++)
		{
			if(c[j].salary()>=s[i].get_min_salary())
			{
				c[j].add_student_selected(i,s[i].get_cgpa());
			}
	        }
        }

	/*for(i=0;i<companies;i++)
	{	

		set < pair<double,int> > st;

		st=c[i].get_student_selected();

		set < pair<double,int> >::iterator it;

		it=st.begin();		

		 while(it!=st.end())
		  {	
			cout<<(*it).first<<" "<<(*it).second<<endl;
			++it;
		  }
	cout<<endl;
        }*/
	
	for(i=0;i<companies;i++)
	{	
		set < pair<double,int> > st;
		st=c[i].get_student_selected();
		set < pair<double,int> >::reverse_iterator it;
		it=st.rbegin();		
		 while((it!=st.rend())&&(c[i].get_offers()>0))
		  {	
			if(s[(*it).second].get_placement_status()==0){
			s[(*it).second].set_placement_status();
			s[(*it).second].add_company_selected(c[i].get_id());
			s[(*it).second].set_sal(c[i].salary());
			c[i].set_offers();}
			++it;
		  }
        }

for(i=0;i<candidates;i++)
	{
         
	 if(s[i].get_placement_status())
		{	cout<<"For candidate "<<i+1<<",  placement status is PLACED";
			cout<<endl<<"Placed in Company Number: "<<s[i].get_company_selected()<<" || Salary: "<< s[i].get_sal()<<" ||\n";// CGPA:"<<s[i].get_cgpa()<<endl;}
	else{
		cout<<"For candidate "<<i+1<<", placement status is NOT PLACED"<<" ||\n";// CGPA:"<<s[i].get_cgpa()<<endl;
		}
 	cout<<endl;
        }
for(i=0;i<companies;i++)

	{

         cout<<"For company "<<c[i].get_id()<<" offers remaining are: "<<c[i].get_offers()<<endl;

        }
}
