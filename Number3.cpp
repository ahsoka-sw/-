#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    Heap hp;
    for (int i = 0; i < n; i++) {
        int stone;
        cin >> stone;
        hp.push(stone);
    }
    while (hp.size() > 1) {
        int y = hp.top();
        hp.pop();
        int x = hp.top();
        hp.pop();
        if (x != y)
            hp.push(y - x);
    }
    if (hp.empty())
        cout << 0;
    else
        cout << hp.top();
}
