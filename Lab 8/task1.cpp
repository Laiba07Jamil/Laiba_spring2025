#include <iostream>
using namespace std;

class BankAccount{
    protected:
    string accountNumber;
    double balance;
    public:
    BankAccount(string accNum , double bal){
        this->accountNumber = accNum;
        this->balance = bal;
    }

    virtual double calculateInterest() {}
    virtual void deposit() {}
    virtual void withdraw() {}

    BankAccount operator +(const BankAccount& acc){
        double b = balance + acc.balance;
        return BankAccount(accountNumber , b);
    }

    BankAccount operator -(double m){
        return BankAccount(accountNumber , balance - m);
    }

    BankAccount operator * (double IR){
        return BankAccount(accountNumber , balance * (1 + IR)/100) ;
    }

    BankAccount operator / (int installments){
        return BankAccount(accountNumber , balance / installments);
    }

    double getbalance(){return balance;}
    string gegtaccNum() { return accountNumber;}
};

class SavingsAccount : public BankAccount{
    public:
    SavingsAccount(string accNum , double bal)  : BankAccount(accNum,bal){}

    double calculateInterest() override{
        return (balance * (1 + 5) / 100);
    }    

    void withdraw(double amount) {
        if(balance - amount < 500){
            cout << "Cannot With draw money." << endl;
        }
        else{
            balance -= amount;
            cout << "With drawn amount: "<< amount << "| New balance: " << balance << endl;

        }
    }

    void deposit(double amount) {
        if(amount > 0){
        balance += amount;
        cout << amount << " Amount deposited successfully.| New Balance: " << balance << endl;
        }
    }

    void deposit(double amount , string checkNum) {
        if(amount > 0){
           balance += amount;
           cout << amount << " Amount deposited successfully.| Check Number: " << checkNum << "|New Balance: "<< balance << endl;
        }
    }

    void deposit(double amount, string bankName, string transactionID)  {
         if(amount > 0){
            balance += amount;
            cout << "Deposited via online transfer from " << bankName << " (Transaction ID: " << transactionID << ") | New Balance: " << balance << endl;
         }
    }
    
};
class CurrentAccount : public BankAccount{
    public:
    CurrentAccount(string accNum , double bal)  : BankAccount(accNum,bal){}
    
    double calculateInterest() override {
        cout << "No interest for Current Account." << endl;
    }

    void withdraw(double amount) {
        if(balance - amount < 1000){
            cout << "Cannot With draw money." << endl;
        }
        else{
            balance -= amount;
            cout << "With drawn amount: "<< amount << "| New balance: " << balance << endl;
        }
    }
    
    
    void deposit(double amount) {
        if(amount > 0){
        balance += amount;
        cout << amount << " Amount deposited successfully.| New Balance: " << balance << endl;
        }
    }

    void deposit(double amount , string checkNum) {
        if(amount > 0){
           balance += amount;
           cout << amount << " Amount deposited successfully.| Check Number: " << checkNum << "|New Balance: "<< balance << endl;
        }
    }

    void deposit(double amount, string bankName, string transactionID)  {
         if(amount > 0){
            balance += amount;
            cout << "Deposited via online transfer from " << bankName << " (Transaction ID: " << transactionID << ") | New Balance: " << balance << endl;
         }
    }

};

int main(){
    SavingsAccount savings("101", 1000);
    CurrentAccount current("102", 500);

    cout << "\n--- Transactions for Savings Account ---\n";
    savings.deposit(200);
    savings.deposit(300, "CHK12345");
    savings.deposit(500, "BankABC", "TXN56789");
    savings.withdraw(600);
    savings.calculateInterest();

    cout << "\n--- Transactions for Current Account ---\n";
    current.deposit(400);
    current.deposit(600, "CHK67890");
    current.deposit(700, "BankXYZ", "TXN98765");
    current.withdraw(1500);
    current.calculateInterest();

    BankAccount b1 = savings + current;
    cout <<"Balance: " << b1.getbalance() << " Acc Num: " <<  b1.gegtaccNum() << endl;

    b1 = savings - 200;
    cout <<"Balance: " << b1.getbalance() << " Acc Num: " <<  b1.gegtaccNum() << endl;

    b1 = savings * 5;
    cout <<"Balance: " << b1.getbalance() << " Acc Num: " <<  b1.gegtaccNum() << endl;

    b1 = savings / 4;
    cout <<"Balance: " << b1.getbalance() << " Acc Num: " <<  b1.gegtaccNum() << endl;

    return 0;
}