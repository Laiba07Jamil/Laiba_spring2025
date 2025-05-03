#include <iostream>
#include <cmath>
#include <typeinfo>
#include <type_traits> 
#include <exception>
using namespace std;

class NegativeNumberException : public std::exception {
    const char* msg;
public:
    NegativeNumberException(const char* message) : msg(message) {}
    const char* what() const noexcept override {
        return msg;
    }
};


class InvalidTypeException : public std::exception {
    const char* msg;
public:
    InvalidTypeException(const char* message) : msg(message) {}
    const char* what() const noexcept override {
        return msg;
    }
};

template <typename T>
double mySqrt(T num) {
    if (!std::is_arithmetic<T>::value) {
        throw InvalidTypeException("Non-numeric type detected!");
    }

    if (num < 0) {
        throw NegativeNumberException("Input must be non-negative!");
    }

    return std::sqrt(static_cast<double>(num));
}

int main() {
    try {
        cout << "sqrt(-4): ";
        double res1 = mySqrt(-4); 
        cout << res1 << endl;
    }
    catch (const NegativeNumberException& e) {
        cout << "NegativeNumberException - " << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cout << "InvalidTypeException - " << e.what() << endl;
    }

    try {
        cout << "sqrt(\"hello\"): ";
        string s = "hello";
        double res2 = mySqrt(s); 
        cout << res2 << endl;
    }
    catch (const NegativeNumberException& e) {
        cout << "NegativeNumberException - " << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cout << "InvalidTypeException - " << e.what() << endl;
    }

    return 0;
}
