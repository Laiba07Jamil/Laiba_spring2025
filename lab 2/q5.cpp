#include <iostream>
#include <cstring>
using namespace std;
void swap_string(char* str , int n);
int main(){
    int n;
    char str[10];
    cout << "Enter the syring:";
    cin.getline(str,10);
    cout << "Enter the number of characters to move:";
    cin >> n;
    swap_string(str,n);
    cout << "Shifted string after shifting last " << n << " characters: " << str << endl;
    return 0;
}

void swap_string(char* str , int n){
    int len = strlen(str);
    int L = len % n ;
    if(L > len || L < 0){
        cout << "Sorry:)";
    }

    char *temp = new char[len + 1];
    strncpy(temp , str + len - n , n);
    strncpy(temp + n , str , len - n);
    temp[len]='\0';
    strcpy(str,temp);
    delete[] temp; 
}