#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
    string name;
    string id;
    string address;
    string phone_num;
    string email;
    public:
    Person(string n , string id ,string num , string add , string mail){
        this->address = add;
        this->phone_num = num;
        this->name = n;
        this->id = id;
        this->email = mail;
    }

    void updateInfo(string n , string i , string a, string p , string e){
        name = n ;
        address = a;
        id = i ;
        email = e;
        phone_num = p;
    }

    virtual void displayInfo(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone-num: " << phone_num << endl;
        cout << "Email: " << email << endl; 
    }
};

class Student : public Person{
    string *enrolled_course;
    int nums;
    float GPA;
    int enrollment_year;
    public:
    Student(string *course, float gpa , int year ,int nums,string n , string id ,string num , string add , string mail) : Person(n,id,num,add,mail) {
        this->enrolled_course = new string[nums];
        for(int i = 0 ; i < nums ; i++){
            enrolled_course[i] = course[i];
        }
        this->GPA = gpa;
        this->enrollment_year = year;
    }

    void displayInfo() override{
        Person :: displayInfo();
        for(int i = 0 ; i < nums ; i++){
            cout << "Enrolled Course " << i+1  << ": " << enrolled_course[i] << endl;
        }
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollment_year << endl;
    }

    float getgpa() const {return GPA;}

    ~Student(){
        delete[] enrolled_course;
    }
};

class  Professor : public Person{
    string department;
    string *courses_taught;
    int taught;
    float salary;
    public:
    Professor(string d ,string *c ,int taught , float s ,string n , string id ,string num , string add , string mail) : Person(n,id,num,add,mail){
        this->courses_taught = new string[taught];
        for(int i = 0 ; i < taught ; i++){
            courses_taught[i] = c[i];
        }
        this->department = d;
        this->salary = s;
    }

    void displayInfo() override{
        Person::displayInfo();
        cout << "Department: " << department<< endl;
        for(int i = 0 ; i  < taught ; i++){
             cout << "Courses Taught " << i+1 << ": " << courses_taught[i] << endl;
        }
        cout << "Salary: " << salary << endl;
    }

    ~Professor(){
        delete[] courses_taught;
    }
};

class Staff : public Person{
    string department;
    string position;
    float salary;
    public:
    Staff(string d , string p , float s ,string n , string id ,string num , string add , string mail) : Person(n,id,num,add,mail){
        this->department = d;
        this->position = p;
        this->salary = s;
    }

    void displayInfo() override{
        Person ::displayInfo();
        cout << "Department: " << department<< endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }

};

class Course{
    string courseid;
    string coursename;
    int credits;
    Professor* instructor;
    string schedule;
    Student** enrolled_student;
    int max;
    int count;
    public:
    Course(string cid , string cn , int c, Professor* intrsu , string sche) : max(10) , count(0){
        this->courseid = cid;
        this->coursename = cn;
        this->credits = c;
        this->instructor = intrsu;
        this->schedule = sche;
        this->enrolled_student = new Student*[max];
    }

    ~Course(){
        delete[] enrolled_student;
    }

    void registerStudent(Student* s){
        if(count > max) {
            cout << "Sorry no more students can enrolled in this course." << endl;
        }
        else{
            enrolled_student[count] = s;
            count++ ;
        }
    }

    void CalculateGrade(){
     for(int i = 0 ; i < count ; i++){
        float gpa = enrolled_student[i]->getgpa();
        if(gpa == 4){
            cout << "Grade: A" << endl;
        }
        else if(gpa >= 3.75 && gpa <=4){
            cout << "Garde: A-" << endl;
        }
        else if(gpa >=3.5 && gpa <= 3.75){
            cout << "Garde: B+" << endl;
        }
        else if(gpa >= 3.0 && gpa <= 3.5){
            cout << "Garde: B" << endl;
        }
        else if(gpa >= 2.75 && gpa <= 3.0){
            cout << "Garde: B-" << endl;
        }
        else if(gpa >= 2.5 && gpa <=2.75){
            cout << "Garde: C+" << endl;
        }
        else if(gpa >= 2.0 && gpa <= 2.5){
            cout << "Garde: C" << endl;
        }
        else if(gpa >= 1.75 && gpa <=2.0){
            cout << "Garde: C-" << endl;
        }
        else if(gpa >= 1 && gpa <= 1.75){
            cout << "Garde: D" << endl;
        }
        else{
             cout << "Garde: F" << endl;
        }
     }   
    }
};

int main(){
  string profCourses[] = {"OOP", "Data Structures"};
  Professor prof("Computer Science", profCourses, 2, 85000.0, "Dr. John Smith", "P123", "555-9876", "123 Faculty St.", "john.smith@university.edu");

    string studentCourses[] = {"OOP", "Data Structures"};
    Student student1(studentCourses, 3.8, 2022, 2, "Alice Johnson", "S456", "555-1234", "456 Student Ln.", "alice.johnson@university.edu");
    Student student2(studentCourses, 2.9, 2023, 2, "Bob Brown", "S789", "555-5678", "789 Student Rd.", "bob.brown@university.edu");

    Staff staff1("Administration", "Registrar", 60000.0, "Mary Lee", "ST001", "555-2222", "10 Admin Plaza", "mary.lee@university.edu");

    Course course1("CS101", "Object-Oriented Programming", 3, &prof, "Mon & Wed 10:00 AM - 11:30 AM");

    course1.registerStudent(&student1);
    course1.registerStudent(&student2);

    cout << "\n--- Professor Info ---" << endl;
    prof.displayInfo();

    cout << "\n--- Student 1 Info ---" << endl;
    student1.displayInfo();

    cout << "\n--- Student 2 Info ---" << endl;
    student2.displayInfo();

    cout << "\n--- Staff Info ---" << endl;
    staff1.displayInfo();

    cout << "\n--- Grade Calculation ---" << endl;
    course1.CalculateGrade();

    return 0;
}