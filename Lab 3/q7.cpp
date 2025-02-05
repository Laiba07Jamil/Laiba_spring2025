#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class Stationary_Shop{ 
    private:
    string items[10];          //Because MAX items are 10
    float prices[10];
    int count;
    public:
    Stationary_Shop() : count(0){}
    void Add_item(string item_ ,float price_ , int MAX_items){          //Add item
        if(count >= MAX_items){
            cout << "Sorry no other items can be added" << endl; 
            return ;
        }
        else{
            items[count] = item_;
            prices[count] = price_;
            count++;
            cout << "Item added successfully" << endl;
        }
    }

    void Fetch_items(){                                                    //Fetch items
        for(int i = 0 ; i < count ; i++){
             cout << "Item " << i+1 << " :" << items[i] << endl ;
        }
    }

    void Edit_prices(string _item , float _price){                                  //Edit prices
        int flag = 0;
        for(int i = 0 ; i < 10 ; i++){
            if(items[i] == _item){
                flag = 1 ;
                prices[i] = _price;
                cout << "Price Updated successfully";
                break;
            }
        }
        if (flag == 0) {  
        cout << "Item not found" << endl;
    }
       
   }
    void all_items_with_prices(){                                                     // Printing all items and prices
        cout << "Items and Prices" << endl;
        for(int i = 0 ; i < count ; i++){
            cout << i+1 << ". " << items[i] << " - " << fixed << setprecision(2) <<prices[i] << endl;
        }
    }
    void create_receipt(){                                                              //Creating receipt for customer
        string purchasedItems[20];
        int quantity[20];
        int items_total[20];
        int purshased_count = 0 ;
        float total_cost = 0;
        string itemname;
        int quantity_;
        cout << "Enter the purchase items OR Type DONE for finish" << endl;
        while(true){
            cout << "Enter the name of item:";
            cin >> itemname;
            if(itemname == "done"){
                break;
            }

            int flag = 0;
            for(int i = 0 ; i < 10 ; i++){
                if(itemname == items[i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                cout << "Enter quantity:";
                cin >> quantity_;

                int index = 0;
                float itemstotal = quantity_ * prices[index];
                total_cost += itemstotal;

                purchasedItems[purshased_count] = itemname;
                quantity[purshased_count] = quantity_;
                items_total[purshased_count] = itemstotal;
                purshased_count++;

            }
            else{
                cout<<"Item not found"<<endl;
            }
        }
        cout << "\nRECEIPT\n" ;
        cout << left << setw(10) << "Items" << setw(10) << "Quantity" << setw(10) << "Prices" << setw(10) << "Total Items" << endl;
        for(int i = 0 ; i < purshased_count ; i++){
        cout << left << setw(10) << purchasedItems[i] << setw(10) << quantity[i] << setw(10) << prices[i] << setw(10) << items_total[i] << endl;

        }
        cout << "Grand Total :" << total_cost << fixed << setprecision(2);
    }
};

int main(){
    Stationary_Shop s1;
    int MAX_items = 10;
    char ch;
    string item_ , _item;
    float price_ , _price;
    int n;
    while(true){
        cout << "1.Add items\n2.Fetch Items\n3.Edit Prices\n4.View Items and Prices\n5.Create receipt\n6.Exit\n";
        ch = _getch();
        switch(ch){
            case '1':
            cout << "Enter item name:";
            cin >> item_;
            cout << "Enter item Price:";
            cin >> price_;
            s1.Add_item(item_,price_,MAX_items);
            break;
            case '2':
            s1.Fetch_items();
            break;
            case '3':
            cout << "Enter the item name for update price:";
            cin >> _item;
            cout << "Enter the price:";
            cin >> _price;
            s1.Edit_prices(_item,_price);
            break;
            case '4':
            s1.all_items_with_prices();
            break;
            case '5':
            s1.create_receipt();
            break;
            case '6':
            cout << "Thank you for coming:";
            break;
            default:
            cout << "Invalid  Input";
            break;
        }
    }
    return 0;
}