#include "ST.h"
#include <algorithm>

SegmentTree::SegmentTree(const vector<int>& a) {
    if (a.empty())
        throw "Tree cannot be empty";
    n = a.size();
    tree.resize(4 * n, 0);
    build(a, 1, 0, n - 1);
}

void SegmentTree::build(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) 
        tree[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

void SegmentTree::update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) 
        tree[v] = val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int SegmentTree::query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void SegmentTree::set(int pos, int val) {
    if (pos < 0 || pos >= n)
        throw "Index out of range";
    update(1, 0, n - 1, pos, val);
}

int SegmentTree::sum(int l, int r) {
    if (l < 0 || r >= n || l > r)
        throw "Invalid range";
    return query(1, 0, n - 1, l, r);
}


