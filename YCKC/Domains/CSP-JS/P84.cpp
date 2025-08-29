#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

bool isCorrect(const string &s) {
    stack<char> st;
    unordered_map<char, int> priority = {
        {'<', 4}, {'>', 4},
        {'(', 3}, {')', 3},
        {'[', 2}, {']', 2},
        {'{', 1}, {'}', 1}
    };

    for (char c : s) {
        if (c == '<' || c == '(' || c == '[' || c == '{') {
            if (!st.empty()) {
                char top = st.top();
                if (priority[c] <= priority[top]) {
                    return false;
                }
            }
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((top == '<' && c == '>') ||
                (top == '(' && c == ')') ||
                (top == '[' && c == ']') ||
                (top == '{' && c == '}')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // 忽略第一行后的换行符

    while (N--) {
        string s;
        getline(cin, s);
        cout << (isCorrect(s) ? "YES" : "NO") << endl;
    }

    return 0;
}
