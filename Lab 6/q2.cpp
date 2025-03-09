#include <iostream>
using namespace std;

class Consumer{
    private:
    string name;
    string consumerID;
    float unitsConsumed;
    public:
    Consumer(string n ,string id,float units){
        this->name = n;
        this->consumerID =id;
        this->unitsConsumed = units;
    }
    void setname(string n){
        name = n;
    }
    void setid(string id){
        consumerID =id;
    }
    void setunits(float units){
        unitsConsumed = units;
    }
    string getname() const{return name;}
    string getid() const {return consumerID;}
    float getunits() const {return unitsConsumed;}

    virtual void Calculate_bill() {}
    void display(){
        cout << "Name: " << name << endl;
        cout << "Consumer ID: " << consumerID << endl;
        cout << "Units Consumed: " << unitsConsumed <<endl;
    }
};

class Residential : public Consumer{
    public:
    Residential(string n ,string id, float units) : Consumer(n,id,units){}
    void Calculate_bill(){
        float R_bill ;
        R_bill = getunits() * 0.12;
        if(getunits() > 500){
            float s_bill = R_bill * 0.05;
            float total_bill = R_bill + s_bill;
            cout << "Your Total bill is: " << total_bill << endl;
        }
        else{
            cout << "Your total bill is: " << R_bill << endl;
        }
    }
};
class Commercial : public Consumer{
     public:
    Commercial(string n ,string id, float units) : Consumer(n,id,units){}
    void Calculate_bill(){
        float C_bill ;
        C_bill = getunits() * 0.20;
        if(getunits() > 1000){
            float s_bill = C_bill * 0.1;
            float total_bill = C_bill + s_bill;
            cout << "Your Total bill is: " << total_bill << endl;
        }
        else{
            cout << "Your total bill is: " << C_bill << endl;
        }
    }
};
class Industrial : public Consumer{
     public:
    Industrial(string n ,string id, float units) : Consumer(n,id,units){}
    void Calculate_bill(){
        float I_bill ;
        I_bill = getunits() * 0.30;
        if(getunits() > 2000){
            float s_bill = I_bill * 0.15;
            float total_bill = I_bill + s_bill;
            cout << "Your Total bill is: " << total_bill << endl;
        }
        else{
            cout << "Your total bill is: " << I_bill << endl;
        }
    }
};

int main(){
    char ch;
    string n,id;
    float units;
    
    while(1){
        cout << "Enter your type:\n1.Residential consumer.\n2.Commercial Consumer.\n3.Industrial Consumer\n";
    cin >> ch;
    if(ch == '1'){
        cout << "Enter your name:";
        cin >> n;
        cout << "Enter your ID:";
        cin >> id;
        cout << "Enter the units consumed:";
        cin >> units;
        Residential r1(n,id,units);
        r1.display();
        r1.Calculate_bill();
    }
    else if(ch == '2'){
         cout << "Enter your name:";
        cin >> n;
        cout << "Enter your ID:";
        cin >> id;
        cout << "Enter the units consumed:";
        cin >> units;
        Commercial c1(n,id,units);
        c1.display();
        c1.Calculate_bill();
    }
    else if(ch == '3'){
        cout << "Enter your name:";
        cin >> n;
        cout << "Enter your ID:";
        cin >> id;
        cout << "Enter the units consumed:";
        cin >> units;
        Industrial i1(n,id,units);
        i1.display();
        i1.Calculate_bill();
        }
    else{
         cout << "Invalid Input:" << endl;
    }
}
    }