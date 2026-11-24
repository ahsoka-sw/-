#pragma once
#include <string>

using namespace std;

// Узел бора
struct Node {
    Node* next[26];
    bool isEnd;

    // Конструктор узла
    Node();
};

// Бор
class Trie {
private:
    Node* root;

    // Рекурсивное удаление всех узлов бора (очистка памяти)
    void clear(Node* node);

public:
    // Конструктор бора
    Trie();

    // Деструктор бора
    ~Trie();

    // Добавление слова в бор
    void insert(const string& word);

    // Поиск слова в боре 
    bool search(const string& word);

    // Проверка, существует ли в боре слово с заданным префиксом
    bool startsWith(const string& prefix);
};
