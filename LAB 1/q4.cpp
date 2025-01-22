#include<iostream>
using namespace std;

int main(){
	int num;
	cout << "Enter the number of lines:";
	cin >> num;
	int *arr = new int[num];
	for(int i = 0 ; i < num ; i++){
		cout << "Enter "<< i+1 <<" line :";
		cin >> arr[i];
	}
	int length;
	int height;
	int max_area = 0;
	for(int i = 0 ; i < num ; i++){
		 for(int j = 1 ; j < num ; j++){
		 	length= j - i ;
		 	if(arr[j] > arr[i]){
		 		height = arr[i];
			 }
			 else{
			 	height = arr[j];
			 }
			int current_area = length * height ;
			if(current_area > max_area){
				max_area = current_area;
			}
		 }
	}
	
	cout << "The maximum amount of water the container can store is " << max_area;
	delete[] arr;
	return 0 ;
}