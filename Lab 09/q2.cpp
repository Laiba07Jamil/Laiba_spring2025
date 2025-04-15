#include <iostream>
using namespace std;

class SmartDevice{
    public:
    SmartDevice() {}

    virtual void turnOn() = 0 ;
    virtual void turnOff() = 0;
    virtual bool getStatus() = 0;
    
    virtual ~SmartDevice () {}
};

class LightBulb : public SmartDevice{
    private:
    bool isOn;
    int brightness;

    public:
    LightBulb(bool on , int brightness){
        this->brightness = brightness;
        this->isOn = on;
    }

    void turnOn() override{
        isOn = true;
        cout << "Light Bulb is turn ON." << endl;
    }

    void turnOff() override{
        isOn = false;
        cout << "Light Bulb is turn OFF." << endl;
    }

    bool getStatus() {return isOn;}
};

class Thermostat : public SmartDevice{
    private:
     bool isOn;
    int temperature;

    public:
    Thermostat(bool on , int t){
        this->temperature = t;
        this->isOn = on;
    }

    void turnOn() override{
        isOn = true;
        cout << "Thermostat is turn ON." << endl;
    }

    void turnOff() override{
        isOn = false;
        cout << "Thermostat is turn OFF." << endl;
    }

    bool getStatus() {return isOn;}
};

int main(){
    LightBulb l(false , 50);
    Thermostat t(false , 17);

    l.turnOn();
    l.turnOff();

    t.turnOn();
    t.turnOff();

    if(l.getStatus()){
        cout << "Light Bulb is ON." << endl;
    }
    else{
        cout << "Light Bulb is OFF." << endl;
    }

    
    if(t.getStatus()){
        cout << "Thermostat is ON." << endl;
    }
    else{
        cout << "Thermostat is OFF." << endl;
    }

}
