#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book{
    string content;
};

int main(){
    ofstream file1;
    file1.open("chapter1.txt" , ios::out);
    if(!file1){
        cout << "Error opening file." << endl;
    }
    Book b;
    cout << "Enter the Conetnt for chapter 1: " << endl;
    cin >> b.content;

    file1 << b.content << endl;
    file1.close();

    ofstream file2;
    file2.open("chapter2.txt" , ios::out);
    if(!file2){
        cout << "Error opening file." << endl;
    }
    Book b1;
    cout << "Enter the Conetnt for chapter 2: " << endl;
    cin >> b1.content;

    file2 << b1.content << endl;
        file2.close();

    ofstream book("book.txt", ios::app);
    if(!book){
         cout << "Error openinig file." << endl;
        return 1;
    }

    ifstream ch1("chapter1.txt");
    if(!ch1){
        cout << "Error openinig file." << endl;
        return 1;
    }

    string line;
    while(getline(ch1 , line)){
        book << line << endl;
    }

    ch1.close();

    ifstream ch2("chapter2.txt");
    if(!ch2){
        cout << "Error openinig file." << endl;
        return 1;
    }

    string line2;
    while(getline(ch2 , line2)){
        book << line2 << endl;
    }

    ch2.close();

    ifstream file("book.txt");
    if(!file){
        cout << "Error opening file." << endl;
    }

    string l1;
    while(getline(file , l1)){
        cout << l1 << endl;
    }

    file.close();

    return 0;

}