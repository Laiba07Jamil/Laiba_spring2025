#include <iostream>
using namespace std;

class Paymentmethod{
    public:
    Paymentmethod() {}
    
    virtual void processPayment(double amount) = 0;

    virtual ~ Paymentmethod() {}
};

class CreditCard : public Paymentmethod{
    private:
    string cardNumber;
    public:
    CreditCard(string num){
        this->cardNumber = num;
    }

    void processPayment(double amount) override{
        if(cardNumber.length() != 16){
            cout << "Invalid Card Number." << endl;
        }
        if(amount <= 0){
            cout << "Invalid Amount." << endl;
        }
        else{
            cout << "Payment is Processing." << endl;
        }
    }
};

class DigitalWallet : public Paymentmethod{
    private:
    double balance;
    public:
    DigitalWallet(double b) : balance(b) {}
    
    void processPayment(double amount) override{
        if(amount > 0 &&  balance >= amount){
            balance -= amount;
            cout << "Payment is processing and also deducting the balance." << endl;
        }
        else{
            cout << "Invalid amount or balnce is not sfficient." << endl;
        }
    }
};

int main(){
    CreditCard c("42201-2345467895");
    DigitalWallet d(250000.00);

    c.processPayment(234505.2);
    d.processPayment(500000000.4);
}