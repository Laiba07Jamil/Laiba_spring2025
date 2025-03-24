#include <iostream>
using namespace std;

class Account{
    private:
    string accountNumber;
    string accountHolder;
    double balance;
    public:
    Account(string num ,string name , double bal) {
        this->accountHolder = name;
        this->balance = bal;
        this->accountNumber = num;
    }

    Account operator + (const Account& acc){
            double b = balance + acc.balance;
            return Account(accountNumber , accountHolder ,b);
    }

    Account operator +=(Account& acc){
        double amount;
        cout << "Enter amount to transfer: ";
        cin >> amount;
        if(amount > 0 && balance >= amount){
            balance -= amount;
            acc.balance += amount;
            cout << "Transefering " << amount << " from " << accountHolder << " to " << acc.accountHolder << endl; 
        }
        else{
            cout << "Amount cannot be transfered." << endl;
        }

        return *this;
    }

    bool operator > (const Account& acc){
        if(balance > acc.balance){
            return true;
        }
        else{
            return false;
        }
    }

    string getname() const{return accountNumber;}
    string getID() const {return accountNumber;}
    double getbalance() const{return balance;}

    friend ostream& operator << (ostream& os , const Account& acc);
};

ostream& operator << (ostream& os , const Account& acc){
    os << "Account Number: " << acc.accountNumber << endl;
    os << "Holder: " << acc.accountHolder << endl;
    os << "Balance: $" << acc.balance << endl;
    return os;
}

int main(){
    Account a1("101A" , "Shafique Rehman" , 5000);
    Account a2("234E" , "Talha" , 3000);

    Account a3 = a1 + a2;
    cout << a3 << endl;

    a1 += a2;
    cout << a1 << endl;
    cout << a2 << endl;

    if(a1 > a2){
        cout << a1.getname() << " has more balance than " << a2.getname() << endl;
    }
    else{
         cout << a1.getname() << "balance is less than " << a2.getname() << endl;
    }

    cout << a1 << endl;
    cout << a2 << endl;

}