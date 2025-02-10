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
    void CreateAccount(){
        string accountnumber,ownersName;
        cout << "Enter the account number:";
        getline(cin,accountnumber);
        cout << "Enter the Owner's Name:";
        getline(cin,ownersName);
        cout  << "Enter your initial balance:";
        cin >> this->balance;
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
    Account a1 = Account("K24I23" , "Laiba" ,25000.0);
   char ch;
   double Amount,Draw;
   while(true){
    cout << "What do you want to do:\n1.Create new Account\n2.Deposit Money\n3.With darw money\n4.Check Balance\n5.Exit\n" ;
    ch =_getch();
    switch(ch){
        case '1':
        a1.CreateAccount();
        break;
        case '2' :
        cout << "Enter the amount to deposit:";
        cin >> Amount;
        a1.deposit(Amount);
        break;
        case '3':
        cout << "Enter the amount to with draw:";
        cin >> Draw;
        a1.wihtdraw(Draw);
        break;
        case '4':
        a1.check_balance();
        break;
        case '5':
        cout << "Thank you for coming" << endl;
        break;
        default:
        cout << "Invalid Input" << endl;
        break;
    }
   }
   return 0;
}