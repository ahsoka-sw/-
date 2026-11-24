#include <iostream>
#include <string>
#include "Trie.h"

using namespace std;

int main() {
    Trie tr;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char s;
        string word;
        cin >> s >> word;
        try {
            if (s == 'a') 
                tr.insert(word);
            else if (s == 'f') 
                cout << tr.search(word) << endl;
            else if (s == 'p') 
                cout << tr.startsWith(word) << endl;
        } 
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }
    }
}

