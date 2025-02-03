#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of Elements:";
	cin>>n;
	float *ptr = new float(n);
	for(int i = 0 ; i < n ; i++){
		cout<<"Enter "<<i+1<<" Element:";
		cin>>ptr[i];
	}
	float sum=0,avg;
	for(int i = 0 ; i < n ; i++){
		sum = sum + *(ptr+i);
	}
	avg = sum/n;
	cout<<"The average is:"<<avg<<endl;
	float closest= *(ptr + 0);
	float min = fabs(closest - avg);
	for(int i = 0 ; i < n ; i++){
		float diff = fabs(ptr[i] - avg);
		if(diff < min){
			min  = diff;
			closest = ptr[i];
		}
	}
	cout<<"The closest number is :"<<closest<<endl;
	delete[] ptr;
	return 0;
}