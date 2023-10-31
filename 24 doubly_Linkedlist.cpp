#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int d) : data(d), next(nullptr), prev(nullptr) {}

    ~node() {
        if (next != nullptr) {
            delete next;
            next = nullptr;
        }
    }
};

void insert_at_head(node* &head, node* &tail, int d) {
    if (head == nullptr) {
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }
    else {
        node* temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insert_at_tail(node* &tail, node* &head, int d) {
    if (tail == nullptr) {
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }
    else {
        node* temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insert_at_pos(node* &head, node* &tail, int pos, int d) {
    if (pos == 1) {
        insert_at_head(head, tail, d);
    }
    else {
        node* temp = head;
        int cnt = 1;
        while (cnt < pos - 1 && temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        if (temp == nullptr) {
            // Position exceeds the length of the list; insert at the tail
            insert_at_tail(tail, head, d);
        }
        else {
            node* dev = new node(d);
            dev->next = temp->next;
            dev->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = dev;
            }
            temp->next = dev;
        }
    }
}

void deletenode(node* &head, int pos) {
    if (pos == 1) {
        node* temp = head;
        if (temp->next != nullptr) {
            temp->next->prev = nullptr;
        }
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    else {
        node* curr = head;
        node* prev = nullptr;
        int cnt = 1;
        while (cnt < pos && curr != nullptr) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr != nullptr) {
            curr->prev = nullptr;
            if (curr->next != nullptr) {
                curr->next->prev = prev;
            }
            prev->next = curr->next;
            curr->next = nullptr;
            delete curr;
        }
    }
}

void print(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = nullptr;
    node* tail = nullptr;
    insert_at_head(head, tail, 30);
    insert_at_head(head, tail, 40);
    insert_at_head(head, tail, 20);
    insert_at_head(head, tail, 10);
    insert_at_head(head, tail, 50);
    insert_at_tail(tail, head, 200);
    insert_at_pos(head, tail, 3, 100);
    cout << "Linked List before deleting the node:" << endl;
    print(head);

    deletenode(head, 2);

    cout << "Linked List after deleting the node:" << endl;
    print(head);
    
    // Properly clean up memory by deleting the linked list
    if (head != nullptr) {
        delete head;
        head = nullptr;
    }

    return 0;
}
