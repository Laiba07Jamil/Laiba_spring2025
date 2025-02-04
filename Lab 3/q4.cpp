#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
class Angle{
    private:
    int degrees;
    float min;
    char direction;     //letter for directions (N,S,E,W)
    public:
    Angle(int degrees,float min, char direction){
        this->degrees = degrees;
        this->min = min;
        this->direction = direction;
    }
    void display(){
        cout << "Initialized Angle:" << degrees << "\xF8" << min <<fixed << setprecision(1)<< "' " << direction << endl;
    }
    void angle_value(){
        cout << "Enter the new value of degree:";
        cin >> degrees;

        cout << "Enter the new vale of mintues:";
        cin >> min;

        cout << "Enter the direction (W for west,E for East,N for north ,S for south):";
        cin >> direction;
    }
};

int main(){
    Angle a1(147,39.5,'W');
    a1.display();
    char ch;
    while(true){
        cout << "Press E:";
        ch= _getch();
        if(ch == 'E' || ch == 'e'){
            a1.angle_value();
            a1.display();
        }
        else{
            cout << "Invalid Input";
            break;
        }
    }
    return 0;   
}