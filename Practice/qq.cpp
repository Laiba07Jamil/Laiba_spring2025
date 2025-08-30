#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node() : data(0) , next(nullptr) {}
    Node(int val) : data(val) , next(nullptr) {}
};

class Circular{
    public:
    Node* head;

    Circular() : head(nullptr) {}

    void InsertatTail(int data){
        if(head == nullptr){      
            Node* newnode = new Node(data); 
            head = newnode;
            newnode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        Node* newnode = new Node(data);
        temp->next = newnode;
        newnode->next = head;
    }

    void printList(){
    if (head == nullptr) return;

    Node* temp = head;
    while (true) {
        cout << temp->data << " -> ";
        temp = temp->next;
        if (temp == head) break;
    }
    cout << "HEAD\n";
}

void deleteDUplicate(){
    if(!head || head->next == head) return;

    Node* temp = head;
    while(temp->next != head){
        if(temp->data == temp->next->data){
            Node* curr = temp->next;
            temp->next = curr->next;
            delete curr;
        }
        else{
            temp = temp->next;
        }
    }
}

void InsertAthead(int data){
    if(!head){
        Node* newnode = new Node(data);
        head = newnode;
        newnode->next = head;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    Node* newnode = new Node(data);    // 1 -> 2 -> 3 -> 4 -> HEAD(1)
    temp -> next = newnode;
    newnode->next = head;
    head = newnode; 
}

void deleteAtTail(){
    if(!head || head->next == head) {
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    Node *curr = temp->next;
    temp->next = head;
    delete curr;
}





};
int main(){
    Circular c1;
    c1.InsertatTail(1);
    c1.InsertatTail(2);
    c1.InsertatTail(3);
    c1.InsertatTail(4);
    c1.InsertatTail(5);
    c1.InsertatTail(6);
    c1.deleteAtTail();
    c1.printList();
}
