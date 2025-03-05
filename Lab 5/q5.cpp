#include <iostream>
using namespace std;
class Engine{
    string fueltype;
    int horsepower;
    public:
    Engine() : fueltype("") , horsepower(0) {}
    
    void setfueltype(string fueltype){
        this->fueltype = fueltype;
    }
    void sethorsepower(int horsepower){
        this->horsepower = horsepower;
    }

    string getfueltype(){return fueltype;}
    int gethorsepower(){return horsepower;}
};

class Wheels{
    int size;
    string color;
    public:
    Wheels() : size(0) , color("") {}
    void setsize(int size){
        this->size =size;
    }
    void setcolor(string color){
        this->color = color;
    }

    int getsize(){return size;}
    string getcolor(){return color;}
};

class Headlights{
    bool status;
    public:
    Headlights() : status(false) {}
    void setstatus(bool status){
        this->status = status;
    }
    bool getstatus(){return status;}
};

class Steering{
    string type;
    bool isturning;
    public:
    Steering() : type("") , isturning(false) {}
    void settype(string type){
        this->type = type;
    }
    void setisturning(bool isturning){
        this->isturning = isturning;
    }
    string gettype(){return type;}
    bool getisturning(){return isturning;}
};

class Car{
    Engine* engine;     // Aggregation
    Wheels w;    
    Headlights h;       // composition      
    Steering s;
    public:
    Car(Wheels w, Headlights h,Steering s,Engine* Engine){
        this->w = w;
        this->s =s;
        this->h = h;
        this->engine =  Engine;
    }
    void displayCarDetails() {
        cout << "Car Details:\n";
        cout << "Engine: " << engine->getfueltype() << ", " << engine->gethorsepower() << " HP\n";
        cout << "Wheels: Size " << w.getsize() << ", Color " << w.getcolor() << endl;
        cout << "Headlights: " << (h.getstatus() ? "On" : "Off") << endl;
        cout << "Steering: Type " << s.gettype() << ", Turning: " << (s.getisturning() ? "Yes" : "No") << endl;
    }
};

int main(){
     // Create components
    Engine* e1 = new Engine();
    e1->setfueltype("Petrol");
    e1->sethorsepower(150);

    Wheels w1;
    w1.setsize(17);
    w1.setcolor("Black");

    Headlights h1;
    h1.setstatus(true);

    Steering s1;
    s1.settype("Power Steering");
    s1.setisturning(false);

    // Create Car object
    Car car1(w1, h1, s1, e1);
    car1.displayCarDetails();

}