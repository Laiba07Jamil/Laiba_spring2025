#include <iostream>
using namespace std;

class Account{
    protected:
    string accountNumber;
    double accountbalance;
    string accountHolderName;
    public:
    Account(string accNum , double accBal , string accName){
        this->accountNumber = accNum;
        this->accountbalance = accBal;
        this->accountHolderName = accName;
    }

    virtual void deposit(double amount){
         if(amount > 0){
             accountbalance += amount ;
             cout << amount << "Money Deposited Successfully" << endl;
        }
        else{
            cout << "Amount is not sufficient" << endl;
        }
    }

    virtual void withdraw(double amount){
        if(amount > 0 && accountbalance >= amount){
            accountbalance -= amount ;
            cout << "Amount withdrawn: " << amount << endl;
            cout << "Remaining Balance: " << accountbalance << endl;
        }
    }

    virtual void CalculateInterest() {}

    virtual void printStatement() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << accountbalance << endl;
    }

    void getAccountInfo() {
        cout << "Account Info:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << accountbalance << endl;
    }
};    

class SavingsAccount : public Account{
    double interestRate;
    double minimumBalance;

    public:
    SavingsAccount(double IR , double minBal , string accNum , double accBal , string accName) : Account(accNum,accBal,accName) {
        this->interestRate = IR;
        this->minimumBalance = minBal;
    }

    void CalculateInterest() override{
        double interest = accountbalance * (interestRate / 100);
        accountbalance += interest;
        cout << "Interest of " << interest << " added. New balance: " << accountbalance << endl;
    }

     void printStatement() override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

};
class CheckingAccount : public Account{
    private:
    double minimumBalance;

public:
    CheckingAccount(string accNum, string holderName, double initialBalance, double minBalance)
        : Account(accNum,initialBalance, holderName ), minimumBalance(minBalance) {}

    void withdraw(double amount) override {
        if (accountbalance - amount >= minimumBalance && amount > 0) {
            accountbalance -= amount;
            cout << "Withdrew " << amount << " from checking account. New balance: " << accountbalance << endl;
        } else {
            cout << "Cannot withdraw! Minimum balance of " << minimumBalance << " must be maintained." << endl;
        }
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Minimum Balance Requirement: " << minimumBalance << endl;
    }
};

class FixeddepositAccount : public Account{
    int maturityDate;
    double fixedInterestRate;
    double interestAmount;
    public:
    FixeddepositAccount(double interestAmount,int MD , double FInRate , string accNum , double accBal , string accName) :  Account(accNum,accBal,accName) {
        this->maturityDate = MD;
        this->fixedInterestRate = FInRate;
        this->interestAmount = interestAmount ;
    }

    void CalculateInterest() override{
         double interest = accountbalance * (fixedInterestRate / 100);
        accountbalance += interest;
        cout << "Interest of " << interest << " added. New balance: " << accountbalance << endl;
    }
     void printStatement() override {
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }
};


int main() {
    // Create accounts for testing
    SavingsAccount savings(1234.00, 453.123,"sdfwdv", 1500.0, "34esdvg");
    CheckingAccount checking("dcswf", "Jane Smith", 3000.0, 500.0);
    FixeddepositAccount fixedDeposit(1003.66,232, 2352.42,"SDVds",564.3,"Laiba");

    // Test Deposit, Withdraw, and Interest Calculation
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.CalculateInterest();
    savings.printStatement();

    checking.deposit(1000.0);
    checking.withdraw(1000.0);
    checking.printStatement();

    fixedDeposit.deposit(2000.0);
    fixedDeposit.CalculateInterest();
    fixedDeposit.printStatement();

    return 0;
}


