#include "Trie.h"
#include <iostream>

using namespace std;

Node::Node() {
    isEnd = false;
    for (int i = 0; i < 26; i++) {
        next[i] = nullptr;
    }
}

Trie::Trie() {
    root = new Node();
}

Trie::~Trie() {
    clear(root);
}

void Trie::clear(Node* node) {
    if (node == nullptr) 
        return;
    for (int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    delete node;
}

void Trie::insert(const string& word) {
    if (word.empty()) 
        throw "Word can't be empty";
    Node* cur = root;
    for (char c : word) {
        if (c < 'a' || c > 'z') 
            throw "Only lowercase English letters are allowed";
        int idx = c - 'a';
        if (cur->next[idx] == nullptr) 
            cur->next[idx] = new Node();
        cur = cur->next[idx];
    }
    cur->isEnd = true;
}

bool Trie::search(const string& word) {
    if (word.empty()) 
        throw "Word can't be empty";
    Node* cur = root;
    for (char c : word) {
        if (c < 'a' || c > 'z') 
            throw "Only lowercase English letters are allowed";
        int idx = c - 'a';
        if (cur->next[idx] == nullptr) {
            return false;
        }
        cur = cur->next[idx];
    }
    return cur->isEnd;
}

bool Trie::startsWith(const string& prefix) {
    if (prefix.empty()) 
        throw "Prefix cannot be empty";
    Node* cur = root;
    for (char c : prefix) {
        if (c < 'a' || c > 'z') 
            throw "Only lowercase English letters are allowed";
        int idx = c - 'a';
        if (cur->next[idx] == nullptr) {
            return false;
        }
        cur = cur->next[idx];
    }
    return true;
}
