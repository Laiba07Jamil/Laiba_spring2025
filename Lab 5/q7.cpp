#include <iostream>
using namespace std;

class Payment;

class MenuItem{
    string foodname;
    float foodprice;
    public:
    MenuItem() : foodname("") , foodprice(0.0) {}
    void setfoodname(string n ,float pr){
        this->foodname = n;
        this->foodprice = pr;
    }
    string getname(){return foodname;}
    float getprice(){return foodprice;}

    void displaymenu(){
        cout << "Food Name: " << foodname <<endl;
        cout << "Food Price: " << foodprice << endl;
    }
};
class Menu{
    MenuItem menu[10];
    int count;
    public:
    Menu() : count(0) {}

    void addItem(string name,float price){
        if(count > 10){
            cout << "Sorry there is no space" << endl;
        }
        else{
            menu[count].setfoodname(name,price);
            count++ ;
            cout << "Food added successfully" << endl;
        }
    }
    void removeItem(string name , float price){
        int flag=0;
        for(int i = 0 ; i < count - 1; i++){
            if(menu[i].getname() == name && menu[i].getprice() == price){
                flag =1;
            }
            for(int j = i ; j < count -1 ; j++){
                menu[j] = menu[j+1];
                count-- ;
                cout << "Item Removed Successfully " <<endl;
            }
        }
        if (flag == 0){
             cout << "Sorry item not found" << endl;
        }
    }
    void displaymenu(){
        for(int i = 0 ; i < count ;i++){
            cout<<"Items " << i+1 << endl;
            menu[i].displaymenu();
        }
    }
};
class Order{
    MenuItem* m;
    Payment* p;
    string* orderitem;
    float* orderprice;
    int itemcount;
    int pricecount;
    public:
    Order() : m(nullptr) , p(nullptr) ,orderitem(nullptr) , orderprice(nullptr) , itemcount(0) ,pricecount(0){
        orderitem =new string[10];
        orderprice = new float[10];
    }
    void setorder(MenuItem* men, Payment* pay){
        m = men;
        p = pay;
    }
    void addItemtooreder(string item,float p){
        if(itemcount > 10){
            cout << "Sorry is not available" << endl;
        }
        else{
            orderitem[itemcount] = item;
            orderprice[pricecount] = p;
            itemcount++ ;
            pricecount++ ;
            cout << "Item added successfully" << endl;
        }
    }
    void dispalytotal(){
        int total =0 ;
        for(int i = 0 ; i < 10 ; i++){
            total += orderprice[i];
        }
        cout << "Your Total is " << total << endl;
    }
    void displayOrder(){
        cout << "\nDisplaying your Order\n" << endl;
        for(int i = 0 ; i < 10 ; i++){
            cout << orderitem[i] << "-$" << orderprice[i] << endl;
        }
    }
    ~Order(){
        delete[] orderitem;
        delete[] orderprice;
    }
};
class Payment{
    float amount;
    public:
    Payment() : amount(0.0) {}
    void setAmount(float amount){
        this->amount = amount;
    }
    float getamount(){return amount;}
    void processpayment(){
        cout << "Your payent is being processed" <<endl;
    }
};
class RestaurantSystem{
    Menu m1;
};
int main(){
    Menu menu;
    Order order;
    Payment payment;
    
    menu.addItem("Burger", 5.99);
    menu.addItem("Pizza", 8.99);
    menu.addItem("Pasta", 7.49);
    menu.addItem("Salad", 4.99);
    
    cout << "\nMenu Items:" << endl;
    menu.displaymenu();
   
    order.addItemtooreder("Burger", 5.99);
    order.addItemtooreder("Pasta", 7.49);
    order.addItemtooreder("Salad", 4.99);
    
    order.displayOrder();
    order.dispalytotal();
    
    float totalAmount = 5.99 + 7.49 + 4.99; 
    payment.setAmount(totalAmount);
    payment.processpayment();
    
    cout << "Payment Amount: $" << payment.getamount() << endl;
    
    return 0;
}