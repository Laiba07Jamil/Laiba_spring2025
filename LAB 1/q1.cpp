#include<iostream>
using namespace std;
int main(){
	int n;
	int count;
	cout<< "Enter a number :";
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		if(n % i == 0){
			count++;
		}
	}
	if(count == 2){
		cout<<" The number is prime" << endl;
	}
	else{
		cout<<"Not a prime number" << endl;
	}
	return 0;
}