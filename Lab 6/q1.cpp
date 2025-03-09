/*1. Create a Message class
o It should have a private instance variable text of type string to store the message
content.
o Implement a method toString() that returns the message text.
o Provide a setter method to modify the text value.
2. Create an SMS class that inherits from Message
o It should have an additional instance variable recipientContactNo to store the
recipient’s phone number.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing the
recipient’s contact number and the message text.
3. Create an Email class that inherits from Message
o It should have additional instance variables: sender, receiver, and subject.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing sender,
receiver, subject, and the message text.
4. Implement Keyword Search Function
o Define a function:
o bool ContainsKeyword(const Message& messageObject, const string& keyword);
o This function should return true if the text of the Message object contains the
given keyword, otherwise return false.

5. Implement Message Encoding
o Define a function to encode a given message using the following scheme:
 Each character should be replaced by the next character in the alphabet
(e.g., ‘A’ → ‘B’, ‘b’ → ‘c’, ‘Z’ → ‘A’, ‘z’ → ‘a’).
 Example: If the message is "This is Java", the encoded message should be
"Uijt jt Kbwb".
6. Test the Implementation
o In the main() function, create sample objects of SMS and Email, assign values,
and test the functionalities including keyword search and encoding.*/


#include <iostream>
#include <cstring>
using namespace std;

class Message{
    private:
    string text;
    public:
    Message(string t) : text(t){}
    void settext(const string text){
        this->text = text;
    }
    string gettext() const {return text;}
    virtual string tostring() const {
        return text;
    }
};

class SMS : public Message{
    private:
    string recipientContactNo;
    public:
    SMS(string n , string t) : Message(t){
        this->recipientContactNo = n;
    }
    void setcontact(string contact){
        this->recipientContactNo = contact;
    }
    string getcontatct() const {return recipientContactNo;}

    string tostring() const{
         return  "Message"+ gettext() + "Recipient number" + recipientContactNo;
    }
};

class Email : public Message{
    private:
    string sender;
    string subject;
    string reciever;
    public:
    Email(string sender , string reciever ,string subject , string t) : Message(t){
        this->sender = sender;
        this->reciever = reciever;
        this->subject =subject;
    }
    void setsender(string s){
        this->sender = s;
    }
    void setreciever(string r){
        this->reciever = r;
    }
    void setsubject(string sub){
        this->subject = sub;
    }
    string getsender() const {return sender;}
    string getreciever() const {return reciever;}
    string getsubject() const {return subject;}

    string tostring(){
        return "Sender: " + sender + "Reciever: " + reciever + "Subject" + subject + "Text:" + gettext();
    }

    bool containskeyword(const Message& messageobject , const string& keyword){
        string mess = messageobject.tostring();
        if (mess != keyword){
            return false;
        }
        else{
            return true;
        }
    }

    string encode_message(const Message& m1){
        string str = m1.tostring();
        for(int i = 0 ; str[i] !='\0' ; i++){
            char ch = str[i];
            if(ch >= 'A' && ch <= 'Z'){
                  str[i] = (ch == 'Z') ? 'A' : ch + 1 ;
            }
             if(ch >= 'a' && ch <= 'z'){
                  str[i] = (ch == 'z') ? 'a' : ch + 1 ;
            }
        }
        return str;
    }
};
int main(){
    SMS s1("1234-4321","Hello World");
    cout << s1.gettext() << " " << s1.getcontatct() <<endl;
    s1.tostring();
    
    Email e1("Laiba","Jamil","Requesting for a meeting" , "For the assignment");
    cout << e1.gettext() << " " << e1.getsubject() << " " << e1.getsender() << " " << e1.getreciever() <<endl;
    s1.tostring();

    string keyword = "Meeting";
    cout << "Keyword '" << keyword << "' found in Email? " 
         << (e1.containskeyword(e1, keyword) ? "Yes" : "No") << "\n";

    string messg = "This is OOPS";
    cout << "Message: " << messg << "\nEncoded Meassage: " << e1.encode_message(messg) << endl;   
}
