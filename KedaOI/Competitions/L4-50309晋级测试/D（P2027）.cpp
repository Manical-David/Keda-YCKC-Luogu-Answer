#include <bits/stdc++.h>
using namespace std;
bool checkop(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int calc(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}
int f(const string& n) {
    stack<int> st;
    for (int i = n.size() - 1; i >= 0; --i) {
        if (n[i] == ' ') {
            continue;
        }
        if (checkop(n[i])) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int ans = calc(a, b, n[i]);
            st.push(ans);
        } else {
            string num;
            while (i >= 0 && n[i]!= ' ' &&!checkop(n[i])) {
                num = n[i] + num;
                --i;
            }
            ++i; 
            istringstream iss(num);
            int tong;
            iss >> tong;
            st.push(tong);
        }
    }
    return st.top();
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    string str;
    getline(cin, str);
    int ans = f(str);
    cout << ans << '\n';
    return 0;
}