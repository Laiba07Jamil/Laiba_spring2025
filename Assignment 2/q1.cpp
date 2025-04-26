#include <iostream>
using namespace std;

class User{
    protected:
    string name;
    string stops[3];
    int stopcount;
    bool cardactive;
    double balance;
    string route;
    public:
    User(string name , bool cardactive , string route){
        this->name = name;
        this->cardactive = cardactive;
        this->route = route;
        stopcount = 0;
        balance = 0.0;
    }

    void addStop(const string &stop){
        if (stopcount > 3){
            cout << "Cannot add more stops. Route is full.\n";
        }
        else{
           stops[stopcount] = stop;
           stopcount++;
        }
    }

    virtual void payfees(double amount){
        balance += amount;
    }

    void tapcard(){
        if(!cardactive){
            cout << "Access denied ! Please pay the fees" << endl;
        }
        else{
            cout << "Access has being assigned" << endl;
        }
    }

    bool operator == (const User& obj){
        for(int i = 0 ; i < stopcount ; i++){
            if(stops[i] == obj.stops[i]){
                return true;
            }
            else{
                return false;
            }
        }
    }
};

class Student : public User{
    private:
    string studentID;
    double semesterfee;
    public:
    Student(string studentID , double semesterfee , string n , bool card , string routes) : User(n,card,routes){
        this->studentID = studentID;
        this->semesterfee = semesterfee;
    }

    void payfees(double amount){
        balance += amount;
        if(balance >= semesterfee){
            cardactive =true;
            cout << "Payment successful! Transport card activated." << endl;
        }
        else{
            cout << "Insufficient balance! Please pay the full fee." << endl;
        }
    }

    void display(){
        cout << "Name: " << name << endl;
        cout << "ID: " << studentID << endl;
        for(int  i = 0 ; i < stopcount ; i++){
            cout << "Stop " << i+1 << ":" << stops[i] << endl;
         }
    }

};
class Teacher : public User{
    private:
    string employeeID;
    double monthlyfee;
    public:
    Teacher(string employeeID , double monthlyfee ,string n , bool card , string routes) : User(n,card,routes){
        this->employeeID = employeeID;
        this->monthlyfee = monthlyfee;
    }

    void payfees(double amount) override{
        balance += amount;
        if(balance >= monthlyfee){
            cardactive =true;
            cout << "Payment successful! Transport card activated." << endl;
        }
        else{
            cout << "Insufficient balance! Please pay the full fee." << endl;
        }

    }

    void display(){
        cout << "Name: " << name << endl;
        cout << "ID: " << employeeID << endl;
        for(int  i = 0 ; i < stopcount ; i++){
            cout << "Stop " << i+1 << ":" << stops[i] << endl;
         }
    }
};
class Staff : public User{
    private:
    string staffID;
    string department;
    double monthlyfees;
    public:
    Staff(string staffID , string department , double monthlyfees ,string n , bool card , string routes) : User(n,card,routes) {
        this->department =department;
        this->staffID = staffID;
        this->monthlyfees = monthlyfees;
    } 

    void payfees(double amount) override{
        balance += amount;
        if(balance >= monthlyfees){
            cardactive =true;
            cout << "Payment successful! Transport card activated." << endl;
        }
        else{
            cout << "Insufficient balance! Please pay the full fee." << endl;
        }
    } 

    void display(){
        cout << "Name: " << name << endl;
        cout << "ID: " << staffID << endl;
        cout << "Department: " << department << endl;
        for(int  i = 0 ; i < stopcount ; i++){
            cout << "Stop " << i+1 << ":" << stops[i] << endl;
         }
    }
};


int main(){
    Student s1("24k-1001", 40000, "Ali Khan", false , "23B");
    Teacher t1("CS1003", 10000, "Sara Ahmed", false , "3B");
    Staff s2("EE1002","Electrical",10000, "Mubashir", false , "4B");

    s1.addStop("Paradise");
    s1.addStop("Maskan");
    s1.addStop("Disco");

    t1.addStop("Paradise");
    t1.addStop("Maskan");
    t1.addStop("Disco");

    s2.addStop("Waterpump");
    s2.addStop("KDA");
    s2.addStop("Airport");

    s1.display();
    cout << "\n";
    t1.display();
    cout << "\n";
    s2.display();
    cout << "\n";

    s1.payfees(35000);
    s1.tapcard();
    t1.payfees(10000);
    t1.tapcard();
    s2.payfees(5000);
    s2.tapcard();

     // operator overloading   

    if(s1 == t1 || s1 == s2 || t1 == s2){
        cout << "Users are on the same route." << endl;
    }
    else{
        cout << "Users are not on the same route." << endl;
    }

    return 0;
}
