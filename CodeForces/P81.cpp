#include <bits/stdc++.h>
using namespace std;
bool check(const string& expr) {
    stack<char> paren;
    bool exp = true;
    for (size_t i = 0; i < expr.size() - 1; ++i) {
        char c = expr[i];
        if (isspace(c)) continue;
        if (exp) {
            if (c == '(') {
                paren.push(c);
            } else if (c == '+' || c == '*' || c == '/') {
                return false;
            } else if (c == '-') {
            } else if (isdigit(c)) {
                exp = false;
            } else {
                return false;
            }
        } else {
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                exp = true;
            } else if (c == ')') {
                if (paren.empty() || paren.top() != '(') {
                    return false;
                }
                paren.pop();
            } else {
                return false;
            }
        }
    }
    if (expr.back() != '@') return false;
    if (!paren.empty()) return false;
    return !exp;
}
int pd(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
vector<string> IN_F(const string& expr) {
    vector<string> pf;
    stack<char> ops;
    for (size_t i = 0; i < expr.size() - 1; ++i) {
        char c = expr[i];
        if (isspace(c)) continue;
        if (isdigit(c)) {
            string num;
            while (i < expr.size() - 1 && isdigit(expr[i])) {
                num += expr[i++];
            }
            --i;
            pf.push_back(num);
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                pf.push_back(string(1, ops.top()));
                ops.pop();
            }
            if (ops.empty()) {
                throw runtime_error("Mismatched parentheses");
            }
            ops.pop();
        } else {
            while (!ops.empty() && pd(ops.top()) >= pd(c)) {
                pf.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(c);
        }
    }
    while (!ops.empty()) {
        if (ops.top() == '(') {
            throw runtime_error("Mismatched parentheses");
        }
        pf.push_back(string(1, ops.top()));
        ops.pop();
    }

    return pf;
}
double eval(const vector<string>& pf) {
    stack<double> vals;
    for (const string& tk : pf) {
        if (isdigit(tk[0])) {
            vals.push(stod(tk));
        } else {
            double b = vals.top(); vals.pop();
            double a = vals.top(); vals.pop();
            switch (tk[0]) {
                case '+': vals.push(a + b); break;
                case '-': vals.push(a - b); break;
                case '*': vals.push(a * b); break;
                case '/': 
                    if (b == 0) throw runtime_error("Division by zero");
                    vals.push(a / b); 
                    break;
                default: throw runtime_error("Unknown operator");
            }
        }
    }
    if (vals.size() != 1) {
        throw runtime_error("Invalid expression");
    }
    return vals.top();
}
int main() {
    string expr;
    getline(cin, expr);
    if (!check(expr)) {
        cout << "NO" << '\n';
        return 0;
    }
    try {
        vector<string> pf = IN_F(expr);
        double ans = eval(pf);
        cout << ans << '\n';
    } catch (const exception& e) {
        cout << "NO" << '\n';
    }
    return 0;
}
 // SDDbui