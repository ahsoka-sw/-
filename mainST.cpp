#include <iostream>
#include <vector>
#include "ST.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    try {
        SegmentTree st(a);
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            char s;
            cin >> s;
            if (s == 'u') {
                int pos, val;
                cin >> pos >> val;
                st.set(pos - 1, val);
            } 
            else if (s == 'q') {
                int l, r;
                cin >> l >> r;
                cout << st.sum(l - 1, r - 1) << endl;
            }
        }
    } 
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}


