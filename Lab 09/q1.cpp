#include <iostream>
using namespace std;

class Vehicle{
    protected:
    string model;
    double rate;
    public:
    Vehicle(string m , double r){
        this->model = m ;
        this->rate = r ;
    }
    virtual double getDisplayDetails() = 0;
    virtual void displayDetails() = 0; 

 virtual ~Vehicle () {}
};

class Car : public Vehicle{
    public:
    Car(string m , double r) : Vehicle(m,r) {}

    double getDisplayDetails() override{
        return rate;
    }

    void displayDetails() override{
        cout << "--------Car Details---------" << endl;
        cout << "Model: " << model << endl;
        cout << "Rate: " << rate << endl;
    }    
};

class Bike : public Vehicle {
    public:
    Bike(string m , double r)  : Vehicle(m,r) {}

    double getDisplayDetails() override{
        return rate;
    }

    void displayDetails() override{
        cout << "--------Bike Details---------" << endl;
        cout << "Model: " << model << endl;
        cout << "Rate: " << rate << endl;
    }    
};

int main(){
    Car c("Volkswagen" , 3200000.00);
    Bike b("Kawasaki" , 2600000.00);

    c.displayDetails();
    b.displayDetails();

    cout << "Rate of Car: " << c.getDisplayDetails() << endl;
    cout << "Rate of Bike: " << b.getDisplayDetails() << endl;

    return 0;
}
