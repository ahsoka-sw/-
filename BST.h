#pragma once

// Узел бинарного дерева поиска
struct Node {
    int val;
    Node* left;
    Node* right;

    // Конструктор узла
    Node(int v);
};

// Класс бинарного дерева поиска
class BST {
private:
    Node* root;

    // Рекурсивная вставка нового значения в поддерево
    Node* insert(Node* node, int val);

    // Рекурсивный поиск значения в поддереве
    bool search(Node* node, int val);

    // Поиск узла с минимальным значением в поддереве
    Node* findMin(Node* node);

    // Рекурсивное удаление узла с заданным значением
    Node* remove(Node* node, int val);

    // Рекурсивная очистка памяти поддерева
    void clear(Node* node);

public:
    // Конструктор дерева
    BST();

    // Деструктор дерева
    ~BST();

    // Добавление элемента в дерево
    void insert(int val);

    // Проверка наличия элемента в дереве
    bool find(int val);

    // Удаление элемента из дерева
    void erase(int val);
};
