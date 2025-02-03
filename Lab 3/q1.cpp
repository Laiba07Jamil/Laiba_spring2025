#include <iostream>
using namespace std;

class Time{
    private:
    int hours;
    int min;
    int sec;
    public:
    Time() : hours(0) , min(0) , sec(0){}
    
    Time(int hours,int min,int sec){        //Student(int hour , int mins ,int secs) :hours(hour),min(mins),sec(secs)
        this->hours = hours;
        this->min = min ;
        this->sec = sec;
    }
    
    void add(const Time t1 , const Time t2){
         sec = (t1.hours*3600)+ (t1.min*60) + (t1.sec) + (t2.hours*3600) + (t2.min*60) + (t2.sec);
         hours = ( sec / 3600 ) % 24;
         min = (sec % 3600) / 60 ;
         sec = (sec % 60);
    }
    void display(){
        cout << hours << ":";
        cout << min << ":" ;
        cout << sec;
    }
};

int main(){
    const Time t1(10,45,30);
    const Time t2(5,15,40);
    Time t3;
    t3.add(t1,t2);
    t3.display();


}
