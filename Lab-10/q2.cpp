#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct User{
    string name;
    string email;
    int yerasOfExperience;
    string summary;
};

int main(){
    ofstream file;
    file.open("resume.txt" , ios::out);
    if(!file){
        cout << "Error openinig file." << endl;
        return 1;
    }
    
    else{
        User u;
        cout << "Enter the details of User." << endl;
        cout << "Enter the name: " << endl;
        cin >> u.name;
        cout << "Enter the email: " << endl;
        cin >> u.email;
        cout << "Enter the years of experience: " << endl;
        cin >> u.yerasOfExperience;
        cout << "Enter the summary: " << endl;
        cin >> u.summary;

        file << u.name << " " << u.yerasOfExperience << " " << u.email << " " << u.summary << endl;

    }

    file.close();

    file.open("resume.txt" , ios::trunc);
    if(!file){
        cout << "Error openinig file." << endl;
        return 1;
    }
    file << "The file content was truncated before entering this." << endl;

    ifstream file1("resume.txt");
    if(!file1){
        cout << "Error openinig file." << endl;
        return 1;
    }

    string line;
    while(getline(file1 , line)){
        cout << line << endl;
    }

    file.close();
}