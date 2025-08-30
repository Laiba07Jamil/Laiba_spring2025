#include <iostream>
using namespace std;

class Node {
public:
    int ticketNo;
    Node* next;

    Node(int val) {
        ticketNo = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Add to rear
    void enqueue(int ticketNo) {
        Node* newNode = new Node(ticketNo);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Ticket " << ticketNo << " added to the queue.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. No ticket to remove.\n";
            return;
        }

        Node* temp = front;
        cout << "Removing ticket " << front->ticketNo << " from the queue.\n";
        front = front->next;
        delete temp;

        if (front == nullptr) rear = nullptr;
    }

    int pop() {
        if (front == nullptr) {
            return -1;
        }

        int val = front->ticketNo;
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) rear = nullptr;

        return val;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Tickets in queue: ";
        while (temp != nullptr) {
            cout << temp->ticketNo << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);

    q.display();

    q.dequeue();
    q.display();

    int ticket = q.pop();
    cout << "Popped ticket: " << ticket << endl;

    q.display();

    return 0;
}
