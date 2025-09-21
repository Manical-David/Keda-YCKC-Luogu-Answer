#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> st;
    string it;
    while (cin >> it && it != "@") {
        if (it == "+" || it == "-" || it == "*" || it == "/") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (it == "+") {
                st.push(a + b);
            } else if (it == "-") {
                st.push(b - a);
            } else if (it == "*") {
                st.push(a * b);
            } else if (it == "/") {
                st.push(b / a);
            }
        } else {
            st.push(stoi(it));
        }
    }
    cout << st.top() << '\n';
    return 0;
}