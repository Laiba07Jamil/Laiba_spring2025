#include <iostream>
using namespace std;

class InsufficientFundsException :public std :: exception{
    private:
    string msg;
    public:
    InsufficientFundsException(double deficiet) : std :: exception() {
        this->msg = "Deficit: $" + to_string(deficiet);
    }

    const char* what() const noexcept{
        return msg.c_str();
    }
};
template <typename T>
class BankAccount{
    private :
    T balance ;
    public:
    BankAccount(T currency){
        this->balance = currency;
    }
    void withDraw(T amount){
        if(amount > balance){
            throw InsufficientFundsException(amount - balance);
        }
        balance -= amount;
    }

    T getbalance()const{
        return balance;
    }
};

int main(){
    BankAccount<double> b(500.00);
    double amount;
    cout << "Enter amount to withddraw: ";
    cin >> amount;
    try{
        b.withDraw(amount);
    }
    catch(const InsufficientFundsException &e){
        cout << "Balance :$" << b.getbalance() << endl;
        cout << "Wihtdraw $" << amount << ": InsufficientFundsException - " << e.what() << endl;  
    }
    return 0;
}