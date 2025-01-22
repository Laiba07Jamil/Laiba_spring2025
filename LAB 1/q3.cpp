#include<iostream>
using namespace std;

int main(){
	int n;
	int target;
	cout<<"Enter the number of elements:";
	cin>>n;
	int arr[n];
	cout<<"Enter the target element:";
	cin>>target;
	for(int i= 0 ; i < n ; i++){
		cout<<"Enter the Elements:";
		cin>>arr[i];
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = n - 1 ; j >= 0 ; j--){
			if(arr[i] + arr [j] == target){
				cout<<"[" << i <<"," << j <<"]"<<endl;
				return 0;
			}
		}
	}
	
}