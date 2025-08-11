#include <bits/stdc++.h>
using namespace std;
bool match(char op, char cl) {
    return (op == '(' && cl == ')') || (op == '[' && cl == ']');
}
string checker(const string& str) {
    stack<char> s;
    for (char b : str) {
        if (b == '(' || b == '[') {
            s.push(b);
        } else if (b == ')' || b == ']') {
            if (s.empty() || !match(s.top(), b)) {
                return "Wrong";
            } else {
                s.pop();
            }
        }
    }
    return s.empty() ? "OK" : "Wrong";
}
int main() {
    string str;
    cin >> str;
    cout << checker(str) << endl;
    return 0;
}