#include <iostream>
#include <string>
using namespace std;

class books {
private:
    int ID;
    string title;
    string author;
    bool availability;

public:
    // Default constructor
    books() : ID(0), title(""), author(""), availability(true) {}

    // Parameterized constructor to initialize book details and availability
    books(int ID, string title, string author, bool availability) {
        this->ID = ID;
        this->title = title;
        this->author = author;
        this->availability = availability;
    }

    // Getter methods
    int getID() { return ID; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool isAvailable() { return availability; }

    void setAvailability(bool status) { availability = status; }

    void displayBook() {
        cout << "ID: " << ID << ", Title: " << title << ", Author: " << author;
        cout << ", Available: " << (availability ? "Yes" : "No") << endl;
    }
};

class library {
private:
    books* book;
    int bookCount; 

public:
    library() : book(nullptr), bookCount(0) {}

    void addBook(int ID, string title, string author, bool availability) {
        books* tempBook = new books[bookCount + 1];
        
        for (int i = 0; i < bookCount; i++) {
            tempBook[i] = book[i];
        }

        tempBook[bookCount] = books(ID, title, author, availability);

      
        delete[] book;
        book = tempBook;
        bookCount++;
    }

    void borrowBook(int ID) {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (book[i].getID() == ID && book[i].isAvailable()) {
                book[i].setAvailability(false);
                cout << "You have borrowed: " << book[i].getTitle() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not available for borrowing!" << endl;
        }
    }

    void returnBook(int ID) {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (book[i].getID() == ID && !book[i].isAvailable()) {
                book[i].setAvailability(true);
                cout << "You have returned: " << book[i].getTitle() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found or it wasn't borrowed!" << endl;
        }
    }

    void displayAvailableBooks() {
        bool found = false;
        cout << "Available Books:" << endl;
        for (int i = 0; i < bookCount; i++) {
            if (book[i].isAvailable()) {
                book[i].displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "No available books at the moment." << endl;
        }
    }

    ~library() {
        delete[] book;
    }
};

int main() {
    library lib;

    cout << "How many books would you like to enter?" << endl;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int ID;
        string title, author;
        bool availability = true; // All books are available initially

        cout << "Enter ID for book " << i + 1 << ": ";
        cin >> ID;
        cout << "Enter title for book " << i + 1 << ": ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author for book " << i + 1 << ": ";
        getline(cin, author);

        lib.addBook(ID, title, author, availability);
    }

    // Display available books
    lib.displayAvailableBooks();

    // Borrow a book
    int borrowID;
    cout << "Enter ID of the book you want to borrow: ";
    cin >> borrowID;
    lib.borrowBook(borrowID);

    // Return a book
    int returnID;
    cout << "Enter ID of the book you want to return: ";
    cin >> returnID;
    lib.returnBook(returnID);

    lib.displayAvailableBooks();

    return 0;
}
