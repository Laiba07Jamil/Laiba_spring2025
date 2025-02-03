#include<iostream>
using namespace std;
struct Register{
	string course_ID;
	string course_name;
};
struct Student{
	string student_ID;
	string first_name;
	string last_name;
	string cell_no;
	string email;
	Register stnd;
};

int main(){
	Student students[5];
	for(int i = 0 ; i < 5 ; i++){
		cout<<"Enter Course ID:";
		cin>>students[i].stnd.course_ID;
		cout<<"Enter Course name:";
		cin>>students[i].stnd.course_name;
	 	cout<<"Enter Student ID:";
	    cin>>students[i].student_ID;
		cout<<"Enter First name:";
		cin>>students[i].first_name;
		cout<<"Enter Last name:";
	    cin>>students[i].last_name;
		cout<<"Enter Cell no:";
		cin>>students[i].cell_no;
		cout<<"Enter Email:";
		cin>>students[i].email;
	}
	
	for(int i = 0 ; i < 5 ; i++){
	cout<<"Course ID:"<<students[i].stnd.course_ID<<endl;
	cout<<"Course name:"<<students[i].stnd.course_name<<endl;
	cout<<"Student ID:"<<students[i].student_ID<<endl;
	cout<<"First name:"<<students[i].first_name<<endl;
	cout<<"Last Name:"<<students[i].last_name<<endl;
	cout<<"Email:"<<students[i].email<<endl;
	cout<<"Cell No:"<<students[i].cell_no<<endl;
}
 return 0;
}
