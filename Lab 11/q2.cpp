#include <iostream>
#include <exception>
using namespace std;

class StackOverFLowException : public std::exception{
    private:
    const char* msg;
    public:
    StackOverFLowException(){
        this->msg = "Stack is Full" ;
    }

    const char* what() const noexcept{
        return msg;
    }
};

class StackUnderFLowException : public std::exception{
    private:
    const char* msg;
    public:
    StackUnderFLowException(){
        this->msg = "Stack is empty" ;
    }

    const char* what() const noexcept{
        return msg;
    }
};

template <typename T ,int length>
class Stack{
    private:
    T arr[length];
    int count;
    public:
    Stack() : count(0) {
    }
    void Push(T a){
        if(count > length){
            throw StackOverFLowException() ;
        }
        else{
            arr[count] = a;
            count++ ;
        }
    }

    void Pop(){
        if(count == 0){
            throw StackUnderFLowException() ;
        }
       count --;
    }
};

int main(){
    Stack <int , 5> s;
    try{
        for(int i = 0 ; i < 5 ; i++){
            s.Push(i+1);
        }
        for(int i = 0 ; i < 6 ; i++){
            s.Pop();
        }
        
    }
    catch(const StackOverFLowException &e){
        cout << "Pushing to a Full Stack - " << e.what() << endl;
    }
    catch(const StackUnderFLowException &e){
        cout << "Poping to an empty Stack - " << e.what() << endl;
    }
}

