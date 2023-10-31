#include <iostream>
using namespace std;

class stack {
public:
    int* arr;
    int top;
    int size;

    stack(int size) {
        this->size = size;
        arr = new int[size]; // Use square brackets for dynamic array allocation
        top = -1;
    }

    void push(int element) {
        if (top < size - 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "stack overflow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "stack underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value
        }
    }

    bool isempty() {
        return (top == -1);
    }
};

int main() {
    stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if (st.isempty()) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Stack is not Empty" << endl;
    }

    // Properly clean up memory by deleting the array
    delete[] st.arr;

    return 0;
}
