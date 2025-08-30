#include <iostream>
using namespace std;

class Node{
    public:
    string name;
    int rollnum;
    Node* next;
    Node* prev;

    Node(int roll , string n) :prev(nullptr), next(nullptr){
        name = n ;
        rollnum = roll;
    }
};

class DoublyLinkedList{
    public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    void sortedDoublyLinkedList(int roll , string name){
        Node* newnode = new Node(roll , name);
        if(head == nullptr){
            head = newnode;
            return;
        }

        if(roll < head->rollnum){
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr &&  temp->next->rollnum < roll){
            temp = temp->next;
        }
        
        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newnode;

        temp->next = newnode;
    }

    void display(){
        Node*temp = head;
        while(temp != nullptr){
            cout << "[" << temp->name << "," << temp->rollnum << "] ->" ;
            temp = temp->next ;  
        }
    }

};

int main(){
    DoublyLinkedList d1;
    d1.sortedDoublyLinkedList(7 , "Hadi");       //[Hani,7]->[Hadi,663]->[Kirsh,820]->[Mustafa,5545]
    d1.sortedDoublyLinkedList(663 ,"Laiba");
    d1.sortedDoublyLinkedList(820 , "Krish");
    d1.sortedDoublyLinkedList(5545 , "Mustafa");

    d1.display();
}