#include<iostream>
#include <conio.h>
using namespace std;
class Car{
    private:
    int carID;
    string model;
    int year;
    bool isRented;
    public:
    Car() : isRented(false) {}
    Car(int carID , string model , int year , bool isRented){
        this->carID =carID;
        this->model = model;
        this->year = year;
        this->isRented = isRented;
    }
    void rentCar(){
        if(isRented){
            cout << "The Car is already Rented" << endl;
        }
        else{
            isRented = true;
            cout << "Car rented Successfully" << endl;
        }
    }
    void returCar(){
        if(isRented){
            isRented=false;
            cout << "Car returned Successfully" << endl;
        }
        else{
            cout << "You did not rent a Car" <<  endl;
        }
    }
    bool isVintage(){
        if(year < 2000){
            cout << "The Car is Vintage" << endl;
            return true;
        }
        else{
            cout << "The Car is not Vintage" << endl;
            return false;
        }
    }
};

int main(){
    Car c1 = Car(819 , "Mercedes" , 2024 ,false);
    char ch;
    while(true){
        cout << "What do you want to do\n1.Rent a Car\n2.Return car\n3.Is vintage\n4.Exit\n";
        ch =_getch();
        switch(ch){
            case '1':
            c1.rentCar();
            break;
            case '2':
            c1.returCar();
            break;
            case '3':
            c1.isVintage();
            break;
            case '4':
            cout << "Thank you for coming" << endl;
            break;
            default :
            cout << "Invalid Input" << endl;
            break;
        }
    }
    return 0;
}