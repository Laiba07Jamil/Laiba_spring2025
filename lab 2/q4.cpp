#include <iostream>
using namespace std;

void unique_array(int  array[] , int n);

int main(){
    int n;
    cout << "Enter the number of Elements:";
    cin >> n;
    int* array = new int[n];
    for(int i = 0 ; i < n ; i++){
        cout << "Enter " << i+1 <<"Element:";
        cin >> array[i];
    }

    unique_array(array,n);
    delete[] array;
    return 0;
}

void unique_array(int  array[] , int n){
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        int flag = 1;
        for(int j = 0 ; j < count  ; j++){
           if(array[i] == array[j]){
            flag = 0 ;
            break;
           }
        }
        if(flag == 1){
            array[count] = array[i]; 
            count++ ;
        }
    }
    cout<< "Unique Elements of Array:";
    for(int i = 0 ; i < count  ; i++){
        cout << array[i] << " ";
    }
}
