/*Picture an innovative design tool aimed at architects and graphic designers that allows for creating, manipulating, and analyzing various
 geometric shapes. The system is structured around a Shape class, which includes data members such as position, color, and an optional
  borderThickness. It provides functions like draw() for rendering, calculateArea() for area measurement, and calculatePerimeter() for 
  perimeter computation. 
Derived classes such as Circle, Rectangle, Triangle, and Polygon introduce their own properties-for example, a Circle includes radius and 
center position, while a Rectangle includes width, height, and top-left corner position. Each derived class overrides draw(), calculateArea(), 
and calculate Perimeter() to handle their respective geometries. */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Shape {
protected:
    string position;
    string color;
    int borderthickness;

public:
    Shape(string position, string color, int thickness) {
        this->borderthickness = thickness;
        this->position = position;
        this->color = color;
    }

    virtual void draw() {
        cout << "This shape is rendering." << endl;
    }

    virtual float Calculatearea() { return 0; }  

    virtual float CalculatePerimeter() { return 0; } 

    virtual ~Shape() {}  
};

class Circle : public Shape {
private:
    float radius;
    float centerposition;

public:
    Circle(float r, float center, string position, string color, int thickness)
        : Shape(position, color, thickness), radius(r), centerposition(center) {}

    float Calculatearea() override {
        return (3.142) * (radius) * (radius);
    }

    float CalculatePerimeter() override {
        return 2 * (3.142) * (radius);
    }
};

class Rectangle : public Shape {
private:
    float width;
    float height;
    float top_leftCorner;

public:
    Rectangle(float width, float height, float top_leftCorner, string position, string color, int thickness)
        : Shape(position, color, thickness), width(width), height(height), top_leftCorner(top_leftCorner) {}

    float Calculatearea() override {
        return width * height;
    }

    float CalculatePerimeter() override {
        return 2 * (width + height);  
    }
};

class Triangle : public Shape {
private:
    float a;
    float b;
    float c;

public:
    Triangle(float a, float b, float c, string position, string color, int thickness)
        : Shape(position, color, thickness), a(a), b(b), c(c) {}

    float Calculatearea() override {
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    float CalculatePerimeter() override {
        return a + b + c;
    }
};

class Polygon : public Shape {
private:
    int numsides;
    float* sidelength;
    float apothem;

public:
    Polygon(float apth, string position, string color, int thickness, int numsides)
        : Shape(position, color, thickness), apothem(apth), numsides(numsides) {
        sidelength = new float[numsides];
        for (int i = 0; i < numsides; i++) {
            cout << "Enter length of side " << i + 1 << ": ";
            cin >> sidelength[i];
        }
    }

    float CalculatePerimeter() override {
        float perimeter = 0;
        for (int i = 0; i < numsides; i++) {
            perimeter += sidelength[i];
        }
        return perimeter;
    }

    float Calculatearea() override {
        return (CalculatePerimeter() * apothem) / 2;
    }

    ~Polygon() {
        delete[] sidelength;
    }
};

int main() {
    Shape* c1 = new Circle(5.5, 4.2, "Upward", "Black", 4);
    Shape* r1 = new Rectangle(3.2, 8.4, 7.8, "Downward", "White", 7);
    Shape* t1 = new Triangle(2.2, 3.4, 4.1, "Downward", "Black", 4);

    int numside;
    cout << "Enter num sides for Polygon: ";
    cin >> numside;
    Shape* p1 = new Polygon(5.5, "Upward", "White", 4, numside);

    cout << "Area of Circle: " << c1->Calculatearea() << endl;
    cout << "Perimeter of Circle: " << c1->CalculatePerimeter() << endl;

    cout << "Area of Rectangle: " << r1->Calculatearea() << endl;
    cout << "Perimeter of Rectangle: " << r1->CalculatePerimeter() << endl;

    cout << "Area of Triangle: " << t1->Calculatearea() << endl;
    cout << "Perimeter of Triangle: " << t1->CalculatePerimeter() << endl;

    cout << "Perimeter of Polygon: " << p1->CalculatePerimeter() << endl;
    cout << "Area of Polygon: " << p1->Calculatearea() << endl;

    delete c1;
    delete r1;
    delete t1;
    delete p1;

    return 0;
}

























