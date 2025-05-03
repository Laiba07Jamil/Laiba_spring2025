#include <iostream>
using namespace std;

class  InvalidValueException : public std :: exception{
    private:
    const char* msg;
    public:
    InvalidValueException(const char* msg) : std :: exception() {
        this->msg = msg;
    }

    const char* what() const noexcept{
        return msg;
    }
};

void validateAge(int age){
        if(age < 0 ){
            throw InvalidValueException("Age should not be less than 0.");
        }
        else if( age > 120){
            throw InvalidValueException("Age should not be greater than 120.");
        }   
    }

int main(){
    int a;
    cout << "Enter age : " ;
    cin >> a;
    try{
    validateAge(a);
    }
    catch(const InvalidValueException &e){
        cout << "Error: InvalildValueException - " << e.what() << endl;
    }
}

