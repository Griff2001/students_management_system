
#include<iostream>
#include<io.h>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main();
	void show_data(int searchkey); // the function used to show data to end-user
	void get_data(int i); //the functions obtains data from end user 
	void search_student (int searchkey);
	void add_student(); // used to add record of new students 
	void edit_student(int idnumber); //edit the existing records 
	void fullscreen();
	int ts; 
	
	
	struct student // structure students is made to store student attributes. 
	{
		int rollno;
		string name;
		string fname;
		string cell;
		string dob;
		string adress;
		
	};
	student rec[50]; // this is basic array of defined structure to store data. 
	
	int main (){
		system("CLS");
		system("color B1");
		
		int choice; //int variable to determine the operation the user wants to get. 
		int idnumber;//' ' to record ID number which user wants to edit. 
		int searchkey; // ' ' to store students roll_no by which user can search. 
		
		cout<<"Enter the Total Number of Students(s)- Max 50: "; 
		cin>>ts; 
		
		while(ts--){
			cout<<"\n\t what do you want to do?"<<endl;
			cout<<"\t\t----------"<<endl;
			cout<<"\t\t1 -Add student"<<endl;
			cout<<"\t\t2 -Edit student" <<endl;
			cout<<"\t\t3 -Search Student"<<endl;
			cout<<"\t\t4 -Quit Program"<<endl;
			cout<<"\t\t --------"<<endl;
			cout<<"Enter your choice"; 
			
			cin>>choice;
			switch(choice)
			{
				case 1:
					add_student(); //if user presesses 1, then student adding module would be displayed. 
					break;
					case 2: 
					if(rec[0].rollno==0)
					{
						cout<<"Please add student first"<<endl;
						system("pause");
						main();
					}
					else  //if the records are present in array then it will show table 
					{
						cout<<endl;
						cout<<"--------------------------------------------------------------------"<<endl;
						cout<<"--------------------------------Student Record Table----------------"<<endl;
						cout<<"--------------------------------------------------------------------"<<endl;
						cout<<"ID  "<<"Roll   "<<"Name    "<<"Father\tCell no.   "<<"DOB      "<<"Adress \n\n";
						cout<<"--------------------------------------------------------------------"<<endl;
						
						for(int i=0; i<=ts;i++)
						{
							show_data(i); //function is called with index value to show data.
							
						}
						cout<<"--------------------------------------------------------------------"<<endl;
						cout<<"Which ID number would you like to edit";
						cin>>idnumber;  // asking the user the type of id he wantes to make changes to. 
						
						if(idnumber>ts||idnumber<0) //validating the ID number. 
						{
							cout<<"\nInvalid ID number" <<endl;
						}
						else
						{
							edit_student(idnumber); //Passing ID number to the Edit function. 
						}
					}
					break;
					case 3:
						if(rec[0].rollno==0) //if no records exists then ask user to enter records first. 
						{
							cout<<"please add students first"<<endl;
							system("pause");
							main();   //return to main so that user can input new record
						}
						else
						{
							cout<<"Enter roll-no of students you want to search";
							cin>>searchkey;   //roll_no as the search key can be entered by the user. 
							search_student(searchkey);
						}
						break; 
						case 4: 
						return 0; //terminating the records
						break; 
						default: 
						cout<<"Invalid Number"<<endl; 
						system("Pause");
						
						
			}
		}
		return 0; 



	}
	void get_data(int i)  //function for receiving data from user and populatig the variables
	{
		cout<<"enter students roll number in format(1XXXX):";
		cin>>rec[i].rollno;
		cout<<"Enter the name of the studnets"; 
		cin>>rec[i].name;
		cout<<"enter the students fathers name";
		cin>>rec[i].fname;
		cout<<"Enter the students cell number ";
		cin>>rec[i].cell;
		cout<<"Enter the students date of birth(dd/mm/yyyy)";
		cin>>rec[i].dob;
		cout<<"enter the students adress";
		cin>>rec[i].adress; 
	}
	
	void show_data(int searchkey) //function for showing data on the screen 
	{
		int i=searchkey;
		cout<<i<<"   ";
		cout<<rec[i].rollno<<"   ";
		cout<<rec[i].name<<"   ";
		cout<<rec[i].fname<<"   ";
		cout<<rec[i].cell<< "   ";
		cout<<rec[i].dob<<"   ";
		cout<<rec[i].adress<<"\n\n ";
	}
	
	void search_student(int searchkey)
	{
		for(int i=0;i<=ts; i++) //loop through complete arrays 
		{
			if(rec[i].rollno==searchkey)//if roll number matches the to search term 
			{
				cout<<"ID    "<<"Roll   "<<"Name     " <<"Father/tCell no.   "<<"DOB        "<<"Adress\n";
				show_data(i); //A function is used inside another function. 
			}
		}
	}
	
	void add_student() //this functions is used to add record of a new student 
	{
		for (int i=0; i<=ts;i++)
		{
			get_data(i); //Loop was processed 5 times to get input for 5 students 
		}
	
	system("CLS");
	cout<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"------------------Student Record Table------------------------------------------------------------------------"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"ID    "<<"Roll     "<<"Name    "<<"Father\tCell no.      "<<"DOB        "<<"Adress\n\n";
	cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
	
	
	for(int i=0;i<=ts;i++)
	{
		show_data(i); //loop was processed for 5 times to show obtained records 
	}
	cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------FINISH------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
	system("pause");
	
	main(); //Return to main function to gain show menu 
}


void edit_student(int idnumber) //funtion is used to edit existing record 
{
for (int i=0;i<ts; i++) //loop is started 
{
if(idnumber==i) //through loop every value is compared with search term. 
{
	cout<<"\Existed information about this record \n\n";
	cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"ID    "<<"Roll    "<<"Name    "<<"Father\tCell no.        "<<"DOB            "<<"Adress\n\n";
	cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
	
	show_data(i); //load information for existing records. 
	cout<<"\n\nEnter new data for above shown record.\n\n";
	get_data(i); //input data for that specific record
	cout<<"\n\nRecord Updated successfully"<<endl;
	
	system("pause");
	main(); //return to main function 
}
}
}
	


