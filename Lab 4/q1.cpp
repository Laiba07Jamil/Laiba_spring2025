#include <iostream>
using namespace std;
class Student{
    private:
    int studentID;
    string name;
    int age;
    char grade;
    public:
    Student() : grade(' ') {}
    Student(int studentID , string name , int age, char grade){
        this->studentID = studentID;
        this->name = name;
        this->grade = grade;
        this->age =age;
    }
    void promoteStudent(char _grade){
        if(_grade == 'A'){
            grade = 'A';
        }
        else{
        this->grade = _grade - 1 ;
        }
    }
    bool isEligibleForScholarship(char grade_){
        if(grade == 'A'){
            cout << name << " is Eligiblle for ScholarShip" << endl;
            return true;
        }
        else{
            cout << name << " is not Eligible for ScholarShip" << endl;
            return false;
        }
    }
    void displayDetails(){
        cout << "Student ID:" << studentID << endl;
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Grade:" << grade << endl;
        cout << endl;
    }
};
int main(){
    Student s1 = Student(1026 , "Laiba" , 17 , 'A');
    Student s2 = Student(2314 , "Absar" , 14 , 'B');
    s1.promoteStudent('A');
    s1.isEligibleForScholarship('B');
    s1.displayDetails();
    s2.promoteStudent('B');
    s2.isEligibleForScholarship('A');
    s2.displayDetails();
    return 0;
}
