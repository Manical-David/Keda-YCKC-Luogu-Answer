#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s) {
        if (!st.empty()) {
            char top = st.top();
            if ((top == 'A' && c == 'P') || (top == 'P' && c == 'P')) {
                st.pop();
                continue;
            }
        }
        st.push(c);
    }
    cout << st.size() << '\n';
    return 0;
}
