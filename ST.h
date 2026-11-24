#pragma once
#include <vector>

using namespace std;

// Класс дерева отрезков для вычисления суммы на подотрезке
class SegmentTree {
private:
    vector<int> tree;
    int n;

    // Рекурсивное построение дерева по исходному массиву
    void build(const vector<int>& a, int v, int tl, int tr);

    // Рекурсивное обновление значения элемента в заданной позиции
    void update(int v, int tl, int tr, int pos, int val);

    // Рекурсивный запрос суммы на отрезке [l, r]
    int query(int v, int tl, int tr, int l, int r);

public:
    // Конструктор дерева отрезков по вектору чисел
    SegmentTree(const vector<int>& a);

    // Изменение значения элемента по индексу pos на val
    void set(int pos, int val);

    // Вычисление суммы элементов на отрезке от l до r включительно
    int sum(int l, int r);
};

