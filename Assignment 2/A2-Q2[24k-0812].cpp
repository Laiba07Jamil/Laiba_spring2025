#include <iostream>
#include <string>
using namespace std;

class Ghost{
    protected:
    string name;
    int scarelevel;
    public:
    Ghost(string name , int scarelevel){
        this->name = name;
        this->scarelevel = scarelevel;
    }

    virtual void haunt(){
        cout << "Ghost is haunting us" << endl;
    }

    friend ostream& operator << (ostream &output , const Ghost &obj);

    Ghost operator +(const Ghost &obj){
        int new_scare = scarelevel + obj.scarelevel;
        string new_name = name + "&" + obj.name;
        return Ghost(new_name,new_scare);
    }  

    int getScareLevel() {return scarelevel;}
};

ostream& operator << (ostream &output , const Ghost &obj){
    output << "Ghost name: " << obj.name <<endl;
    output << "Ghost Scare level: " << obj.scarelevel << endl; 
}

class Poltergeists : virtual public Ghost{                 
    public:
    Poltergeists(string n , int s) : Ghost(n,s) {}
    void haunt() override{
        cout << name << " ghost is moving objects." << endl;
    }
};   

class Banshees : public Ghost{                            
    public:                 
    Banshees(string n , int s) : Ghost(n,s) {}
    void haunt() override{
        cout << name << " ghost let out a terrifying scream." << endl;
    }
}; 

class ShadowGhosts :virtual public Ghost{                 
    public:
     ShadowGhosts(string n , int s) : Ghost(n,s) {}
     void haunt() override{
        cout << name << " ghost let out a creepy wshiper." << endl;
    }
};

class ShadowPoltergeist : public Poltergeists , public ShadowGhosts{
    public:
    ShadowPoltergeist(string n , int s) : Ghost(n,s) ,Poltergeists(n,s) , ShadowGhosts(n,s) {}
    void haunt() override  {
        Poltergeists :: haunt();
        ShadowGhosts :: haunt();
    }
};
class Visitor {
    protected:
    string name;
    int bravery;
    public:
    Visitor(string visitorName, int braveryLevel) : name(visitorName) {
        if (braveryLevel < 1) braveryLevel = 1;
        if (braveryLevel > 10) braveryLevel = 10;
        bravery = braveryLevel;
    }

    string getName() const { return name; }
    int getBravery() const { return bravery; }

    void reactToScare(int ghostScare) const {
        cout << name << " encounters a ghost with scare level " << ghostScare << "!" << endl;

        bool isCowardly = (bravery >= 1 && bravery <= 4);
        bool isAverage = (bravery >= 5 && bravery <= 7);
        bool isFearless = (bravery >= 8 && bravery <= 10);

        bool ghostIsWeak = (ghostScare >= 1 && ghostScare <= 4);
        bool ghostIsModerate = (ghostScare >= 5 && ghostScare <= 7);
        bool ghostIsTerrifying = (ghostScare >= 8 && ghostScare <= 10);

        if (isCowardly && ghostIsWeak) {
            cout << name << " still feels uneasy but manages to laugh nervously." << endl;
        } 
        else if (isCowardly && ghostIsModerate) {
            cout << name << " gets extremely scared and hides behind others!" << endl;
        } 
        else if (isCowardly && ghostIsTerrifying) {
            cout << name << " screams and runs away in terror!" << endl;
        } 
        else if (isAverage && ghostIsWeak) {
            cout << name << " finds the ghost funny and mocks it!" << endl;
        } 
        else if (isAverage && ghostIsModerate) {
            cout << name << " gets a shaky voice but stands firm!" << endl;
        } 
        else if (isAverage && ghostIsTerrifying) {
            cout << name << " screams but doesn't run away!" << endl;
        } 
        else if (isFearless && ghostIsWeak) {
            cout << name << " laughs loudly and challenges the ghost!" << endl;
        } 
        else if (isFearless && ghostIsModerate) {
            cout << name << " stands tall and ignores the ghost. " << endl;
        } 
        else if (isFearless && ghostIsTerrifying) {
            cout << name << " gets slightly nervous but keeps their cool!" << endl;
        }
    }
    
};


class HauntedHouse{
    protected:
    string name;
    Ghost* ghosts[3];
    int ghostcount;
    public:
    HauntedHouse(string name) : name(name), ghostcount(0) {}

    void addGhost(Ghost* ghost) {
        if (ghostcount < 3) {
            ghosts[ghostcount++] = ghost;
        }
    }

    void startHaunting(Visitor visitors[], int numVisitors) const {
        cout << "\n*** Welcome to " << name << " ***\n";
        for (int i = 0; i < ghostcount; i++) {
            ghosts[i]->haunt();
            for (int j = 0; j < numVisitors; j++) {
                visitors[j].reactToScare(ghosts[i]->getScareLevel());
            }
        }
    }

};

 
void visit(Visitor visitors[], int numVisitors, HauntedHouse& house) {
    house.startHaunting(visitors, numVisitors);
}


int main() {
    HauntedHouse house1("Dark Manor");
    HauntedHouse house2("Phantom Castle");

    Poltergeists polter("John", 5);
    Banshees banshee("Emily", 8);
    ShadowGhosts shadow("Tom", 3);
    ShadowPoltergeist hybrid("Michael", 6);

    house1.addGhost(&polter);
    house1.addGhost(&banshee);

    house2.addGhost(&shadow);
    house2.addGhost(&hybrid);

    Visitor visitors[] = {
        Visitor("Alice", 3),   
        Visitor("Bob", 6),     
        Visitor("Charlie", 9)  
    };

    visit(visitors, 3, house1);
    visit(visitors, 3, house2);

}
