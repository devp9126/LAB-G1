#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) : data(data), next(nullptr) {}
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
            temp->next = dev;
        }
    }
}

node* getmidnode(node* &head) {
    node* fast = head;
    node* slow = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
    cout << "Inserting the nodes" << endl;
    insert_at_head(head, tail, 30);
    insert_at_head(head, tail, 40);
    insert_at_head(head, tail, 20);
    insert_at_head(head, tail, 10);
    insert_at_head(head, tail, 50);
    insert_at_tail(tail, head, 200);
    insert_at_pos(head, tail, 3, 100);
    cout << "Linked List: ";
    print(head);
    cout << "Middle node is " << getmidnode(head)->data << endl;

    // Properly clean up memory by deleting the linked list
    if (head != nullptr) {
        delete head;
        head = nullptr;
    }

    return 0;
}
