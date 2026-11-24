#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    Stack st;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        st.push(val);
    }
    Stack sorted;
    while (!st.empty()) {
        int temp = st.top();
        st.pop();
        while (!sorted.empty() && sorted.top() < temp) {
            st.push(sorted.top());
            sorted.pop();
        }
        sorted.push(temp);
    }
    while (!sorted.empty()) {
        cout << sorted.top() << ' ';
        sorted.pop();
    }
}
