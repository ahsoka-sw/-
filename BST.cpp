#include "BST.h"

Node::Node(int v) {
    val = v;
    left = nullptr;
    right = nullptr;
}

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    clear(root);
}

void BST::clear(Node* node) {
    if (node == nullptr)
        return;
    clear(node->left);
    clear(node->right);
    delete node;
}

Node* BST::insert(Node* node, int val) {
    if (node == nullptr)
        return new Node(val);
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    return node;
}

bool BST::search(Node* node, int val) {
    if (node == nullptr)
        return false;
    if (node->val == val)
        return true;
    if (val < node->val)
        return search(node->left, val);
    return search(node->right, val);
}

Node* BST::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* BST::remove(Node* node, int val) {
    if (node == nullptr)
        throw "Element not found";
    if (val < node->val) 
        node->left = remove(node->left, val);
    else if (val > node->val) 
        node->right = remove(node->right, val);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } 
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->val = temp->val;
        node->right = remove(node->right, temp->val);
    }
    return node;
}

void BST::insert(int val) {
    root = insert(root, val);
}

bool BST::find(int val) {
    return search(root, val);
}

void BST::erase(int val) {
    root = remove(root, val);
}
