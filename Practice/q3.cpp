#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void removeCycle(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (slow != fast)
        return;
    slow = head;
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = nullptr;
        return;
    }

    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr;
}

void printReverse(Node* head) {
    if (head == nullptr) {
        cout << "NULL";
        return;
    }
    printReverse(head->next);
    cout << "->" << head->data;
}

void createCycle(Node* head, int pos) {
    Node* temp = head;
    Node* cycleStart = nullptr;
    int count = 1;

    while (temp->next != nullptr) {
        if (count == pos)
            cycleStart = temp;
        temp = temp->next;
        count++;
    }
    temp->next = cycleStart;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    createCycle(head, 2);
    removeCycle(head);
    printReverse(head);
    cout << endl;

    return 0;
}
