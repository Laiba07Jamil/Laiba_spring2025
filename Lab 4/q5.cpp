#include <iostream>
#include <conio.h>
using namespace std;

class Employee{
    private:
    int employeeID;
    string name;
    string department;
    double salary;
    public:
    Employee() : salary(0.0) {}
    Employee(int employeeID , string name ,string department, double salary){
        this->employeeID = employeeID;
        this->name = name;
        this->department = department;
        this->salary = salary;
    }
    void giveBonus(double amount){
        if(amount > 0){
            salary += amount;
            cout << "Bonus Added successfully" << endl;
        }
        else{
            cout << "Bonus can't added successfully" << endl;
        }
    }
    bool isManager(string department){
        if(this->department == department){
            cout << "The Employee is the Manager" << endl;
            return true;
        }
        else{
            cout << "The Employee is not the manager" << endl;
            return false;
        }
    }
    void displayDetails(){
        cout << "Name:" << name << endl;
        cout << "Department:" << department << endl;
        cout << "employee ID:" << employeeID << endl;
        cout << "Salary:" << salary << endl;   
        }
};

int main(){
    Employee e1 = Employee(8123 , "Laiba" , "Management" , 250000.0);
    char ch;
    double Amount;
    string Department;
    while(true){
        cout << "What do you want to do\n1.Give Bonus\n2.Found is Manager\n3.Display Details\n4.Exit\n";
        ch = _getch();
        switch(ch){
            case '1':
            cout << "Enter the amount of bonus to add:" ;
            cin >> Amount;
            e1.giveBonus(Amount);
            break;
            case '2':
            cout << "Enter the Department of the Employee:";
            cin >> Department;
            e1.isManager(Department);
            break;
            case '3':
            e1.displayDetails();
            break;
            case '4':
            cout << "Thank you for coming" ;
            break;
            default:
            cout << "Invalid Input" ;
            break;
        }
    }
}
