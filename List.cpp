#include "List.h"

Node::Node(int v) {
    val = v;
    prev = nullptr;
    next = nullptr;
}

List::List() {
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

List::~List() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::push_front(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) 
        head = tail = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    sz++;
}

void List::push_back(int val) {
    Node* newNode = new Node(val);
    if (tail == nullptr) 
        head = tail = newNode;
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    sz++;
}

void List::pop_front() {
    if (head == nullptr)
        throw "List is empty";
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete temp;
    sz--;
}

void List::pop_back() {
    if (tail == nullptr)
        throw "List is empty";
    Node* temp = tail;
    tail = tail->prev;
    if (tail != nullptr)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp;
    sz--;
}

int List::get(int pos) {
    if (pos < 0 || pos >= sz)
        throw "Index out of range";
    Node* cur = head;
    for (int i = 0; i < pos; i++) {
        cur = cur->next;
    }
    return cur->val;
}

int List::size() {
    return sz;
}
