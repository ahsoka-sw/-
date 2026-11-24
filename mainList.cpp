#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List lst;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char s;
        cin >> s;
        try {
            if (s == 'f') {
                int val;
                cin >> val;
                lst.push_front(val);
            } 
            else if (s == 'b') {
                int val;
                cin >> val;
                lst.push_back(val);
            } 
            else if (s == 'p') 
                lst.pop_front();
            else if (s == 'k') 
                lst.pop_back();
            else if (s == 'g') {
                int pos;
                cin >> pos;
                cout << lst.get(pos - 1) << endl;
            }
        } 
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }
    }
}

