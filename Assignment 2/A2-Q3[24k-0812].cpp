#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Vehicle{
protected:
    string vehicleID;
    static int totalDeliveries;

    Vehicle(string id) : vehicleID(id) {}

public:
    virtual ~Vehicle() {}

    virtual void calculateRoute() = 0;
    virtual void estimateDeliveryTime() = 0;
    virtual void command(string cmd) = 0;
    virtual void command(string cmd, int urgency) = 0;

    static int getTotalDeliveries() { return totalDeliveries; }

    friend bool operator==(const Vehicle &v1, const Vehicle &v2);
};

int Vehicle::totalDeliveries = 0;

class RamzanDrone : public Vehicle{
private:
    double speed;
    double batteryLife;

public:
    RamzanDrone(string id, double spd, double battery) : Vehicle(id), speed(spd), batteryLife(battery) {}

    void calculateRoute() override{
        cout << "Drone " << vehicleID << ": Calculating aerial route via GPS satellites\n";
    }

    void estimateDeliveryTime() override{
        cout << "Drone " << vehicleID << ": Estimated delivery in 15-30 minutes\n";
    }

    void command(string cmd) override{
        if (cmd == "Deliver"){
            cout << "Drone " << vehicleID << ": Initiating standard iftar meal delivery\n";
            totalDeliveries++;
        }
    }

    void command(string cmd, int urgency) override{
        if (cmd == "Deliver") {
            if (urgency > 7){
                cout << "Drone " << vehicleID << ": ACTIVATING HIGH-SPEED IFTAR DELIVERY MODE!\n";
                speed *= 1.5;
                batteryLife *= 0.8;
            }
            totalDeliveries++;
        }
    }

    double getSpeed() const { return speed; }
    double getBattery() const { return batteryLife; }
};

class RamzanTimeShip : public Vehicle
{
private:
    bool historicalAccuracyVerified;
    int temporalStability;

public:
    RamzanTimeShip(string id, int stability): Vehicle(id), temporalStability(stability), historicalAccuracyVerified(false) {}

    void verifyHistoricalConsistency(){
        historicalAccuracyVerified = true;
        cout << "TimeShip " << vehicleID << ": Historical timeline verified - safe to proceed\n";
    }

    void calculateRoute() override{
        cout << "TimeShip " << vehicleID << ": Calculating temporal coordinates\n";
        verifyHistoricalConsistency();
    }

    void estimateDeliveryTime() override{
        cout << "TimeShip " << vehicleID << ": Delivery will arrive precisely at requested time\n";
    }

    void command(string cmd) override{
        if (cmd == "Deliver"){
            cout << "TimeShip " << vehicleID << ": Beginning standard temporal delivery\n";
            totalDeliveries++;
        }
    }

    void command(string cmd, int urgency) override{
        if (cmd == "Deliver") {
            if (urgency > 5){
                cout << "TimeShip " << vehicleID << ": INITIATING HISTORICAL SENSITIVITY PROTOCOL\n";
                verifyHistoricalConsistency();
            }
            totalDeliveries++;
        }
    }

    int getStability() const { return temporalStability; }
};

class RamzanHyperPod : public Vehicle{
private:
    double capacity;
    double efficiency;

public:
    RamzanHyperPod(string id, double cap, double eff)
        : Vehicle(id), capacity(cap), efficiency(eff) {}

    void calculateRoute() override{
        cout << "HyperPod " << vehicleID << ": Mapping underground hyperloop network\n";
    }

    void estimateDeliveryTime() override{
        cout << "HyperPod " << vehicleID << ": Bulk delivery ETA 45-60 minutes\n";
    }

    void command(string cmd) override{
        if (cmd == "Deliver"){
            cout << "HyperPod " << vehicleID << ": Loading bulk sehri packages\n";
            totalDeliveries++;
        }
    }

    void command(string cmd, int urgency) override{
        if (cmd == "Deliver") {
            cout << "HyperPod " << vehicleID << ": Prioritizing bulk ";
            if (urgency > 6){
                cout << "IFTAR delivery via express tunnel\n";
            }
            else{
                cout << "SEHRI delivery via standard route\n";
            }
            totalDeliveries++;
        }
    }

    double getCapacity() const { return capacity; }
    double getEfficiency() const { return efficiency; }
};


bool operator==(const Vehicle &v1, const Vehicle &v2){

    const RamzanDrone *drone1 = dynamic_cast<const RamzanDrone *>(&v1);
    const RamzanDrone *drone2 = dynamic_cast<const RamzanDrone *>(&v2);

    const RamzanTimeShip *ship1 = dynamic_cast<const RamzanTimeShip *>(&v1);
    const RamzanTimeShip *ship2 = dynamic_cast<const RamzanTimeShip *>(&v2);

    const RamzanHyperPod *pod1 = dynamic_cast<const RamzanHyperPod *>(&v1);
    const RamzanHyperPod *pod2 = dynamic_cast<const RamzanHyperPod *>(&v2);

    if (drone1 && drone2){
        return (drone1->getSpeed() * drone1->getBattery()) ==
               (drone2->getSpeed() * drone2->getBattery());
    }
    else if (ship1 && ship2) {
        return ship1->getStability() == ship2->getStability();
    }
    else if (pod1 && pod2){
        return (pod1->getCapacity() * pod1->getEfficiency()) ==
               (pod2->getCapacity() * pod2->getEfficiency());
    }

    return false;
}

Vehicle *resolveConflict(Vehicle *v1, Vehicle *v2, int packageUrgency){
    return v1;
}

int main(){
    Vehicle *drone = new RamzanDrone("DRONE-IFTAR-1", 120.5, 95.0);
    Vehicle *timeship = new RamzanTimeShip("TIMESHIP-X7", 85);
    Vehicle *hyperpod = new RamzanHyperPod("HYPOD-BULK-3", 500.0, 88.5);

    Vehicle *vehicles[3] = {drone, timeship, hyperpod};

    for (int i = 0; i < 3; i++){
        vehicles[i]->calculateRoute();
        vehicles[i]->estimateDeliveryTime();
        cout << endl;
    }

    cout << "=== Testing Commands ===\n";
    drone->command("Deliver");
    drone->command("Deliver", 9);
    cout << endl;

    timeship->command("Deliver");
    timeship->command("Deliver", 6);
    cout << endl;

    hyperpod->command("Deliver");
    hyperpod->command("Deliver", 7);
    cout << endl;

    cout << "=== Conflict Resolution ===\n";
    Vehicle *chosen = resolveConflict(drone, hyperpod, 8);
    cout << "Selected vehicle for delivery: " << (chosen == drone ? "Drone" : "HyperPod") << endl;

    delete drone;
    delete timeship;
    delete hyperpod;

    cout << "\nTotal deliveries scheduled: " << Vehicle::getTotalDeliveries() << endl;
    return 0;
}