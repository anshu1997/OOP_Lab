#include "IIKHclass.h"
using namespace std;
//Wherever we perform some search operation using *it or *iti -> REPLACE with .find()
int main()
{
   vector <recipe> s;
   vector <ingredient> ij;
   vector <miniplanmanager>availability;
   vector <userdata> users;
   vector <recipe>::iterator it;
   vector <ingredient>::iterator iti;
   string st;int qty;
   int a,i,j,k,invar=1,v;
   while(invar)
   {
	cout<<endl<<"ADMIN MENU"<<endl;
   	cout<<"01. Add new Recipe"<<endl;
   	cout<<"02. Add ingredients to existing Recipe"<<endl;
   	cout<<"03. Change procedure of cooking for a Recipe"<<endl;
	cout<<"04. Add quantity of ingredients to Stock"<<endl;
   	cout<<"05. See Recipes"<<endl;
	cout<<"06. See Ingredients in stock/ Grocery"<<endl;
	cout<<"07. See availability of each recipe"<<endl;
	cout<<"USER MENU"<<endl;
	cout<<"08. Choose 7-Day meal"<<endl;
	cout<<"09. See your 7-Day menu"<<endl;
	cout<<"10. See all recorded users"<<endl;
   	cout<<"11. Exit"<<endl;
   	
   	cout<<"Enter Your Choice :) ";
   	cin>>a;
   	if(a==11)break;
   	switch(a)
   	{
   	    case 1:{
   	      string stl;
   	      cout<<"Enter Name of Recipe :";
   	      cin.ignore();
   	      getline(cin,st);
   	      recipe r(st);
	      
   	      cout<<"Enter Number of Ingredients:";
   	      cin>>k;
   	      cout<<"Enter Ingredients and their respective quantities one by one:"<<endl;
	      
   	      for(i=0;i<k;i++)
   	      {
   	        cin.ignore();
   	      	getline(cin,st);
   	      	cin>>qty;
   	      	r.add_ingredient(st,qty);
			   	      iti = ij.begin();
			   	      while(iti!=ij.end())
			   	      {
			   	          if((*iti).get_ingredient_name() == st)
			   	            break;
			   	          iti++;
			   	      }
			   	      if(iti==ij.end())
			   	      {
			   	         ingredient ijk(st);
						 ij.push_back(ijk);
			   	      }
   	      	
   	      }
   	      cout<<"Enter Recipe Procedure:";
   	      cin.ignore();
   	      getline(cin,st);
   	      r.make_recipe(st);
   	      s.push_back(r);}
   	      break;
   	    case 2:{
   	      cout<<"Enter name of Recipe in which you wish to add ingredient:";
   	      cin.ignore();
   	      getline(cin,st);
   	      it = s.begin();
   	      while(it!=s.end())
   	      {
   	          if((*it).get_recipe_name() == st)
   	            break;
   	          it++;
   	      }
   	      if(it==s.end())
   	      {
   	         cout<<"Such a Recipe does not exist. Please try again :("<<endl;
   	         break;
   	      }
   	      cout<<"Enter Number of Ingredients(extra) for this recipe:";
   	      cin>>k;
   	      cout<<"Now enter the Ingredients and their quantities:"<<endl;
	      
   	      for(i=0;i<k;i++)
   	       {
   	       	cin.ignore();
   	      	getline(cin,st);
   	      	cin>>qty;
   	      	(*it).add_ingredient(st,qty);
   	      			  iti = ij.begin();
			   	      while(iti!=ij.end())
			   	      {
			   	          if((*iti).get_ingredient_name() == st)
			   	            break;
			   	          iti++;
			   	      }
			   	      if(iti==ij.end())
			   	      {
			   	         ingredient ijk(st);
						 ij.push_back(ijk);
			   	      }
   	       }
	      }
   	      break;
   	    case 3:{
   	      cout<<"Enter name of Recipe in which you wish to edit the method:";
   	      cin.ignore();
   	      getline(cin,st);
   	      it = s.begin();
   	      while(it!=s.end())
   	      {
   	          if((*it).get_recipe_name() == st)
   	            break;
   	          it++;
   	      }
   	      if(it==s.end())
   	      {
   	         cout<<"Such a Recipe does not exist. Please try again :("<<endl;
   	         break;
   	      }
   	      else
   	      {
   	         string st2;
   	         cout<<"Enter New Recipe Procedure:"<<endl;
   	         getline(cin,st2);
   	         (*it).make_recipe(st2);
   	      }
   	    }
   	      break;
	    case 4:{
   	      cout<<"Enter Number of Ingredients:";
   	      cin>>k;
   	      cout<<"Enter Ingredients and their quantities:"<<endl;
	      
   	      for(i=0;i<k;i++)
   	      {
   	        cin.ignore();
   	      	getline(cin,st);
   	      	cin>>qty;
			   	      iti = ij.begin();
			   	      while(iti!=ij.end())
			   	      {
			   	          if((*iti).get_ingredient_name() == st)
			   	            {	ij.erase(iti);
			   	            	ingredient ijk(st,qty);
						 		ij.push_back(ijk);
			   	            	break;
							   }
			   	          iti++;
			   	      }
			   	      if(iti==ij.end())
			   	      {
			   	         ingredient ijk(st,qty);
						 ij.push_back(ijk);
			   	      }
   	      }
   	  }
   	      break;
   	    case 5:{
   	    it=s.begin();
   	    while(it!=s.end())
   	    {
   	       cout<<endl<<"RECIPES on MENU"<<endl;
   	       (*it).print_recipe();
   	       it++;
   	    }
   	    }
   	      break;
	    case 6:{
	    	/*sort(ij.begin(),ij.end());
	    	ij.erase(unique(ij.begin(),ij.end()), ij.end());*/
	    	cout<<endl<<"INGREDIENTS in STOCK"<<endl;
	    	for(int i=0;i<ij.size();i++){
	    		cout<<"\n"<<ij[i].get_ingredient_name()<<" "<<ij[i].get_quantity();
			}
			cout<<endl;
   	    }
   	      break;
   	    case 7:{
	    	miniplanmanager obj;
	    	//always create availability array from scratch as it can be updated anytime
	    	availability.clear();
	    	cout<<endl;
	    	for(int i=0;i<s.size();i++){
	    		obj.count(s[i],ij);
	    		availability.push_back(obj);
	    		//PRINT
	    		obj.printavail();
			}
   	    }
   	      break;
   	    case 8:{
	    	vector<string> menu;
	    	vector <string> temp;
	    	vector <int> temp2;
	    	string xyz;
	    	cout<<"\nEnter roll no. and name: ";
	    	cin>>qty;
	    	int p=0,flag=0;
   	    	for(p=0;p<users.size();p++){
   	    		if(users[p].get_userid()==qty)
   	    			{
   	    				flag=1;
   	    				break;
					   }
			   }
	    	cin.ignore();
   	      	getline(cin,st);
   	      	cout<<"\nChoose your meal menu from the following \n";
   	      	//always create availability array from scratch as it can be updated anytime
   	      	miniplanmanager obj;
   	      	availability.clear();
	    	for(int i=0;i<s.size();i++){
	    		obj.count(s[i],ij);
	    		availability.push_back(obj);
			}
			//PRINT
	    	for(int i=0;i<availability.size();i++){
	    		availability[i].printavail();
			}
			/*cout<<endl<<"Number of Meals:CHOICES"<<endl;
		   	cout<<"01. 1 Day Meal, i.e. 4 meals/day"<<endl;
		   	cout<<"02. 2 Day Meal, i.e. 4 meals/day"<<endl;
		   	cout<<"03. 3 Day Meal, i.e. 4 meals/day"<<endl;
			cout<<"04. 4 Day Meal, i.e. 4 meals/day"<<endl;
		   	cout<<"05. 5 Day Meal, i.e. 4 meals/day"<<endl;
		   	cout<<"06. 6 Day Meal, i.e. 4 meals/day"<<endl;
			cout<<"07. 7 Day Meal, i.e. 4 meals/day"<<endl;
			cin>>v;
			
				case 1:if(v==1){*/
				for(int i=0;i<7;i++){
					getline(cin,xyz);
					//CHECK! BECAUSE WE NEED TO UPDATE INGREDIENTS LIST TOO
					it = s.begin();
			   	      	while(it!=s.end())
				   	      {
				   	          if((*it).get_recipe_name() == xyz)
				   	          	break;
				   	          it++;
				   	      }
			   	    temp=(*it).get_ingre_name();
			   	    temp2=(*it).get_qty();
				
					for(int j=0;j<temp.size();j++)
				   	       {
				   	      			  iti = ij.begin();
							   	      while(iti!=ij.end())
							   	      {
							   	          if((*iti).get_ingredient_name() == temp[j])
							   	            break;
							   	          iti++;
							   	      }
							   	      (*iti).update_quantity(temp2[j]);
				   	       }	
					menu.push_back(xyz);
				}
				if(flag==0){
					userdata objuser(qty,st,menu);
					users.push_back(objuser);	
				}
				else{
					users[p].changemeal(menu);
				}
				/*}
			case 2:else if(v==2){
				for(int i=0;i<4*2;i++){
					getline(cin,xyz);
					//CHECK! BECAUSE WE NEED TO UPDATE INGREDIENTS LIST TOO
					it = s.begin();
			   	      	while(it!=s.end())
				   	      {
				   	          if((*it).get_recipe_name() == xyz)
				   	          	break;
				   	          it++;
				   	      }
			   	    temp=(*it).get_ingre_name();
			   	    temp2=(*it).get_qty();
				
					for(int j=0;j<temp.size();j++)
				   	       {
				   	      			  iti = ij.begin();
							   	      while(iti!=ij.end())
							   	      {
							   	          if((*iti).get_ingredient_name() == temp[j])
							   	            break;
							   	          iti++;
							   	      }
							   	      (*iti).update_quantity(temp2[j]);
				   	       }	
					menu.push_back(xyz);
				}
				if(flag==0){
					userdata objuser(qty,st,menu);
					users.push_back(objuser);	
				}
				else{
					users[p].changemeal(menu);
				}
				}
			case 3:{
				for(int i=0;i<4*3;i++){
					getline(cin,xyz);
					//CHECK! BECAUSE WE NEED TO UPDATE INGREDIENTS LIST TOO
					it = s.begin();
			   	      	while(it!=s.end())
				   	      {
				   	          if((*it).get_recipe_name() == xyz)
				   	          	break;
				   	          it++;
				   	      }
			   	    temp=(*it).get_ingre_name();
			   	    temp2=(*it).get_qty();
				
					for(int j=0;j<temp.size();j++)
				   	       {
				   	      			  iti = ij.begin();
							   	      while(iti!=ij.end())
							   	      {
							   	          if((*iti).get_ingredient_name() == temp[j])
							   	            break;
							   	          iti++;
							   	      }
							   	      (*iti).update_quantity(temp2[j]);
				   	       }	
					menu.push_back(xyz);
				}
				if(flag==0){
					userdata objuser(qty,st,menu);
					users.push_back(objuser);	
				}
				else{
					users[p].changemeal(menu);
				}
				}break;

			case 4:{
				for(int i=0;i<4*4;i++){
					getline(cin,xyz);
					//CHECK! BECAUSE WE NEED TO UPDATE INGREDIENTS LIST TOO
					it = s.begin();
			   	      	while(it!=s.end())
				   	      {
				   	          if((*it).get_recipe_name() == xyz)
				   	          	break;
				   	          it++;
				   	      }
			   	    temp=(*it).get_ingre_name();
			   	    temp2=(*it).get_qty();
				
					for(int j=0;j<temp.size();j++)
				   	       {
				   	      			  iti = ij.begin();
							   	      while(iti!=ij.end())
							   	      {
							   	          if((*iti).get_ingredient_name() == temp[j])
							   	            break;
							   	          iti++;
							   	      }
							   	      (*iti).update_quantity(temp2[j]);
				   	       }	
					menu.push_back(xyz);
				}
				if(flag==0){
					userdata objuser(qty,st,menu);
					users.push_back(objuser);	
				}
				else{
					users[p].changemeal(menu);
				}
				}break;

			case 5:{
				for(int i=0;i<4*5;i++){
					getline(cin,xyz);
					//CHECK! BECAUSE WE NEED TO UPDATE INGREDIENTS LIST TOO
					it = s.begin();
			   	      	while(it!=s.end())
				   	      {
				   	          if((*it).get_recipe_name() == xyz)
				   	          	break;
				   	          it++;
				   	      }
			   	    temp=(*it).get_ingre_name();
			   	    temp2=(*it).get_qty();
				
					for(int j=0;j<temp.size();j++)
				   	       {
				   	      			  iti = ij.begin();
							   	      while(iti!=ij.end())
							   	      {
							   	          if((*iti).get_ingredient_name() == temp[j])
							   	            break;
							   	          iti++;
							   	      }
							   	      (*iti).update_quantity(temp2[j]);
				   	       }	
					menu.push_back(xyz);
				}
				if(flag==0){
					userdata objuser(qty,st,menu);
					users.push_back(objuser);	
				}
				else{
					users[p].changemeal(menu);
				}
				}break;
			case 6:{
				for(int i=0;i<4*6;i++){
					getline(cin,xyz);
					//CHECK! BECAUSE WE NEED TO UPDATE INGREDIENTS LIST TOO
					it = s.begin();
			   	      	while(it!=s.end())
				   	      {
				   	          if((*it).get_recipe_name() == xyz)
				   	          	break;
				   	          it++;
				   	      }
			   	    temp=(*it).get_ingre_name();
			   	    temp2=(*it).get_qty();
				
					for(int j=0;j<temp.size();j++)
				   	       {
				   	      			  iti = ij.begin();
							   	      while(iti!=ij.end())
							   	      {
							   	          if((*iti).get_ingredient_name() == temp[j])
							   	            break;
							   	          iti++;
							   	      }
							   	      (*iti).update_quantity(temp2[j]);
				   	       }	
					menu.push_back(xyz);
				}
				if(flag==0){
					userdata objuser(qty,st,menu);
					users.push_back(objuser);	
				}
				else{
					users[p].changemeal(menu);
				}
				}break;
			case 7:{
				for(int i=0;i<4*7;i++){
					getline(cin,xyz);
					//CHECK! BECAUSE WE NEED TO UPDATE INGREDIENTS LIST TOO
					it = s.begin();
			   	      	while(it!=s.end())
				   	      {
				   	          if((*it).get_recipe_name() == xyz)
				   	          	break;
				   	          it++;
				   	      }
			   	    temp=(*it).get_ingre_name();
			   	    temp2=(*it).get_qty();
				
					for(int j=0;j<temp.size();j++)
				   	       {
				   	      			  iti = ij.begin();
							   	      while(iti!=ij.end())
							   	      {
							   	          if((*iti).get_ingredient_name() == temp[j])
							   	            break;
							   	          iti++;
							   	      }
							   	      (*iti).update_quantity(temp2[j]);
				   	       }	
					menu.push_back(xyz);
				}
				if(flag==0){
					userdata objuser(qty,st,menu);
					users.push_back(objuser);	
				}
				else{
					users[p].changemeal(menu);
				}
				}break;*/		
   	    }
   	      break;
   	    case 9:{
   	    	cout<<"Enter your user id: ";cin>>qty;
   	    	int i=0;
   	    	for(i=0;i<users.size();i++){
   	    		if(users[i].get_userid()==qty)
   	    			break;
			   }
			users[i].printmeal();
   	    }
   	      break;
   	    case 10:{
   	    	cout<<endl;
   	    	for(int i=0;i<users.size();i++){
   	    		users[i].printuser();
			   }
   	    }
   	      break;
   	    case 11:{invar=0;}
   	      break;  
   	    default:
   	      cout<<"Wrong Choice Please Re-enter :("<<endl;  
   	}
   } 
}
