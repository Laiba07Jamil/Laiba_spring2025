/*You are testing how file pointers work in a file while reading and writing.
Requirements:
1. Write the sentence "C++ is a powerful programming language." to a file named
info.txt using ofstream in ios::out mode.
2. Reopen the file using fstream with both ios::in | ios::out modes.
3. Display the initial position of get pointer using tellg() and put pointer using tellp().
4. Use seekg(6) to move the read pointer to the word "powerful" and read the word
from there.
5. Use seekp(6) to move the write pointer to the same position, and overwrite
"powerful" with "dynamic" (same length).
6. Use tellg() and tellp() again to show the new pointer positions.
7. Display the updated content of the file.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream file("info.txt" , ios::out);
    if(!file){
        cout << "Error in opening file." << endl;
    }

    file << "C++ is a powerful programming language." << endl;
    file.close();

    fstream both_file("info.txt" , ios::out | ios::in);
    if(!both_file){
        cout << "Error in opening file." << endl;
    }
    both_file.seekg(0 , ios::beg);
    streampos pos = both_file.tellg();  //gets the current position 
    cout << "file pointer is at position: " << pos << endl;

    both_file.seekg(9 , ios::beg);      // sets the get pointer
    streampos ptr = both_file.tellg();
    cout << "Now file pointer is at position: " << ptr << endl;

    string word;
    both_file >> word;
    cout << "The word at which the pointer is: " << word << endl;

    both_file.seekp(9 , ios ::beg);
    both_file << "dynamic";
    

    cout << "The new pointer position is: " << both_file.tellg() << endl;
    cout << "The new pointer position is: " << both_file.tellp() << endl;


    both_file.seekg(0, ios::beg);  // very important: reset get pointer before reading
    cout << "\nUpdated content of the file:" << endl;

    string line;
    while(getline(both_file , line)){
        cout << line;
    }

    file.close();
    return 0;
 }