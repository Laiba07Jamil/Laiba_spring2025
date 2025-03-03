#include<iostream>
using namespace std;
 
class LoanHelper{
    private:
    float interest_rate;
    int months;
    float amount;
    public:
    LoanHelper() : interest_rate(0.0) , months(0) , amount(0.0) {}
    LoanHelper(float amount , int months , float interest_rate ){
        this->amount = amount;
        if(interest_rate > 0 && interest_rate < 0.5){
            this->interest_rate = interest_rate;
        }
        this->months = months;
    }
    void calculateloan_payments(){
        float payment = amount / months;
        float irate_payment = payment * interest_rate;
        float final_payment = payment + irate_payment;
        cout << "You have to Pay " << final_payment << "every month for " << months << "months to repay your loan." << endl;
    }
};

int main(){
    float a,irate;
    int month;
    cout << "Enter thhe amount:" ;
    cin >> a;
    cout << "Enter the interest rate between 0 - 0.5%:" ;
    cin >> irate;
    cout << "Enter the months:" ;
    cin >> month;
    LoanHelper l1(a , month , irate / 100);
    l1.calculateloan_payments();
    return 0;
}