#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    char c;
    stack <char> tong;
    while(cin >> c) {
        if(c == '(') {
            tong.push(c);
        }
        else if(c == ')') {
            if(!tong.empty() && tong.top() == '(') tong.pop();
            else if(tong.empty() || tong.top() != '('){
                cout << "NO";
                return 0;
            }
        }
    }
    if(!tong.empty()) cout << "NO";
    else cout << "YES";
    return 0;
}