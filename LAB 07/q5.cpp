#include <iostream>
using namespace std;

class Media{
    protected:
    string title;
    int publicationDate;
    string uniqueID;
    string publisher;
    bool available;
    public:
    Media(string t,int date,string id,string publish) : available(true){
        this->publicationDate = date;
        this->publisher = publish;
        this->uniqueID = id;
        this->title = t;
    }

    string gettitle() const {return title;}
    int getpublicationyear() const { return publicationDate;}
    virtual void displayInfo(){
        cout << "Tilte: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    void checkOut(){
         if (available){
            available = false;
            cout << "Item Checked out successfully." << endl;
        }
        else
            cout << "Item is already checked out." << endl;
    }

    void returnItem(){
        if(available){
            cout << "Item is already retrun." << endl;
        }
        else{
            available = true;
            cout << "Item isnot returned." << endl;
        }
    }

};

class Book : public Media{
    string author;
    string ISBN;
    int num_pages;
    public:
    Book(string author,string isbn , int num ,string t,int date,string id,string publish) : Media(t,date,id,publish) {
        this->author = author;
        this->ISBN = isbn;
        this->num_pages = num;
    }

    void displayInfo() override{
        Media::displayInfo();
        cout <<" Author: " << author << endl;
        cout << "ISBN: " << ISBN <<  endl;
        cout << "Number of Pages: " << num_pages;
    }

    string getauthor() const {return author;}
};
class DVD : public Media{
    string director;
    float duration;
    float rating;
    public:
    DVD(string d,float dur, float r,string t,int date,string id,string publish) : Media(t,date,id,publish){
        this->rating = r;
        this->director = d;
        this->duration = dur;
    }

    void displayInfo() override{
        Media ::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << endl;
        cout << "Rating: " << rating << endl;
       }
};
class CD : public Media{
    string artist;
    int numberofTracks;
    string genre;
    public:
    CD(string art , int tracks, string genre ,string t,int date,string id,string publish) : Media(t,date,id,publish){
        this->artist = art;
        this->numberofTracks = tracks;
        this->genre = genre;
    }


};
class Magazine : public Media{
     int issueNumber;
     public:
     Magazine(int num , string t,int date,string id,string publish) : Media(t,date,id,publish){
        this->issueNumber = num;
     }

     void displayInfo() override{
        Media :: displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
     }
};

void searchMedia(Book** booklist , int size , string author){
    for(int i = 0 ; i < size ; i++){
        if(booklist[i]->getauthor() == author){
            cout << "Book Found!! " << endl;
            booklist[i]->displayInfo();
            return;
        }
    }
     cout << "Book not found." << endl; 
}

void serachMedia(Media** medialist , int size , string title){
    for(int i = 0 ; i < size ; i++){
        if(medialist[i]->gettitle() == title){
            cout << "Media Found!!" << endl;
            medialist[i]->displayInfo();
            return;
        }
    }
    cout << "Media not found" << endl;
}

void searchMedia(Media **mediaList, int size, int year)
{
    for (int i = 0; i < size; i++)
    {
        if (mediaList[i]->getpublicationyear() == year)
        {
            cout << "Book Found!" << endl;
            mediaList[i]->displayInfo();
            return;
        }
    }
    cout << "No Media found of year: " << year << endl;
}

#include <iostream>
using namespace std;

int main() {
    Book book1("J.K. Rowling", "9780747532743", 223, "Harry Potter", 1997, "B001", "Bloomsbury");
    Book book2("George Orwell", "9780451524935", 328, "1984", 1949, "B002", "Secker & Warburg");

    DVD dvd1("Steven Spielberg", 120.5, 8.7, "Jurassic Park", 1993, "D001", "Universal Pictures");

    CD cd1("Taylor Swift", 13, "Pop", "1989", 2014, "C001", "Big Machine Records");

    Magazine mag1(45, "National Geographic", 2021, "M001", "NatGeo");

    Book* bookList[] = { &book1, &book2 };
    Media* mediaList[] = { &book1, &book2, &dvd1, &cd1, &mag1 };

    int bookSize = sizeof(bookList) / sizeof(bookList[0]);
    int mediaSize = sizeof(mediaList) / sizeof(mediaList[0]);

    cout << "\n--- Displaying All Media ---\n";
    for (int i = 0; i < mediaSize; i++) {
        mediaList[i]->displayInfo();
        cout << "\n";
    }

    cout << "\n--- Searching for a Book by Author ---\n";
    searchMedia(bookList, bookSize, "J.K. Rowling");

    cout << "\n--- Searching for Media by Title ---\n";
    serachMedia(mediaList, mediaSize, "1989");

    cout << "\n--- Searching for Media by Year ---\n";
    searchMedia(mediaList, mediaSize, 1997);
    
    cout << "\n--- Checking Out and Returning Media ---\n";
    book1.checkOut();  
    book1.checkOut();   
    book1.returnItem();
    book1.returnItem();

    return 0;
}
