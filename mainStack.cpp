#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack st;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char s;
        cin >> s;
        try {
            if (s == 'a') {
                int val;
                cin >> val;
                st.push(val);
            } 
            else if (s == 'p') 
                st.pop();
            else if (s == 't') 
                cout << st.top() << endl;
            else if (s == 's') 
                cout << st.size() << endl;
        } 
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }
    }
}
