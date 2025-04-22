#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student{
    int id;
    string name;
    float gpa;
};

int main(){
    ofstream file;
    file.open("students.txt" , ios::out);
    if(!file){
        cout << "Error openinig file." << endl;
        return 1;
    }
    else{
         Student s[5];
        for(int i = 0 ; i < 5 ; i++){
        cout << "Enter the details of student " << i+1 << endl;
        cout << "Enter name for student " << i+1 << endl;
        cin >> s[i].name ;
        cout << "Enter ID for student " << i+1 << endl;
        cin >> s[i].id ;
        cout << "Enter gpa for student " << i+1 << endl;
        cin >> s[i].gpa ;

        file << "" << i+1 << ". "<< "ID: " << s[i].id << " " << "GPA: " << s[i].gpa << " " << "Name: " << s[i].name << endl;
    }
}
    file.close();

    file.open("students.txt" , ios::app);
    if(!file){
        cout << "Error opening file." << endl;
    }
    else{
        Student s1;
        cout << "Enter ID: "<< endl;
        cin >> s1.id;
        cout << "Enter Name: " << endl;
        cin >> s1.name;
        cout << "Enter gpa: " << endl;
        cin >> s1.gpa;

        file << s1.id << " " << s1.gpa << " " << s1.name << endl;
    }

    file.close();

    ifstream file1("students.txt");
    if(!file1){
        cout << "Error opening file." << endl;
    }

    string line;
    while(getline(file1 , line)){
        cout << line << endl;
    }
}