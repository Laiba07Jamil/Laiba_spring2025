#include <iostream>
#include <conio.h>
using namespace std;
class Calender{
    private:
    string array[12][31];
    int curr_year;
    public:
    Calender(){
        for(int i = 0 ; i < 12 ; i++){
            for (int j = 0 ; j < 31 ; j++){
                array[i][j] = " ";                   //for line 30 and 37
            }
        }
    }
    void Add_task(string task_detail,int date ,int month){
        if(date < 1 || date > 31 || month < 1 || month > 12){
            return;
        }
        else{
            array[month - 1][date - 1] = task_detail;      
			  }
    }

    void remove_task(int date_ , int month_){
         if(date_ < 1 || date_ > 31 || month_ < 1 || month_ > 12){            
		 return;
        }
        else{
            array[month_ - 1][date_ - 1] = " " ; 
        }
    }
    void show_task(){
        cout << "Showing Taks" << endl;
        for(int i = 0 ; i < 12 ; i++){
            for(int j = 0 ; j < 31 ; j++){
                if(array[i][j] != " " ){
                cout << "Day: " << j+1 << " Month: " << i+1 << " Task = " << array[i][j] << endl;
                }
            }
        }

    }
};


int main(){
    Calender c1;
    c1.Add_task("Meeting with client" ,6, 15);
    c1.Add_task("Doctor Appointment",2,10);
    c1.Add_task("Submit Project Report",3,5);
    c1.Add_task("Attend Wedding",4,22);
    c1.Add_task("Family Dinner",5,12);
    char ch;
    string task_details;
    int date,month,date_,month_;
    while(true){
        cout << "What do you want to do:\n1.Add a task\n2.Remove a task\n3.Show tasks\n";
        ch = _getch();
        switch(ch){
            case '1':
            cout << "Enter the task details:";
            cin >> task_details;
            cout << "Enter date:";
            cin >> date;
            cout << "Enter th month:";
            cin >> month;
            c1.Add_task(task_details,date,month);
            break;
            case '2':
            cout << "Enter the date to remove:";
            cin >> date_;
            cout << "Enter the month to remove:";
            cin >> month_;
            c1.remove_task(date_,month_);
            break;
            case '3':
            c1.show_task();
            break;
            default:
            cout << "Invalid Input" << endl;
        } 
    }
    return 0;
}
