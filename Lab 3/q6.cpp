#include <iostream>
using namespace std;

class Smartphone{
    private:
    string company;
    string model;
    string resolution;
    string RAM;
    string ROM;
    string storage;

    public:
    void set_company(string company){
        this->company = company;
    }
    string get_company(){
        return company;
    }
    void set_model(string model){
        this->model = model;
    }
    string get_model(){
        return model;
    }
    void set_resolution(string resolution){
        this->resolution= resolution;
    }
    string get_resolution(){
        return resolution;
    }
    void set_RAM(string RAM){
        this->RAM = RAM;
    }
    string get_RAM(){
        return RAM;
    }
    void set_ROM(string ROM){
        this->ROM = ROM;
    }
    string get_ROM(){
        return ROM;
    }
    void set_storage(string storage){
        this->storage = storage;
    }
    string get_storage(){
        return storage;
    }
    void dispaly(){
        cout << get_company() << endl;
        cout << get_model() << endl;
        cout << get_RAM() << endl;
        cout << get_resolution() << endl;
        cout << get_ROM() << endl;
        cout << get_storage() <<endl;
    }
    void make_phone(string make){
        cout << "Dialing" << make << endl;
    }
    void send_msg(string message , string number){
       cout << "Sending message: \"" << message << "\" to " << number << endl;
    }
    void connect_wifi(string wifiName){
        cout << "Connecting to Wi-Fi: " << wifiName << "...\n";
    }
    void brwoser(string website){
        cout << "Browsing: " << website << "...\n";
    }
};

int main()
{
    Smartphone s1;
    s1.set_company("Iphone");
    s1.set_model("11 promax");
    s1.set_RAM("126gb");
    s1.set_ROM("638mb");
    s1.set_resolution("2532 * 1170");
    cout << "Phone Details";
    s1.dispaly();
    
    cout << "Phone Actions";
    s1.make_phone("123-456-7890");
    s1.send_msg("Hello, how are you?", "123-456-7890");
    s1.connect_wifi("Home Network");
    s1.brwoser("www.apple.com");


}
