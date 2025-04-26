#include <iostream>
#include <string>
using namespace std;

unsigned long hashPassword(const string &password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = hash * 33 + c;
    }
    return hash;
}

class User {
protected:
    string name;
    int id;
    string email;
    unsigned long hashed_password;
    string permissions;

public:
    User(string n, int i, string e, string password, string perms) : name(n), id(i), email(e), permissions(perms) {
        hashed_password = hashPassword(password);
    }

    bool authenticate(string password) {
        return hashPassword(password) == hashed_password;
    }

    virtual void display() {
        cout << "Name: " << name << " | ID: " << id << " | Email: " << email << "\n";
    }

    bool hasPermission(string action) {
        return permissions == action;
    }
};

class Student : public User {
protected:
    int *assignments;
    int numAssing; 

public:
    Student(string n, int i, string e, string password , int numAssing) : User(n, i, e, password, "submit_assignment") {
        assignments = new int [numAssing] ; 
        for(int i = 0 ; i < numAssing ; i++){
            assignments[i] = 0;
        }
    }

    void submitAssignment(int index) {
        if (index >= 0 && index < 5) {
            assignments[index] = 1;
            cout << "Assignment " << index + 1 << " submitted.\n";
        } else {
            cout << "Invalid assignment index.\n";
        }
    }

    void display() override {
        User::display();
        cout << "Assignments: ";
        for (int i = 0; i < 5; i++) {
            cout << assignments[i] << " ";
        }
        cout << "\n";
    }
};

class TA : public Student {
private:
    int *studentsAssigned;
    int numStudentAssign; 
    string projects[2] = {"", ""}; 

public:
    TA(string n, int i, string e, string password , int numStudentAssign,int numAssign) : Student(n, i, e, password,numAssign) {
        permissions = "view_projects manage_students";
        studentsAssigned = new int[numStudentAssign] ;
        for(int i = 0 ; i < numStudentAssign ; i++){
            studentsAssigned[i] = 0;
        }
    }

    void assignStudent(int studentID) {
        for (int j = 0; j < 10; j++) {
            if (studentsAssigned[j] == 0) {
                studentsAssigned[j] = studentID;
                cout << "Student " << studentID << " assigned to TA.\n";
                return;
            }
        }
        cout << "TA already has 10 students.\n";
    }

    void startProject(string projectName) {
        for (int i = 0; i < 2; i++) {
            if (projects[i] == "") {
                projects[i] = projectName;
                cout << "Started project: " << projectName << "\n";
                return;
            }
        }
        cout << "Cannot take more than 2 projects.\n";
    }

    void display() override {
        Student::display();
        cout << "Projects: " << projects[0] << " " << projects[1] << "\n";
    }
};

class Professor : public User {
public:
    Professor(string n, int i, string e, string password) : User(n, i, e, password, "assign_projects full_lab_access") {}

    void assignProjectToTA(TA &ta, string project) {
        ta.startProject(project);
    }

    void display() override {
        User::display();
        cout << "Role: Professor\n";
    }
};

void authenticateAndPerformAction(User *user, string action, string password) {
    if (user->authenticate(password)) {
        if (user->hasPermission(action)) {
            cout << "Action " << action << " permitted.\n";
        } else {
            cout << "Permission denied for action: " << action << "\n";
        }
    } else {
        cout << "Authentication failed.\n";
    }
}

int main() {
    Student student("Alice", 1, "alice@example.com", "pass123",10);
    TA ta("Bob", 2, "bob@example.com", "pass456",10,5);
    Professor professor("Dr. Smith", 3, "smith@example.com", "pass789");

    student.display();
    ta.display();
    professor.display();

    cout << "\n-- Student Actions --\n";
    student.submitAssignment(2);
    student.display();

    cout << "\n-- TA Actions --\n";
    ta.assignStudent(101);
    ta.display();

    cout << "\n-- Professor Actions --\n";
    professor.assignProjectToTA(ta, "AI Research");
    ta.display();

    cout << "\n-- Authentication Tests --\n";
    authenticateAndPerformAction(&student, "submit_assignment", "pass123");
    authenticateAndPerformAction(&ta, "view_projects", "pass456");
    authenticateAndPerformAction(&professor, "full_lab_access", "wrongpass");

}
