#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST tree;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char s;
        cin >> s;
        try {
            if (s == 'a') {
                int val;
                cin >> val;
                tree.insert(val);
            } 
            else if (s == 'f') {
                int val;
                cin >> val;
                cout << tree.find(val) << endl;
            } 
            else if (s == 'd') {
                int val;
                cin >> val;
                tree.erase(val);
            }
        } 
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }
    }
}
