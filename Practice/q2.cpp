// #include <iostream>
// #include <string>
// using namespace std;

// template <class T>
// class Course{
//     string name;
//     string course_code;
//     int credithours;
//     string instructor;
//     public:
//     Course(string n , string c, int ci ,string i){
//         this->course_code = c;
//         this->name = n ;
//         this->instructor = i;
//         this->credithours = ci;
//     }
//     virtual void printdetails(){
//         cout << name << endl;
//         cout << course_code << endl;
//         cout << credithours << endl;
//         cout << instructor << endl;
//     }
// };

// template <class T>
// class TheoryCourse : public Course<T>{
//     float project , final_marks;
//     float mid1 ,mid2;
//     public:
//     TheoryCourse(float f,float p , float m1 ,float m2 ,string n , string c,int ci,string i) : Course<T>(n ,c , ci ,i){
//         this->final_marks = f;
//         this->project = p;
//         this->mid2 =m2;
//         this->mid1 = m1;
//     }

//     string get_grade(){
//         float result = project + final_marks + mid1 + mid2;
//         if(result >= 65.5 && result <= 70.5){
//             cout << "grade : C" << endl;
//         }
//         else if(result >= 70.5 && result <= 75.5){
//             cout << "Grade : B" << endl;
//         }
//         else if(result >= 75.5 && result <= 80.5){
//             cout << "Grdae : A";
//         }
//         else{
//             cout << "Grade : A+" ;
//         }
//     }

//     void printdetails() override{
//         Course::printdetails();
//          cout << project << endl;
//         cout << final_marks << endl;
//         cout << mid2 << endl;
//         cout << mid1 << endl;
//             }
// };

// template <class T>
// class LabCoursE : public Course<T>{
//     float lab_tasks;
//     float lab_mid;
//     float lab_final_marks;
//     LabCoursE(float lb , float lf,float labfm,string n , string c,int ci,string i) : Course<T>(n ,c , ci ,i) {
//         this->lab_final_marks = labfm;
//         this->lab_tasks = lb;
//         this->lab_mid = lf;
//     }

//     string getGrage(){
//         float result = lab_tasks + lab_mid + lab_final_marks;
//         if(result >= 65.5 && result <= 70.5){
//             cout << "grade : C" << endl;
//         }
//         else if(result >= 70.5 && result <= 75.5){
//             cout << "Grade : B" << endl;
//         }
//         else if(result >= 75.5 && result <= 80.5){
//             cout << "Grdae : A";
//         }
//         else{
//             cout << "Grade : A+" ;
//         }
//     }

//     void printdetails() override{
//         Course::printdetails();
//          cout << lab_final_marks << endl;
//         cout << lab_mid << endl;
//         cout << lab_tasks << endl;
//    }
// };

// template <typename T>
// T display_grade(T& obj){
//     obj.get_grade();
// }

// template <typename T1>
// void filter_courses(T1* arr , string instructor ,int size){
//     bool found = false;
//     for(int i = 0  ; i  < size , i++){
//         if(arr[i].getinstructor() == instructor){
//             arr[i].printdetails();
//             found = true;
//         }
//     }
//     if(!found){
//         cout << "not found" << endl;
//     }
// }
/* string str = "Hello";
ofstream file("binary.dat" , ios :: binary);
if(file){
size_t len = str.length();
file.write(reintercept_cast<char*>&(len) , sizeof(len));
file.write(str, len);
file.close()}

ifstream infile("binary.dat" , ios :: binary);
if(infile){
string readstr;
size_t readSize;
infile.read(reintercept_cast<char*>&(readSize) , sizeof(readSize));
readstr.resize(readSize);
infile.read(readstr , readSize);
infile.close();}*/



template <class T>
class Box{
    T value;
    public:
    Box(T val) : value(val) {}
    virtual void display(){
        cout << "= " << value << endl;
    }
};

template <class T>
class couluresBox : public Box<T>{
    string color;
    public:
    couluresBox(string c , T v) : Box<T>(v){
        this->color = c;
    }
    void display(){
        Box::display();
        cout << "Color: " << color << endl;
    }
};

int main(){
    Box<int> obj(5);
    couluresBox <double> obj1("bule" , 6);

}

