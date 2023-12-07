#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

Node* leftRotate(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        if (key < node->left->key) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balanceFactor < -1) {
        if (key > node->right->key) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

void printTree(Node* root, int space) {
    if (root == nullptr) {
        return;
    }

    printTree(root->right, space + 5);

    cout << std::endl;
    for (int i = 0; i < space; i++) {
        cout << " ";
    }
    cout << root->key << "\n";

    printTree(root->left, space + 5);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 19);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 18);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 23);

    printTree(root, 0);

    return 0;
}