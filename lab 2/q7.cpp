#include <iostream>
#include <cstring>
using namespace std;

struct Product{
    string product_name;
    string product_ID;
    int quantity;
    float price;
};

//function prototypes

void new_product(Product products[],string id,string name,int _quantity,float _price,int count,int MAXproduct);
void displayproducts(Product products[],string search_id,int count);
void updateproduct(Product products[],int count,string name_ , int quantity_ , float price_ ,string id_);
void removeproducts(Product products[],int count,string removeid);

int main(){
    string id, name, search_id, removeid, name_, id_;
    int _quantity, quantity_;
    float _price, price_;
    int MAXproduct = 5;             //assuming there are only 5 products
    int count = 0;
    Product products[MAXproduct];       
    for(int i = 0 ; i < MAXproduct ; i++){
    cout << "Enter the product name "<<i+1<<":";
    cin >> products[i].product_name;
    cout << "Enter the product ID "<<i+1<<":";
    cin >> products[i].product_ID;
    cout << "Enter the price "<<i+1<<":";
    cin >> products[i].price;
    cout << "Enter the quantity "<<i+1<<":";
    cin >> products[i].quantity;
    cout <<endl;
    }
    char choice;
    do{
        cout<<"Enter your choice:\n1.Add new product\n2.Search and Display\n3.Update the product information\n4.Remove the product\n5.Quit\n";
        cin >> choice;
        switch(choice){
            case '1':
            cout << "Enter the new Product"<<endl;
            cout << "Enter product ID:";
            cin >> id;
            cout << "Enter product name:";
            cin >> name;
            cout << "Enter the product quantity:";
            cin >> _quantity;
            cout << "Enter the product price:";
            cin >> _price;
            new_product(products,id,name,_quantity,_price,count,MAXproduct);
            break;

            case '2':
            cout<<"Display the Product"<<endl;
            cout <<"Enter the Product ID to search";
            cin >> search_id;
            displayproducts(products,search_id,MAXproduct);
            break;

            case '3':
            cout << "Updating the inventary" << endl;
            cout << "Enter the product id to update the product:";
            cin >> id_;
            cout << "Enter the Quantity for the product:";
            cin >> quantity_;
            cout << "Enter the updated price for the product:";
            cin >> price_;
            cout << "Enter the updated product name:";
            cin >> name_;
            updateproduct(products,MAXproduct,name_,quantity_,price_,id_);
            break;

            case '4':
            cout << "Removing products"<<endl;
            cout << "Enter the id of Product to remove:";
            cin >> removeid;
            removeproducts(products, MAXproduct,removeid);
            break;

            case '5':
            cout << "Thank you for coming" << endl;
            break;

            default:
            cout << "Inavlid Input" << endl;

        }
    }
    while(choice!='5');
}

void new_product(Product products[],string id,string name,int _quantity,float _price,int count,int MAXproduct){
            if(count>=MAXproduct){
                cout << "Sorry There's no space available;)"<<endl;
            }   
        products[count].price = _price;
        products[count].quantity = _quantity;
        products[count].product_ID = id;
        products[count].product_name = name;

        count++;
        cout << "Product added successfully";
}

void displayproducts(Product products[],string search_id,int count){
    int flag = 0;
    for(int i = 0 ; i < count ; i++){
        if(products[i].product_ID == search_id){
              flag =1;
              cout << "Product ID:"<<products[i].product_ID<<"\n";
              cout << "Product name:" << products[i].product_name<<"\n";
              cout << "Product Price:" << products[i].price<<"\n";
              cout << "Quantity of Product" << products[i].quantity << "\n"; 
           }
    }
    if(flag == 0){
        cout<<"Sorry Product not found";
    }
}

void updateproduct(Product products[],int count,string name_ , int quantity_ , float price_ ,string id_){
    int flag = 0;
    for(int i = 0 ; i < count ; i++){
         if(products[i].product_ID == id_) {
            flag = 1;
            products[i].price = price_;
            products[i].quantity = quantity_;
            products[i].product_ID = id_;
            cout<<"Product updated successfully";
            break;
         }   
    }
    if(flag == 0){
        cout<<"Sorry Product not found for update\n";
    }
}

void removeproducts(Product products[],int count,string removeid){
    int flag =0;
    for(int i = 0 ; i < (count) ; i++){
        if(products[i].product_ID == removeid){
            flag = 1;

            for(int j = i ; j < (count) - 1 ; j++)    
             products[j] = products[j+1];
             cout << "Product remove successfully ";
          }
          (count)--;
          
    }
    if(flag == 0){
        cout<<"Sorry Product not found to remove it\n";
    }

}
