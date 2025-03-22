#include <iostream>
#include <string>

using namespace std;

class Currency {
protected:
    double amount;
    string currencycode;
    char currencysymbol;
    float exchangerate;

public:
    Currency(double amt, string code, char symbol, float rate)
        : amount(amt), currencycode(code), currencysymbol(symbol), exchangerate(rate) {}

    virtual float convertTobase() = 0; 

    float convertTo(string targetCurrency, float targetExchangeRate) {
        float baseamt = convertTobase();
        return baseamt / targetExchangeRate;
    }

    virtual void displayCurrency() {
        cout << "Amount: " << amount << endl;
        cout << "Currency Code: " << currencycode << endl;
        cout << "Currency Symbol: " << currencysymbol << endl;
        cout << "Exchange Rate: " << exchangerate << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt, string code, char symbol, float rate)
        : Currency(amt, code, symbol, rate) {}

    float convertTobase() override {
        return amount * exchangerate;
    }

    void displayCurrency() override {
        Currency::displayCurrency();
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt, string code, char symbol, float rate)
        : Currency(amt, code, symbol, rate) {}

    float convertTobase() override {
        return amount * exchangerate;
    }

    void displayCurrency() override {
        Currency::displayCurrency();
    }
};

class Ruppee : public Currency {
public:
    Ruppee(double amt, string code, char symbol, float rate)
        : Currency(amt, code, symbol, rate) {}

    float convertTobase() override {
        return amount * exchangerate;
    }

    void displayCurrency() override {
        Currency::displayCurrency();
    }
};

int main() {
    Euro eur(4500.5, "EUR", '€', 1.23);
    Dollar usd(2500.5, "USD", '$', 1.14);
    Ruppee inr(5005.50, "INR", '₹', 2.23);

    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();

    cout << "\nConverting 100 EUR to USD: " << eur.convertTo("USD", 1.14) << " USD" << endl;
    cout << "Converting 100 EUR to INR: " << eur.convertTo("INR", 2.23) << " INR" << endl;
    cout << "Converting 10000 INR to USD: " << inr.convertTo("USD", 1.14) << " USD" << endl;
    cout << "Converting 100 USD to INR: " << usd.convertTo("INR", 2.23) << " INR" << endl;

    return 0;
}
