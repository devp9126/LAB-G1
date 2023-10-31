#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) : data(data), next(nullptr) {}
};

node* merge(node* &first, node* &second) {
    if (first == nullptr) {
        return second;
    }
    if (second == nullptr) {
        return first;
    }

    node* ans = new node(-1);
    node* temp = ans;

    while (first != nullptr && second != nullptr) {
        if (first->data <= second->data) {
            temp->next = first;
            temp = first;
            first = first->next;
        }
        else {
            temp->next = second;
            temp = second;
            second = second->next;
        }
    }

    while (first != nullptr) {
        temp->next = first;
        temp = first;
        first = first->next;
    }
    while (second != nullptr) {
        temp->next = second;
        temp = second;
        second = second->next;
    }

    ans = ans->next;
    return ans;
}

void displayList(node* head) {
    node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    node* list1 = new node(1);
    list1->next = new node(3);
    list1->next->next = new node(5);

    node* list2 = new node(2);
    list2->next = new node(4);
    list2->next->next = new node(6);

    cout << "List 1: ";
    displayList(list1);

    cout << "List 2: ";
    displayList(list2);

    node* mergedList = merge(list1, list2);

    cout << "Merged List: ";
    displayList(mergedList);

    // Properly clean up memory by deleting the linked lists
    if (list1 != nullptr) {
        delete list1;
        list1 = nullptr;
    }

    if (list2 != nullptr) {
        delete list2;
        list2 = nullptr;
    }

    if (mergedList != nullptr) {
        delete mergedList;
        mergedList = nullptr;
    }

    return 0;
}
