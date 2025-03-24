#include <iostream>

using namespace std;

class Device{
    protected:
    string deviceID;
    string deviceType;
    float powerrating;
    bool status;
    public:
    Device(string id , string type,float rating) : deviceID(id) , deviceType(type) , powerrating(rating) , status(false) {}

    virtual void turnOn() {}
    virtual void turnOFF() {}

    virtual double calculatePowerUsage(int hours) {}
    string gettype() const {return deviceType;}
};

class Light : public Device{
    public:
    Light(string id , string type,float rating) : Device(id,type,rating) {}
    void turnOn() override{
        status = true;
        cout << gettype()<< "[ID: " << deviceID << "] turned ON." << endl; 
     }

    void turnOFF() override{
        status = false;
        cout << gettype()<< "[ID: " << deviceID << "] turned OFF." << endl;
    } 

    double calculatePowerUsage(int hours) override{
        return powerrating * hours;
    }
};

class Fan : public Device {
    private:
    float speedFactor;
    public:
    Fan(string id , string type,float rating ,float sf) :speedFactor(sf), Device(id,type,rating) {}
     void turnOn() override{
        status = true;
        cout << gettype() << "[ID: " << deviceID << "] turned ON." << endl; 
     }

    void turnOFF() override{
        status = false;
        cout << gettype() << "[ID: " << deviceID << "] turned OFF." << endl;
    } 

    double calculatePowerUsage(int hours) override{
        return powerrating * hours * speedFactor;
    }
};
class AC : public Device {
    private:
    int desiredTemp , currentTemp;
    public:
    AC(string id , string type,float rating ,int desiretemp) : desiredTemp(desiretemp) , Device(id,type,rating) {}

    void turnOn() override{
        status = true;
        cout <<gettype() << "[ID: " << deviceID << "] turned ON.Cooling to " << desiredTemp << endl; 
     }

    void turnOFF() override{
        status = false;
        cout <<gettype() << "[ID: " << deviceID << "] turned OFF." << endl;
    }   

    double calculatePowerUsage(int hours) override{
        cout << "Enter Current Temperature";
        cin >> currentTemp;
        return powerrating * hours * ( 1 - currentTemp - desiredTemp) / 100 ;
    } 
};

class MaintenanceTool{};

class SecuritySystem : public Device {
    friend class MaintenanceTool;
    public:
    SecuritySystem(string id , string type,float rating ) :  Device(id,type,rating) {}

     void turnOn() override{
        status = true;
        cout << gettype() << "[ID: " << deviceID << "] activated." << endl; 
     }

    void turnOFF() override{
        status = false;
        cout << gettype() << "[ID: " << deviceID << "] deactivated." << endl;
    } 

    double calculatePowerUsage(int hours) override{
        return powerrating * hours;
    }

    friend void accessSecurityLogs(){};
};

void accessSecurityLogs(const SecuritySystem& secsys){
     cout << "Security Logs Accessed:\n";
    cout << "- Intrusion Detected at 3:00 AM\n";
    cout << "- System Reset Required\n";
}

class MaintenanceTool{
    public:
    void resetSystem(SecuritySystem &secSys) {
        cout << "Maintenance Personnel Resetting Security Alerts...\n";
    }
};
class User{
    private:
    string UserID;
    string UserRole;
    int access_level;
    public:
    User(string id , string role, int level) : UserID(id) , UserRole(role) , access_level(level) {}

    void viewAccessibleDevices(Device* devices[] ,int size){
        cout << "User: " << UserID << "-Accessible Devices: " << endl;
        for(int i = 0 ; i  < size ; i++){
            if(devices[i]->gettype() != "Security System" || UserRole == "Maintenance Staff")
                  cout << devices[i]->gettype() << endl;            
            }
    }

    void viewSecurityLogs(SecuritySystem &secSys){
        if(UserRole == "Maintenance Staff"){
            accessSecurityLogs(secSys);
        }
        else{
            cout << "Access Denied." << endl;
        }
    }    
};

int main(){
   User user1("U001", "Regular User", 1);
   User user2("U002", "Maintenance Staff", 2);

   Light light1("L001", "LED Light", 10); 
   Fan fan1("F001" , "Ceiling Fan" ,75 ,3);
   AC ac1("AC001", "Split AC", 1500, 25);
   SecuritySystem secSys1("S001" , "Home Alarm", 100);

    Device *devices[4] = {&light1, &fan1, &ac1, &secSys1};
   
    light1.turnOn(); 
    fan1.turnOn(); 
    ac1.turnOn();
    secSys1.turnOn();

    cout << "\nPower Consumption:\n";
    cout << "LED Light: " << light1.calculatePowerUsage(5) << " Watts\n";
    cout << "Ceiling Fan: " << fan1.calculatePowerUsage(3) << " Watts\n";
    cout << "Split AC: " << ac1.calculatePowerUsage(6) << " Watts\n";
    cout << "Security System: " << secSys1.calculatePowerUsage(24) << " Watts\n";

    user1.viewAccessibleDevices(devices,4);
    user2.viewSecurityLogs(secSys1);

    return 0;
}