#include "Stack.h"

Node::Node(int v) {
    val = v;
    next = nullptr;
}

Stack::Stack() {
    head = nullptr;
    sz = 0;
}

Stack::~Stack() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Stack::push(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    sz++;
}

void Stack::pop() {
    if (head == nullptr)
        throw "Stack is empty";
    Node* temp = head;
    head = head->next;
    delete temp;
    sz--;
}

int Stack::top() {
    if (head == nullptr)
        throw "Stack is empty";
    return head->val;
}

int Stack::size() {
    return sz;
}

bool Stack::empty() {
    return sz == 0;
}

