#include <iostream>
using namespace std;

class Square{
    private:
    float sideLength;
    float area;
    static float allareas;
    public:
    Square() : sideLength(0.0) , area(0.0) {}
    Square(int sideLength){
        this->sideLength = sideLength;
        area = 0.0;
    }

    void calculateArea(){
        area = (this->sideLength) * (this->sideLength);
        this->allareas += area;
    }

    void setSideLength(float s){
        sideLength = s;
    }
    void setArea(float a){
        this->area =a;
    }
    void setallareas(float l){
        this->allareas = l;
    }

    float getArea(){return area;}
    static float getallarea(){return allareas;}
    float getSideLength(){return sideLength;}
};
float Square :: allareas= 0.0;

int main(){
    float a1,a2,a3;
    cout << "Enter the area 1:";
    cin >> a1;
    Square s1(a1);
    s1.calculateArea();
    cout << "Area: " << Square::.getArea() ;
    cout << " All Areas:" << Square::getallarea() << endl;
    cout << "Enter the area 2:";
    cin >> a2;
    Square s2(a2);
    s2.calculateArea();
    cout << "Area:" << Square ::getArea();
    cout << " All Areas:" << Square ::getallarea() << endl;
    cout << "Enter the area 3:";
    cin >> a3;
    Square s3(a3);
    s3.calculateArea();
    cout << "Area:" << Square::getArea();
    cout << " All Areas:" << Square::getallarea() << endl;
    return 0;
    
}