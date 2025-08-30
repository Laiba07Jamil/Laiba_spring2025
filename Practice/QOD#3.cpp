#include <iostream>
using namespace std;

void selection_sort(int arr[] , int n){
    for(int i = 0 ; i < n - 1 ; i++){
        int minInd = i;
        for(int j = i + 1 ; j < n  ; j++){
            if(arr[j] < arr[minInd]){
                minInd = j ;
            }
        }
        swap(arr[i] , arr[minInd]);
    }
}

void Bubble_sort(int  arr[] , int n){
    for(int i = 0 ; i  < n - 1 ; i++){
        for(int j = 0; j < n - i - 1 ; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j] , arr[j + 1]);
            }
        }
    }
}

void insertion_sort(int arr[] , int n){
    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

bool duplicates(int arr[] , int n){
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if (arr[i] == arr[j]){
                count ++;
            }
        }
    }
    return count > n / 4 ;
}

bool isnearlysorted(int arr[] , int n){
    int misplaced = 0 ; 
    for(int i = 0 ; i < n - 1 ; i++){
        if(arr[i] > arr[i + 1]){
            misplaced++ ;
        }
    }
    return (misplaced <= 2);
}
void function(int arr[] , int n){
    if(duplicates(arr,n)){
        cout << "Using bubble sort: array have duplicates" << endl ;
        Bubble_sort(arr,n);
    }
    else if(isnearlysorted(arr,n)){
        cout << "Using insertion sort: array is nearly sorted" << endl;
        insertion_sort(arr,n);
    }
    else{
        cout << "Use selection sort for random array" << endl;
        selection_sort(arr,n);
    }
}
int main(){
    int arr[] = {10 , 15 , 17 , 20 , 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    function(arr,n);

    return 0;
}