#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


node* insertGcd(node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    node* curr = head;

    while (curr != nullptr && curr->next != nullptr) {
        int g = gcd(curr->data, curr->next->data);

        node* gcdNode = new node(g);

        gcdNode->next = curr->next;
        curr->next = gcdNode;

        curr = gcdNode->next;
    }

    return head;
}

// Helper to print the list
void printList(node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Sample usage
int main() {
    // Create the list: 18 -> 6 -> 10 -> 3
    node* head = new node(18);
    head->next = new node(6);
    head->next->next = new node(10);
    head->next->next->next = new node(3);

    // Modify the list
    head = insertGcd(head);

    // Output: 18->6->6->2->10->1->3
    printList(head);

    return 0;
}
