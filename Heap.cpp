#include "Heap.h"
#include <algorithm>

Heap::Heap() {}

void Heap::siftUp(int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (data[idx] > data[parent]) {
            swap(data[idx], data[parent]);
            idx = parent;
        } 
        else 
            break;
    }
}

void Heap::siftDown(int idx) {
    int sz = data.size();
    while (2 * idx + 1 < sz) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int largest = left;
        if (right < sz && data[right] > data[left])
            largest = right;
        if (data[largest] > data[idx]) {
            swap(data[idx], data[largest]);
            idx = largest;
        } 
        else 
            break;
    }
}

void Heap::push(int val) {
    data.push_back(val);
    siftUp(data.size() - 1);
}

void Heap::pop() {
    if (data.empty())
        throw "Heap is empty";
    data[0] = data.back();
    data.pop_back();
    if (!data.empty())
        siftDown(0);
}

int Heap::top() {
    if (data.empty())
        throw "Heap is empty";
    return data[0];
}

int Heap::size() {
    return data.size();
}

bool Heap::empty() {
    return data.empty();
}
