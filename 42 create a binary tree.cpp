#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* buildBinaryTree() {
    int data;
    cout << "Enter the root node value (-1 for empty): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftValue, rightValue;

        cout << "Enter left child value of " << current->data << " (-1 for empty): ";
        cin >> leftValue;

        if (leftValue != -1) {
            current->left = new TreeNode(leftValue);
            q.push(current->left);
        }

        cout << "Enter right child value of " << current->data << " (-1 for empty): ";
        cin >> rightValue;

        if (rightValue != -1) {
            current->right = new TreeNode(rightValue);
            q.push(current->right);
        }
    }

    return root;
}

void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    TreeNode* root = buildBinaryTree();

    cout << "Level Order Traversal of the Binary Tree: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
