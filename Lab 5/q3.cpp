/*Create a class called ValidateString. The purpose of this class will be check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.*/


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class ValidateString{
    private:
    string word;
    public:
    ValidateString(string w){
        this->word = w;
    }

    // we make this function const as it will not be allowed to modify or change the data members of the object 
    bool validstring() const {
        for(int i = 0 ; i < word.length() ; i++){
            if(!isalpha(word[i])){
                return false;
            }
            else{
                return true;
            }
        }
    }
};

int main(){
    ValidateString v1("HELLO WORLD");
    ValidateString v2("!@EF#V");

    if(v1.validstring()){
        cout << "String 1 is valid" << endl;
    }
    else{
        cout << "String 1 is not valid" << endl;
    }

    if(v2.validstring()){
        cout << "String 2 is valid" << endl;
    }
    else{
        cout << "String 2 is not valid" << endl;
    }
}