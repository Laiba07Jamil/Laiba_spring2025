#include <iostream>
#include <fstream>
#include <cstring> 
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <string>  
#include <stdexcept> 
#include <limits>    

using namespace std;

// Forward declarations
class Car;
class Customer;
class Sale;
class User;
class Person; 

// ===== Utility Classes =====
template <typename T>
class DynamicArray
{
private:
    T *array;
    int capacity;
    int size;

public:
    DynamicArray() : capacity(5), size(0){
        array = new T[capacity];
    }

    ~DynamicArray(){
        delete[] array;
    }

    // Add element to array
    void add(T element)
    {
        if (size >= capacity)
        {
            capacity *= 2;
            T *newArray = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }

            delete[] array;
            array = newArray;
        }

        array[size++] = element;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            return; 
        }

        
        for (int i = index; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }

        size--;
    }

    T &get(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        return array[index];
    }

    
    int getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }
};

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(){
        time_t now = time(0);
        tm localTime = {}; 
#ifdef _WIN32
                           
        tm *tempLtm = localtime(&now);
        if (tempLtm != nullptr)
        {
            localTime = *tempLtm; 
        }
        else{
            day = 1;
            month = 1;
            year = 1970; 
            return;    
        }
#else
        tm *temp = localtime(&now); 
        if (temp != nullptr)
        {
            localTime = *temp;
        }
        else
        {
            day = 1;
            month = 1;
            year = 1970;
            return;
        }
#endif

        day = localTime.tm_mday;
        month = 1 + localTime.tm_mon;
        year = 1900 + localTime.tm_year;
    }

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

   string toString() const
    {
        string d_str = to_string(day);
        string m_str = to_string(month);
        if (day < 10)
            d_str = "0" + d_str;
        if (month < 10)
            m_str = "0" + m_str;
        return d_str + "/" + m_str + "/" + to_string(year);
    }
};

// ===== Base Classes =====

class User
{
protected:
    int userId;
    string username;
    string password;
    string role;

public:
    User() : userId(0), username(""), password(""), role("") {} 

    User(int id, const string &u, const string &p, const string &r) : userId(id), username(u), password(p), role(r) {}

    virtual ~User() {}

    int getUserId() const { return userId; }
    const string &getUsername() const { return username; } 
    const string &getPassword() const { return password; } 
    const string &getRole() const { return role; }         

    void setUserId(int id) { this->userId = id; }
    void setUsername(const string &u) { this->username = u; }
    void setPassword(const string &p) { this->password = p; }
    void setRole(const string &r) { this->role = r; }

    bool verifyLogin(const string &u, const string &p) const
    {
        return (this->username == u && this->password == p);
    }

    virtual void displayUser() const
    {
        cout << "User ID: " << userId << endl;
        cout << "Username: " << username << endl;
        cout << "Role: " << role << endl;
    }
};

// Person base class
class Person
{
protected:
    int personId;
    string name;
    string phone;
    string email;

public:
    Person() : personId(0), name(""), phone(""), email("") {} 

    Person(int id, const string &n, const string &ph, const string &e) : personId(id), name(n), phone(ph), email(e) {}
    virtual ~Person() {}

    int getPersonId() const { return personId; }
    const string &getName() const { return name; }   
    const string &getPhone() const { return phone; } 
    const string &getEmail() const { return email; } 

    void setPersonId(int id) { this->personId = id; }
    void setName(const string &n) { this->name = n; }
    void setPhone(const string &ph) { this->phone = ph; }
    void setEmail(const string &e) { this->email = e; }

    virtual void displayPerson() const
    {
        cout << "ID: " << personId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
    }

    virtual const string getRole() const = 0;
};

// Car base class
class Car
{
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
    Car() : id(0), year(0), price(0.0), quantity(0), horsepower(0), zeroToSixty(0.0), topSpeed(0), model(""), brand(""), driveType(""), colors(""), description("") {} 

    Car(int id, const string &model, const string &brand, int year, double price, int quantity,
        int horsepower, double zeroToSixty, int topSpeed, const string &driveType, const string &colors, const string &description)
        : id(id), year(year), price(price), quantity(quantity),
          horsepower(horsepower), zeroToSixty(zeroToSixty), topSpeed(topSpeed),
          model(model), brand(brand), driveType(driveType), colors(colors), description(description) {} 

    virtual ~Car() {}

    int getId() const { return id; }
    const string &getModel() const { return model; }
    const string &getBrand() const { return brand; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    int getHorsepower() const { return horsepower; }
    double getZeroToSixty() const { return zeroToSixty; }
    int getTopSpeed() const { return topSpeed; }
    const string &getDriveType() const { return driveType; }
    const string &getColors() const { return colors; }
    const string &getDescription() const { return description; }

    void setId(int id) { this->id = id; }
    void setModel(const string &model) { this->model = model; } 
    void setBrand(const string &brand) { this->brand = brand; } 
    void setYear(int year) { this->year = year; }
    void setPrice(double price) { this->price = price; }
    void setQuantity(int quantity) { this->quantity = quantity; }
    void setHorsepower(int horsepower) { this->horsepower = horsepower; }
    void setZeroToSixty(double zeroToSixty) { this->zeroToSixty = zeroToSixty; }
    void setTopSpeed(int topSpeed) { this->topSpeed = topSpeed; }
    void setDriveType(const string &driveType) { this->driveType = driveType; }         
    void setColors(const string &colors) { this->colors = colors; }                     
    void setDescription(const string &description) { this->description = description; } 

    void updateQuantity(int change)
    {
        quantity += change;
        if (quantity < 0)
            quantity = 0;
    }

    virtual void display() const
    {
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
        if (!description.empty())
        { 
            cout << "Description: " << description << endl;
        }
    }

    virtual const string getType() const = 0;
};

// ===== Derived Classes =====
class Admin : public Person, public User{ 
public:
    Admin() : Person(), User(){
        role = "Admin"; 
    }
    Admin(int id, const string &name, const string &phone, const string &email,
          const string &username, const string &password)
        : Person(id, name, phone, email), User(id, username, password, "Admin")
    {
    }

    void display() const
    {
        displayPerson();
        cout << "Username: " << username << endl;
        cout << "Role: " << role << endl;
    }

    const string getRole() const override
    {
        return User::getRole(); 
    }

    int getId() const
    {
        return getPersonId();
    }
};

class Salesperson : public Person, public User{
private:
    double commission;
    int salesCount;

public:
    Salesperson() : Person(), User(), commission(0.0), salesCount(0){                    
        role = "Salesperson"; 
    }

    Salesperson(int id, const string &name, const string &phone, const string &email,
                const string &username, const string &password, double commission = 0.0)
        : Person(id, name, phone, email), User(id, username, password, "Salesperson"),
          commission(commission), salesCount(0)
    {}

    double getCommission() const { return commission; }
    int getSalesCount() const { return salesCount; }

    void setCommission(double commission) { this->commission = commission; }

    void incrementSalesCount() { salesCount++; }

    void display() const{ 
        displayPerson();
        cout << "Username: " << username << endl;
        cout << "Role: " << role << endl;
        cout << "Commission Rate: " << fixed << setprecision(2) << commission * 100 << "%" << endl;
        cout << "Total Sales: " << salesCount << endl;
    }

    const string getRole() const override
    {
        return User::getRole(); 
    }

    int getId() const
    {
        return getPersonId();
    }
};

// Customer class (derived from Person and User)
class Customer : public Person, public User{
private:
    string address;
    int purchaseCount;

public:
    Customer() : Person(), User(), address(""), purchaseCount(0){ 
        this->address = "";
        role = "Customer"; 
    }

    Customer(int id, const string &name, const string &phone, const string &email, const string &address,
             const string &username, const string &password)
        : Person(id, name, phone, email), User(id, username, password, "Customer"),
          purchaseCount(0){
        this->address = address;
    }

    Customer(int id, const string &name, const string &phone, const string &email, const string &address)
        : Person(id, name, phone, email), User(), purchaseCount(0){ 
        this->address = address;
        role = "Customer";
        username = "";
        password = "";
    }

    const string &getAddress() const { return address; }
    int getPurchaseCount() const { return purchaseCount; }

    void setAddress(const string &address) { this->address = address; }


    void incrementPurchaseCount() { purchaseCount++; }

    bool isRegistered() const{
        return !username.empty();
    }

    void display() const{ 
        displayPerson();
        cout << "Address: " << address << endl;
        cout << "Role: " << role << endl;
        cout << "Purchase Count: " << purchaseCount << endl;
        if (isRegistered())
        {
            cout << "Username: " << username << endl;
            cout << "Status: Registered Customer" << endl;
        }
        else
        {
            cout << "Status: Non-Registered Customer" << endl;
        }
    }
    const string getRole() const override{
        return isRegistered() ? User::getRole() : "Customer";
    }

    int getId() const
    {
        return getPersonId();
    }
};

// Sedan class (derived from Car)
class Sedan : public Car
{
private:
    string type;
    int doors;
    string transmission;

public:
    Sedan() : Car(), type("Sedan"), doors(0), transmission("") {} 

    Sedan(int id, const string &model, const string &brand, int year, double price, int quantity,
          int doors, const string &transmission, int horsepower, double zeroToSixty, int topSpeed,
          const string &driveType, const string &colors, const string &description = "")
        : Car(id, model, brand, year, price, quantity, horsepower, zeroToSixty, topSpeed, driveType, colors, description),
          type("Sedan"), doors(doors), transmission(transmission) {} 

    int getDoors() const { return doors; }
    const string &getTransmission() const { return transmission; }

    void setDoors(int doors) { this->doors = doors; }
    void setTransmission(const string &transmission) { this->transmission = transmission; } 

    void display() const override{
        Car::display();
        cout << "Type: " << type << endl;
        cout << "Doors: " << doors << endl;
        cout << "Transmission: " << transmission << endl;
        cout << "=======================================" << endl;
    }

    const string getType() const override{
        return type;
    }
};

// SUV class (derived from Car)
class SUV : public Car{
private:
    string type;
    bool fourWheelDrive;
    int seatingCapacity;

public:
    SUV() : Car(), type("SUV"), fourWheelDrive(false), seatingCapacity(0) {} 

    SUV(int id, const string &model, const string &brand, int year, double price, int quantity,
        bool fourWheelDrive, int seatingCapacity, int horsepower, double zeroToSixty, int topSpeed,
        const string &driveType, const string &colors, const string &description = "")
        : Car(id, model, brand, year, price, quantity, horsepower, zeroToSixty, topSpeed, driveType, colors, description),
          type("SUV"), fourWheelDrive(fourWheelDrive), seatingCapacity(seatingCapacity) {}

    bool hasFourWheelDrive() const { return fourWheelDrive; }
    int getSeatingCapacity() const { return seatingCapacity; }

    void setFourWheelDrive(bool fourWheelDrive) { this->fourWheelDrive = fourWheelDrive; }
    void setSeatingCapacity(int seatingCapacity) { this->seatingCapacity = seatingCapacity; }


    void display() const override{
        Car::display();
        cout << "Type: " << type << endl;
        cout << "Four Wheel Drive: " << (fourWheelDrive ? "Yes" : "No") << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "=======================================" << endl;
    }

    const string getType() const override
    {
        return type;
    }
};

// Hatchback class (derived from Car)
class Hatchback : public Car
{
private:
    string type;
    bool hasSunroof;
    string fuelType;

public:
    Hatchback() : Car(), type("Hatchback"), hasSunroof(false), fuelType("") {} 

    Hatchback(int id, const string &model, const string &brand, int year, double price, int quantity,
              bool hasSunroof, const string &fuelType, int horsepower, double zeroToSixty, int topSpeed,
              const string &driveType, const string &colors, const string &description = "")
        : Car(id, model, brand, year, price, quantity, horsepower, zeroToSixty, topSpeed, driveType, colors, description),
          type("Hatchback"), hasSunroof(hasSunroof), fuelType(fuelType) {}

    bool getHasSunroof() const { return hasSunroof; }
    const string &getFuelType() const { return fuelType; }

    void setHasSunroof(bool hasSunroof) { this->hasSunroof = hasSunroof; }
    void setFuelType(const string &fuelType) { this->fuelType = fuelType; }

    void display() const override{
        Car::display();
        cout << "Type: " << type << endl;
        cout << "Sunroof: " << (hasSunroof ? "Yes" : "No") << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "=======================================" << endl;
    }

    const string getType() const override{
        return type;
    }
};

// ===== System Classes =====

// Sale class to represent a transaction
class Sale
{
private:
    int id;
    int carId;
    int customerId;
    int salespersonId; 
    Date saleDate;
    double amount;
    string paymentMethod;

public:

    Sale() : id(0), carId(0), customerId(0), salespersonId(0), amount(0.0), paymentMethod("") {} 

    Sale(int id, int carId, int customerId, int salespersonId,
         const Date &saleDate, double amount, const string &paymentMethod)
        : id(id), carId(carId), customerId(customerId),
          salespersonId(salespersonId), saleDate(saleDate), amount(amount), paymentMethod(paymentMethod) {}

    int getId() const { return id; }
    int getCarId() const { return carId; }
    int getCustomerId() const { return customerId; }
    int getSalespersonId() const { return salespersonId; }
    Date getSaleDate() const { return saleDate; }
    double getAmount() const { return amount; }
    const string &getPaymentMethod() const { return paymentMethod; }

    void setId(int id) { this->id = id; }
    void setCarId(int carId) { this->carId = carId; }
    void setCustomerId(int customerId) { this->customerId = customerId; }
    void setSalespersonId(int salespersonId) { this->salespersonId = salespersonId; }
    void setSaleDate(const Date &saleDate) { this->saleDate = saleDate; }
    void setAmount(double amount) { this->amount = amount; }
    void setPaymentMethod(const string &paymentMethod) { this->paymentMethod = paymentMethod; }


    void display() const
    {
        cout << "Sale ID: " << id << endl;
        cout << "Car ID: " << carId << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Salesperson ID: " << (salespersonId == 0 ? "N/A" : to_string(salespersonId)) << endl;
        cout << "Sale Date: " << saleDate.toString() << endl;
        cout << "Amount: $" << fixed << setprecision(2) << amount << endl;
        cout << "Payment Method: " << paymentMethod << endl;
    }
};

// Invoice class to generate sales documentation
class Invoice
{
private:
    int id;
    Sale sale; 
    double taxRate;
    double discount;
    double totalAmount;

public:
    Invoice() : id(0), taxRate(0.0), discount(0.0), totalAmount(0.0) {} 

    Invoice(int id, const Sale &sale, double taxRate, double discount)
        : id(id), sale(sale), taxRate(taxRate), discount(discount){
        calculateTotal();
    }

    int getId() const { return id; }
    Sale getSale() const { return sale; } 
    double getTaxRate() const { return taxRate; }
    double getDiscount() const { return discount; }
    double getTotalAmount() const { return totalAmount; }

    void setId(int id) { this->id = id; }
    void setSale(const Sale &sale)
    {
        this->sale = sale;
        calculateTotal();
    } 
    void setTaxRate(double taxRate)
    {
        this->taxRate = taxRate;
        calculateTotal();
    }
    void setDiscount(double discount)
    {
        this->discount = discount;
        calculateTotal();
    }

    void calculateTotal()
    {
        double saleAmount = sale.getAmount();
        double taxAmount = saleAmount * taxRate;
        double discountAmount = saleAmount * discount;
        totalAmount = saleAmount + taxAmount - discountAmount;
        if (totalAmount < 0)
            totalAmount = 0; 
    }

    void generateInvoice() const
    {
        cout << "=======================================" << endl;
        cout << "             INVOICE                   " << endl;
        cout << "=======================================" << endl;
        cout << "Invoice ID: " << id << endl;
        cout << "Date: " << sale.getSaleDate().toString() << endl;
        cout << "---------------------------------------" << endl;
        cout << "Sale ID: " << sale.getId() << endl;
        cout << "Car ID: " << sale.getCarId() << endl;
        cout << "Customer ID: " << sale.getCustomerId() << endl;
        cout << "Salesperson ID: " << (sale.getSalespersonId() == 0 ? "N/A" : to_string(sale.getSalespersonId())) << endl;
        cout << "---------------------------------------" << endl;
        cout << "Subtotal: $" << fixed << setprecision(2) << sale.getAmount() << endl;
        cout << "Tax (" << fixed << setprecision(2) << taxRate * 100 << "%): $" << fixed << setprecision(2) << sale.getAmount() * taxRate << endl;
        cout << "Discount (" << fixed << setprecision(2) << discount * 100 << "%): $" << fixed << setprecision(2) << sale.getAmount() * discount << endl;
        cout << "---------------------------------------" << endl;
        cout << "Total Amount: $" << fixed << setprecision(2) << totalAmount << endl;
        cout << "Payment Method: " << sale.getPaymentMethod() << endl;
        cout << "=======================================" << endl;
    }


    bool saveToFile(const string &filename) const
    {                     
        ofstream file(filename.c_str()); 
        if (!file)
        {
            cerr << "Error opening file for writing: " << filename << endl;
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
        file << "Salesperson ID: " << (sale.getSalespersonId() == 0 ? "N/A" : to_string(sale.getSalespersonId())) << endl;
        file << "---------------------------------------" << endl;
        file << "Subtotal: $" << fixed << setprecision(2) << sale.getAmount() << endl;
        file << "Tax (" << fixed << setprecision(2) << taxRate * 100 << "%): $" << fixed << setprecision(2) << sale.getAmount() * taxRate << endl;
        file << "Discount (" << fixed << setprecision(2) << discount * 100 << "%): $" << fixed << setprecision(2) << sale.getAmount() * discount << endl;
        file << "---------------------------------------" << endl;
        file << "Total Amount: $" << fixed << setprecision(2) << totalAmount << endl;
        file << "Payment Method: " << sale.getPaymentMethod() << endl;
        file << "=======================================" << endl;

        file.close();
        return file.good(); 
    }
};

// Inventory class to manage car stock
class Inventory
{
private:
    DynamicArray<Car *> cars;
    int nextCarId;

public:
    Inventory() : nextCarId(1) {}

    ~Inventory(){
        for (int i = 0; i < cars.getSize(); i++){
            delete cars.get(i);
        }
    
    }

    void addCar(Car *car)
    {
        if (!car)
            return; 
        car->setId(nextCarId++);
        cars.add(car);
    }

    bool removeCar(int id)
    {
        for (int i = 0; i < cars.getSize(); i++){
        
            if (cars.get(i) && cars.get(i)->getId() == id)
            {
                delete cars.get(i);
                cars.remove(i);     
                return true;
            }
        }
        return false;
    }

    Car *findCar(int id) const{
        for (int i = 0; i < cars.getSize(); i++){
            if (cars.get(i) && cars.get(i)->getId() == id)
            {
                return cars.get(i);
            }
        }
        return nullptr;
    }

    bool updateCarQuantity(int id, int change)
    {
        Car *car = findCar(id);
        if (car){ 
            car->updateQuantity(change);
            return true;
        }
        return false;
    }

    void displayAllCars() const
    {
        if (cars.getSize() == 0)
        {
            cout << "No cars in inventory." << endl;
            return;
        }

        cout << "======= INVENTORY =======" << endl;
        for (int i = 0; i < cars.getSize(); i++)
        {
            if (cars.get(i)){ 
                cars.get(i)->display();
            }
        }
    }

    void displayCarsByType(const string &type) const{
        bool found = false;
        string lowerType = type;
        for (char &c : lowerType){
            c = tolower(c);
        }

        cout << "======= " << type << " CARS =======" << endl;
        for (int i = 0; i < cars.getSize(); i++){
            if (cars.get(i)){ 
                string carType = cars.get(i)->getType();
                string lowerCarType = carType;
                for (char &c : lowerCarType){
                    c = tolower(c);
                }

                if (lowerCarType == lowerType){ 
                    cars.get(i)->display();
                    found = true;
                }
            }
        }

        if (!found){
            cout << "No " << type << " cars found in inventory." << endl;
        }
    }

    int getCarCount() const{
        return cars.getSize();
    }

    int getAvailableCarCount() const{
        int count = 0;
        for (int i = 0; i < cars.getSize(); i++){
            if (cars.get(i) && cars.get(i)->getQuantity() > 0){ 
                count++;
            }
        }
        return count;
    }

    void initializeInventory(){
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

        nextCarId = getCarCount() > 0 ? cars.get(getCarCount() - 1)->getId() + 1 : 1;
    }

    const DynamicArray<Car *> &getCars() const { return cars; }
};

class FileHandler{
private:
    static void writeStringToFile(ofstream &file, const string &str){
        size_t len = str.length();
        file.write(reinterpret_cast<const char *>(&len), sizeof(len));
        file.write(str.c_str(), len);
    }

    static string readStringFromFile(ifstream &file) {
        size_t len;
        file.read(reinterpret_cast<char *>(&len), sizeof(len));
        if (!file || len > 1024 * 10){
            return "";
        }
        if (len == 0)
            return "";
        string str(len, '\0');
        file.read(&str[0], len);
        if (!file){
            return "";
        }
        return str;
    }

public:
    static bool saveAdmins(const DynamicArray<Admin *> &admins, const string &filename)
    {
        ofstream file(filename, ios::binary | ios::trunc);
        if (!file){
            return false;
        }

        int size = admins.getSize();
        file.write(reinterpret_cast<const char *>(&size), sizeof(size));

        for (int i = 0; i < size; i++){
            Admin *admin = admins.get(i);
            if (admin){
                int personId = admin->getPersonId();
                int userId = admin->getUserId();
                file.write(reinterpret_cast<const char *>(&personId), sizeof(personId));
                file.write(reinterpret_cast<const char *>(&userId), sizeof(userId));
                writeStringToFile(file, admin->getName());
                writeStringToFile(file, admin->getPhone());
                writeStringToFile(file, admin->getEmail());
                writeStringToFile(file, admin->getUsername());
                writeStringToFile(file, admin->getPassword());
                if (!file){
                    file.close();
                    return false;
                }
            }
        }

        file.close();
        return file.good();
    }

    static bool loadAdmins(DynamicArray<Admin *> &admins, const string &filename)
    {
        ifstream file(filename, ios::binary);
        if (!file)
        {
            return false;
        }

        int size = 0;
        file.read(reinterpret_cast<char *>(&size), sizeof(size));
        if (!file || size < 0 || size > 10000)
        {
            file.close();
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            int personId, userId;
            file.read(reinterpret_cast<char *>(&personId), sizeof(personId));
            file.read(reinterpret_cast<char *>(&userId), sizeof(userId));
            if (!file)
            {
                break;
            }

            string name = readStringFromFile(file);
            string phone = readStringFromFile(file);
            string email = readStringFromFile(file);
            string username = readStringFromFile(file);
            string password = readStringFromFile(file);
            if (!file)
            {
                break;
            }

            Admin *admin = new Admin(personId, name, phone, email, username, password);
            admin->setUserId(userId);
            admins.add(admin);
        }

        file.close();
        return true;
    }

    static bool saveSalespeople(const DynamicArray<Salesperson *> &salespeople, const string &filename)
    {
        ofstream file(filename, ios::binary | ios::trunc);
        if (!file)
        {
            return false;
        }

        int size = salespeople.getSize();
        file.write(reinterpret_cast<const char *>(&size), sizeof(size));

        for (int i = 0; i < size; i++)
        {
            Salesperson *sp = salespeople.get(i);
            if (sp)
            {
                int personId = sp->getPersonId();
                int userId = sp->getUserId();
                double commission = sp->getCommission();
                int salesCount = sp->getSalesCount();
                file.write(reinterpret_cast<const char *>(&personId), sizeof(personId));
                file.write(reinterpret_cast<const char *>(&userId), sizeof(userId));
                file.write(reinterpret_cast<const char *>(&commission), sizeof(commission));
                file.write(reinterpret_cast<const char *>(&salesCount), sizeof(salesCount));
                writeStringToFile(file, sp->getName());
                writeStringToFile(file, sp->getPhone());
                writeStringToFile(file, sp->getEmail());
                writeStringToFile(file, sp->getUsername());
                writeStringToFile(file, sp->getPassword());
                if (!file)
                {
                    file.close();
                    return false;
                }
            }
        }

        file.close();
        return file.good();
    }

    static bool loadSalespeople(DynamicArray<Salesperson *> &salespeople, const string &filename)
    {
        ifstream file(filename, ios::binary);
        if (!file)
        {
            return false;
        }

        int size = 0;
        file.read(reinterpret_cast<char *>(&size), sizeof(size));
        if (!file || size < 0 || size > 10000)
        {
            file.close();
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            int personId, userId, salesCount;
            double commission;
            file.read(reinterpret_cast<char *>(&personId), sizeof(personId));
            file.read(reinterpret_cast<char *>(&userId), sizeof(userId));
            file.read(reinterpret_cast<char *>(&commission), sizeof(commission));
            file.read(reinterpret_cast<char *>(&salesCount), sizeof(salesCount));
            if (!file)
            {
                break;
            }

            string name = readStringFromFile(file);
            string phone = readStringFromFile(file);
            string email = readStringFromFile(file);
            string username = readStringFromFile(file);
            string password = readStringFromFile(file);
            if (!file)
            {
                break;
            }

            Salesperson *sp = new Salesperson(personId, name, phone, email, username, password, commission);
            sp->setUserId(userId);
            for (int j = 0; j < salesCount; ++j)
                sp->incrementSalesCount();
            salespeople.add(sp);
        }

        file.close();
        return true;
    }

    static bool saveCustomers(const DynamicArray<Customer *> &customers, const string &filename)
    {
        ofstream file(filename, ios::binary | ios::trunc);
        if (!file)
        {
            return false;
        }

        int size = customers.getSize();
        file.write(reinterpret_cast<const char *>(&size), sizeof(size));

        for (int i = 0; i < size; i++)
        {
            Customer *cust = customers.get(i);
            if (cust)
            {
                int personId = cust->getPersonId();
                int purchaseCount = cust->getPurchaseCount();
                bool registered = cust->isRegistered();
                int userId = registered ? cust->getUserId() : 0;

                file.write(reinterpret_cast<const char *>(&personId), sizeof(personId));
                file.write(reinterpret_cast<const char *>(&purchaseCount), sizeof(purchaseCount));
                file.write(reinterpret_cast<const char *>(&registered), sizeof(registered));

                writeStringToFile(file, cust->getName());
                writeStringToFile(file, cust->getPhone());
                writeStringToFile(file, cust->getEmail());
                writeStringToFile(file, cust->getAddress());

                if (registered)
                {
                    file.write(reinterpret_cast<const char *>(&userId), sizeof(userId));
                    writeStringToFile(file, cust->getUsername());
                    writeStringToFile(file, cust->getPassword());
                }
                if (!file)
                {
                    file.close();
                    return false;
                }
            }
        }

        file.close();
        return file.good();
    }

    static bool loadCustomers(DynamicArray<Customer *> &customers, const string &filename)
    {
        ifstream file(filename, ios::binary);
        if (!file)
        {
            return false;
        }

        int size = 0;
        file.read(reinterpret_cast<char *>(&size), sizeof(size));
        if (!file || size < 0 || size > 100000)
        {
            file.close();
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            int personId, purchaseCount;
            bool registered;
            int userId = 0;
            string username = "", password = "";

            file.read(reinterpret_cast<char *>(&personId), sizeof(personId));
            file.read(reinterpret_cast<char *>(&purchaseCount), sizeof(purchaseCount));
            file.read(reinterpret_cast<char *>(&registered), sizeof(registered));
            if (!file)
            {
                break;
            }

            string name = readStringFromFile(file);
            string phone = readStringFromFile(file);
            string email = readStringFromFile(file);
            string address = readStringFromFile(file);
            if (!file){
                break;
            }

            if (registered){
                file.read(reinterpret_cast<char *>(&userId), sizeof(userId));
                if (!file){
                    break;
                }
                username = readStringFromFile(file);
                password = readStringFromFile(file);
                if (!file){
                    break;
                }
            }

            Customer *cust;
            if (registered){
                cust = new Customer(personId, name, phone, email, address, username, password);
                cust->setUserId(userId);
            }
            else{
                cust = new Customer(personId, name, phone, email, address);
            }

            for (int j = 0; j < purchaseCount; ++j)
                cust->incrementPurchaseCount();

            customers.add(cust);
        }

        file.close();
        return true;
    }

    static bool saveCars(const Inventory &inventory, const string &filename){
        ofstream file(filename.c_str()); 
        if (!file)
        {
            return false;
        }

        file << "Cars saved: " << inventory.getCarCount() << endl;
        file.close();
        return true;
    }

    static bool loadCars(Inventory &inventory, const string &filename)
    { 
        ifstream file(filename.c_str()); 
        if (!file)
        {
            return false;
        }

        string line;
        getline(file, line);
        file.close();
        return true;
    }

    // Save sales to file
    static bool saveSales(const DynamicArray<Sale *> &sales, const string &filename)
    {
        ofstream file(filename, ios::binary | ios::trunc);
        if (!file)
        {
            return false;
        }

        int size = sales.getSize();
        file.write(reinterpret_cast<const char *>(&size), sizeof(size));

        for (int i = 0; i < size; i++)
        {
            Sale *sale = sales.get(i);
            if (sale)
            {
                int id = sale->getId();
                int carId = sale->getCarId();
                int customerId = sale->getCustomerId();
                int salespersonId = sale->getSalespersonId();
                double amount = sale->getAmount();
                Date saleDate = sale->getSaleDate();
                int d = saleDate.getDay();
                int m = saleDate.getMonth();
                int y = saleDate.getYear();

                file.write(reinterpret_cast<const char *>(&id), sizeof(id));
                file.write(reinterpret_cast<const char *>(&carId), sizeof(carId));
                file.write(reinterpret_cast<const char *>(&customerId), sizeof(customerId));
                file.write(reinterpret_cast<const char *>(&salespersonId), sizeof(salespersonId));
                file.write(reinterpret_cast<const char *>(&amount), sizeof(amount));
                file.write(reinterpret_cast<const char *>(&d), sizeof(d));
                file.write(reinterpret_cast<const char *>(&m), sizeof(m));
                file.write(reinterpret_cast<const char *>(&y), sizeof(y));

                writeStringToFile(file, sale->getPaymentMethod());
                if (!file)
                {
                    file.close();
                    return false;
                }
            }
        }

        file.close();
        return file.good();
    }

    // Load sales from file
    static bool loadSales(DynamicArray<Sale *> &sales, const string &filename){
        ifstream file(filename, ios::binary);
        if (!file){
            return false;
        }

        int size = 0;
        file.read(reinterpret_cast<char *>(&size), sizeof(size));
        if (!file || size < 0 || size > 100000){
            file.close();
            return false;
        }

        for (int i = 0; i < size; i++){
            int id, carId, customerId, salespersonId;
            double amount;
            int d, m, y;

            file.read(reinterpret_cast<char *>(&id), sizeof(id));
            file.read(reinterpret_cast<char *>(&carId), sizeof(carId));
            file.read(reinterpret_cast<char *>(&customerId), sizeof(customerId));
            file.read(reinterpret_cast<char *>(&salespersonId), sizeof(salespersonId));
            file.read(reinterpret_cast<char *>(&amount), sizeof(amount));
            file.read(reinterpret_cast<char *>(&d), sizeof(d));
            file.read(reinterpret_cast<char *>(&m), sizeof(m));
            file.read(reinterpret_cast<char *>(&y), sizeof(y));
            if (!file)
            {
                break;
            }

            string paymentMethod = readStringFromFile(file);
            if (!file)
            {
                break;
            }

            Date saleDate(d, m, y);
            Sale *sale = new Sale(id, carId, customerId, salespersonId, saleDate, amount, paymentMethod);
            sales.add(sale);
        }

        file.close();
        return true;
    }

    static bool saveInvoices(const DynamicArray<Invoice *> &invoices, const string &filename)
    {
        ofstream file(filename, ios::binary | ios::trunc);
        if (!file)
        {
            return false;
        }

        int size = invoices.getSize();
        file.write(reinterpret_cast<const char *>(&size), sizeof(size));

        for (int i = 0; i < size; i++)
        {
            Invoice *inv = invoices.get(i);
            if (inv)
            {
                int id = inv->getId();
                double taxRate = inv->getTaxRate();
                double discount = inv->getDiscount();
                Sale sale = inv->getSale();
                int saleId = sale.getId();

                file.write(reinterpret_cast<const char *>(&id), sizeof(id));
                file.write(reinterpret_cast<const char *>(&taxRate), sizeof(taxRate));
                file.write(reinterpret_cast<const char *>(&discount), sizeof(discount));
                file.write(reinterpret_cast<const char *>(&saleId), sizeof(saleId));
                if (!file)
                {
                    file.close();
                    return false;
                }
            }
        }

        file.close();
        return file.good();
    }

    // Load invoices from file
    static bool loadInvoices(DynamicArray<Invoice *> &invoices, const DynamicArray<Sale *> &salesData, const string &filename)
    {
        ifstream file(filename, ios::binary);
        if (!file)
        {
            return false;
        }

        int size = 0;
        file.read(reinterpret_cast<char *>(&size), sizeof(size));
        if (!file || size < 0 || size > 100000)
        {
            file.close();
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            int id;
            double taxRate, discount;
            int saleId;

            file.read(reinterpret_cast<char *>(&id), sizeof(id));
            file.read(reinterpret_cast<char *>(&taxRate), sizeof(taxRate));
            file.read(reinterpret_cast<char *>(&discount), sizeof(discount));
            file.read(reinterpret_cast<char *>(&saleId), sizeof(saleId));
            if (!file)
            {
                break;
            }

            Sale *foundSale = nullptr;
            for (int j = 0; j < salesData.getSize(); ++j){
                if (salesData.get(j) && salesData.get(j)->getId() == saleId)
                {
                    foundSale = salesData.get(j);
                    break;
                }
            }

            if (foundSale){
                Invoice *invoice = new Invoice(id, *foundSale, taxRate, discount);
                invoices.add(invoice);
            }
            else
            {
            }
        }

        file.close();
        return true;
    }
};

// Showroom class - main system class
class Showroom
{
private:
    string name;
    string address;
    string phone;

    DynamicArray<Admin *> admins;
    DynamicArray<Salesperson *> salespeople;
    DynamicArray<Customer *> customers;
    DynamicArray<Sale *> sales;
    DynamicArray<Invoice *> invoices;

    Inventory inventory;

    int nextSaleId;
    int nextInvoiceId;
    int nextCustomerId; 
    int nextUserId;    

    User *currentUser;

    int getNextPersonId()
    {
        int maxId = 0;
        for (int i = 0; i < admins.getSize(); ++i)
            if (admins.get(i) && admins.get(i)->getPersonId() > maxId)
                maxId = admins.get(i)->getPersonId();
        for (int i = 0; i < salespeople.getSize(); ++i)
            if (salespeople.get(i) && salespeople.get(i)->getPersonId() > maxId)
                maxId = salespeople.get(i)->getPersonId();
        for (int i = 0; i < customers.getSize(); ++i)
            if (customers.get(i) && customers.get(i)->getPersonId() > maxId)
                maxId = customers.get(i)->getPersonId();
        return maxId + 1;
    }

    int getNextUserId(){
        int maxId = 0;
        for (int i = 0; i < admins.getSize(); ++i)
            if (admins.get(i) && admins.get(i)->getUserId() > maxId)
                maxId = admins.get(i)->getUserId();
        for (int i = 0; i < salespeople.getSize(); ++i)
            if (salespeople.get(i) && salespeople.get(i)->getUserId() > maxId)
                maxId = salespeople.get(i)->getUserId();
        for (int i = 0; i < customers.getSize(); ++i)
            if (customers.get(i) && customers.get(i)->isRegistered() && customers.get(i)->getUserId() > maxId)
                maxId = customers.get(i)->getUserId();
        return maxId + 1;
    }

    int getNextSaleId(){
        int maxId = 0;
        for (int i = 0; i < sales.getSize(); ++i)
            if (sales.get(i) && sales.get(i)->getId() > maxId)
                maxId = sales.get(i)->getId();
        return maxId + 1;
    }

    int getNextInvoiceId()
    {
        int maxId = 0;
        for (int i = 0; i < invoices.getSize(); ++i)
            if (invoices.get(i) && invoices.get(i)->getId() > maxId)
                maxId = invoices.get(i)->getId();
        return maxId + 1;
    }

public:
    Showroom(const char *name_cstr, const char *address_cstr, const char *phone_cstr) 
        : name(name_cstr), address(address_cstr), phone(phone_cstr),                  
          nextSaleId(1), nextInvoiceId(1), nextCustomerId(1), nextUserId(1), currentUser(nullptr){
        bool dataLoaded = loadData();

        if (admins.getSize() == 0) {
            Admin *admin = new Admin(1, "Admin", "1234567890", "admin@showroom.com", "admin", "admin123");
            admin->setUserId(1); 
            admins.add(admin);
            nextCustomerId = 2;
            nextUserId = 2;
        }

        if (inventory.getCarCount() == 0){
            inventory.initializeInventory();
        }

        nextCustomerId = getNextPersonId();
        nextUserId = getNextUserId();
        nextSaleId = getNextSaleId();
        nextInvoiceId = getNextInvoiceId();
    }

    ~Showroom(){
        saveData();
        for (int i = 0; i < admins.getSize(); i++){
            delete admins.get(i);
        }

        for (int i = 0; i < salespeople.getSize(); i++){
            delete salespeople.get(i);
        }

        for (int i = 0; i < customers.getSize(); i++){
            delete customers.get(i);
        }

        for (int i = 0; i < sales.getSize(); i++){
            delete sales.get(i);
        }

        for (int i = 0; i < invoices.getSize(); i++){
            delete invoices.get(i);
        }
    }


    bool login(const string &username, const string &password)
    {
        for (int i = 0; i < admins.getSize(); i++)
        {
            Admin *admin = admins.get(i);
            if (admin && admin->verifyLogin(username, password))
            { 
                currentUser = admin;
                return true;
            }
        }

        for (int i = 0; i < salespeople.getSize(); i++)
        {
            Salesperson *salesperson = salespeople.get(i);
            if (salesperson && salesperson->verifyLogin(username, password))
            { 
                currentUser = salesperson;
                return true;
            }
        }

        for (int i = 0; i < customers.getSize(); i++)
        {
            Customer *customer = customers.get(i);
            if (customer && customer->isRegistered() && customer->verifyLogin(username, password))
            {
                currentUser = customer;
                return true;
            }
        }

        currentUser = nullptr;
        return false;
    }

    bool isUsernameExists(const string &username) const
    { 
        for (int i = 0; i < admins.getSize(); i++){
            if (admins.get(i) && admins.get(i)->getUsername() == username){ 
                return true;
            }
        }
        for (int i = 0; i < salespeople.getSize(); i++){
            if (salespeople.get(i) && salespeople.get(i)->getUsername() == username){ 
                return true;
            }
        }

        for (int i = 0; i < customers.getSize(); i++){
            if (customers.get(i) && customers.get(i)->isRegistered() && customers.get(i)->getUsername() == username){ 
                return true;
            }
        }

        return false;
    }

    bool isEmailExists(const string &email) const
    {
        for (int i = 0; i < admins.getSize(); i++)
        {
            if (admins.get(i) && admins.get(i)->getEmail() == email)
            { 
                return true;
            }
        }

        for (int i = 0; i < salespeople.getSize(); i++)
        {
            if (salespeople.get(i) && salespeople.get(i)->getEmail() == email)
            { 
                return true;
            }
        }

        for (int i = 0; i < customers.getSize(); i++)
        {
            if (customers.get(i) && customers.get(i)->getEmail() == email)
            { 
                return true;
            }
        }

        return false;
    }

    bool registerUser(const string &name, const string &phone, const string &email,
                      const string &address, const string &username, const string &password,
                      const string &role, double commissionRate = 0.0)
    {
        if (isUsernameExists(username)){
            cout << "Error: Username already exists. Please choose a different username." << endl;
            return false;
        }

        if (isEmailExists(email))
        {
            cout << "Error: Email address already in use. Please use a different email." << endl;
            return false;
        }

        int newPersonId = nextCustomerId;
        int newUserId = nextUserId;

        if (role == "Customer")
        {
            Customer *customer = new Customer(newPersonId, name, phone, email, address, username, password);
            customer->setUserId(newUserId);
            customers.add(customer);
        }
        else if (role == "Admin")
        {
            Admin *admin = new Admin(newPersonId, name, phone, email, username, password);
            admin->setUserId(newUserId);
            admins.add(admin);
        }
        else if (role == "Salesperson")
        {
            Salesperson *salesperson = new Salesperson(newPersonId, name, phone, email, username, password, commissionRate);
            salesperson->setUserId(newUserId);
            salespeople.add(salesperson);
        }
        else{
            cout << "Error: Invalid role specified for registration." << endl;
            return false;
        }

        nextCustomerId++;
        nextUserId++;
        return true;
    }

    void logout(){
        currentUser = nullptr;
    }


    User *getCurrentUser() const{
        return currentUser;
    }

    bool isAdmin() const{
        return currentUser != nullptr && dynamic_cast<Admin *>(currentUser) != nullptr;
    }

    bool isSalesperson() const{
        return currentUser != nullptr && dynamic_cast<Salesperson *>(currentUser) != nullptr;
    }

    bool isCustomer() const{
        return currentUser != nullptr && dynamic_cast<Customer *>(currentUser) != nullptr;
    }

    bool addAdmin(const string &name, const string &phone, const string &email,
                  const string &username, const string &password){ // Use const string&
        if (!isAdmin()){
            cout << "Error: Only Admins can add new Admins." << endl;
            return false;
        }
        
        return registerUser(name, phone, email, "N/A", username, password, "Admin");
    }

    bool addSalesperson(const string &name, const string &phone, const string &email,
                        const string &username, const string &password, double commission){ 
        if (!isAdmin()){
            cout << "Error: Only Admins can add new Salespeople." << endl;
            return false;
        }
        return registerUser(name, phone, email, "N/A", username, password, "Salesperson", commission);
    }
    
    int addCustomer(const string &name, const string &phone, const string &email, const string &address){ 
        bool emailConflict = false;
        for (int i = 0; i < admins.getSize(); ++i){
            if (admins.get(i) && admins.get(i)->getEmail() == email){
                emailConflict = true;
                break;
            }
        }
        if (!emailConflict){
            for (int i = 0; i < salespeople.getSize(); ++i){
                if (salespeople.get(i) && salespeople.get(i)->getEmail() == email){
                    emailConflict = true;
                    break;
                }
            }
        }
        if (!emailConflict){
            for (int i = 0; i < customers.getSize(); ++i){
                if (customers.get(i) && customers.get(i)->isRegistered() && customers.get(i)->getEmail() == email){
                    emailConflict = true;
                    break;
                }
            }
        }

        if (emailConflict)
        {
            cout << "Error: Email address is already associated with a registered user or staff member." << endl;
            return -1;
        }

        int newPersonId = nextCustomerId; 
        Customer *customer = new Customer(newPersonId, name, phone, email, address);
        customers.add(customer);
        nextCustomerId++;
        return customer->getPersonId(); 
    }

    int addRegisteredCustomer(const char *name_cstr, const char *phone_cstr, const char *email_cstr,
                              const char *address_cstr, const char *username_cstr, const char *password_cstr)
    {
        string s_name(name_cstr ? name_cstr : "");
        string s_phone(phone_cstr ? phone_cstr : "");
        string s_email(email_cstr ? email_cstr : "");
        string s_address(address_cstr ? address_cstr : "");
        string s_username(username_cstr ? username_cstr : "");
        string s_password(password_cstr ? password_cstr : "");

        if (registerUser(s_name, s_phone, s_email, s_address, s_username, s_password, "Customer"))
        {
            for (int i = customers.getSize() - 1; i >= 0; --i){ 
                if (customers.get(i) && customers.get(i)->getUsername() == s_username)
                {
                    return customers.get(i)->getPersonId();
                }
            }
            return -1; 
        }
        else
        {
            return -1; 
        }
    }

    Customer *findCustomer(int personId) const{ 
        for (int i = 0; i < customers.getSize(); i++)
        {
            if (customers.get(i) && customers.get(i)->getPersonId() == personId){ 
                return customers.get(i);
            }
        }
        return nullptr;
    }

    void findCustomersByName(const string &name) const{
        bool found = false;
        string lowerSearchName = name;
        for (char &c : lowerSearchName)
            c = tolower(c); 

        cout << "--- Customers matching '" << name << "' ---" << endl;
        for (int i = 0; i < customers.getSize(); i++)
        {
            Customer *customer = customers.get(i);
            if (customer){ 
                string lowerCustName = customer->getName();
                for (char &c : lowerCustName)
                    c = tolower(c); 

                if (lowerCustName.find(lowerSearchName) != string::npos)
                {
                    customer->display();
                    cout << "------------------------" << endl;
                    found = true;
                }
            }
        }

        if (!found)
        {
            cout << "No customers found matching '" << name << "'." << endl;
        }
    }

    bool addCar(Car *car)
    {
        if (!isAdmin())
        {
            cout << "Error: Only Admins can add cars to inventory." << endl;
            return false;
        }
        if (car == nullptr)
        {
            cout << "Error: Cannot add null car." << endl;
            return false;
        }

        inventory.addCar(car);
        return true;
    }

    bool processSale(int carId, int customerId, const string &paymentMethod){
        Car *car = inventory.findCar(carId);
        if (!car || car->getQuantity() <= 0)
        {
            cout << "Error: Car ID " << carId << " not available in inventory or out of stock." << endl;
            return false;
        }

        
        Customer *customer = findCustomer(customerId);
        if (!customer)
        {
            cout << "Error: Customer ID " << customerId << " not found." << endl;
            return false;
        }

        int salespersonId = 0; 
        if (isSalesperson()){
            salespersonId = currentUser->getUserId();
        }
        else if (isAdmin())
        {
            if (salespeople.getSize() > 0)
            {
                cout << "Available Salespeople:" << endl;
                for (int i = 0; i < salespeople.getSize(); i++)
                {
                    Salesperson *sp = salespeople.get(i);
                    if (sp){ 
                        cout << " Person ID: " << sp->getPersonId() << ", Name: " << sp->getName() << " (Enter User ID: " << sp->getUserId() << ")" << endl;
                    }
                }

                int inputSpUserId;
                cout << "Enter Salesperson's User ID to assign (0 for none): ";
                while (!(cin >> inputSpUserId))
                {
                    cout << "Invalid input. Please enter a numeric User ID (or 0): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                bool validId = false;
                if (inputSpUserId != 0)
                {
                    for (int i = 0; i < salespeople.getSize(); i++)
                    {
                        if (salespeople.get(i) && salespeople.get(i)->getUserId() == inputSpUserId)
                        {                                 
                            salespersonId = inputSpUserId; 
                            validId = true;
                            break;
                        }
                    }

                    if (!validId)
                    {
                        cout << "Invalid Salesperson User ID. Assigning no salesperson." << endl;
                        salespersonId = 0;
                    }
                }
                else
                {
                    salespersonId = 0; 
                }
            }
            else
            {
                cout << "No salespeople available to assign." << endl;
                salespersonId = 0;
            }
        }
       
        Sale *sale = new Sale(
            nextSaleId, carId, customerId, salespersonId, 
            Date(), car->getPrice(), paymentMethod);
        sales.add(sale);
        nextSaleId++; 

        inventory.updateCarQuantity(carId, -1);

        customer->incrementPurchaseCount();

        if (salespersonId > 0)
        {
            for (int i = 0; i < salespeople.getSize(); i++)
            {
                Salesperson *sp = salespeople.get(i);
                if (sp && sp->getUserId() == salespersonId){
                    sp->incrementSalesCount();
                    break;
                }
            }
        }

        double taxRate = 0.07;
        double discount = 0.0; 

        if (customer->getPurchaseCount() > 1)
        {                
            discount = 0.05; 
            cout << "Applying 5% repeat customer discount." << endl;
        }

        Invoice *invoice = new Invoice(nextInvoiceId, *sale, taxRate, discount);
        invoices.add(invoice);
        nextInvoiceId++;
        invoice->generateInvoice();

        string filename = "invoice_" + to_string(invoice->getId()) + ".txt";
        if (invoice->saveToFile(filename))
        {
            cout << "Invoice saved to " << filename << endl;
        }
        else
        {
            cout << "Warning: Failed to save invoice to file." << endl;
        }

        return true;
    }

    bool purchaseCar(int carId, const string &paymentMethod)
    { 
        if (!isCustomer())
        {
            cout << "Error: Only logged-in customers can use this function." << endl;
            return false;
        }

        int customerPersonId = 0;
        Customer *currentCustomer = dynamic_cast<Customer *>(currentUser);
        if (currentCustomer)
        {
            customerPersonId = currentCustomer->getPersonId();
        }
        else
        {
            cout << "Error: Could not retrieve customer profile information." << endl;
            return false;
        }

        return processSale(carId, customerPersonId, paymentMethod);
    }

    void displayInventory() const
    {
        inventory.displayAllCars();
    }

    void displayCarsByType(const string &type) const{
        inventory.displayCarsByType(type);
    }

    void displayAllCustomers() const
    {
        if (customers.getSize() == 0)
        {
            cout << "No customers registered." << endl;
            return;
        }

        cout << "======= CUSTOMERS =======" << endl;
        for (int i = 0; i < customers.getSize(); i++)
        {
            if (customers.get(i))
            { 
                customers.get(i)->display();
                cout << "------------------------" << endl;
            }
        }
    }

    bool displayAllSalespeople() const
    {
        if (!isAdmin())
        {
            cout << "Access Denied: Admin privileges required." << endl;
            return false;
        }

        if (salespeople.getSize() == 0)
        {
            cout << "No salespeople registered." << endl;
            return true; 
        }

        cout << "======= SALESPEOPLE =======" << endl;
        for (int i = 0; i < salespeople.getSize(); i++)
        {
            if (salespeople.get(i))
            {                                  
                salespeople.get(i)->display();
                cout << "------------------------" << endl;
            }
        }

        return true;
    }

    bool generateSalesReport() const
    {
        if (!isAdmin() && !isSalesperson())
        {
            cout << "Access Denied: Admin or Salesperson privileges required." << endl;
            return false;
        }

        if (sales.getSize() == 0)
        {
            cout << "No sales recorded yet." << endl;
            return true;
        }

        double totalRevenue = 0.0;

        cout << "\n======= SALES REPORT =======" << endl;
        cout << "Total Sales Transactions: " << sales.getSize() << endl;

        for (int i = 0; i < invoices.getSize(); i++)
        {
            if (invoices.get(i))
            { 
                totalRevenue += invoices.get(i)->getTotalAmount();
            }
        }

        cout << "Total Revenue (including tax/discounts): $" << fixed << setprecision(2) << totalRevenue << endl;
        cout << "------------------------" << endl;
        cout << "Sales Count by Car Type:" << endl;
        int sedanCount = 0, suvCount = 0, hatchbackCount = 0, unknownCount = 0;

        for (int i = 0; i < sales.getSize(); i++)
        {
            Sale *sale = sales.get(i);
            if (!sale)
                continue;

            Car *car = inventory.findCar(sale->getCarId());
            if (car)
            { 
                string typeLower = car->getType();
                for (char &c : typeLower)
                    c = tolower(c);

                if (typeLower == "sedan")
                {
                    sedanCount++;
                }
                else if (typeLower == "suv")
                {
                    suvCount++;
                }
                else if (typeLower == "hatchback")
                {
                    hatchbackCount++;
                }
                else
                {
                    unknownCount++;
                }
            }
            else
            {
                unknownCount++;
            }
        }

        cout << "  Sedan: " << sedanCount << endl;
        cout << "  SUV: " << suvCount << endl;
        cout << "  Hatchback: " << hatchbackCount << endl;
        if (unknownCount > 0)
        {
            cout << "  Unknown/Removed Car Type: " << unknownCount << endl;
        }
        cout << "------------------------" << endl;

        return true;
    }


    bool viewPurchaseHistory() const
    {
        if (!isCustomer())
        {
            cout << "Error: Only logged-in customers can view their purchase history." << endl;
            return false;
        }

        int customerPersonId = 0;
        Customer *currentCustomer = dynamic_cast<Customer *>(currentUser);
        if (currentCustomer)
        {
            customerPersonId = currentCustomer->getPersonId();
        }
        else
        {
            cout << "Error: Could not retrieve customer profile information." << endl;
            return false;
        }

        bool found = false;
        cout << "\n======= YOUR PURCHASE HISTORY =======" << endl;

        for (int i = 0; i < sales.getSize(); i++)
        {
            Sale *sale = sales.get(i);
            if (sale && sale->getCustomerId() == customerPersonId)
            {                                                  
                Car *car = inventory.findCar(sale->getCarId()); 
                Invoice *relatedInvoice = nullptr;
                for (int j = 0; j < invoices.getSize(); ++j)
                {
                    if (invoices.get(j) && invoices.get(j)->getSale().getId() == sale->getId())
                    {
                        relatedInvoice = invoices.get(j);
                        break;
                    }
                }

                cout << "Sale ID: " << sale->getId() << endl;
                cout << "Date: " << sale->getSaleDate().toString() << endl;
                if (car)
                {
                    cout << "Car: " << car->getBrand() << " " << car->getModel() << " (ID: " << car->getId() << ")" << endl;
                }
                else
                {
                    cout << "Car: (Details unavailable - Car ID: " << sale->getCarId() << ")" << endl;
                }
                cout << "Base Amount: $" << fixed << setprecision(2) << sale->getAmount() << endl;
                if (relatedInvoice)
                {
                    cout << "Total Paid (incl. Tax/Discount): $" << fixed << setprecision(2) << relatedInvoice->getTotalAmount() << endl;
                    cout << "Invoice ID: " << relatedInvoice->getId() << endl;
                }
                else
                {
                    cout << "Total Paid: (Invoice details unavailable)" << endl;
                }
                cout << "Payment Method: " << sale->getPaymentMethod() << endl;
                if (sale->getSalespersonId() != 0)
                {
                    string spName = "ID " + to_string(sale->getSalespersonId());
                    for (int k = 0; k < salespeople.getSize(); ++k)
                    {
                        if (salespeople.get(k) && salespeople.get(k)->getUserId() == sale->getSalespersonId())
                        {
                            spName = salespeople.get(k)->getName();
                            break;
                        }
                    }
                    cout << "Handled by Salesperson: " << spName << endl;
                }
                cout << "------------------------" << endl;
                found = true;
            }
        }

        if (!found)
        {
            cout << "You have no purchase history." << endl;
        }

        return true;
    }

    bool updateCustomerDetails(int personIdToUpdate){
        if (!isAdmin() && !isSalesperson()){
            cout << "Access Denied. Only Admin or Salesperson can update customer details." << endl;
            return false;
        }

        Customer *customer = findCustomer(personIdToUpdate);
        if (!customer)
        {
            cout << "Customer with Person ID " << personIdToUpdate << " not found." << endl;
            return false;
        }

        cout << "\n--- Updating Customer: " << customer->getName() << " (ID: " << customer->getPersonId() << ") ---" << endl;
        customer->display();
        cout << "------------------------------------" << endl;

        int fieldChoice;
        cout << "Which detail to update?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Phone" << endl;
        cout << "3. Email" << endl;
        cout << "4. Address" << endl;
        cout << "0. Cancel" << endl;
        cout << "Enter choice: ";
        while (!(cin >> fieldChoice) || fieldChoice < 0 || fieldChoice > 4)
        {
            cout << "Invalid choice. Please enter a number between 0 and 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string newValue;
        switch (fieldChoice)
        {
        case 1:
            cout << "Enter new Name: ";
            getline(cin, newValue);
            if (!newValue.empty())
                customer->setName(newValue);
            else
                cout << "Name not changed (input was empty)." << endl;
            break;
        case 2:
            cout << "Enter new Phone: ";
            getline(cin, newValue);
            if (!newValue.empty())
                customer->setPhone(newValue);
            else
                cout << "Phone not changed (input was empty)." << endl;
            break;
        case 3:
            cout << "Enter new Email: ";
            getline(cin, newValue);
            if (!newValue.empty())
            {
                bool emailTaken = false;
                for (int i = 0; i < admins.getSize(); ++i)
                    if (admins.get(i)->getEmail() == newValue && admins.get(i)->getPersonId() != customer->getPersonId())
                        emailTaken = true;
                if (!emailTaken)
                    for (int i = 0; i < salespeople.getSize(); ++i)
                        if (salespeople.get(i)->getEmail() == newValue && salespeople.get(i)->getPersonId() != customer->getPersonId())
                            emailTaken = true;
                if (!emailTaken)
                    for (int i = 0; i < customers.getSize(); ++i)
                        if (customers.get(i)->getEmail() == newValue && customers.get(i)->getPersonId() != customer->getPersonId())
                            emailTaken = true;

                if (emailTaken)
                {
                    cout << "Error: This email is already in use by another account. Email not updated." << endl;
                }
                else
                {
                    customer->setEmail(newValue);
                }
            }
            else
                cout << "Email not changed (input was empty)." << endl;
            break;
        case 4:
            cout << "Enter new Address: ";
            getline(cin, newValue);
            if (!newValue.empty())
                customer->setAddress(newValue);
            else
                cout << "Address not changed (input was empty)." << endl;
            break;
        case 0:
            cout << "Update cancelled." << endl;
            return false;
        default:
            cout << "Invalid choice. No update performed." << endl;
            return false;
        }
        cout << "Customer details updated successfully." << endl;
        return true;
    }

    // Save all data to files
    bool saveData()
    {
        cout << "Attempting to save data..." << endl;
        bool success = true;
        string errorLog = "";

        if (!FileHandler::saveAdmins(admins, "admins.dat"))
        {
            success = false;
            errorLog += " admins.dat";
        }
        if (!FileHandler::saveSalespeople(salespeople, "salespeople.dat"))
        {
            success = false;
            errorLog += " salespeople.dat";
        }
        if (!FileHandler::saveCustomers(customers, "customers.dat"))
        {
            success = false;
            errorLog += " customers.dat";
        }
        if (!FileHandler::saveSales(sales, "sales.dat"))
        {
            success = false;
            errorLog += " sales.dat";
        }
        if (!FileHandler::saveInvoices(invoices, "invoices.dat"))
        {
            success = false;
            errorLog += " invoices.dat";
        }
        if (!FileHandler::saveCars(inventory, "cars.dat"))
        {
            success = false;
            errorLog += " cars.dat(simplified)";
        }

        if (success)
        {
            cout << "Data saved successfully." << endl;
        }
        else
        {
            cout << "Warning: Failed to save some data. Errors occurred with:" << errorLog << endl;
        }
        return success;
    }

    // Load all data from files
    bool loadData()
    {
        cout << "Attempting to load data..." << endl;
        bool overallSuccess = true;
        bool adminsLoaded = FileHandler::loadAdmins(admins, "admins.dat");
        bool salespeopleLoaded = FileHandler::loadSalespeople(salespeople, "salespeople.dat");
        bool customersLoaded = FileHandler::loadCustomers(customers, "customers.dat");
        bool salesLoaded = FileHandler::loadSales(sales, "sales.dat");
        bool invoicesLoaded = FileHandler::loadInvoices(invoices, sales, "invoices.dat");
        bool carsLoaded = FileHandler::loadCars(inventory, "cars.dat"); 

        // Report loaded counts
        cout << "Loaded Admins: " << admins.getSize() << endl;
        cout << "Loaded Salespeople: " << salespeople.getSize() << endl;
        cout << "Loaded Customers: " << customers.getSize() << endl;
        cout << "Loaded Sales: " << sales.getSize() << endl;
        cout << "Loaded Invoices: " << invoices.getSize() << endl;
        if (carsLoaded)
            cout << "Car data file processed (simplified load)." << endl;

        overallSuccess = adminsLoaded || salespeopleLoaded || customersLoaded || salesLoaded || invoicesLoaded || carsLoaded;
        return overallSuccess;
    }
    Inventory &getInventory() { return inventory; }
};

void getPasswordInput(string &password){      
    password = ""; 
    int ch;
    while (true)
    {
        ch = getch();
        if (ch == 13 || ch == 10)
        {             
            cout << endl;
            break;
        }
        else if (ch == 8){ 
            if (!password.empty())
            {
                password.pop_back(); 
                cout << "\b \b";    
            }
        }
        else if (ch >= 32 && ch <= 126)
        {                                           
            password.push_back(static_cast<char>(ch)); 
            cout << "*";                              
        }
            }
}

int main()
{
    Showroom showroom("Luxury Auto Showroom", "123 Main Street, City", "555-1234-5678");

    int choice = -1; 
    
    bool loggedIn = false;

    do
    {
        if (!loggedIn)
        {
            cout << "\n===== CAR SHOWROOM MANAGEMENT SYSTEM =====" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register New Account" << endl; 
            cout << "0. Exit" << endl;                
            cout << "Enter your choice: ";
            while (!(cin >> choice))
            {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            switch (choice)
            {
            case 1:
            {
                string username, pass;
                cout << "Enter username: ";
                getline(cin, username); 
                cout << "Enter password: ";
                getPasswordInput(pass); 

                if (showroom.login(username, pass))
                {
                    loggedIn = true;
                    User *user = showroom.getCurrentUser();
                    if (user)
                    {
                        cout << "Login successful. Welcome, " << user->getUsername()
                             << " (" << user->getRole() << ")" << endl;
                    }
                    else
                    {
                        cout << "Login reported success but user object is null. Internal error." << endl;
                        loggedIn = false;
                    }
                }
                else
                {
                    cout << "Invalid username or password." << endl;
                }
                break;
            }
            case 2:
            { // *** MODIFIED REGISTRATION PROCESS ***
                string name, phone, email, address, username, password, confirmPassword;
                int roleChoice;
                string roleToRegister;
                double commissionRate = 0.0;

                cout << "\n===== ACCOUNT REGISTRATION =====" << endl;
                cout << "Select role to register as:" << endl;
                cout << "1. Customer" << endl;
                cout << "2. Salesperson" << endl;
                cout << "3. Admin" << endl;
                cout << "Enter choice: ";
                while (!(cin >> roleChoice) || roleChoice < 1 || roleChoice > 3)
                {
                    cout << "Invalid choice. Please enter 1, 2, or 3: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter your details:" << endl;
                cout << "Name: ";
                getline(cin, name);
                cout << "Phone: ";
                getline(cin, phone);
                cout << "Email: ";
                getline(cin, email);

                if (roleChoice == 1)
                {
                    roleToRegister = "Customer";
                    cout << "Address: ";
                    getline(cin, address);
                }
                else if (roleChoice == 2)
                {
                    roleToRegister = "Salesperson";
                    address = "N/A"; 
                    cout << "Commission Rate (e.g., 0.05 for 5%): ";
                    while (!(cin >> commissionRate) || commissionRate < 0 || commissionRate > 1)
                    {
                        cout << "Invalid rate. Enter value between 0.0 and 1.0: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    roleToRegister = "Admin";
                    address = "N/A"; 
                }

                cout << "Desired Username: ";
                getline(cin, username);
                cout << "Password: ";
                getPasswordInput(password);
                cout << "Confirm Password: ";
                getPasswordInput(confirmPassword);

                if (password != confirmPassword)
                {
                    cout << "Passwords do not match. Registration failed." << endl;
                }
                else if (username.empty() || password.empty() || name.empty() || email.empty())
                {
                    cout << "All fields (Name, Email, Username, Password) are required. Registration failed." << endl;
                }
                else
                {
                    if (showroom.registerUser(name, phone, email, address, username, password, roleToRegister, commissionRate))
                    {
                        cout << "Registration successful as " << roleToRegister << ". You can now login." << endl;
                    }
                    else
                    {
                        cout << "Error" << endl;
                    }
                }
                break;
            }
            case 0: 
                cout << "Exiting system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        else
        { 
            bool isAdmin = showroom.isAdmin();
            bool isSalesperson = showroom.isSalesperson();
            bool isCustomer = showroom.isCustomer();

            cout << "\n===== MAIN MENU (" << showroom.getCurrentUser()->getRole() << ") =====" << endl;

           
            cout << "1. View Full Inventory" << endl;
            cout << "2. View Cars by Type" << endl;

            int currentOption = 3;                                                                                             // Start numbering from 3
            int viewCustomersOpt = -1, findCustomerOpt = -1, processSaleOpt = -1, salesReportOpt = -1, updateCustomerOpt = -1; // Added updateCustomerOpt
            if (isAdmin || isSalesperson)
            {
                viewCustomersOpt = currentOption++;
                cout << viewCustomersOpt << ". View All Customers" << endl;
                findCustomerOpt = currentOption++;
                cout << findCustomerOpt << ". Find Customer (by ID or Name)" << endl;
                updateCustomerOpt = currentOption++; 
                cout << updateCustomerOpt << ". Update Customer Details" << endl;
                processSaleOpt = currentOption++;
                cout << processSaleOpt << ". Process New Sale" << endl;
                salesReportOpt = currentOption++;
                cout << salesReportOpt << ". Generate Sales Report" << endl;
            }

            int addCarOpt = -1, addSPOpt = -1, addAdminOpt = -1, viewSPOpt = -1;
            if (isAdmin)
            {
                addCarOpt = currentOption++;
                cout << addCarOpt << ". Add New Car to Inventory" << endl;
                addSPOpt = currentOption++;
                cout << addSPOpt << ". Add New Salesperson" << endl;
                addAdminOpt = currentOption++;
                cout << addAdminOpt << ". Add New Admin" << endl;
                viewSPOpt = currentOption++;
                cout << viewSPOpt << ". View All Salespeople" << endl;
            }

            int viewProfileOpt = -1, purchaseCarOpt = -1, viewHistoryOpt = -1;
            if (isCustomer)
            {
                viewProfileOpt = currentOption++;
                cout << viewProfileOpt << ". View My Profile" << endl;
                purchaseCarOpt = currentOption++;
                cout << purchaseCarOpt << ". Purchase a Car" << endl;
                viewHistoryOpt = currentOption++;
                cout << viewHistoryOpt << ". View My Purchase History" << endl;
            }
            cout << "99. Logout" << endl;     
            cout << "0. Save & Exit" << endl; 
            cout << "Enter your choice: ";
            while (!(cin >> choice))
            {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

         
            if (choice == 1)
            { 
                showroom.displayInventory();
            }
            else if (choice == 2)
            { 
                int typeChoice;
                cout << "Select car type:" << endl;
                cout << "1. Sedan" << endl;
                cout << "2. SUV" << endl;
                cout << "3. Hatchback" << endl;
                cout << "Enter choice: ";
                while (!(cin >> typeChoice) || typeChoice < 1 || typeChoice > 3)
                {
                    cout << "Invalid input. Please enter 1, 2, or 3: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                switch (typeChoice)
                {
                case 1:
                    showroom.displayCarsByType("Sedan");
                    break;
                case 2:
                    showroom.displayCarsByType("SUV");
                    break;
                case 3:
                    showroom.displayCarsByType("Hatchback");
                    break;
                }
            }
            else if ((isAdmin || isSalesperson) && choice == viewCustomersOpt)
            {
                showroom.displayAllCustomers();
            }
            else if ((isAdmin || isSalesperson) && choice == findCustomerOpt)
            {
                int searchChoice;
                cout << "Search customer by:" << endl;
                cout << "1. Person ID" << endl;
                cout << "2. Name (partial match)" << endl;
                cout << "Enter choice: ";
                while (!(cin >> searchChoice) || (searchChoice != 1 && searchChoice != 2))
                {
                    cout << "Invalid input. Please enter 1 or 2: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (searchChoice == 1)
                {
                    int id;
                    cout << "Enter customer Person ID: ";
                    while (!(cin >> id))
                    {
                        cout << "Invalid input. Please enter a numeric ID: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    Customer *customer = showroom.findCustomer(id);
                    if (customer)
                    {
                        customer->display();
                    }
                    else
                    {
                        cout << "Customer with Person ID " << id << " not found." << endl;
                    }
                }
                else if (searchChoice == 2)
                {
                    string name;
                    cout << "Enter customer name (or part of name): ";
                    getline(cin, name);
                    showroom.findCustomersByName(name);
                }
            }
            else if ((isAdmin || isSalesperson) && choice == updateCustomerOpt)
            { 
                int customerIdToUpdate;
                cout << "Enter Person ID of the customer to update: ";
                while (!(cin >> customerIdToUpdate))
                {
                    cout << "Invalid input. Please enter a numeric Person ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                showroom.updateCustomerDetails(customerIdToUpdate);
            }
            else if ((isAdmin || isSalesperson) && choice == processSaleOpt)
            {
                int carId, customerId;
                string paymentMethod;
                int existingCustomerChoice;

                showroom.displayInventory();
                cout << "Enter Car ID for sale: ";
                while (!(cin >> carId))
                {
                    cout << "Invalid input. Please enter a numeric Car ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Is this an existing customer? (1: Yes, 0: No): ";
                while (!(cin >> existingCustomerChoice) || (existingCustomerChoice != 0 && existingCustomerChoice != 1))
                {
                    cout << "Invalid input. Please enter 1 for Yes or 0 for No: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (existingCustomerChoice == 1)
                {
                    cout << "Enter customer Person ID: ";
                    while (!(cin >> customerId))
                    {
                        cout << "Invalid input. Please enter a numeric Person ID: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!showroom.findCustomer(customerId))
                    {
                        cout << "Error: Customer with Person ID " << customerId << " not found. Sale cancelled." << endl;
                        continue; 
                    }
                }
                else
                {
                    string custName, custPhone, custEmail, custAddress;
                    cout << "Enter NEW customer details:" << endl;
                    cout << "Name: ";
                    getline(cin, custName);
                    cout << "Phone: ";
                    getline(cin, custPhone);
                    cout << "Email: ";
                    getline(cin, custEmail);
                    cout << "Address: ";
                    getline(cin, custAddress);

                    if (custName.empty() || custEmail.empty())
                    {
                        cout << "Error: Name and Email are required for new customers. Sale cancelled." << endl;
                        continue;
                    }
                    customerId = showroom.addCustomer(custName, custPhone, custEmail, custAddress);
                    if (customerId == -1)
                    {
                        cout << "Failed to add new customer (check email uniqueness). Sale cancelled." << endl;
                        continue;
                    }
                    cout << "New customer added with Person ID: " << customerId << endl;
                }

                cout << "Enter payment method (e.g., Cash, Card, Finance): ";
                getline(cin, paymentMethod);

                if (showroom.processSale(carId, customerId, paymentMethod))
                {
                    cout << "Sale processed successfully." << endl;
                }
                else
                {
                    cout << "Failed to process sale." << endl;
                }
            }
            else if ((isAdmin || isSalesperson) && choice == salesReportOpt)
            {
                showroom.generateSalesReport();
            }
            else if (isAdmin && choice == addCarOpt)
            {
                int carTypeChoice, year, quantity, doors, seatingCapacity, horsepower, topSpeed;
                double price, zeroToSixty;
                string model, brand, transmission, fuelType, driveType, colors, description;
                int fwdInput, sunroofInput;
                bool fourWheelDrive = false, hasSunroof = false;

                cout << "Enter car type:" << endl;
                cout << "1. Sedan" << endl;
                cout << "2. SUV" << endl;
                cout << "3. Hatchback" << endl;
                cout << "Enter choice: ";
                while (!(cin >> carTypeChoice) || carTypeChoice < 1 || carTypeChoice > 3)
                {
                    cout << "Invalid input. Please enter 1, 2, or 3: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter model: ";
                getline(cin, model);
                cout << "Enter brand: ";
                getline(cin, brand);
                cout << "Enter year: ";
                while (!(cin >> year))
                {
                    cout << "Invalid year. Enter numeric value: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter price: $";
                while (!(cin >> price) || price < 0)
                {
                    cout << "Invalid price. Enter positive numeric value: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter initial quantity: ";
                while (!(cin >> quantity) || quantity < 0)
                {
                    cout << "Invalid quantity. Enter non-negative numeric value: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter horsepower: ";
                while (!(cin >> horsepower) || horsepower < 0)
                {
                    cout << "Invalid horsepower. Enter positive numeric value: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter 0-60 mph time (seconds): ";
                while (!(cin >> zeroToSixty) || zeroToSixty < 0)
                {
                    cout << "Invalid time. Enter positive numeric value: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter top speed (mph): ";
                while (!(cin >> topSpeed) || topSpeed < 0)
                {
                    cout << "Invalid speed. Enter positive numeric value: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter drive type (e.g., 'AWD', 'FWD', 'RWD'): ";
                getline(cin, driveType);
                cout << "Enter available colors (comma separated): ";
                getline(cin, colors);
                cout << "Enter description (optional): ";
                getline(cin, description);

                Car *newCar = nullptr;
                switch (carTypeChoice)
                {
                case 1: 
                    cout << "Enter number of doors: ";
                    while (!(cin >> doors) || doors < 1)
                    {
                        cout << "Invalid doors. Enter positive numeric value: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter transmission type (e.g., 'Automatic', 'Manual'): ";
                    getline(cin, transmission);
                    newCar = new Sedan(0, model, brand, year, price, quantity, doors, transmission,
                                       horsepower, zeroToSixty, topSpeed, driveType, colors, description);
                    break;
                case 2:
                    cout << "Has four wheel drive? (1: Yes, 0: No): ";
                    while (!(cin >> fwdInput) || (fwdInput != 0 && fwdInput != 1))
                    {
                        cout << "Invalid input. Enter 1 or 0: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    fourWheelDrive = (fwdInput == 1);
                    cout << "Enter seating capacity: ";
                    while (!(cin >> seatingCapacity) || seatingCapacity < 1)
                    {
                        cout << "Invalid capacity. Enter positive numeric value: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    newCar = new SUV(0, model, brand, year, price, quantity, fourWheelDrive, seatingCapacity,
                                     horsepower, zeroToSixty, topSpeed, driveType, colors, description);
                    break;
                case 3: 
                    cout << "Has sunroof? (1: Yes, 0: No): ";
                    while (!(cin >> sunroofInput) || (sunroofInput != 0 && sunroofInput != 1))
                    {
                        cout << "Invalid input. Enter 1 or 0: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    hasSunroof = (sunroofInput == 1);
                    cout << "Enter fuel type (e.g., 'Gasoline', 'Hybrid', 'Electric'): ";
                    getline(cin, fuelType);
                    newCar = new Hatchback(0, model, brand, year, price, quantity, hasSunroof, fuelType,
                                           horsepower, zeroToSixty, topSpeed, driveType, colors, description);
                    break;
                }

                if (newCar)
                {
                    if (showroom.addCar(newCar))
                    {
                        cout << "Car added to inventory successfully." << endl;
                    }
                    else
                    {
                        cout << "Failed to add car." << endl;
                        delete newCar;
                    }
                }
                else
                {
                    cout << "Car creation failed (invalid type?)." << endl;
                }
            }
            else if (isAdmin && choice == addSPOpt)
            {
                string spName, spPhone, spEmail, spUsername, spPassword, spConfirmPass;
                double spCommission;

                cout << "Enter NEW Salesperson details:" << endl;
                cout << "Name: ";
                getline(cin, spName);
                cout << "Phone: ";
                getline(cin, spPhone);
                cout << "Email: ";
                getline(cin, spEmail);
                cout << "Desired Username: ";
                getline(cin, spUsername);
                cout << "Password: ";
                getPasswordInput(spPassword);
                cout << "Confirm Password: ";
                getPasswordInput(spConfirmPass);
                cout << "Commission rate (e.g., 0.05 for 5%): ";
                while (!(cin >> spCommission) || spCommission < 0 || spCommission > 1)
                {
                    cout << "Invalid rate. Enter value between 0.0 and 1.0: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (spPassword != spConfirmPass)
                {
                    cout << "Passwords do not match. Salesperson not added." << endl;
                }
                else if (spUsername.empty() || spPassword.empty() || spName.empty() || spEmail.empty())
                {
                    cout << "All fields (Name, Email, Username, Password) are required. Salesperson not added." << endl;
                }
                else
                {
                    if (showroom.addSalesperson(spName, spPhone, spEmail, spUsername, spPassword, spCommission))
                    {
                        cout << "Salesperson added successfully." << endl;
                    }
                    else
                    {
                        cout << "Error" << endl;
                     }
                }
            }
            else if (isAdmin && choice == addAdminOpt)
            {
                string adName, adPhone, adEmail, adUsername, adPassword, adConfirmPass;

                cout << "Enter NEW Admin details:" << endl;
                cout << "Name: ";
                getline(cin, adName);
                cout << "Phone: ";
                getline(cin, adPhone);
                cout << "Email: ";
                getline(cin, adEmail);
                cout << "Desired Username: ";
                getline(cin, adUsername);
                cout << "Password: ";
                getPasswordInput(adPassword);
                cout << "Confirm Password: ";
                getPasswordInput(adConfirmPass);

                if (adPassword != adConfirmPass)
                {
                    cout << "Passwords do not match. Admin not added." << endl;
                }
                else if (adUsername.empty() || adPassword.empty() || adName.empty() || adEmail.empty())
                {
                    cout << "All fields (Name, Email, Username, Password) are required. Admin not added." << endl;
                }
                else
                {
                    if (showroom.addAdmin(adName, adPhone, adEmail, adUsername, adPassword))
                    {
                        cout << "Admin added successfully." << endl;
                    }
                    else
                    {
                        cout << "Error" << endl;
                    }
                }
            }
            else if (isAdmin && choice == viewSPOpt)
            {
                showroom.displayAllSalespeople();
            }
            else if (isCustomer && choice == viewProfileOpt)
            {
                showroom.getCurrentUser()->displayUser();
                Customer *custProfile = dynamic_cast<Customer *>(showroom.getCurrentUser());
                if (custProfile)
                {
                    cout << "--- Full Profile ---" << endl;
                    custProfile->display();
                }
            }
            else if (isCustomer && choice == purchaseCarOpt)
            {
                int carIdToPurchase;
                string paymentMethodPurchase;

                showroom.displayInventory();
                cout << "Enter the ID of the car you wish to purchase: ";
                while (!(cin >> carIdToPurchase))
                {
                    cout << "Invalid input. Please enter a numeric Car ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Car *carToBuy = showroom.getInventory().findCar(carIdToPurchase);
                if (!carToBuy || carToBuy->getQuantity() <= 0)
                {
                    cout << "Error: Car ID " << carIdToPurchase << " is not available or does not exist." << endl;
                    continue; 
                }

                cout << "Enter payment method (e.g., Cash, Card, Finance): ";
                getline(cin, paymentMethodPurchase);

                if (showroom.purchaseCar(carIdToPurchase, paymentMethodPurchase))
                {
                    cout << "Car purchase successful! Invoice generated." << endl;
                }
                else
                {
                    cout << "Car purchase failed." << endl;
                }
            }
            else if (isCustomer && choice == viewHistoryOpt)
            {
                showroom.viewPurchaseHistory();
            }
            else if (choice == 99)
            { 
                showroom.logout();
                loggedIn = false;
                cout << "Logged out successfully." << endl;
            }
            else if (choice == 0)
            { 
                cout << "Saving data and exiting system." << endl;
                break; 
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }

        } 

        if (choice != 0)
        {
            cout << "\nPress Enter to continue...";
            cin.get();
        }

    } while (choice != 0); 

    return 0;
}
