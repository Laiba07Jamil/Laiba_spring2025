#include <iostream>
using namespace std;

class Product {
protected:
    string productID;
    double price;
public:
    Product(string id, double p) : productID(id), price(p) {}
    virtual double calculatePrice() = 0; // Pure virtual function

    // Percentage Discount
    virtual void applyDiscount(double discountPercentage) {
        price *= (1 - discountPercentage / 100.0);
    }

    string getproductid() const { return productID; }
    double getprice() const { return price; }
};

// Electronics: Applies 15% Tax
class Electronics : public Product {
public:
    Electronics(string id, double p) : Product(id, p) {}

    double calculatePrice() override {
        return price * 1.15;
    }
};

// Clothing: Applies 5% Tax
class Clothing : public Product {
public:
    Clothing(string id, double p) : Product(id, p) {}

    double calculatePrice() override {
        return price * 1.05;
    }
};

// ShoppingCart: Manages Products (No vectors used)
class ShoppingCart {
private:
    Product** product;
    int count;
    int itemcount;
public:
    ShoppingCart(int itemcount) : itemcount(itemcount), count(0) {
        product = new Product*[itemcount]();
    }

    ~ShoppingCart() {
        for (int i = 0; i < count; i++) {
            delete product[i]; // Free each allocated object
        }
        delete[] product;
    }

    void addProduct(Product* p) {
        if (count >= itemcount) {
            cout << "Sorry, no space available.\n";
            return;
        }
        product[count] = p;
        count++;
    }

    void removeProduct(string productid) {
        for (int i = 0; i < count; i++) {
            if (product[i]->getproductid() == productid) {
                delete product[i]; // Free memory
                for (int j = i; j < count - 1; j++) {
                    product[j] = product[j + 1]; // Shift items
                }
                count--;
                cout << "Item removed successfully.\n";
                return;
            }
        }
        cout << "Product not found in cart.\n";
    }

    ShoppingCart operator+(const ShoppingCart &other) {
        ShoppingCart new_cart(this->itemcount + other.itemcount);
        for (int i = 0; i < count; i++) {
            new_cart.addProduct(product[i]);
        }
        for (int i = 0; i < other.count; i++) {
            new_cart.addProduct(other.product[i]);
        }
        return new_cart;
    }

    void operator*(double discountPercentage) {
        for (int i = 0; i < count; i++) {
            product[i]->applyDiscount(discountPercentage);
        }
    }

    void operator/(int users) {
        if (users > 0) {
            double total = getTotalPrice();
            cout << "Each user pays: $" << (total / users) << endl;
        }
    }

    double getTotalPrice() {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += product[i]->calculatePrice();
        }
        return total;
    }

    void displayCart() {
        cout << "Cart Contents:\n";
        for (int i = 0; i < count; i++) {
            cout << "Product ID: " << product[i]->getproductid() << " | Price after tax: $" << product[i]->calculatePrice() << endl;
        }
        cout << "Total Cart Price: $" << getTotalPrice() << endl;
    }
};


int main() {
    Electronics* e1 = new Electronics("101", 500);
    Clothing* c1 = new Clothing("201", 100);

    ShoppingCart cart1(5), cart2(5);
    cart1.addProduct(e1);
    cart2.addProduct(c1);

    cout << "Cart 1 Before Discount:\n";
    cart1.displayCart();
    ShoppingCart mergedCart = cart1 + cart2;
    cout << "\nMerged Cart:\n";
    mergedCart.displayCart();

    
    mergedCart * 10; 
    cout << "\nAfter 10% Discount:\n";
    mergedCart.displayCart();
    mergedCart.removeProduct("201");
    cout << "\nAfter Removing Clothing Item:\n";
    mergedCart.displayCart();


    mergedCart / 2;

    return 0;
}

