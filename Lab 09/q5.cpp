#include <iostream>
using namespace std;

class Activity{
    public:
    virtual double calculateCaloriesBurned() = 0;

    virtual ~ Activity() {}
};

class Running : public Activity{
    private:
    double distance;
    double time;
    public:
    Running(double d,double t){
        this->distance = d;
        this->time = t;
    }

    double calculateCaloriesBurned() override{
        double calories = 60 * distance;
        return calories;
    }
};

class Cycling : public Activity{
    private:
    double speed;
    double time;
    public:
    Cycling(double s,double t){
        this->speed = s;
        this->time = t;
    }
    double calculateCaloriesBurned() override{
        double distance = speed * time;
        double calories = distance * 30;
        return calories;
    }
};

int main(){
    Running r(5 , 60);
    Cycling c(50 , 50);

    cout << "Calories Burned During Runnig: " << r.calculateCaloriesBurned() << endl;
    cout << "Calories Burned During Cycling: " << c.calculateCaloriesBurned() << endl;

    return 0;
}
