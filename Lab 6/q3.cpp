#include <iostream>
using namespace std;

class Vehicle{
    private:
    string ownerName;
    string vehicleID;
    int speed;
    public:
    Vehicle(string ownerName ,string vehicleId ,int speed) {
        this->ownerName =ownerName;
        this->vehicleID = vehicleId;
        this->speed =speed ;
    } 
    void setname(string name){
        this->ownerName =name;
    }
    void setid(string id){
        this->vehicleID =id;
    }
    void setspeed(int s){
        this->speed =s;
    }
    string getname() const {return ownerName;}
    string getid() const {return vehicleID;}
    int getspeed() const {return speed;}

    virtual void Calculate_fine(){}
    
};

class Car : public Vehicle{
    private:
    int speedlimit;
    public:
    Car(string n ,string id ,int s) : Vehicle(n,id,s) {
        this->speedlimit = 80;
    }
    int overspeeding;
    float C_fine;
    float s_fine,total_fine;
    void Calculate_fine(int ss){
         overspeeding = ss - speedlimit;
        C_fine = overspeeding * 5;
        if(getspeed() > 120){
             s_fine = C_fine * 0.1;
            total_fine = C_fine + s_fine;
    }
    }
    void dispaly(){
        cout << "Traffic Violation Details" << endl;
        cout << "--------------------------" << endl;
        cout << "Name: " << getname() << endl;
        cout << "Vehicle ID: " << getid() << endl;
        cout << "Speed Recorded: " << getspeed() << endl; 
        cout << "Speed Limit: " << speedlimit << endl;
        cout << "Over Speeding: " << overspeeding << endl;
        cout << "Base Fine: $" << C_fine << endl;
        cout << "Surcharge(10% for extreme speeding) applied: $" << s_fine << endl;
        cout << "Total Fine: $" << total_fine << endl;
    }
};
class Bike : public Vehicle{
    private:
    int speedlimit;
    public:
    Bike(string n ,string id ,int s) : Vehicle(n,id,s) {
        this->speedlimit = 60;
    }
    int overspeeding;
    float B_fine;
    float s_fine,total_fine;
    void Calculate_fine(int ss){
        overspeeding = ss - speedlimit;
        B_fine = overspeeding * 3;
        if(getspeed() > 90){
         s_fine = B_fine * 0.15;
         total_fine = B_fine + s_fine;
        }
    }
    void dispaly(){
        cout << "Traffic Violation Details" << endl;
        cout << "--------------------------" << endl;
        cout << "Name: " << getname() << endl;
        cout << "Vehicle ID: " << getid() << endl;
        cout << "Speed Recorded: " << getspeed() << endl; 
        cout << "Speed Limit: " << speedlimit << endl;
        cout << "Over Speeding: " << overspeeding << endl;
        cout << "Base Fine: $" << B_fine << endl;
        cout << "Surcharge(15% for extreme speeding) applied: $" << s_fine << endl;
        cout << "Total Fine: $" << total_fine << endl;
    }
};
class Truck : public Vehicle{
    private:
    int speedlimit;
    public:
    Truck(string n ,string id ,int s) : Vehicle(n,id,s) {
        this->speedlimit = 70;
    }
    int overspeeding;
    float T_fine;
    float s_fine,total_fine;
    void Calculate_fine(int ss){
        overspeeding =ss - speedlimit;
        T_fine = overspeeding * 7;
        if(getspeed() > 100){
            float s_fine = T_fine * 0.20;
            float total_fine = T_fine + s_fine;
        }
    }
     void dispaly(){
        cout << "\n" << endl;
        cout << "Traffic Violation Details" << endl;
        cout << "--------------------------" << endl;
        cout << "Name: " << getname() << endl;
        cout << "Vehicle ID: " << getid() << endl;
        cout << "Speed Recorded: " << getspeed() << endl; 
        cout << "Speed Limit: " << speedlimit << endl;
        cout << "Over Speeding: " << overspeeding << endl;
        cout << "Base Fine: $" << T_fine << endl;
        cout << "Surcharge(20% for extreme speeding) applied: $" << s_fine << endl;
        cout << "Total Fine: $" << total_fine << endl;
    }
};

int main(){
    string n,id;
    int ch,ss;

    cout << "Select vehicle type(1:Car ,2.Bike,3.Truck) : ";
    cin >> ch;
    cin.ignore();

    cout << "Enter owner name:";
    cin >> n;
    getline(cin, n); 

    cout << "Enter Vehicle ID: ";
    cin >>id;
    getline(cin, n); 
    cout << "Enter the speed of the vehile: ";
    cin >> ss;

    if(ch == 1){
    cout << "Vehicle Type: Car" << endl;
    Car c1(n,id,ss);
    c1.Calculate_fine(ss);
    c1.dispaly();
    }

    else if(ch == 2){
    cout << "Vehicle type:Bike" << endl;
    Bike b1(n,id,ss);
    b1.Calculate_fine(ss);
    b1.dispaly();
    }

    else if(ch == 3) {
    cout << "Vehicle Type:Truck" << endl; 
    Truck t1(n,id,ss);
    t1.Calculate_fine(ss);
    t1.dispaly();
    }

    else{
        cout << "Invalid Input" << endl;
    }
    return 0;
}