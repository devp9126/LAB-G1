#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}

    ~Node() {
        // Destructor to release memory recursively for the linked list
        cout << "Memory freed for node with data: " << data << endl;
        if (next != nullptr) {
            delete next;
        }
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    // Insert a new node at the head of the linked list
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void deleteNode(int position, Node* &head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    } else if (position > 1) {
        int currentPos = 1;
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && currentPos < position) {
            prev = temp;
            temp = temp->next;
            currentPos++;
        }

        if (temp == nullptr) {
            cout << "Invalid position to delete." << endl;
        } else {
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
        }
    } else {
        cout << "Invalid position to delete." << endl;
    }
}

void print(Node* head) {
    // Print the elements of the linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert elements at the head
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);

    cout << "Linked List after insertions: ";
    print(head);

    // Delete a node at position 1 (head)
    deleteNode(1, head);

    cout << "Linked List after deletion: ";
    print(head);

    // Destructor for releasing memory
    if (head != nullptr) {
        delete head;
        head = nullptr;
    }

    return 0;
}
