#include <iostream>
using namespace std;
class Object{
    private:
    static int count;
    int serial_num;
    public:
    Object(){
        serial_num = ++count;
    }
     void showSerial() const {
        cout << "I am object number " << serial_num << endl;
    }
};

int Object::count = 0;

int main() {
    Object obj1, obj2, obj3;
    obj1.showSerial();
    obj2.showSerial();
    obj3.showSerial();
    return 0;
}
 