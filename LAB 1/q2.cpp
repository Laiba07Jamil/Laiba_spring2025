#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of students:";
	cin>>n;
	int arr[n][3];
	for(int i = 0 ; i < n ; i++){
		cout<<"Enter the marks of Maths for Student:" << i+1 <<endl;
		cin>>arr[i][0];
		cout<<"Enter the marks of Science for Student:" << i+1 <<endl;
		cin>>arr[i][1];
		cout<<"Enter the marks of English for Student:" << i+1 << endl;
		cin>>arr[i][2];
	}
	
	for(int i= 0 ; i < n ; i++){
			float total= arr[i][0] + arr[i][1] +arr[i][2];
			float avg= total /3;
			cout<<"Result for Student :"<< i+1 <<endl;
			cout<<"Total :"<< total <<endl;
			cout<<"Average :" << avg << endl;
			if(avg >= 90){
				cout<<"Grade A\n"<<endl;
			}
			else if(avg >= 80 && avg <= 89){
				cout<<"Grade B\n"<<endl;
			}
			else if(avg >= 70 && avg <=79){
				cout<<"Grade C\n"<<endl;		
			}
			else if(avg >= 60 && avg <= 69){
				cout<<"Grade D\n"<<endl;
			}
			else{
				cout<<"Grade F\n"<<endl;
			}	
		}
		return 0;
}