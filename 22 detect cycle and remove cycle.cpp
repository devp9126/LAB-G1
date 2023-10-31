#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) : data(data), next(nullptr) {}
    ~node() {
        // Destructor to release memory recursively for the linked list
        if (next != nullptr) {
            delete next;
        }
    }
};

bool hasCycle(node* head) {
    if (head == nullptr) return false;

    node* fast = head;
    node* slow = head;
    while (fast && fast->next) {
        if (fast == slow) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

void removeCycle(node* head) {
    node* slow = head;
    node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            break;
        }
    }

    if (fast == slow) {
        // Cycle detected, find the start of the cycle
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Break the cycle
        fast->next = nullptr;
    }
}

void print(node* head) {
    // Print the elements of the linked list
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with a cycle
    node* head1 = new node(1);
    head1->next = new node(2);
    head1->next->next = new node(3);
    head1->next->next->next = new node(4);
    head1->next->next->next->next = new node(5);
    head1->next->next->next->next->next = head1->next->next;

    // Check if a cycle is present and remove it
    if (hasCycle(head1)) {
        cout << "Cycle is present" << endl;

        removeCycle(head1);
        cout << "Cycle removed" << endl;
    } else {
        cout << "Cycle is not present" << endl;
    }

    // Print the linked list before and after removing the cycle
    cout << "Linked List before removing the cycle: ";
    print(head1);

    return 0;
}
