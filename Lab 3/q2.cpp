#include<iostream>
#include<cstring>
using namespace std;
int countVowels(const char* str) {

    int vowelCount = 0;
    while (*str) {
        char c = tolower(*str); 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
        }
        str++; 
    }
    return vowelCount;
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
   
    char** strings = new char*[n];
    
    cout << "Enter the " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        strings[i] = new char[100]; 
        cin>> strings[i]; 
    }

    cout << "\nStrings in reverse order:\n";
    for (char** ptr = strings + n - 1; ptr >= strings; ptr--) {
        cout << *ptr << endl; 
    }
    int maxVowels = 0;
    char* stringWithMaxVowels = nullptr;
    for (int i = 0; i < n; i++) {
        int vowelCount = countVowels(strings[i]);
        if (vowelCount > maxVowels) {
            maxVowels = vowelCount;
            stringWithMaxVowels = strings[i];
        }
    }


    cout << "\nString with the most vowels: " << stringWithMaxVowels << endl;


    float totalLength = 0.0000;
    for (int i = 0; i < n; i++) {
        totalLength += strlen(strings[i]);
    }
    float averageLength = (totalLength) / n;
  
    cout << "\nAverage length of strings: " << averageLength << endl;


    for (int i = 0; i < n; i++) {
        delete[] strings[i]; 
    }
    delete[] strings; 

    return 0;
}
}
