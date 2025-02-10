#include<iostream>
#include <conio.h>
using namespace std;
class Account{
    private:
    string accountNumber ;
    string accountHoldername;
    double balance;
    public:
    Account() : balance(0.0) {}
    Account(string accountNumber, string accountHoldername ,double balance){
        this->accountNumber = accountNumber;
        this->accountHoldername =accountHoldername;
        this->balance = balance;
    }
    void deposit(double amount){
        if(amount > 0){
             balance += amount ;
             cout << "Money Deposited Successfully" << endl;
        }
        else{
            cout << "Amount is not sufficient" << endl;
        }
    }

    void wihtdraw(double amount){
        if(amount > 0 && balance >= amount){
            balance -= amount ;
            cout << "With draw amount:" << amount <<endl;
        }
    }
    void check_balance(){
        cout << "Balnace:" << balance <<endl;
    }
};

int main(){
    Account a1 = Account("K24I23" , "Laiba" , 25000.0);
   char ch;
   double Amount,Draw;
   while(true){
    cout << "What do you want to do:\n1.Deposit Money\n2.With darw money\n3.Check Balance\n4.Exit\n" ;
    ch =_getch();
    switch(ch){
        case '1' :
        cout << "Enter the amount to deposit:";
        cin >> Amount;
        a1.deposit(Amount);
        break;
        case '2':
        cout << "Enter the amount to with draw:";
        cin >> Draw;
        a1.wihtdraw(Draw);
        break;
        case '3':
        a1.check_balance();
        break;
        case '4':
        cout << "Thank you for coming" << endl;
        break;
        default:
        cout << "Invalid Input" << endl;
        break;
    }
   }
   return 0;
}