#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <conio.h>

using namespace std;

// Forward declarations
class Car;
class Customer;
class Sale;
class User;

// ===== Utility Classes =====

// Dynamic Array template for storing collections without using vector
template <typename T>
class DynamicArray {
private:
    T* array;
    int capacity;
    int size;

public:
    // Constructor
    DynamicArray() : capacity(5), size(0) {
        array = new T[capacity];
    }

    // Destructor
    ~DynamicArray() {
        delete[] array;
    }

    // Add element to array
    void add(T element) {
        if (size >= capacity) {
            // Double capacity if array is full
            capacity *= 2;
            T* newArray = new T[capacity];
            
            // Copy existing elements
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            
            // Delete old array and update pointer
            delete[] array;
            array = newArray;
        }
        
        array[size++] = element;
    }

    // Remove element at index
    void remove(int index) {
        if (index < 0 || index >= size) {
            return; // Invalid index
        }
        
        // Shift elements to fill gap
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        
        size--;
    }

    // Get element at index
    T& get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return array[index];
    }

    // Get current size
    int getSize() const {
        return size;
    }

    // Check if array is empty
    bool isEmpty() const {
        return size == 0;
    }
};

// Date class for handling dates
class Date {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor - sets to current date
    Date() {
        time_t now = time(0);      
        tm* ltm = localtime(&now);    
        
        day = ltm->tm_mday;
        month = 1 + ltm->tm_mon;
        year = 1900 + ltm->tm_year;
    }
    
    // Parameterized constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    
    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    
    // Format date as string
    string toString() const {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
};

// ===== Base Classes =====

// User base class for authentication
class User {
protected:
    int userId;  
    string username;
    string password;
    string role;

public:
    // Default constructor
    User() : userId(0) {
        username = "";
        password = "";
        role = "";
    }
    
    // Parameterized constructor
    User(int id, const string username, const string password, const string role) : userId(id) {
       this->username = username;
       this->password = password;
       this->role = role;
    }
    
    // Virtual destructor
    virtual ~User() {}
    
    // Getters
    int getUserId() const { return userId; }  
    const string getUsername() const { return username; }
    const string getPassword() const { return password; }
    const string getRole() const { return role; }
    
    // Setters
    void setUserId(int id) { this->userId = id; }  
    void setUsername(const string username) { this->username = username; }
    void setPassword(const string password) { this->password = password; }
    void setRole(const string role) { this->role = role; }
    
    // Verify login credentials
    bool verifyLogin(const string username, const string password) const {
        return (this->username == username && this->password == password);
    }
    
    // Display user details
    virtual void displayUser() const {  
        cout << "User ID: " << userId << endl;
        cout << "Username: " << username << endl;
        cout << "Role: " << role << endl;
    }
};

// Person base class
class Person {
protected:
    int personId; 
    string name;
    string phone;
    string email;

public:
    // Default constructor
    Person() : personId(0) {
        name = "";
        phone = "";
        email = "";
    }
    
    // Parameterized constructor
    Person(int id, const string name, const string phone, const string email) : personId(id) {
        this->name = name;
        this->phone = phone;
        this->email = email;
    }
    
    // Virtual destructor
    virtual ~Person() {}
    
    // Getters
    int getPersonId() const { return personId; } 
    const string getName() const { return name; }
    const string getPhone() const { return phone; }
    const string getEmail() const { return email; }
    
    // Setters
    void setPersonId(int id) { this->personId = id; }  
    void setName(const string name) { this->name = name; }
    void setPhone(const string phone) { this->phone = phone; }
    void setEmail(const string email) { this->email = email; }
    
    // Display person details - virtual for polymorphism
    virtual void displayPerson() const {  
        cout << "ID: " << personId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
    }
    
    // Pure virtual function to make Person an abstract class
    virtual const string getRole() const = 0;
};

// Car base class
class Car {
protected:
    int id;
    string model;
    string brand;
    int year;
    double price;
    int quantity;
    int horsepower;
    double zeroToSixty;
    int topSpeed;
    string driveType;
    string colors;
    string description;

public:
    // Default constructor
    Car() : id(0), year(0), price(0.0), quantity(0), horsepower(0), zeroToSixty(0.0), topSpeed(0) {
        model = "";
        brand = "";
        driveType = "";
        colors = "";
        description = "";
    }
    
    // Parameterized constructor
    Car(int id, const string model, const string brand, int year, double price, int quantity,
        int horsepower, double zeroToSixty, int topSpeed, const string driveType, const string colors, const string description)
        : id(id), year(year), price(price), quantity(quantity), 
          horsepower(horsepower), zeroToSixty(zeroToSixty), topSpeed(topSpeed) {
        this->model = model ;
        this->brand = brand ;
        this->driveType = driveType ;
        this->colors = colors ;
        this->description = description ;
    }
    
    // Virtual destructor
    virtual ~Car() {}
    
    // Getters
    int getId() const { return id; }
    const string getModel() const { return model; }
    const string getBrand() const { return brand; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    int getHorsepower() const { return horsepower; }
    double getZeroToSixty() const { return zeroToSixty; }
    int getTopSpeed() const { return topSpeed; }
    const string getDriveType() const { return driveType; }
    const string getColors() const { return colors; }
    const string getDescription() const { return description; }
    
    // Setters
    void setId(int id) { this->id = id; }
    void setModel(const char* model) { this->model = model; }
    void setBrand(const char* brand) { this->brand = brand; }
    void setYear(int year) { this->year = year; }
    void setPrice(double price) { this->price = price; }
    void setQuantity(int quantity) { this->quantity = quantity; }
    void setHorsepower(int horsepower) { this->horsepower = horsepower; }
    void setZeroToSixty(double zeroToSixty) { this->zeroToSixty = zeroToSixty; }
    void setTopSpeed(int topSpeed) { this->topSpeed = topSpeed; }
    void setDriveType(const char* driveType) { this->driveType = driveType; }
    void setColors(const char* colors) { this->colors = colors; }
    void setDescription(const char* description) { this->description = description; }
    
    // Update quantity
    void updateQuantity(int change) {
        quantity += change;
        if (quantity < 0) quantity = 0;
    }
    
    // Display car details - virtual for polymorphism
    virtual void display() const {
        cout << "=======================================" << endl;
        cout << brand << " " << model << endl;
        cout << "From $" << fixed << setprecision(2) << price << "*" << endl;
        cout << endl;
        cout << horsepower << " hp" << endl;
        cout << "Max. engine power" << endl;
        cout << zeroToSixty << " s" << endl;
        cout << "0 - 60 mph" << endl;
        cout << topSpeed << " mph" << endl;
        cout << "Top track speed (with summer tires)" << endl;
        cout << driveType << endl;
        cout << "Available in colors: " << colors << endl;
        cout << "Year: " << year << endl;
        cout << "Available: " << quantity << endl;
        cout << "ID: " << id << endl;
        if (description.length() > 0) {
            cout << "Description: " << description << endl;
        }
    }
    
    // Pure virtual function to make Car an abstract class
    virtual const string getType() const = 0;
};

// ===== Derived Classes =====

// Admin class (derived from Person and User)
class Admin : public Person, public User {       //multiple inheritance
public:
    // Default constructor
    Admin() {
        // setRole("Admin");
        role = "Admin";
    }
    
    // Parameterized constructor
    Admin(int id, const string name, const string phone, const string email,
          const string username, const string password)
        : Person(id, name, phone, email), User(id, username, password, "Admin") {
    }
    
    // Override display method
    void display() const {
        displayPerson();
        cout << "Username: " << username << endl;
        cout << "Role: " << role << endl;
    }
    
    // Override getRole method
    const string getRole() const override {
        return User::getRole();
    }
    
    // Get ID (resolves ambiguity)
    int getId() const {
        return getPersonId();
    }
};

// Salesperson class (derived from Person and User)
class Salesperson : public Person, public User {
private:
    double commission;
    int salesCount;

public:
    // Default constructor
    Salesperson() : commission(0.0), salesCount(0) {
        role = "Salesperson";
    }
    
    // Parameterized constructor
    Salesperson(int id, const string name, const string phone, const string email,
                const string username, const string password, double commission = 0.0)
        : Person(id, name, phone, email), User(id, username, password, "Salesperson"), 
          commission(commission), salesCount(0) {
    }
    
    // Getters
    double getCommission() const { return commission; }
    int getSalesCount() const { return salesCount; }
    
    // Setters
    void setCommission(double commission) { this->commission = commission; }
    
    // Increment sales count
    void incrementSalesCount() { salesCount++; }
    
    // Override display method
    void display() const {
        displayPerson();
        cout << "Username: " << username << endl;
        cout << "Role: " << role << endl;
        cout << "Commission Rate: " << fixed << setprecision(2) << commission * 100 << "%" << endl;
        cout << "Total Sales: " << salesCount << endl;
    }
    
    // Override getRole method
    const string getRole() const override {
        return User::getRole();
    }
    
    // Get ID (resolves ambiguity)
    int getId() const {
        return getPersonId();
    }
};

// Customer class (derived from Person and User)
class Customer : public Person, public User {
private:
    string address;
    int purchaseCount;

public:
    // Default constructor
    Customer() : purchaseCount(0) {
        this->address = "";
        role = "Customer";
    }
    
    // Parameterized constructor for registered customer
    Customer(int id, const string name, const string phone, const string email, const string address,
             const string username, const string password)
        : Person(id, name, phone, email), User(id, username, password, "Customer"), 
          purchaseCount(0) {
        this->address = address;
    }
    
    // Parameterized constructor for non-registered customer
    Customer(int id, const string name, const string phone, const string email, const string address)
        : Person(id, name, phone, email), purchaseCount(0) {
        this->address = address;
        role = "Customer";
        // Set empty username and password for non-registered customers
        username = "";
        password = "";
    }
    
    // Getters
    const string getAddress() const { return address; }
    int getPurchaseCount() const { return purchaseCount; }
    
    // Setters
    void setAddress(const string address) { this->address = address; }
    
    // Increment purchase count
    void incrementPurchaseCount() { purchaseCount++; }
    
    // Check if customer is registered
    bool isRegistered() const {
        return username.length() > 0;
    }
    
    // Override display method
    void display() const {
        displayPerson();
        cout << "Address: " << address << endl;
        cout << "Role: " << role << endl;
        cout << "Purchase Count: " << purchaseCount << endl;
        if (isRegistered()) {
            cout << "Username: " << username << endl;
            cout << "Status: Registered Customer" << endl;
        } else {
            cout << "Status: Non-Registered Customer" << endl;
        }
    }
    
    // Override getRole method
    const string getRole() const override {
        return User::getRole();
    }
    
    // Get ID (resolves ambiguity)
    int getId() const {
        return getPersonId();
    }
};

// Sedan class (derived from Car)
class Sedan : public Car {
private:
    string type;
    int doors;
    string transmission;

public:
    // Default constructor
    Sedan() : doors(0) {
        type = "Sedan";
        transmission = "";
    }
    
    // Parameterized constructor - FIXED SYNTAX ERRORS
    Sedan(int id, const string model, const string brand, int year, double price, int quantity,
          int doors, const string transmission, int horsepower, double zeroToSixty, int topSpeed, 
          const string driveType, const string colors, const string description = "")
        : Car(id, model, brand, year, price, quantity, horsepower, zeroToSixty, topSpeed, driveType, colors, description), 
          doors(doors) {
        this->type = "Sedan";
        this->transmission = transmission;
    }
    
    // Getters
    int getDoors() const { return doors; }
    const string getTransmission() const { return transmission; }
    
    // Setters
    void setDoors(int doors) { this->doors = doors; }
    void setTransmission(const string transmission) { this->transmission, transmission; }
    
    // Override display method
    void display() const override {
        Car::display();
        cout << "Type: " << type << endl;
        cout << "Doors: " << doors << endl;
        cout << "Transmission: " << transmission << endl;
        cout << "=======================================" << endl;
    }
    
    // Override getType method
    const string getType() const override {
        return type;
    }
};

// SUV class (derived from Car)
class SUV : public Car {
private:
    string type;
    bool fourWheelDrive;
    int seatingCapacity;

public:
    // Default constructor
    SUV() : fourWheelDrive(false), seatingCapacity(0) {
        type = "SUV";
    }
    
    // Parameterized constructor
    SUV(int id, const string model, const string brand, int year, double price, int quantity,
        bool fourWheelDrive, int seatingCapacity, int horsepower, double zeroToSixty, int topSpeed, 
        const string driveType, const string colors, const string description = "")
        : Car(id, model, brand, year, price, quantity, horsepower, zeroToSixty, topSpeed, driveType, colors, description), 
          fourWheelDrive(fourWheelDrive), seatingCapacity(seatingCapacity) {
        this->type = "SUV";
    }
    
    // Getters
    bool hasFourWheelDrive() const { return fourWheelDrive; }
    int getSeatingCapacity() const { return seatingCapacity; }
    
    // Setters
    void setFourWheelDrive(bool fourWheelDrive) { this->fourWheelDrive = fourWheelDrive; }
    void setSeatingCapacity(int seatingCapacity) { this->seatingCapacity = seatingCapacity; }
    
    // Override display method
    void display() const override {
        Car::display();
        cout << "Type: " << type << endl;
        cout << "Four Wheel Drive: " << (fourWheelDrive ? "Yes" : "No") << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "=======================================" << endl;
    }
    
    // Override getType method
    const string getType() const override {
        return type;
    }
};

// Hatchback class (derived from Car)
class Hatchback : public Car {
private:
    string type;
    bool hasSunroof;
    string fuelType;

public:
    // Default constructor
    Hatchback() : hasSunroof(false) {
        type = "Hatchback";
        fuelType = "";
    }
    
    // Parameterized constructor
    Hatchback(int id, const string model, const string brand, int year, double price, int quantity,
              bool hasSunroof, const string fuelType, int horsepower, double zeroToSixty, int topSpeed, 
              const string driveType, const string colors, const string description = "")
        : Car(id, model, brand, year, price, quantity, horsepower, zeroToSixty, topSpeed, driveType, colors, description), 
          hasSunroof(hasSunroof) {
        this->type = "Hatchback";
        this->fuelType = fuelType;
    }
    
    // Getters
    bool getHasSunroof() const { return hasSunroof; }
    const string getFuelType() const { return fuelType; }
    
    // Setters
    void setHasSunroof(bool hasSunroof) { this->hasSunroof = hasSunroof; }
    void setFuelType(const string fuelType) { this->fuelType = fuelType; }
    
    // Override display method
    void display() const override {
        Car::display();
        cout << "Type: " << type << endl;
        cout << "Sunroof: " << (hasSunroof ? "Yes" : "No") << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "=======================================" << endl;
    }
    
    // Override getType method
    const string getType() const override {
        return type;
    }
};

// ===== System Classes =====

// Sale class to represent a transaction
class Sale {
private:
    int id;
    int carId;
    int customerId;
    int salespersonId;
    Date saleDate;
    double amount;
    string paymentMethod;

public:
    // Default constructor
    Sale() : id(0), carId(0), customerId(0), salespersonId(812), amount(0.0) {
        this->paymentMethod = "";
    }
    
    // Parameterized constructor
    Sale(int id, int carId, int customerId, int salespersonId, 
         const Date& saleDate, double amount, const string paymentMethod)
        : id(id), carId(carId), customerId(customerId), 
          salespersonId(salespersonId), saleDate(saleDate), amount(amount) {
        this->paymentMethod = paymentMethod;
    }
    
    // Getters
    int getId() const { return id; }
    int getCarId() const { return carId; }
    int getCustomerId() const { return customerId; }
    int getSalespersonId() const { return salespersonId; }
    Date getSaleDate() const { return saleDate; }
    double getAmount() const { return amount; }
    string getPaymentMethod() const { return paymentMethod; }
    
    // Setters
    void setId(int id) { this->id = id; }
    void setCarId(int carId) { this->carId = carId; }
    void setCustomerId(int customerId) { this->customerId = customerId; }
    void setSalespersonId(int salespersonId) { this->salespersonId = salespersonId; }
    void setSaleDate(const Date& saleDate) { this->saleDate = saleDate; }
    void setAmount(double amount) { this->amount = amount; }
    void setPaymentMethod(const string paymentMethod) { this->paymentMethod = paymentMethod; }
    
    // Display sale details
    void display() const {
        cout << "Sale ID: " << id << endl;
        cout << "Car ID: " << carId << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Salesperson ID: " << salespersonId << endl;
        cout << "Sale Date: " << saleDate.toString() << endl;
        cout << "Amount: $" << fixed << setprecision(2) << amount << endl;
        cout << "Payment Method: " << paymentMethod << endl;
    }
};

// Invoice class to generate sales documentation
class Invoice {
private:
    int id;
    Sale sale;
    double taxRate;
    double discount;
    double totalAmount;

public:
    // Default constructor
    Invoice() : id(0), taxRate(0.0), discount(0.0), totalAmount(0.0) {}
    
    // Parameterized constructor
    Invoice(int id, const Sale& sale, double taxRate, double discount)
        : id(id), sale(sale), taxRate(taxRate), discount(discount) {
        // Calculate total amount with tax and discount
        calculateTotal();
    }
    
    // Getters
    int getId() const { return id; }
    Sale getSale() const { return sale; }
    double getTaxRate() const { return taxRate; }
    double getDiscount() const { return discount; }
    double getTotalAmount() const { return totalAmount; }
    
    // Setters
    void setId(int id) { this->id = id; }
    void setSale(const Sale& sale) { this->sale = sale; }
    void setTaxRate(double taxRate) { 
        this->taxRate = taxRate; 
        calculateTotal();
    }
    void setDiscount(double discount) { 
        this->discount = discount; 
        calculateTotal();
    }
    
    // Calculate total amount with tax and discount
    void calculateTotal() {
        double saleAmount = sale.getAmount();
        double taxAmount = saleAmount * taxRate;
        double discountAmount = saleAmount * discount;
        totalAmount = saleAmount + taxAmount - discountAmount;
    }
    
    // Generate and display invoice
    void generateInvoice() const {
        cout << "=======================================" << endl;
        cout << "             INVOICE                   " << endl;
        cout << "=======================================" << endl;
        cout << "Invoice ID: " << id << endl;
        cout << "Date: " << sale.getSaleDate().toString() << endl;
        cout << "---------------------------------------" << endl;
        cout << "Sale ID: " << sale.getId() << endl;
        cout << "Car ID: " << sale.getCarId() << endl;
        cout << "Customer ID: " << sale.getCustomerId() << endl;
        cout << "Salesperson ID: " << sale.getSalespersonId() << endl;
        cout << "---------------------------------------" << endl;
        cout << "Subtotal: $" << fixed << setprecision(2) << sale.getAmount() << endl;
        cout << "Tax (" << taxRate * 100 << "%): $" << sale.getAmount() * taxRate << endl;
        cout << "Discount (" << discount * 100 << "%): $" << sale.getAmount() * discount << endl;
        cout << "---------------------------------------" << endl;
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Payment Method: " << sale.getPaymentMethod() << endl;
        cout << "=======================================" << endl;
    }
    
    // Save invoice to file
    bool saveToFile(const char* filename) const {
        ofstream file(filename);
        if (!file) {
            return false;
        }
        
        file << "=======================================" << endl;
        file << "             INVOICE                   " << endl;
        file << "=======================================" << endl;
        file << "Invoice ID: " << id << endl;
        file << "Date: " << sale.getSaleDate().toString() << endl;
        file << "---------------------------------------" << endl;
        file << "Sale ID: " << sale.getId() << endl;
        file << "Car ID: " << sale.getCarId() << endl;
        file << "Customer ID: " << sale.getCustomerId() << endl;
        file << "Salesperson ID: " << sale.getSalespersonId() << endl;
        file << "---------------------------------------" << endl;
        file << "Subtotal: $" << fixed << setprecision(2) << sale.getAmount() << endl;
        file << "Tax (" << taxRate * 100 << "%): $" << sale.getAmount() * taxRate << endl;
        file << "Discount (" << discount * 100 << "%): $" << sale.getAmount() * discount << endl;
        file << "---------------------------------------" << endl;
        file << "Total Amount: $" << totalAmount << endl;
        file << "Payment Method: " << sale.getPaymentMethod() << endl;
        file << "=======================================" << endl;
        
        file.close();
        return true;
    }
};

// Inventory class to manage car stock
class Inventory {
private:
    DynamicArray<Car*> cars;
    int nextCarId;

public:
    // Constructor
    Inventory() : nextCarId(1) {}
    
    // Destructor
    ~Inventory() {
        // Clean up dynamically allocated Car objects
        for (int i = 0; i < cars.getSize(); i++) {
            delete cars.get(i);
        }
    }
    
    // Add a car to inventory
    void addCar(Car* car) {
        car->setId(nextCarId++);
        cars.add(car);
    }
    
    // Remove a car from inventory
    bool removeCar(int id) {
        for (int i = 0; i < cars.getSize(); i++) {
            if (cars.get(i)->getId() == id) {
                delete cars.get(i);
                cars.remove(i);
                return true;
            }
        }
        return false;
    }
    
    // Find a car by ID
    Car* findCar(int id) const {
        for (int i = 0; i < cars.getSize(); i++) {
            if (cars.get(i)->getId() == id) {
                return cars.get(i);
            }
        }
        return nullptr;
    }
    
    // Update car quantity
    bool updateCarQuantity(int id, int change) {
        Car* car = findCar(id);
        if (car) {
            car->updateQuantity(change);
            return true;
        }
        return false;
    }
    
    // Display all cars in inventory
    void displayAllCars() const {
        if (cars.getSize() == 0) {
            cout << "No cars in inventory." << endl;
            return;
        }
        
        cout << "======= INVENTORY =======" << endl;
        for (int i = 0; i < cars.getSize(); i++) {
            cars.get(i)->display();
        }
    }
    
    // Display cars by type
    void displayCarsByType(const string type) const {
        bool found = false;
        
        cout << "======= " << type << " CARS =======" << endl;
        for (int i = 0; i < cars.getSize(); i++) {
            if (cars.get(i)->getType() == type)  {
                cars.get(i)->display();
                found = true;
            }
        }
        
        if (!found) {
            cout << "No " << type << " cars in inventory." << endl;
        }
    }
    
    // Get car count
    int getCarCount() const {
        return cars.getSize();
    }
    
    // Get available car count (quantity > 0)
    int getAvailableCarCount() const {
        int count = 0;
        for (int i = 0; i < cars.getSize(); i++) {
            if (cars.get(i)->getQuantity() > 0) {
                count++;
            }
        }
        return count;
    }
    
    // Initialize inventory with sample cars
    void initializeInventory() {
        // Add Sedans
        addCar(new Sedan(0, "Model S", "Tesla", 2023, 89990.0, 5, 4, "Automatic", 
            670, 3.1, 155, "All Wheel Drive", "Red, Black, White, Blue", 
            "Luxury electric sedan with advanced autopilot features"));
        
        addCar(new Sedan(0, "S-Class", "Mercedes-Benz", 2023, 114500.0, 3, 4, "Automatic", 
                         429, 4.9, 130, "Rear Wheel Drive", "Black, Silver, White", 
                         "Flagship luxury sedan with premium features"));
                         
        addCar(new Sedan(0, "5 Series", "BMW", 2023, 54800.0, 7, 4, "Automatic", 
                         335, 5.2, 155, "Rear Wheel Drive", "Alpine White, Black Sapphire, Mineral Grey", 
                         "Executive sedan with sporty handling"));
                         
        addCar(new Sedan(0, "A6", "Audi", 2023, 55900.0, 4, 4, "Automatic", 
                         261, 5.8, 130, "All Wheel Drive", "Brilliant Black, Florett Silver, Glacier White", 
                         "Premium midsize luxury sedan"));
                         
        // Add SUVs
        addCar(new SUV(0, "Model X", "Tesla", 2023, 99990.0, 3, true, 7, 
                       670, 3.8, 155, "All Wheel Drive", "Red, Black, White, Blue", 
                       "Electric SUV with falcon wing doors"));
                       
        addCar(new SUV(0, "X5", "BMW", 2023, 61600.0, 5, true, 5, 
                       335, 5.3, 130, "All Wheel Drive", "Alpine White, Carbon Black, Mineral White", 
                       "Luxury midsize SUV with advanced technology"));
                       
        addCar(new SUV(0, "GLE", "Mercedes-Benz", 2023, 57700.0, 4, true, 5, 
                       255, 7.1, 130, "All Wheel Drive", "Black, Polar White, Selenite Grey", 
                       "Premium SUV with excellent comfort"));
                       
        addCar(new SUV(0, "Q7", "Audi", 2023, 57500.0, 6, true, 7, 
                       248, 6.7, 130, "All Wheel Drive", "Carrara White, Mythos Black, Samurai Gray", 
                       "Three-row luxury SUV with refined interior"));
                       
        // Add Hatchbacks
        addCar(new Hatchback(0, "Golf GTI", "Volkswagen", 2023, 30530.0, 8, true, "Gasoline", 
                             241, 5.1, 155, "Front Wheel Drive", "Deep Black Pearl, Pure White, Atlantic Blue", 
                             "Sporty hatchback with excellent handling"));
                             
        addCar(new Hatchback(0, "A3", "Audi", 2023, 34900.0, 5, true, "Gasoline", 
                             201, 6.6, 130, "Front Wheel Drive", "Brilliant Black, Glacier White, Mythos Black", 
                             "Premium compact hatchback"));
                             
        addCar(new Hatchback(0, "Civic Type R", "Honda", 2023, 42895.0, 3, false, "Gasoline", 
                             315, 5.0, 169, "Front Wheel Drive", "Championship White, Rallye Red, Crystal Black Pearl", 
                             "High-performance hatchback with racing heritage"));
                             
        addCar(new Hatchback(0, "i30 N", "Hyundai", 2023, 32250.0, 6, true, "Gasoline", 
                             276, 5.9, 155, "Front Wheel Drive", "Performance Blue, Phantom Black, Polar White", 
                             "Performance-oriented hot hatchback"));
    }
};

// FileHandler class for data persistence
class FileHandler {
public:
    // Save admins to file
    static bool saveAdmins(const DynamicArray<Admin*>& admins, const char* filename) {
        ofstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size = admins.getSize();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Admin* admin = admins.get(i);
            file.write(reinterpret_cast<const char*>(admin), sizeof(Admin));
        }
        
        file.close();
        return true;
    }
    
    // Load admins from file
    static bool loadAdmins(DynamicArray<Admin*>& admins, const char* filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Admin* admin = new Admin();
            file.read(reinterpret_cast<char*>(admin), sizeof(Admin));
            admins.add(admin);
        }
        
        file.close();
        return true;
    }
    
    // Save salespeople to file
    static bool saveSalespeople(const DynamicArray<Salesperson*>& salespeople, const char* filename) {
        ofstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size = salespeople.getSize();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Salesperson* salesperson = salespeople.get(i);
            file.write(reinterpret_cast<const char*>(salesperson), sizeof(Salesperson));
        }
        
        file.close();
        return true;
    }
    
    // Load salespeople from file
    static bool loadSalespeople(DynamicArray<Salesperson*>& salespeople, const char* filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Salesperson* salesperson = new Salesperson();
            file.read(reinterpret_cast<char*>(salesperson), sizeof(Salesperson));
            salespeople.add(salesperson);
        }
        
        file.close();
        return true;
    }
    
    // Save customers to file
    static bool saveCustomers(const DynamicArray<Customer*>& customers, const char* filename) {
        ofstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size = customers.getSize();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Customer* customer = customers.get(i);
            file.write(reinterpret_cast<const char*>(customer), sizeof(Customer));
        }
        
        file.close();
        return true;
    }
    
    // Load customers from file
    static bool loadCustomers(DynamicArray<Customer*>& customers, const char* filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Customer* customer = new Customer();
            file.read(reinterpret_cast<char*>(customer), sizeof(Customer));
            customers.add(customer);
        }
        
        file.close();
        return true;
    }
    
    // Save cars to file - simplified implementation
    static bool saveCars(const Inventory& inventory, const char* filename) {
        // This is a simplified implementation
        // In a real system, we would need to handle polymorphism properly
        ofstream file(filename);
        if (!file) {
            return false;
        }
        
        file << "Cars saved: " << inventory.getCarCount() << endl;
        file.close();
        return true;
    }
    
    // Load cars from file - simplified implementation
    static bool loadCars(Inventory& inventory, const char* filename) {
        // This is a simplified implementation
        // In a real system, we would need to handle polymorphism properly
        ifstream file(filename);
        if (!file) {
            return false;
        }
        
        string line;
        getline(file, line);
        file.close();
        return true;
    }
    
    // Save sales to file
    static bool saveSales(const DynamicArray<Sale*>& sales, const char* filename) {
        ofstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size = sales.getSize();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Sale* sale = sales.get(i);
            file.write(reinterpret_cast<const char*>(sale), sizeof(Sale));
        }
        
        file.close();
        return true;
    }
    
    // Load sales from file
    static bool loadSales(DynamicArray<Sale*>& sales, const char* filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Sale* sale = new Sale();
            file.read(reinterpret_cast<char*>(sale), sizeof(Sale));
            sales.add(sale);
        }
        
        file.close();
        return true;
    }
    
    // Save invoices to file
    static bool saveInvoices(const DynamicArray<Invoice*>& invoices, const char* filename) {
        ofstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size = invoices.getSize();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Invoice* invoice = invoices.get(i);
            file.write(reinterpret_cast<const char*>(invoice), sizeof(Invoice));
        }
        
        file.close();
        return true;
    }
    
    // Load invoices from file
    static bool loadInvoices(DynamicArray<Invoice*>& invoices, const char* filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            return false;
        }
        
        int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            Invoice* invoice = new Invoice();
            file.read(reinterpret_cast<char*>(invoice), sizeof(Invoice));
            invoices.add(invoice);
        }
        
        file.close();
        return true;
    }
};

// Showroom class - main system class
class Showroom {
private:
    char name[50];
    char address[100];
    char phone[15];
    
    DynamicArray<Admin*> admins;
    DynamicArray<Salesperson*> salespeople;
    DynamicArray<Customer*> customers;
    DynamicArray<Sale*> sales;
    DynamicArray<Invoice*> invoices;
    
    Inventory inventory;
    
    int nextSaleId;
    int nextInvoiceId;
    int nextCustomerId;
    int nextUserId;
    
    // Current logged in user
    User* currentUser;
    
public:
    // Constructor
    Showroom(const char* name, const char* address, const char* phone)
        : nextSaleId(1), nextInvoiceId(1), nextCustomerId(1), nextUserId(1), currentUser(nullptr) {
        strcpy(this->name, name);
        strcpy(this->address, address);
        strcpy(this->phone, phone);
        
        // Create default admin
        Admin* admin = new Admin(1, "Admin", "1234567890", "admin@showroom.com", "admin", "admin123");
        admins.add(admin);
        nextUserId++;
        
        // Initialize inventory with sample cars
        inventory.initializeInventory();
    }
    
    // Destructor
    ~Showroom() {
        // Clean up dynamically allocated objects
        for (int i = 0; i < admins.getSize(); i++) {
            delete admins.get(i);
        }
        
        for (int i = 0; i < salespeople.getSize(); i++) {
            delete salespeople.get(i);
        }
        
        for (int i = 0; i < customers.getSize(); i++) {
            delete customers.get(i);
        }
        
        for (int i = 0; i < sales.getSize(); i++) {
            delete sales.get(i);
        }
        
        for (int i = 0; i < invoices.getSize(); i++) {
            delete invoices.get(i);
        }
    }
    
    // Login function
    bool login(const string username, const string password) {
        // Check admins
        for (int i = 0; i < admins.getSize(); i++) {
            Admin* admin = admins.get(i);
            if (admin->verifyLogin(username, password)) {
                currentUser = admin;
                return true;
            }
        }
        
        // Check salespeople
        for (int i = 0; i < salespeople.getSize(); i++) {
            Salesperson* salesperson = salespeople.get(i);
            if (salesperson->verifyLogin(username, password)) {
                currentUser = salesperson;
                return true;
            }
        }
        
        // Check customers
        for (int i = 0; i < customers.getSize(); i++) {
            Customer* customer = customers.get(i);
            if (customer->isRegistered() && customer->verifyLogin(username, password)) {
                currentUser = customer;
                return true;
            }
        }
        
        return false;
    }
    
    // Register a new user
    bool registerUser(const string name, const string phone, const string email, 
                     const string address, const string username, const string password, 
                     const string role) {
        // Check if username already exists
        if (isUsernameExists(username)) {
            cout << "Username already exists. Please choose a different username." << endl;
            return false;
        }
        
        if (role == "Admin") {
            Admin* admin = new Admin(nextUserId++, name, phone, email, username, password);
            admins.add(admin);
            return true;
        } else if (role == "Salesperson")  {
            Salesperson* salesperson = new Salesperson(nextUserId++, name, phone, email, username, password);
            salespeople.add(salesperson);
            return true;
        } else if (role == "Customer") {
            Customer* customer = new Customer(nextUserId++, name, phone, email, address, username, password);
            customers.add(customer);
            nextCustomerId++;
            return true;
        }
        
        return false;
    }
    
    // Check if username already exists
    bool isUsernameExists(const string username) const {
        // Check admins
        for (int i = 0; i < admins.getSize(); i++) {
            if (admins.get(i)->getUsername() == username) {
                return true;
            }
        }
        
        // Check salespeople
        for (int i = 0; i < salespeople.getSize(); i++) {
            if (salespeople.get(i)->getUsername() == username)  {
                return true;
            }
        }
        
        // Check customers
        for (int i = 0; i < customers.getSize(); i++) {
            if (customers.get(i)->isRegistered() && customers.get(i)->getUsername() ==username) {
                return true;
            }
        }
        
        return false;
    }
    
    // Logout function
    void logout() {
        currentUser = nullptr;
    }
    
    // Get current user
    User* getCurrentUser() const {
        return currentUser;
    }
    
    // Check if current user is admin
    bool isAdmin() const {
        if (!currentUser) return false;
        return (currentUser->getRole() == "Admin");
    }
    
    // Check if current user is salesperson
    bool isSalesperson() const {
        if (!currentUser) return false;
        return (currentUser->getRole() == "Salesperson");
    }
    
    // Check if current user is customer
    bool isCustomer() const {
        if (!currentUser) return false;
        return (currentUser->getRole() == "Customer");
    }
    
    // Add a new admin (only admin can do this)
    bool addAdmin(const string name, const string phone, const string email, 
                 const string username, const string password) {
        if (!isAdmin()) return false;
        
        // Check if username already exists
        if (isUsernameExists(username)) {
            cout << "Username already exists. Please choose a different username." << endl;
            return false;
        }
        
        Admin* admin = new Admin(nextUserId++, name, phone, email, username, password);
        admins.add(admin);
        return true;
    }
    
    // Add a new salesperson (only admin can do this)
    bool addSalesperson(const string name, const string phone, const string email, 
                       const string username, const string password, double commission) {
        if (!isAdmin()) return false;
        
        // Check if username already exists
        if (isUsernameExists(username)) {
            cout << "Username already exists. Please choose a different username." << endl;
            return false;
        }
        
        Salesperson* salesperson = new Salesperson(
            nextUserId++, name, phone, email, username, password, commission);
        salespeople.add(salesperson);
        return true;
    }
    
    // Add a new customer (non-registered)
    int addCustomer(const string name, const string phone, const string email, const string address) {
        Customer* customer = new Customer(nextCustomerId++, name, phone, email, address);
        customers.add(customer);
        return customer->getId();
    }
    
    // Add a new registered customer
    int addRegisteredCustomer(const char* name, const char* phone, const char* email, 
                             const char* address, const char* username, const char* password) {
        // Check if username already exists
        if (isUsernameExists(username)) {
            cout << "Username already exists. Please choose a different username." << endl;
            return -1;
        }
        
        Customer* customer = new Customer(nextCustomerId++, name, phone, email, address, username, password);
        customers.add(customer);
        nextUserId++;
        return customer->getId();
    }
    
    // Find customer by ID
    Customer* findCustomer(int id) const {
        for (int i = 0; i < customers.getSize(); i++) {
            if (customers.get(i)->getId() == id) {
                return customers.get(i);
            }
        }
        return nullptr;
    }
    
    // Find customer by name (partial match)
    void findCustomersByName(const string name) const {
        bool found = false;
        
        for (int i = 0; i < customers.getSize(); i++) {
            Customer* customer = customers.get(i);
            if (customer->getName() == name) {
                customer->display();
                cout << "------------------------" << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "No customers found with name containing '" << name << "'." << endl;
        }
    }
    
    // Add a car to inventory (only admin can do this)
    bool addCar(Car* car) {
        if (!isAdmin()) return false;
        
        inventory.addCar(car);
        return true;
    }
    
    // Process a sale
    bool processSale(int carId, int customerId, const string paymentMethod) {
        // Find the car
        Car* car = inventory.findCar(carId);
        if (!car || car->getQuantity() <= 0) {
            cout << "Error: Car not available in inventory." << endl;
            return false;
        }
        
        // Find the customer
        Customer* customer = findCustomer(customerId);
        if (!customer) {
            cout << "Error: Customer not found." << endl;
            return false;
        }
        
        // Get salesperson ID
        int salespersonId = 0;
        if (isSalesperson()) {
            salespersonId = currentUser->getUserId();
        } else if (isAdmin()) {
            // If admin is processing the sale, ask for salesperson ID
            if (salespeople.getSize() > 0) {
                cout << "Available Salespeople:" << endl;
                for (int i = 0; i < salespeople.getSize(); i++) {
                    Salesperson* sp = salespeople.get(i);
                    cout << sp->getId() << ": " << sp->getName() << endl;
                }
                
                cout << "Enter Salesperson ID (0 for none): ";
                cin >> salespersonId;
                
                // Validate salesperson ID
                bool validId = false;
                if (salespersonId != 0) {
                    for (int i = 0; i < salespeople.getSize(); i++) {
                        if (salespeople.get(i)->getId() == salespersonId) {
                            validId = true;
                            break;
                        }
                    }
                    
                    if (!validId) {
                        cout << "Invalid Salesperson ID. Using none." << endl;
                        salespersonId = 0;
                    }
                }
            }
        }
        
        // Create sale
        Sale* sale = new Sale(
            nextSaleId++, carId, customerId, salespersonId, 
            Date(), car->getPrice(), paymentMethod
        );
        sales.add(sale);
        
        // Update inventory
        inventory.updateCarQuantity(carId, -1);
        
        // Update customer purchase count
        customer->incrementPurchaseCount();
        
        // Update salesperson sales count if applicable
        if (salespersonId > 0) {
            for (int i = 0; i < salespeople.getSize(); i++) {
                Salesperson* sp = salespeople.get(i);
                if (sp->getUserId() == salespersonId) {
                    sp->incrementSalesCount();
                    break;
                }
            }
        }
        
        // Generate invoice
        double taxRate = 0.07; // 7% tax
        double discount = 0.0; // No discount by default
        
        // Apply discount for repeat customers
        if (customer->getPurchaseCount() > 1) {
            discount = 0.05; // 5% discount for repeat customers
        }
        
        Invoice* invoice = new Invoice(nextInvoiceId++, *sale, taxRate, discount);
        invoices.add(invoice);
        
        // Display invoice
        invoice->generateInvoice();
        
        // Save invoice to file
        char filename[50];
        sprintf(filename, "invoice_%d.txt", invoice->getId());
        if (invoice->saveToFile(filename)) {
            cout << "Invoice saved to " << filename << endl;
        } else {
            cout << "Failed to save invoice to file." << endl;
        }
        
        return true;
    }
    
    // Customer purchase function (for customer users)
    bool purchaseCar(int carId, const string paymentMethod) {
        if (!isCustomer()) {
            cout << "Error: Only customers can use this function." << endl;
            return false;
        }
        
        // Get customer ID from current user
        int customerId = 0;
        for (int i = 0; i < customers.getSize(); i++) {
            Customer* customer = customers.get(i);
            if (customer->getUserId() == currentUser->getUserId()) {
                customerId = customer->getId();
                break;
            }
        }
        
        if (customerId == 0) {
            cout << "Error: Customer profile not found." << endl;
            return false;
        }
        
        // Process the sale with no salesperson (direct purchase)
        return processSale(carId, customerId, paymentMethod);
    }
    
    // Display all cars in inventory
    void displayInventory() const {
        inventory.displayAllCars();
    }
    
    // Display cars by type
    void displayCarsByType(const string type) const {
        inventory.displayCarsByType(type);
    }
    
    // Display all customers
    void displayAllCustomers() const {
        if (customers.getSize() == 0) {
            cout << "No customers registered." << endl;
            return;
        }
        
        cout << "======= CUSTOMERS =======" << endl;
        for (int i = 0; i < customers.getSize(); i++) {
            customers.get(i)->display();
            cout << "------------------------" << endl;
        }
    }
    
    // Display all salespeople (admin only)
    bool displayAllSalespeople() const {
        if (!isAdmin()) return false;
        
        if (salespeople.getSize() == 0) {
            cout << "No salespeople registered." << endl;
            return true;
        }
        
        cout << "======= SALESPEOPLE =======" << endl;
        for (int i = 0; i < salespeople.getSize(); i++) {
            salespeople.get(i)->display();
            cout << "------------------------" << endl;
        }
        
        return true;
    }
    
    // Generate sales report
    bool generateSalesReport() const {
        if (!isAdmin() && !isSalesperson()) return false;
        
        if (sales.getSize() == 0) {
            cout << "No sales recorded." << endl;
            return true;
        }
        
        double totalRevenue = 0.0;
        
        cout << "======= SALES REPORT =======" << endl;
        cout << "Total Sales: " << sales.getSize() << endl;
        
        // Calculate total revenue
        for (int i = 0; i < sales.getSize(); i++) {
            totalRevenue += sales.get(i)->getAmount();
        }
        
        cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << endl;
        cout << "------------------------" << endl;
        
        // Display sales by car type
        cout << "Sales by Car Type:" << endl;
        int sedanCount = 0, suvCount = 0, hatchbackCount = 0;
        
        for (int i = 0; i < sales.getSize(); i++) {
            Car* car = inventory.findCar(sales.get(i)->getCarId());
            if (car) {
                if (car->getType() == "Sedan") { sedanCount++;}
                else if (car->getType() == "SUV") {suvCount++;}
                else if (car->getType() == "Hatchback") { hatchbackCount++;}
            }
        }
        
        cout << "Sedan: " << sedanCount << endl;
        cout << "SUV: " << suvCount << endl;
        cout << "Hatchback: " << hatchbackCount << endl;
        cout << "------------------------" << endl;
        
        return true;
    }
    
    // View purchase history (for customers)
    bool viewPurchaseHistory() const {
        if (!isCustomer()) return false;
        
        // Get customer ID from current user
        int customerId = 0;
        for (int i = 0; i < customers.getSize(); i++) {
            Customer* customer = customers.get(i);
            if (customer->getUserId() == currentUser->getUserId()) {
                customerId = customer->getId();
                break;
            }
        }
        
        if (customerId == 0) {
            cout << "Error: Customer profile not found." << endl;
            return false;
        }
        
        bool found = false;
        cout << "======= PURCHASE HISTORY =======" << endl;
        
        for (int i = 0; i < sales.getSize(); i++) {
            Sale* sale = sales.get(i);
            if (sale->getCustomerId() == customerId) {
                Car* car = inventory.findCar(sale->getCarId());
                if (car) {
                    cout << "Date: " << sale->getSaleDate().toString() << endl;
                    cout << "Car: " << car->getBrand() << " " << car->getModel() << endl;
                    cout << "Amount: $" << fixed << setprecision(2) << sale->getAmount() << endl;
                    cout << "Payment Method: " << sale->getPaymentMethod() << endl;
                    cout << "------------------------" << endl;
                    found = true;
                }
            }
        }
        
        if (!found) {
            cout << "No purchase history found." << endl;
        }
        
        return true;
    }
    
    // Save all data to files
    bool saveData() {
        bool success = true;
        
        success &= FileHandler::saveAdmins(admins, "admins.dat");
        success &= FileHandler::saveSalespeople(salespeople, "salespeople.dat");
        success &= FileHandler::saveCustomers(customers, "customers.dat");
        success &= FileHandler::saveSales(sales, "sales.dat");
        success &= FileHandler::saveInvoices(invoices, "invoices.dat");
        success &= FileHandler::saveCars(inventory, "cars.dat");
        
        return success;
    }
    
    // Load all data from files
    bool loadData() {
        bool success = true;
        
        success &= FileHandler::loadAdmins(admins, "admins.dat");
        success &= FileHandler::loadSalespeople(salespeople, "salespeople.dat");
        success &= FileHandler::loadCustomers(customers, "customers.dat");
        success &= FileHandler::loadSales(sales, "sales.dat");
        success &= FileHandler::loadInvoices(invoices, "invoices.dat");
        success &= FileHandler::loadCars(inventory, "cars.dat");
        
        return success;
    }
};

void playasterik(string password){
    int ch;
          while (true) {
        ch = getch();
        if (ch == 13) break; 
        else if (ch == 8) {  
            if (!password.empty()) {
                password.erase(password.length() - 1);      
                cout << "\b \b";      
            }
        } else {
            password.push_back(ch);
            cout << "*";
        }
    }
}
// Main function with menu system
int main() {
    // Create showroom
    Showroom showroom("Luxury Auto Showroom", "123 Main Street, City", "555-1234-5678");
    
    // Try to load data from files
    showroom.loadData();
    
    int choice;
    bool loggedIn = false;
    
    do {
        // Display appropriate menu based on login status
        if (!loggedIn) {
            cout << "\n===== CAR SHOWROOM MANAGEMENT SYSTEM =====" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1: {
                    string username, pass;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    playasterik(pass);
                    cout << endl;
                    
                    if (showroom.login(username, pass)) {
                        loggedIn = true;
                        User* user = showroom.getCurrentUser();
                        cout << "Login successful. Welcome, " << user->getUsername() 
                             << " (" << user->getRole() << ")" << endl;
                    } else {
                        cout << "Invalid username or password." << endl;
                    }
                    break;
                }
                case 2: {
                    string name, phone, email, address,confirm, username, password;
                    int roleChoice;
                    
                    cout << "\n===== REGISTRATION =====" << endl;
                    cout << "Enter your details:" << endl;
                    
                    cout << "Name: ";
                    cin.ignore();
                    cin >> name;
                    
                    cout << "Phone: ";
                    cin >> phone;
                    
                    cout << "Email: ";
                    cin >> email;
                    
                    cout << "Address: ";
                    cin >> address;
                    
                    cout << "Username: ";
                    cin >> username;
                    
                    cout << "Password: ";
                    playasterik(password);
                    cout << endl;

                    cout << "Confirm Password: ";
                    playasterik(confirm);
                    cout << endl;

                    cout << "Select role:" << endl;
                    cout << "1. Customer" << endl;
                    cout << "Enter choice: ";
                    cin >> roleChoice;
                    
                    if (roleChoice == 1) {
                        if (showroom.registerUser(name, phone, email, address, username, password, "Customer")) {
                            cout << "Registration successful. You can now login." << endl;
                        } else {
                            cout << "Registration failed. Please try again." << endl;
                        }
                    } else {
                        cout << "Invalid choice." << endl;
                    }
                    break;
                }
                case 3:
                    cout << "Thank you for using Car Showroom Management System." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } 
        else {
            // Check user role
            bool isAdmin = showroom.isAdmin();
            bool isSalesperson = showroom.isSalesperson();
            bool isCustomer = showroom.isCustomer();
            
            cout << "\n===== CAR SHOWROOM MANAGEMENT SYSTEM =====" << endl;
            
            // Common options
            cout << "1. View Inventory" << endl;
            cout << "2. View Cars by Type" << endl;
            
            // Admin and Salesperson options
            if (isAdmin || isSalesperson) {
                cout << "3. View Customers" << endl;
                cout << "4. Find Customer" << endl;
                cout << "5. Process Sale" << endl;
                cout << "6. Generate Sales Report" << endl;
            }
            
            // Admin-only options
            if (isAdmin) {
                cout << "7. Add Car to Inventory" << endl;
                cout << "8. Add Salesperson" << endl;
                cout << "9. View Salespeople" << endl;
            }
            
            // Customer-only options
            if (isCustomer) {
                cout << "3. View My Profile" << endl;
                cout << "4. Purchase a Car" << endl;
                cout << "5. View Purchase History" << endl;
            }
            
            cout << "10. Logout" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    showroom.displayInventory();
                    break;
                case 2: {
                    int typeChoice;
                    cout << "Select car type:" << endl;
                    cout << "1. Sedan" << endl;
                    cout << "2. SUV" << endl;
                    cout << "3. Hatchback" << endl;
                    cout << "Enter choice: ";
                    cin >> typeChoice;
                    
                    switch (typeChoice) {
                        case 1:
                            showroom.displayCarsByType("Sedan");
                            break;
                        case 2:
                            showroom.displayCarsByType("SUV");
                            break;
                        case 3:
                            showroom.displayCarsByType("Hatchback");
                            break;
                        default:
                            cout << "Invalid choice." << endl;
                    }
                    break;
                }
                case 3:
                    if (isAdmin || isSalesperson) {
                        showroom.displayAllCustomers();
                    } else if (isCustomer) {
                        showroom.getCurrentUser()->displayUser();
                    }
                    break;
                case 4:
                    if (isAdmin || isSalesperson) {
                        int searchChoice;
                        cout << "Search customer by:" << endl;
                        cout << "1. ID" << endl;
                        cout << "2. Name" << endl;
                        cout << "Enter choice: ";
                        cin >> searchChoice;
                        
                        if (searchChoice == 1) {
                            int id;
                            cout << "Enter customer ID: ";
                            cin >> id;
                            
                            Customer* customer = showroom.findCustomer(id);
                            if (customer) {
                                customer->display();
                            } else {
                                cout << "Customer not found." << endl;
                            }
                        } else if (searchChoice == 2) {
                            string name;
                            cout << "Enter customer name (or part of name): ";
                            cin >> name;
                            
                            showroom.findCustomersByName(name);
                        } else {
                            cout << "Invalid choice." << endl;
                        }
                    } else if (isCustomer) {
                        // Customer purchasing a car
                        int carId;
                        string paymentMethod;
                        
                        // Display available cars
                        showroom.displayInventory();
                        
                        cout << "Enter car ID to purchase: ";
                        cin >> carId;
                        
                        cout << "Enter payment method (Cash/Card/Finance): ";
                        cin >> paymentMethod;
                        
                        if (showroom.purchaseCar(carId, paymentMethod)) {
                            cout << "Car purchased successfully!" << endl;
                        } else {
                            cout << "Failed to purchase car. Please check car availability." << endl;
                        }
                    }
                    break;
                case 5:
                    if (isAdmin || isSalesperson) {
                        int carId, customerId;
                        string paymentMethod;
                        string customerName, customerPhone, customerEmail, customerAddress;
                        
                        cout << "Enter car ID: ";
                        cin >> carId;
                        
                        cout << "Is this an existing customer? (1: Yes, 0: No): ";
                        int existingCustomer;
                        cin >> existingCustomer;
                        
                        if (existingCustomer) {
                            cout << "Enter customer ID: ";
                            cin >> customerId;
                        } else {
                            cout << "Enter customer details:" << endl;
                            cout << "Name: ";
                            cin >> customerName;
                            
                            cout << "Phone: ";
                            cin >> customerPhone;
                            
                            cout << "Email: ";
                            cin >> customerEmail;
                            
                            cout << "Address: ";
                            cin >> customerAddress;
                            
                            customerId = showroom.addCustomer(customerName, customerPhone, customerEmail, customerAddress);
                        }
                        
                        cout << "Enter payment method (Cash/Card/Finance): ";
                        cin >> paymentMethod;
                        
                        if (showroom.processSale(carId, customerId, paymentMethod)) {
                            cout << "Sale processed successfully." << endl;
                        } else {
                            cout << "Failed to process sale. Please check car and customer details." << endl;
                        }
                    } else if (isCustomer) {
                        // View purchase history
                        showroom.viewPurchaseHistory();
                    }
                    break;
                case 6:
                    if (isAdmin || isSalesperson) {
                        showroom.generateSalesReport();
                    }
                    break;
                case 7:
                    if (isAdmin) {
                        int carType, year, quantity, doors, seatingCapacity;
                        double price;
                        string model, brand, transmission, fuelType;
                        bool fourWheelDrive, hasSunroof;
                        int horsepower, topSpeed;
                        double zeroToSixty;
                        string driveType, colors, description;
                        
                        cout << "Enter car type:" << endl;
                        cout << "1. Sedan" << endl;
                        cout << "2. SUV" << endl;
                        cout << "3. Hatchback" << endl;
                        cout << "Enter choice: ";
                        cin >> carType;
                        
                        cout << "Enter model: ";
                        cin.ignore();
                        cin >> model;
                        
                        cout << "Enter brand: ";
                        cin >> brand;
                        
                        cout << "Enter year: ";
                        cin >> year;
                        
                        cout << "Enter price: ";
                        cin >> price;
                        
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        
                        cout << "Enter horsepower: ";
                        cin >> horsepower;
                        
                        cout << "Enter 0-60 mph time (seconds): ";
                        cin >> zeroToSixty;
                        
                        cout << "Enter top speed (mph): ";
                        cin >> topSpeed;
                        
                        cout << "Enter drive type (e.g., 'Front Wheel Drive'): ";
                        cin.ignore();
                        cin >> driveType;
                        
                        cout << "Enter available colors (comma separated): ";
                        cin >> colors;
                        
                        cout << "Enter description (optional): ";
                        cin >> description;
                        
                        Car* car = nullptr;
                        
                        switch (carType) {
                            case 1: // Sedan
                                cout << "Enter number of doors: ";
                                cin >> doors;
                                
                                cout << "Enter transmission type: ";
                                cin >> transmission;
                                
                                car = new Sedan(0, model, brand, year, price, quantity, doors, transmission,
                                               horsepower, zeroToSixty, topSpeed, driveType, colors, description);
                                break;
                                
                            case 2: // SUV
                                cout << "Has four wheel drive? (1: Yes, 0: No): ";
                                cin >> fourWheelDrive;
                                
                                cout << "Enter seating capacity: ";
                                cin >> seatingCapacity;
                                
                                car = new SUV(0, model, brand, year, price, quantity, fourWheelDrive, seatingCapacity,
                                             horsepower, zeroToSixty, topSpeed, driveType, colors, description);
                                break;
                                
                            case 3: // Hatchback
                                cout << "Has sunroof? (1: Yes, 0: No): ";
                                cin >> hasSunroof;
                                
                                cout << "Enter fuel type: ";
                                cin.ignore();
                                cin >> fuelType;
                                
                                car = new Hatchback(0, model, brand, year, price, quantity, hasSunroof, fuelType,
                                                   horsepower, zeroToSixty, topSpeed, driveType, colors, description);
                                break;
                                
                            default:
                                cout << "Invalid car type." << endl;
                        }
                        
                        if (car && showroom.addCar(car)) {
                            cout << "Car added to inventory successfully." << endl;
                        } else {
                            cout << "Failed to add car to inventory." << endl;
                            delete car; // Clean up if not added
                        }
                    } else {
                        cout << "Access denied. Admin privileges required." << endl;
                    }
                    break;
                case 8:
                    if (isAdmin) {
                        string name, phone, email, username, password;
                        double commission;
                        
                        cout << "Enter salesperson details:" << endl;
                        cout << "Name: ";
                        cin >> name;
                        
                        cout << "Phone: ";
                        cin >> phone ;
                        
                        cout << "Email: ";
                        cin >> email;
                        
                        cout << "Username: ";
                        cin >> username;
                        
                        cout << "Password: ";
                        cin >> password;
                        
                        cout << "Commission rate (0.0 to 1.0): ";
                        cin >> commission;
                        
                        if (showroom.addSalesperson(name, phone, email, username, password, commission)) {
                            cout << "Salesperson added successfully." << endl;
                        } else {
                            cout << "Failed to add salesperson." << endl;
                        }
                    } else {
                        cout << "Access denied. Admin privileges required." << endl;
                    }
                    break;
                case 9:
                    if (isAdmin) {
                        showroom.displayAllSalespeople();
                    } else {
                        cout << "Access denied. Admin privileges required." << endl;
                    }
                    break;
                case 10:
                    showroom.logout();
                    loggedIn = false;
                    cout << "Logged out successfully." << endl;
                    break;
                case 0:
                    // Save data before exiting
                    if (showroom.saveData()) {
                        cout << "Data saved successfully." << endl;
                    } else {
                        cout << "Warning: Failed to save some data." << endl;
                    }
                    cout << "Thank you for using Car Showroom Management System." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    } while (choice != 0);
    
    return 0;
}
