#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertIntoBST(node* root, int d) {
    if (root == NULL) {
        return new node(d);
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    }
    else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void levelOrder(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

node* findMinimum(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

node* deleteNode(node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void takeInput(node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main() {
    node* root = NULL;
    cout << "Enter the data (-1 to end input):" << endl;
    takeInput(root);
    cout << "Level Order Traversal of the BST: ";
    levelOrder(root);
    cout << endl;

    int key;
    cout << "Enter the node to delete: ";
    cin >> key;
    root = deleteNode(root, key);

    cout << "BST after deleting node " << key << ": ";
    levelOrder(root);
    cout << endl;

    return 0;
}
