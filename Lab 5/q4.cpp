#include <iostream>
using namespace std;

class BankAccount{
    private:
    string accountNumber;
    string accountHolderName;
    double balance;
    public:
    BankAccount() : accountHolderName(" ") , accountNumber(" ") , balance(0.0) {}
    BankAccount(string a , string name, double b){
        this->accountNumber = a;
        this->accountHolderName = name;
        this->balance = b;
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

    void withdraw(double amount){
        if(amount > 0 && balance >= amount){
            balance -= amount ;
            cout << "With draw amount:" << amount <<endl;
        }
    }
    void display(){
        cout << "Account Number:" << accountNumber << endl;
        cout << "Account Holder Name:" << accountHolderName << endl;
        cout << "Balance: " << balance << endl; 
    }
};
int main(){
    BankAccount account[3] ;
    account[0] = BankAccount("SFWG" , "Laiba" ,245.64);
    account[1] = BankAccount("FDHSR" , "Simal" ,132.54);
    account[2] = BankAccount("FDBfb" , "Absar" ,213.53);
    for(int i = 0 ;i < 3 ; i++){
        cout << "Account " << i+1 << "Details: " << endl; 
        account[i].display() ;
        account[i].deposit(500.0);
        cout << "Updated" << endl;
        account[i].display() ;
        account[i].withdraw(200.0);
        cout << "Updated" << endl;
        account[i].display();
    }
    
}