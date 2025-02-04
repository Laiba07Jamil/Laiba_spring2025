#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class TollBooth{
    private:
    unsigned int car_count;
    double cash_collected;
    public:
    TollBooth (): car_count(0) , cash_collected(0) {}

    void paying_car(){
        car_count++;
        cash_collected += 0.5 ;
    }
    void no_pay_car(){
        car_count++;
    }

    void display(){
        cout << "Total Cars:" << car_count << endl;
        cout << "Total Cash Collected:" << cash_collected << endl;
    }
};

int main(){
    TollBooth t1;
    char ch;
    cout << "Press\n1.P for Paying car\n2.N for non-paying car\n3.Esc\n";
    while(true){
        ch = _getch();
        if(ch == 27){
            t1.display();
            break;
        }
        else if(ch == 'P' || ch =='p'){
            t1.paying_car();
            cout << "Car Paied Successfully" << endl;
        }
        else{
            t1.no_pay_car();
            cout << "Car not Paied" << endl;

        }
    }
    return 0;
}
