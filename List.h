#pragma once

// Узел двусвязного списка
struct Node {
    int val;
    Node* prev;
    Node* next;

    // Конструктор узла
    Node(int v);
};

// Класс двусвязного списка
class List {
private:
    Node* head;
    Node* tail;
    int sz;

public:
    // Конструктор списка
    List();

    // Деструктор списка (очистка памяти)
    ~List();

    // Добавление элемента в начало списка
    void push_front(int val);

    // Добавление элемента в конец списка
    void push_back(int val);

    // Удаление элемента из начала списка
    void pop_front();

    // Удаление элемента из конца списка
    void pop_back();

    // Получение значения элемента по индексу
    int get(int pos);

    // Получение текущего размера списка
    int size();
};

