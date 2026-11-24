#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    Heap hp;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char s;
        cin >> s;
        try {
            if (s == 'a') {
                int val;
                cin >> val;
                hp.push(val);
            } 
            else if (s == 'p') 
                hp.pop();
            else if (s == 't') 
                cout << hp.top() << endl;
            else if (s == 's') 
                cout << hp.size() << endl;
        } 
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }
    }
}
