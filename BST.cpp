#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    int arr[] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6};

    Node* root = nullptr;

    for (int i = 0; i < 10; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Binary Search Tree created successfully." << endl;
    cout << "In-order Traversal of the Tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}